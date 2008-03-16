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


MX_PRINTFLIKE_METHOD(1, 2) mx::Size mx::Log::LogMessage(
        const Char * sFormat, ...) const
{
    va_list pArgs;
    va_start(pArgs, sFormat);
    const Size iResult = LogMessageV(sFormat, pArgs);
    va_end(pArgs);
    return iResult;
}


MX_PRINTFLIKE_METHOD(1, 2) MX_NORETURN_TYPE(mx::Size) mx::Log::LogFatal(
        const Char * sFormat, ...) const
{
    va_list pArgs;
    va_start(pArgs, sFormat);
    const Size iResult = LogMessageV(sFormat, pArgs);
    va_end(pArgs);
    abort();
    return iResult;
}


MX_PRINTFLIKE_METHOD(1, 2) MX_NORETURN_TYPE(mx::Size) mx::Log::LogAssert(
        const Char * sFormat, ...) const
{
    va_list pArgs;
    va_start(pArgs, sFormat);
    const Size iResult = LogMessageV(sFormat, pArgs);
    va_end(pArgs);
    abort();
    return iResult;
}


mx::Size mx::Log::LogMessageV(
        const Char * sFormat, va_list pArguments) const
{
    LogHandler * const pTarget = Log::GetActiveTarget();
    if (!pTarget)
    {
        // None active target selected - logging entirely disabled.
        return 0;
    }
    // Log the message to the log target.
    return pTarget->DoLogV(m_xFileInfo, m_iType, sFormat, pArguments);
}


MX_PRINTFLIKE_METHOD(1, 2) mx::Size mx::Log::LogTrace(
        const Char * sFormat, ...) const
{
    if (!Log::TracingEnabled())
    {
        return 0;
    }
    va_list pArgs;
    va_start(pArgs, sFormat);
    const Size iResult = LogTraceV(TRACE_User, LEVEL_Normal, sFormat, pArgs);
    va_end(pArgs);
    return iResult;
}


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
    const Size iResult = LogTraceV(iClass, LEVEL_Normal, sFormat, pArgs);
    va_end(pArgs);
    return iResult;
}


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
    const Size iResult = LogTraceV(iClass, iLevel, sFormat, pArgs);
    va_end(pArgs);
    return iResult;
}


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
    const Size iResult = LogTraceV(sClass, LEVEL_Normal, sFormat, pArgs);
    va_end(pArgs);
    return iResult;
}


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
    const Size iResult = LogTraceV(sClass, iLevel, sFormat, pArgs);
    va_end(pArgs);
    return iResult;
}


// Define inline methods here if inlining is disabled.
#ifndef MX_INLINE_ENABLED
#include "mx/Log.inl"
#endif

/* EOF */
