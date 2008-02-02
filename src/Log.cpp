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

    Logging subsystem (implementation).

    @author Emil Maskovsky
*/


/* Framework libraries. */
#include "mx/Debug.hpp"


/* Application specific. */
#include "mx/Log.hpp"


MX_PRINTFLIKE_METHOD(1, 2) void mx::Log::Starter::LogMessage(
        const char * sFormat, ...)
{
    Log * const pTarget = Log::GetActiveTarget();
    if (!pTarget)
    {
        // None active target selected - logging entirely disabled.
        return;
    }
    // Log the message to the log target.
    va_list pArgs;
    va_start(pArgs, sFormat);
    pTarget->DoLogV(m_sFileName, m_iFileLine, m_iType, sFormat, pArgs);
    va_end(pArgs);
}


/**
    Mapping of Log::LogType to printable names.

    @warning
    The order must match the definition of Log::LogType.
*/
static const mx::ArrayItemInitializer< const char * >
sm_sLogTypeStrings[mx::Log::LogType_COUNT] =
{
    // InvalidType
    "Log",
    // Inform
    "Info",
    // Notify
    "Notify",
    // Warning
    "Warning",
    // Check
    "Check",
    // Assert
    "Assert",
    // Error
    "Error",
    // FatalError
    "Fatal error",
    // Debug
    "Debug",
    // Trace
    "Trace",
};


/// Currently active log target.
/* static */ mx::Log * mx::Log::sm_pTarget = NULL;


MX_PRINTFLIKE_METHOD(4, 5) void mx::Log::DoLog(
        const char * const sFileName,
        const Size iFileLine,
// The log message type is after file and name in the parameters list, to
// prevent confusion with the second version, which does not use file name and
// line.
//
// If the type is the first parameter, then there will be ambiquity while the
// second parameter might be file name or format string.
        const LogType iType,
        const char * sFormat, ...)
{
    va_list pArgs;
    va_start(pArgs, sFormat);
    DoLogV(sFileName, iFileLine, iType, sFormat, pArgs);
    va_end(pArgs);
}


MX_PRINTFLIKE_METHOD(2, 3) void mx::Log::DoLog(
        const LogType iType,
        const char * sFormat, ...)
{
    va_list pArgs;
    va_start(pArgs, sFormat);
    DoLogV(iType, sFormat, pArgs);
    va_end(pArgs);
}


void mx::Log::DoLogV(
        const char * const sFileName,
        const Size iFileLine,
// The log message type is after file and name in the parameters list, to
// prevent confusion with the second version, which does not use file name and
// line.
//
// If the type is the first parameter, then there will be ambiquity while the
// second parameter might be file name or format string.
        const LogType iType,
        const char * sFormat, va_list pArgs)
{
    // Check the log type.
    LogType iLogType = iType;
    if ((iLogType <= InvalidType) || (iLogType >= LogType_COUNT))
    {
        DoLog(sFileName, iFileLine, Warning,
                _("Invalid log message type!"));
        // Treat all as "Log: ..."
        iLogType = InvalidType;
    }
    // Check the format.
    if (!sFormat)
    {
        DoLog(sFileName, iFileLine, Error,
                _("Invalid log message format string!"));
        // Invalid format string.
        return;
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
    const char * sMessage;

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
    mxAssert(iLogType
            < mxArrayLength(sLogTypeStrings));
    mxAssert(sm_sLogTypeStrings[iLogType]);
    const char * const sTypeString = sm_sLogTypeStrings[iLogType];

    // Always pass the message to the interactive debugger,
    // if we are running under one.
#ifdef MX_DEBUGGER_OUTPUT
    // Don't bother abour debug/non-debug mode, pass always - in non-debug mode
    // the function we are in mostly doesn't get run at all, and when is, we
    // really want to see the debug output.
    {
        const Size iMessageLength = strlen(sMessage);
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
            MX_DEBUGGER_OUTPUT(_(sTypeString));
            MX_DEBUGGER_OUTPUT(": ");
        }
        __KW_DEBUGGER_OUTPUT__(sMessage);
        if (!bSupressFormatting)
        {
            if (sFileName)
            {
                // Static to not do any memory allocations.
                // The entire block is locked by mutex, so it will not interfere
                // in case of multi threads.
                static char sFileLineBuffer[20];
                sprintf(sFileLineBuffer, "%lu", iFileLine);
                MX_DEBUGGER_OUTPUT(" (");
                MX_DEBUGGER_OUTPUT(sFileName);
                MX_DEBUGGER_OUTPUT(":");
                MX_DEBUGGER_OUTPUT(sFileLineBuffer);
                MX_DEBUGGER_OUTPUT(")");
            }
            MX_DEBUGGER_OUTPUT("\n");
        }
    }
#endif // MX_DEBUGGER_OUTPUT

    OnLog(sFileName, iFileLine, iType, sTypeString,
            // If not formatted yet, will be formatted now by the log target.
            sMessage, pArgs);
}


// Define inline methods here if inlining is disabled.
#ifndef MX_INLINE_ENABLED
#include "mx/log.inl"
#endif

/* EOF */
