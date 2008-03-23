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
#include "mx/LogStdE.hpp"


/* Application specific. */
#include "mx/Log.hpp"


/**
    Unregister log target.

    Unregisters the log target, if currently registered in the handler.

    @param [in] pTarget The log target to be unregistered.

    @return
    Returns @c true, if the @p pTarget was unregistered (i.e. was registered
    before). Returns @c false if current target registered within the handler is
    other than the @p pTarget.
*/
/* static */ bool mx::Log::UnregisterTarget(const LogHandler * const pTarget)
{
    /// @todo Thread safety.
    if (pTarget == sm_pTarget)
    {
        SetActiveTarget(LogStdErr::Instance());
        return true;
    }
    return false;
}


/**
    Flush active log target, if any.
*/
/* static */ void mx::Log::Flush()
{
    if (GetActiveTarget())
    {
        GetActiveTarget()->Flush();
    }
}


/// Currently active log target.
/* static */ mx::LogHandler * mx::Log::sm_pTarget = mx::LogStdErr::Instance();

/// File information engine status.
/* static */ bool mx::Log::sm_bFileInfoEnabled = true;


/**
    Log the message.

    @param [in] sFormat @c printf(3) like formatting string.
    @param [in] ...     Argument list matching the @a sFormat string.

    @return
    See LogHandler::DoLog() for description of return values.
*/
MX_PRINTFLIKE_METHOD(1, 2) mx::Size mx::Log::LogMessage(
        const Char * sFormat, ...) const
{
    va_list pArgs;
    va_start(pArgs, sFormat);
    const Size iResult = LogMessage(sFormat, pArgs);
    va_end(pArgs);
    return iResult;
}


/**
    Log the message (vararg version).

    @param [in] sFormat    @c printf(3) like formatting string.
    @param [in] pArguments Argument list matching the @a sFormat string.

    @return
    See LogHandler::DoLog() for description of return values.
*/
mx::Size mx::Log::LogMessage(
        const Char * sFormat, va_list pArguments) const
{
    LogHandler * const pTarget = Log::GetActiveTarget();
    if (!pTarget)
    {
        // None active target selected - logging entirely disabled.
        return 0;
    }
    // Log the message to the log target.
    return pTarget->DoLog(m_xFileInfo, m_iType, sFormat, pArguments);
}


/**
    Special method for logging of fatal errors.

    @param [in] sFormat @c printf(3) like formatting string.
    @param [in] ...     Argument list matching the @a sFormat string.

    @return
    This method does never return, always causes the application shutdown via the
    standard function abort().
*/
MX_PRINTFLIKE_METHOD(1, 2) MX_NORETURN_TYPE(mx::Size) mx::Log::LogFatal(
        const Char * sFormat, ...) const
{
    va_list pArgs;
    va_start(pArgs, sFormat);
    // Does not return.
    const Size iResult = LogFatal(sFormat, pArgs);
    va_end(pArgs);
    return iResult;
}


/**
    Special method for logging of fatal errors (vararg version).

    @param [in] sFormat    @c printf(3) like formatting string.
    @param [in] pArguments Argument list matching the @a sFormat string.

    @return
    This method does never return, always causes the application shutdown via the
    standard function abort().
*/
// Does not need to be inline, it cannot be called more than once.
MX_NORETURN_TYPE(mx::Size) mx::Log::LogFatal(
        const Char * sFormat, va_list pArguments) const
{
    const Size iResult = LogMessage(sFormat, pArguments);
    abort();
    return iResult;
}


/**
    Special method for logging of assertion failure messages.

    @param [in] sFormat @c printf(3) like formatting string.
    @param [in] ...     Argument list matching the @a sFormat string.

    @return
    This method does never return, always causes the application shutdown via the
    standard function abort().
*/
MX_PRINTFLIKE_METHOD(1, 2) MX_NORETURN_TYPE(mx::Size) mx::Log::LogAssert(
        const Char * sFormat, ...) const
{
    va_list pArgs;
    va_start(pArgs, sFormat);
    // Does not return.
    const Size iResult = LogAssert(sFormat, pArgs);
    va_end(pArgs);
    return iResult;
}


/**
    Special method for logging of assertion failure messages (vararg version).

    @param [in] sFormat    @c printf(3) like formatting string.
    @param [in] pArguments Argument list matching the @a sFormat string.

    @return
    This method does never return, always causes the application shutdown via the
    standard function abort().
*/
// Does not need to be inline, it cannot be called more than once.
MX_NORETURN_TYPE(mx::Size) mx::Log::LogAssert(
        const Char * sFormat, va_list pArguments) const
{
    return LogFatal(sFormat, pArguments);
}


#ifdef MXCPP_DEBUG_ENABLED

/**
    Special method for logging of debug messages.

    @param [in] sFormat @c printf(3) like formatting string.
    @param [in] ...     Argument list matching the @a sFormat string.

    @return
    See LogHandler::DoLog() for description of return values.
*/
MX_PRINTFLIKE_METHOD(1, 2) mx::Size mx::Log::LogDebug(
        const Char * sFormat, ...) const
{
    va_list pArgs;
    va_start(pArgs, sFormat);
    const Size iResult = LogDebug(sFormat, pArgs);
    va_end(pArgs);
    return iResult;
}


#endif // MXCPP_DEBUG_ENABLED


/**
    Special method for logging of trace messages.

    @param [in] sFormat @c printf(3) like formatting string.
    @param [in] ...     Argument list matching the @a sFormat string.

    @return
    See LogHandler::DoLog() for description of return values.

    @note
    In addition to normal logging functions behavior, the logging will not be
    done and the value of @c 0 will be returned in the case, that the tracing
    is disabled for requested trace class and priority level.
*/
MX_PRINTFLIKE_METHOD(1, 2) mx::Size mx::Log::LogTrace(
        const Char * sFormat, ...) const
{
    if (!Log::TracingEnabled())
    {
        return 0;
    }
    va_list pArgs;
    va_start(pArgs, sFormat);
    const Size iResult = LogTrace(sFormat, pArgs);
    va_end(pArgs);
    return iResult;
}


/**
    Special method for logging of trace messages.

    @param [in] iClass  Trace class.
    @param [in] sFormat @c printf(3) like formatting string.
    @param [in] ...     Argument list matching the @a sFormat string.

    @return
    See LogHandler::DoLog() for description of return values.

    @note
    In addition to normal logging functions behavior, the logging will not be
    done and the value of @c 0 will be returned in the case, that the tracing
    is disabled for requested trace class and priority level.
*/
MX_PRINTFLIKE_METHOD(2, 3) mx::Size mx::Log::LogTrace(
        const TraceClass iClass,
        const Char * sFormat, ...) const
{
    if (!Log::TracingEnabled(iClass))
    {
        return 0;
    }
    va_list pArgs;
    va_start(pArgs, sFormat);
    const Size iResult = LogTrace(iClass, sFormat, pArgs);
    va_end(pArgs);
    return iResult;
}


/**
    Special method for logging of trace messages.

    @param [in] iClass  Trace class.
    @param [in] iLevel  Trace priority level.
    @param [in] sFormat @c printf(3) like formatting string.
    @param [in] ...     Argument list matching the @a sFormat string.

    @return
    See LogHandler::DoLog() for description of return values.

    @note
    In addition to normal logging functions behavior, the logging will not be
    done and the value of @c 0 will be returned in the case, that the tracing
    is disabled for requested trace class and priority level.
*/
MX_PRINTFLIKE_METHOD(3, 4) mx::Size mx::Log::LogTrace(
        const TraceClass iClass,
        const TraceLevel iLevel,
        const Char * sFormat, ...) const
{
    if (!Log::TracingEnabled(iClass, iLevel))
    {
        return 0;
    }
    va_list pArgs;
    va_start(pArgs, sFormat);
    const Size iResult = LogTrace(iClass, iLevel, sFormat, pArgs);
    va_end(pArgs);
    return iResult;
}


/**
    Special method for logging of trace messages (string trace mask variant).

    @param [in] sClass  Trace class.
    @param [in] sFormat @c printf(3) like formatting string.
    @param [in] ...     Argument list matching the @a sFormat string.

    @return
    See LogHandler::DoLog() for description of return values.

    @note
    In addition to normal logging functions behavior, the logging will not be
    done and the value of @c 0 will be returned in the case, that the tracing
    is disabled for requested trace class and priority level.
*/
MX_PRINTFLIKE_METHOD(2, 3) mx::Size mx::Log::LogTrace(
        const Char * const sClass,
        const Char * sFormat, ...) const
{
    if (!Log::TracingEnabled(sClass))
    {
        return 0;
    }
    va_list pArgs;
    va_start(pArgs, sFormat);
    const Size iResult = LogTrace(sClass, sFormat, pArgs);
    va_end(pArgs);
    return iResult;
}


/**
    Special method for logging of trace messages (string trace mask variant).

    @param [in] sClass  Trace class.
    @param [in] iLevel  Trace priority level.
    @param [in] sFormat @c printf(3) like formatting string.
    @param [in] ...     Argument list matching the @a sFormat string.

    @return
    See LogHandler::DoLog() for description of return values.

    @note
    In addition to normal logging functions behavior, the logging will not be
    done and the value of @c 0 will be returned in the case, that the tracing
    is disabled for requested trace class and priority level.
*/
MX_PRINTFLIKE_METHOD(3, 4) mx::Size mx::Log::LogTrace(
        const Char * const sClass,
        const TraceLevel iLevel,
        const Char * sFormat, ...) const
{
    if (!Log::TracingEnabled(sClass, iLevel))
    {
        return 0;
    }
    va_list pArgs;
    va_start(pArgs, sFormat);
    const Size iResult = LogTrace(sClass, iLevel, sFormat, pArgs);
    va_end(pArgs);
    return iResult;
}


// Define inline methods here if inlining is disabled.
#ifndef MX_INLINE_ENABLED
#include "mx/Log.inl"
#endif

/* EOF */
