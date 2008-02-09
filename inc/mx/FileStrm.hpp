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

    File streams (interface).

    @author Emil Maskovsky
*/


#ifndef MXCPP_SYSDEFS
#include "mx/sysdefs.hpp"
#endif


#ifndef MXCPP_FILE_STREAM_HPP_INCLUDE_GUARD
#define MXCPP_FILE_STREAM_HPP_INCLUDE_GUARD


#ifndef MXCPP_TYPES
#include "mx/types.hpp"
#endif

#include "mx/Stream.hpp"


namespace mx
{


/**
    File based Stream.

    Input/Output file stream.
*/
class MXCPP_DLL_EXPORT FileStream
    : public Stream
{


// Types, constants etc.

public:

    /**
        File descriptor.

        @see #INVALID_DESCRIPTOR.
    */
    typedef FILE * FileDescriptor;

    /// Invalid file descriptor.
    static const FileDescriptor INVALID_DESCRIPTOR;


// Class methods (static).

public:

// Class attributes (static).

public:

// Construction, destruction.

public:

    explicit FileStream(
            const FileDescriptor hFileDescriptor = INVALID_DESCRIPTOR);

    virtual ~FileStream();


// Class instance methods.

public:

    MX_OVERRIDDEN bool IsOpen() const;

    MX_OVERRIDDEN void Flush();

    MX_OVERRIDDEN void Close();

    MX_OVERRIDDEN Size PrintfV(
            const Char * const sFormat, va_list pArguments);


// Class instance attributes.

protected:

    /// Stream file descriptor (descriptor of open file).
    FileDescriptor m_hFileDescriptor;


}; // class FileStream


/**
    End of file exception.

    This specific IOException indicates that end of file have been reached.

    This exception is reserved for methods which read from a file. It @b
    must @b not be thrown by methods which write data to indicate that no
    more data can be written.
*/
class MXCPP_DLL_EXPORT EndOfFile
    : public IOException
{

    MX_DECLARE_EXCEPTION_CLASS(EndOfFile, IOException);


// Construction, destruction.

public:

    MX_INLINE EndOfFile();


}; // class EndOfFile


/**
    Generic I/O exception.

    This generic IOException indicates that some I/O error occured. The
    content of @c errno is stored in this exception.
*/
class MXCPP_DLL_EXPORT GenericIOException
    : public IOException
{

    MX_DECLARE_EXCEPTION_CLASS(GenericIOException, IOException);


// Construction, destruction.

public:

    MX_INLINE GenericIOException(const int iErrno = 0);


// Class instance attributes.

private:

    const int m_iErrno;


}; // class GenericIOException


} // namespace mx


// Define inline methods here if inlining is enabled.
#ifdef MX_INLINE_ENABLED
#include "mx/FileStrm.inl"
#endif

#endif // MXCPP_FILE_STREAM_HPP_INCLUDE_GUARD

/* EOF */
