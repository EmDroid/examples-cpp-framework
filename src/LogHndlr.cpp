/*
    Copyright (C) 1998-2007 Emil Maskovsky

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
    implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/


/**
    @file

    Log handler base (implementation).

    @author Emil Maskovsky
*/


/* Framework libraries. */
#include "mx/LogStdE.hpp"


/* Application specific. */
#include "mx/LogHndlr.hpp"


/**
    Mapping of Log::LogType to printable names.

    @warning
    The order must match the definition of Log::LogType.
*/
static const mx::ArrayItemInitializer< const mx::Char * >
sm_sLogTypeStrings[mx::Log::LOG_COUNT] =
{
    // Message
    mxTranslate("Message"),
    // Warning
    mxTranslate("Warning"),
    // Check
    mxTranslate("Check failed"),
    // Assert
    mxTranslate("Assertion failed"),
    // Error
    mxTranslate("Error"),
    // FatalError
    mxTranslate("Fatal error"),
    // Debug
    mxTranslate("Debug"),
    // Trace
    mxTranslate("Trace"),
};


/**
    Log the message.

    @param [in] xFileInfo Source file location information.
    @param [in] iType     Type of log message.
    @param [in] sFormat   @c printf(3) like formatting string.
    @param [in] ...       Argument list matching the @a sFormat string.

    @return
    Returns the result of logging. The return value will be @c -1 on failure (but
    in most situations some exception will be thrown in that case), @c 0 if no
    logging was done (the logging subsystem is disabled for the log type etc.),
    and a value greater than zero if the logging was successfully done.
*/
MX_PRINTFLIKE_METHOD(3, 4) mx::Size mx::LogHandler::DoLog(
        const Debug::Checkpoint & xFileInfo,
        const Log::LogType iType,
        const Char * sFormat, ...)
{
    va_list pArgs;
    va_start(pArgs, sFormat);
    const Size iResult = DoLog(xFileInfo, iType, sFormat, pArgs);
    va_end(pArgs);
    return iResult;
}


/**
    Log the message.

    @param [in] iType   Type of log message.
    @param [in] sFormat @c printf(3) like formatting string.
    @param [in] ...     Argument list matching the @a sFormat string.

    @return
    See DoLog() for description of return values.
*/
MX_PRINTFLIKE_METHOD(2, 3) mx::Size mx::LogHandler::DoLog(
        const Log::LogType iType,
        const Char * sFormat, ...)
{
    va_list pArgs;
    va_start(pArgs, sFormat);
    const Size iResult = DoLog(iType, sFormat, pArgs);
    va_end(pArgs);
    return iResult;
}


/**
    Log the message (vararg version).

    @param [in] xFileInfo  Source file location information.
    @param [in] iType      Type of log message.
    @param [in] sFormat    @c printf(3) like formatting string.
    @param [in] pArguments Argument list matching the @a sFormat string.

    @return
    See DoLog() for description of return values.
*/
mx::Size mx::LogHandler::DoLog(
        const Debug::Checkpoint & xFileInfo,
        const Log::LogType iType,
        const Char * sFormat, va_list pArguments)
{
    // Check the log type.
    Log::LogType iLogType = iType;
    if ((iLogType < 0) || (iLogType >= Log::LOG_COUNT))
    {
        DoLog(xFileInfo, Log::LOG_Warning,
                _("Invalid log message type!"));
        // Treat all as "Log: ..."
        iLogType = static_cast< Log::LogType >(0);
    }
    // Check the format.
    if (!sFormat)
    {
        DoLog(xFileInfo, Log::LOG_Error,
                _("Invalid log message format string!"));
        // Invalid format string.
        return 0;
    }

    /* Prepare the message. */

    // See if the message needs any formatting. Print it to String buffer if
    // it does, use it as it is otherwise. Also check for the special case when
    // the formatting string is equal to "%s". In that case we pass the first
    // (and only) string argument instead.
    //
    // This is to avoid any memory allocations unless they are necessary.
    // This way the debugging system can work even in low memory situations.
    //
    // In case the memory allocation fails, warn about that fact and pass the
    // message string as is, unformated.
    //
    // This all may seem like lot of needless work but the debug output is very
    // precious and we really really want to give the developer as much clue
    // as possible.
    const Char * sMessage;

    /*
    // Declare String message buffer pointer here, no allocations are done at
    // the moment. We must ensure that the String potentialy allocated is not
    // destroyed before its C-string (sMessage) is used.
    ScopedPointer< String > sMessageBuffer;
    */

//    if (NULL == strchr(sFormat, '%') )
    {
        // No formatting sequences at all.
        sMessage = sFormat;
    }
    /*
    else if (strcmp(sFormat, "%s") == 0)
    {
        // The format string uses only first string argument.
        sMessage = va_arg(pArgs, char *);
    }
    else
    {
        try
        {
            sMessageBuffer = new String;
            sMessageBuffer->PrintfV(sFormat, pArgs);
            sMessage = sMessageBuffer->Cstring();
        }
        catch (const MemoryException e)
        {
            mxLogWarning(_("Not enough memory to format the debug output,"
                " passing the formatting string as is.") );
            sMessage = sFormat;
            // Ignore the exception.
            e->Destroy();
        }
    }
    */

    // Convert the message type to type name.
    mxAssert((unsigned int)iLogType < mxArrayLength(sm_sLogTypeStrings));
    mxAssert(sm_sLogTypeStrings[iLogType] != NULL);
    const Char * const sTypeString = GetTranslation(
            sm_sLogTypeStrings[iLogType]);

    // Always pass the message to the interactive debugger,
    // if we are running under one.
#ifdef MX_DEBUGGER_OUTPUT
    // Don't bother abour debug/non-debug mode, pass always - in non-debug mode
    // the function we are in mostly doesn't get run at all, and when is, we
    // really want to see the debug output.
    {
        const Size iMessageLength =
#ifndef MXCPP_UNICODE
                    ::strlen
#else
                    ::wcslen
#endif
                (sMessage);
        const bool bSupressFormatting = ((iMessageLength > 0)
                                         && ('\n' == sMessage[iMessageLength - 1]));

        /*
#ifdef MXCPP_MULTITHREAD
        static Mutex mutexDebugOutput;
        const MutexLocker locker(mutexDebugOutput);
#endif
       */
        // Do not construct the string using String, can cause endless loop
        // (if we're tracing memory allocations).
        //
        // Write it directly.
        if (!bSupressFormatting)
        {
            MX_DEBUGGER_OUTPUT(sTypeString);
            MX_DEBUGGER_OUTPUT(_T(": "));
        }
        MX_DEBUGGER_OUTPUT(sMessage);
        if (!bSupressFormatting)
        {
            if (!xFileInfo.Empty())
            {
                // Static to not do any memory allocations.
                // The entire block is locked by mutex, so it will not interfere
                // in case of multi threads.
                static Char sFileLineBuffer[20];
#ifndef MXCPP_UNICODE
                ::sprintf
#else
                ::wsprintf
#endif
                    (sFileLineBuffer, _T("%lu"), xFileInfo.getLine());
                MX_DEBUGGER_OUTPUT(_T(" ["));
                MX_DEBUGGER_OUTPUT(xFileInfo.getFile());
                MX_DEBUGGER_OUTPUT(_T(":"));
                MX_DEBUGGER_OUTPUT(sFileLineBuffer);
                MX_DEBUGGER_OUTPUT(_T("]"));
            }
            MX_DEBUGGER_OUTPUT(_T("\n"));
        }
    }
#endif // MX_DEBUGGER_OUTPUT

    try
    {
        return OnLog(xFileInfo, iType, sTypeString,
                // If not formatted yet, will be formatted now by the log target.
                sMessage, pArguments);
    }
    catch (...)
    {
        // Ignore all exceptions, to allow usage of logging system even in
        // UncaughtExceptionHandler.
#ifdef MX_DEBUGGER_OUTPUT
        MX_DEBUGGER_OUTPUT(_T("Exception caught during logging!\n"));
#endif // MX_DEBUGGER_OUTPUT
        /// @todo Try to log to some default log target.
    }
    // Logging failed.
    return 0;
}


/**
    Flush the log handler.
*/
void mx::LogHandler::Flush()
{
    try
    {
        OnFlush();
    }
    catch (...)
    {
        // Ignore all exceptions for now.
#ifdef MX_DEBUGGER_OUTPUT
        MX_DEBUGGER_OUTPUT(_T("Exception caught during logging!\n"));
#endif // MX_DEBUGGER_OUTPUT
        /// @todo Try to log to some default log target.
    }
}


// Define inline methods here if inlining is disabled.
#ifndef MX_INLINE_ENABLED
#include "mx/LogHndlr.inl"
#endif

/* EOF */
