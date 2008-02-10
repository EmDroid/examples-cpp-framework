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

    Log message handler printing to stream (inline methods).

    @author Emil Maskovsky
*/


MX_INLINE mx::LogStream::LogStream(Stream * const pStream)
    : m_pStream(pStream)
{}


/* virtual */ MX_INLINE mx::LogStream::~LogStream()
{}


/* MX_OVERRIDDEN */ MX_INLINE mx::Size mx::LogStream::OnLog(
        const Debug::Checkpoint & xFileInfo,
        const Log::LogType MX_UNUSED(iType),
        const Char * const sTypeString,
        const Char * sFormat, va_list pArgs)
{
    return OnLog(xFileInfo, m_pStream, sTypeString, sFormat, pArgs);
}


/* MX_OVERRIDDEN */ MX_INLINE void mx::LogStream::OnFlush()
{
    OnFlush(m_pStream);
}


/* EOF */
