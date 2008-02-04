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

    Log message handler printing to standard error (implementation).

    @author Emil Maskovsky
*/


/* Framework libraries. */
#include "mx/StdStrm.hpp"


/* Application specific. */
#include "mx/LogStdE.hpp"


/* MX_OVERRIDDEN */ mx::Size mx::LogStdErr::OnLog(
        const Debug::Checkpoint & xFileInfo,
        const Log::LogType iType,
        const char * const sTypeString,
        const char * sFormat, va_list pArgs)
{
    Size iCharsWritten = StandardError.Printf("%s: ", sTypeString)
                         + StandardError.PrintfV(sFormat, pArgs);
    if (!xFileInfo.Empty())
    {
        iCharsWritten += StandardError.Printf(" [%s(%u)])",
                xFileInfo.getFile(), xFileInfo.getLine());
    }
    return iCharsWritten;
}


// Define inline methods here if inlining is disabled.
#ifndef MX_INLINE_ENABLED
#include "mx/LogStdE.inl"
#endif

/* EOF */
