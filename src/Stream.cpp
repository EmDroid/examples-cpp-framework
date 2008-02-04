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


/* Application specific. */
#include "mx/Stream.hpp"


/**
    Constructor.
*/
mx::Stream::Stream()
{}


/**
    Destructor.
*/
/* virtual */ mx::Stream::~Stream()
{}


/**
    Formatted printing into the stream.

    @param [in] sFormat @c printf(3) like formatting string.
    @param [in] ...     Argument list matching the @p sFormat string.

    @exception MemoryException
    Memory allocation problem occured.

    @exception IOException
    Input/Output problem occured.

    This function is just simple wrapper around Stream::PrintfV().
    See there for more documentation.

    @see PrintfV().
*/
MX_PRINTFLIKE_METHOD(1, 2) mx::Size mx::Stream::Printf(
        const char * const sFormat, ...)
{
    mxAssert(sFormat != NULL);

    va_list pArguments;
    va_start(pArguments, sFormat);
    const Size iCharsWritten = PrintfV(sFormat, pArguments);
    va_end(pArguments);

    return iCharsWritten;
}


// Define inline methods here if inlining is disabled.
#ifndef MX_INLINE_ENABLED
#include "mx/Stream.inl"
#endif

/* EOF */
