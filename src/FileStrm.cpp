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

    File streams (implementation).

    @author Emil Maskovsky
*/


/* Framework libraries. */
#include "mx/Debug.hpp"


/* Application specific. */
#include "mx/FileStrm.hpp"

// #include <errno.h>  // errno variable


// Start the exception implementation.
MX_IMPLEMENT_EXCEPTION_CLASS(mx::EndOfFile);


// Start the exception implementation.
MX_IMPLEMENT_EXCEPTION_CLASS(mx::GenericIOException);


/* static */ const mx::FileStream::FileDescriptor
mx::FileStream::INVALID_DESCRIPTOR = NULL;


/**
    Constructor taking file descriptor.

    @param [in] hFileDescriptor @copydoc m_hFileDescriptor.
*/
mx::FileStream::FileStream(
        const FileDescriptor hFileDescriptor)
    : m_hFileDescriptor(hFileDescriptor)
{}


/**
    Destructor.
*/
mx::FileStream::~FileStream()
{
    if (IsOpen())
    {
        Close();
    }
}


/* MX_OVERRIDDEN */ bool mx::FileStream::IsOpen(void) const
{
    return m_hFileDescriptor != INVALID_DESCRIPTOR;
}


/**
    Flush the file stream.
*/
/* MX_OVERRIDDEN */ void mx::FileStream::Flush(void)
{
    mxAssert(IsOpen());

    if (EOF == fflush(m_hFileDescriptor))
    {
        // We cannot reach eof during write (check it).
        mxAssert(!feof(m_hFileDescriptor));
        // File I/O error other than EOF.
        Throw(GenericIOException(ferror(m_hFileDescriptor)));
    }
}


/**
    Close the file stream.
*/
/* MX_OVERRIDDEN */ void mx::FileStream::Close(void)
{
    mxAssert(IsOpen());

    if (EOF == fclose(m_hFileDescriptor))
    {
        // We cannot reach eof during write (check it).
        mxAssert(!feof(m_hFileDescriptor));
        // File I/O error other than EOF.
        Throw(GenericIOException(ferror(m_hFileDescriptor)));
    }
    m_hFileDescriptor = INVALID_DESCRIPTOR;
}


/**
    Formatted printing into the file stream (vararg version).

    @param [in] sFormat    @c printf(3) like formatting string.
    @param [in] pArguments Argument list matching the @p sFormat string.
*/
/* MX_OVERRIDDEN */ mx::Size mx::FileStream::PrintfV(
        const char * const sFormat, va_list pArguments)
{
//    mxAssert(IsOpen());
    mxAssert(sFormat != NULL);

    int iCharsWritten;
    if ((iCharsWritten = vfprintf(m_hFileDescriptor, sFormat, pArguments))
        < 0)
    {
        // We cannot reach eof during write (check it).
        mxAssert(!feof(m_pFileDescriptor));
        // File I/O error other than EOF.
        Throw(GenericIOException(ferror(m_hFileDescriptor)));
    }

    return iCharsWritten;
}


// Define inline methods here if inlining is disabled.
#ifndef MX_INLINE_ENABLED
#include "mx/FileStrm.inl"
#endif

/* EOF */
