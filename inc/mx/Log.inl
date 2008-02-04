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


MX_INLINE mx::Log::Log(
        const LogType iType,
        const Debug::Checkpoint & xFileInfo)
    : m_iType(iType)
    , m_xFileInfo(xFileInfo)
{}


MX_INLINE mx::Size mx::Log::LogTraceV(
        const TraceClass iClass,
        const TraceLevel iLevel,
        const char * sFormat, va_list pArguments) const
{
    return Log::TracingEnabled(iClass, iLevel)
           ? LogMessageV(sFormat, pArguments)
           : 0;
}


MX_INLINE mx::Size mx::Log::LogTraceV(
        const char * const sClass,
        const TraceLevel iLevel,
        const char * sFormat, va_list pArguments) const
{
    return Log::TracingEnabled(sClass, iLevel)
           ? LogMessageV(sFormat, pArguments)
           : 0;
}


/* static */ MX_INLINE mx::LogHandler * mx::Log::GetActiveTarget()
{
    return sm_pTarget;
}


/* static */ MX_INLINE mx::LogHandler * mx::Log::SetActiveTarget(
        LogHandler * const pTarget)
{
    LogHandler * const pPrevTarget = sm_pTarget;
    sm_pTarget = pTarget;
    return pPrevTarget;
}


/* static */ MX_INLINE bool mx::Log::TracingEnabled(
        const TraceClass MX_UNUSED(iClass),
        const TraceLevel MX_UNUSED(iLevel))
{
    return true;
}


/* static */ MX_INLINE bool mx::Log::TracingEnabled(
        const char * const MX_UNUSED(sClass),
        const TraceLevel MX_UNUSED(iLevel))
{
    return true;
}


/* static */ MX_INLINE void mx::Log::EnableFileInfo()
{
    sm_bFileInfoEnabled = true;
}


/* static */ MX_INLINE void mx::Log::DisableFileInfo()
{
    sm_bFileInfoEnabled = false;
}


/* static */ MX_INLINE bool mx::Log::FileInfoEnabled()
{
    return sm_bFileInfoEnabled;
}


MX_INLINE mx::LogHandler::LogHandler()
{}


/* virtual */ MX_INLINE mx::LogHandler::~LogHandler()
{}


MX_INLINE mx::Size mx::LogHandler::DoLogV(
        const Log::LogType iType,
        const char * sFormat, va_list pArgs)
{
    // The file-line logging not used.
    return DoLogV(Debug::Checkpoint(), iType, sFormat, pArgs);
}


/* EOF */
