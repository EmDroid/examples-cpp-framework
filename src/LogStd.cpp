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

    Log message handler printing to standard outputs (implementation).

    @author Emil Maskovsky
*/


/* Framework libraries. */


/* Application specific. */
#include "mx/LogStd.hpp"


/**
    Get the default instance.

    Because this is the default log handler, we need some statically allocated
    instance which lasts the entire application time.

    @return
    The default instance of the LogStandard log handler.
*/
/* static */ mx::LogStandard * mx::LogStandard::Instance()
{
    static LogStandard * const sm_instance = new LogStandard();
    return sm_instance;
}


/* MX_OVERRIDDEN */ mx::Size mx::LogStandard::OnLog(
        const Debug::Checkpoint & xFileInfo,
        const Log::LogType iType,
        const Char * const sTypeString,
        const Char * sFormat, va_list pArgs)
{
    FileStream & pOutput
        = (iType >= Log::LOG_Warning) ? StandardError : StandardOutput;
    return LogStream::OnLog(xFileInfo, &pOutput, sTypeString, sFormat, pArgs);
}


/* MX_OVERRIDDEN */ void mx::LogStandard::OnFlush()
{
    LogStream::OnFlush(&StandardOutput);
    LogStream::OnFlush(&StandardError);
}


// Define inline methods here if inlining is disabled.
#ifndef MX_INLINE_ENABLED
#include "mx/LogStd.inl"
#endif

/* EOF */
