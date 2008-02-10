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

    Log message handler printing to stream (implementation).

    @author Emil Maskovsky
*/


/* Framework libraries. */
#include "mx/Stream.hpp"


/* Application specific. */
#include "mx/LogStrm.hpp"


mx::Size mx::LogStream::OnLog(
        const Debug::Checkpoint & xFileInfo,
        Stream * const pStream,
        const Char * const sTypeString,
        const Char * sFormat, va_list pArgs)
{
    mxAssert(pStream != NULL);
    Size iCharsWritten = pStream->Printf(_T("%s: "), sTypeString);
    iCharsWritten += pStream->PrintfV(sFormat, pArgs);
    if (!xFileInfo.Empty())
    {
        iCharsWritten += pStream->Printf(_T(" [%s(%lu)]"),
                xFileInfo.getFile(), xFileInfo.getLine());
    }
    iCharsWritten += pStream->Printf(_T("\n"));
    return iCharsWritten;
}


void mx::LogStream::OnFlush(Stream * const pStream)
{
    mxAssert(pStream != NULL);
    pStream->Flush();
}


// Define inline methods here if inlining is disabled.
#ifndef MX_INLINE_ENABLED
#include "mx/LogStrm.inl"
#endif

/* EOF */
