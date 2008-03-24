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

    Logging subsystem (inline methods).

    @author Emil Maskovsky
*/


#ifndef MXCPP_SYSDEFS
// Required for proper documentation creation.
#include "mx/sysdefs.hpp"
#endif


/**
    The log starter constructor.

    Sets up the log event to call logging methods on it.

    In most situations you do not need to bother with the log event startup
    manually, you might want to use want @ref logging_macros "logging macros"
    instead.

    @param [in] iType     Type of log message.
    @param [in] xFileInfo Source file location information.
*/
MX_INLINE mx::Log::Log(
        const LogType iType,
        const Debug::Checkpoint & xFileInfo)
    : m_iType(iType)
    , m_xFileInfo(xFileInfo)
{}


#ifdef MXCPP_DEBUG_ENABLED

/**
    Special method for logging of debug messages (vararg version).

    @param [in] sFormat    @c printf(3) like formatting string.
    @param [in] pArguments Argument list matching the @a sFormat string.

    @return
    See LogHandler::DoLog() for description of return values.
*/
MX_INLINE mx::Size mx::Log::LogDebug(
        const Char * sFormat, va_list pArguments) const
{
    return LogMessage(sFormat, pArguments);
}


#endif // MXCPP_DEBUG_ENABLED


/**
    Special method for logging of trace messages (vararg version).

    @param [in] sFormat    @c printf(3) like formatting string.
    @param [in] pArguments Argument list matching the @a sFormat string.

    @return
    See LogHandler::DoLog() for description of return values.

    @note
    In addition to normal logging functions behavior, the logging will not be
    done and the value of @c 0 will be returned in the case, that the tracing
    is disabled for requested trace class and priority level.
*/
MX_INLINE mx::Size mx::Log::LogTrace(
        const Char * sFormat, va_list pArguments) const
{
    return Log::TracingEnabled(TRACE_User, LEVEL_Normal)
           ? LogMessage(sFormat, pArguments)
           : 0;
}


/**
    Special method for logging of trace messages (vararg version).

    @param [in] iClass     Trace class.
    @param [in] sFormat    @c printf(3) like formatting string.
    @param [in] pArguments Argument list matching the @a sFormat string.

    @return
    See LogHandler::DoLog() for description of return values.

    @note
    In addition to normal logging functions behavior, the logging will not be
    done and the value of @c 0 will be returned in the case, that the tracing
    is disabled for requested trace class and priority level.
*/
MX_INLINE mx::Size mx::Log::LogTrace(
        const TraceClass iClass,
        const Char * sFormat, va_list pArguments) const
{
    return Log::TracingEnabled(iClass, LEVEL_Normal)
           ? LogMessage(sFormat, pArguments)
           : 0;
}


/**
    Special method for logging of trace messages (vararg version).

    @param [in] iClass     Trace class.
    @param [in] iLevel     Trace priority level.
    @param [in] sFormat    @c printf(3) like formatting string.
    @param [in] pArguments Argument list matching the @a sFormat string.

    @return
    See LogHandler::DoLog() for description of return values.

    @note
    In addition to normal logging functions behavior, the logging will not be
    done and the value of @c 0 will be returned in the case, that the tracing
    is disabled for requested trace class and priority level.
*/
MX_INLINE mx::Size mx::Log::LogTrace(
        const TraceClass iClass,
        const TraceLevel iLevel,
        const Char * sFormat, va_list pArguments) const
{
    return Log::TracingEnabled(iClass, iLevel)
           ? LogMessage(sFormat, pArguments)
           : 0;
}


/**
    Special method for logging of trace messages (string trace mask variant,
    vararg version).

    @param [in] sClass     Trace class.
    @param [in] sFormat    @c printf(3) like formatting string.
    @param [in] pArguments Argument list matching the @a sFormat string.

    @return
    See LogHandler::DoLog() for description of return values.

    @note
    In addition to normal logging functions behavior, the logging will not be
    done and the value of @c 0 will be returned in the case, that the tracing
    is disabled for requested trace class and priority level.
*/
MX_INLINE mx::Size mx::Log::LogTrace(
        const Char * const sClass,
        const Char * sFormat, va_list pArguments) const
{
    return Log::TracingEnabled(sClass, LEVEL_Normal)
           ? LogMessage(sFormat, pArguments)
           : 0;
}


/**
    Special method for logging of trace messages (string trace mask variant,
    vararg version).

    @param [in] sClass     Trace class.
    @param [in] iLevel     Trace priority level.
    @param [in] sFormat    @c printf(3) like formatting string.
    @param [in] pArguments Argument list matching the @a sFormat string.

    @return
    See LogHandler::DoLog() for description of return values.

    @note
    In addition to normal logging functions behavior, the logging will not be
    done and the value of @c 0 will be returned in the case, that the tracing
    is disabled for requested trace class and priority level.
*/
MX_INLINE mx::Size mx::Log::LogTrace(
        const Char * const sClass,
        const TraceLevel iLevel,
        const Char * sFormat, va_list pArguments) const
{
    return Log::TracingEnabled(sClass, iLevel)
           ? LogMessage(sFormat, pArguments)
           : 0;
}


/**
    Get current active log target.
*/
/* static */ MX_INLINE mx::LogHandler * mx::Log::GetActiveTarget()
{
    return sm_pTarget;
}


/**
    Set active log target.

    @param [in] pTarget The new log target.

    The @p pTarget can be @c NULL, in that case the entire logging facility will
    be disabled.

    @return
    Returns previous log target.
*/
/* static */ MX_INLINE mx::LogHandler * mx::Log::SetActiveTarget(
        LogHandler * const pTarget)
{
    LogHandler * const pPrevTarget = sm_pTarget;
    sm_pTarget = pTarget;
    return pPrevTarget;
}


/**
    Check if tracing level is enabled for particular trace class.

    @param [in] iClass The trace class.
    @param [in] iLevel The trace priority level.

    @return
    Returns @c true, if tracing level @p iLevel is enabled for trace class
    @p iClass, @c false otherwise.
*/
/* static */ MX_INLINE bool mx::Log::TracingEnabled(
        const TraceClass MX_UNUSED(iClass),
        const TraceLevel MX_UNUSED(iLevel))
{
    return true;
}


/**
    Check if tracing level is enabled for particular trace class (string trace
    mask variant).

    @param [in] sClass The trace class.
    @param [in] iLevel The trace priority level.

    @return
    Returns @c true, if tracing level @p iLevel is enabled for trace class
    @p iClass, @c false otherwise.
*/
/* static */ MX_INLINE bool mx::Log::TracingEnabled(
        const Char * const MX_UNUSED(sClass),
        const TraceLevel MX_UNUSED(iLevel))
{
    return true;
}


/**
    Enable file-line logging in log messages.
*/
/* static */ MX_INLINE void mx::Log::EnableFileInfo()
{
    sm_bFileInfoEnabled = true;
}


/**
    Disable file-line logging in log messages.
*/
/* static */ MX_INLINE void mx::Log::DisableFileInfo()
{
    sm_bFileInfoEnabled = false;
}


/**
    Check if file-line loggin enabled in log messages.

    @return
    Returns @c true, if file-line logging is enabled, @c false otherwise.
*/
/* static */ MX_INLINE bool mx::Log::FileInfoEnabled()
{
    return sm_bFileInfoEnabled;
}


/* EOF */
