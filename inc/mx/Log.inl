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


/* explicit */ MX_INLINE mx::Log::Starter::Starter(
        const LogType iType,
        const char * const sFileName,
        const Size iFileLine)
    : m_iType(iType)
    , m_sFileName(sFileName)
    , m_iFileLine(iFileLine)
{}


/* static */ MX_INLINE mx::Log * mx::Log::GetActiveTarget()
{
    return sm_pTarget;
}


/* static */ MX_INLINE mx::Log * mx::Log::SetActiveTarget(
        Log * const pTarget)
{
    Log * const pPrevTarget = sm_pTarget;
    sm_pTarget = pTarget;
    return pPrevTarget;
}


MX_INLINE void mx::Log::DoLogV(
        const LogType iType,
        const char * sFormat, va_list pArgs)
{
    // The file-line logging not used.
    DoLogV(static_cast< const char * >(NULL), 0, iType, sFormat, pArgs);
}


/* EOF */
