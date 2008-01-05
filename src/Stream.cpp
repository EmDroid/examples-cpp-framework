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

    Input/Output streams generic base (implementation).

    @author Emil Maskovsky
*/


/* Framework libraries. */
#include "mx/debug.h"


/* Application specific. */
#include "mx/Stream.hpp"


mx::Stream::Stream()
{}


/* virtual */ mx::Stream::~Stream()
{}


MX_PRINTFLIKE_METHOD(1, 2) mx::Size mx::Stream::Printf(
        const char * const sFormat,
        ...)
{
    mxAssert(sFormat);

    va_list pArguments;
    va_start(pArguments, sFormat);
    const Size iCharsWritten = PrintfV(sFormat, pArguments);
    va_end(pArguments);

    return iCharsWritten;
}


// Start the exception implementation.
MX_IMPLEMENT_EXCEPTION_CLASS(mx::StreamException);


// Start the exception implementation.
MX_IMPLEMENT_EXCEPTION_CLASS(mx::EndOfFile);

void EndOfFileImp()
{
    mxThrow(mx::EndOfFile());
}


// Start the exception implementation.
MX_IMPLEMENT_EXCEPTION_CLASS(mx::GenericIOException);

void GenericIOExceptionImp()
{
    mxThrow(mx::GenericIOException());
}


// Define inline methods here if inlining is disabled.
#ifndef MX_INLINE_ENABLED
#include "mx/Stream.inl"
#endif

/* EOF */
