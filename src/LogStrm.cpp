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


/**
    Log the message to the stream..

    @param [in] xFileInfo   Source file location information.
    @param [in] pStream     The stream to log (normally, it would be the
                            @a m_pStream attribute, but derived implementations
                            might want to use multiple stream inplementation).
    @param [in] sTypeString The string representation of the message type.
    @param [in] sFormat     @c printf(3) like formatting string.
    @param [in] pArguments  Argument list matching the @a sFormat string.

    @exception SystemException
    System problem occured.

    @return
    See LogHandler::DoLog() for description of return values.
*/
mx::Size mx::LogStream::OnLog(
        const Debug::Checkpoint & xFileInfo,
        Stream * const pStream,
        const Char * const sTypeString,
        const Char * sFormat, va_list pArguments)
{
    mxAssert(pStream != NULL);
#ifndef MXCPP_UNICODE
    const Char * const sTypeFormat = _T("%s: ");
    const Char * const sFileFormat = _T(" [%s(%lu)]");
#else
    const Char * const sTypeFormat = _T("%ls: ");
    const Char * const sFileFormat = _T(" [%ls(%lu)]");
#endif
    Size iCharsWritten = pStream->Printf(sTypeFormat, sTypeString);
    iCharsWritten += pStream->PrintfV(sFormat, pArguments);
    if (!xFileInfo.Empty())
    {
        iCharsWritten += pStream->Printf(sFileFormat,
                xFileInfo.getFile(), xFileInfo.getLine());
    }
    iCharsWritten += pStream->Printf(_T("\n"));
    return iCharsWritten;
}


/**
    Flush the stream.

    Flushes any unwritten data to the stream.

    @param [in] pStream The stream to log (normally, it would be the @a m_pStream
                        attribute, but derived implementations might want to use
                        multiple stream inplementation).

    @exception SystemException
    System problem occured.
*/
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
