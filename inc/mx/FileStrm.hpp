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


#ifndef MXCPP_FILE_STREAM_HPP_INCLUDE_GUARD
#define MXCPP_FILE_STREAM_HPP_INCLUDE_GUARD


#include "mx/sysdefs.h"

#include "mx/types.h"

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

    MX_CLASS_NO_COPY(FileStream);
    MX_CLASS_NO_ASSIGNMENT(FileStream);


// Types, constants etc.

public:

    /**
        File descriptor.

        @see #INVALID_FILE_DESCRIPTOR.
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
            const FileDescriptor pFileDescriptor = INVALID_DESCRIPTOR);

    virtual ~FileStream();


// Class instance methods.

public:

    MX_OVERRIDDEN bool IsOpen() const;

    MX_OVERRIDDEN void Flush();

    MX_OVERRIDDEN void Close();

    MX_OVERRIDDEN Size PrintfV(
            const char * const sFormat, va_list pArguments);


// Class instance attributes.

protected:

    /// Stream file descriptor (descriptor of open file).
    FileDescriptor m_pFileDescriptor;


}; // class FileStream


} // namespace mx


// Define inline methods here if inlining is enabled.
#ifdef MX_INLINE_ENABLED
#include "mx/FileStrm.inl"
#endif

#endif // MXCPP_FILE_STREAM_HPP_INCLUDE_GUARD

/* EOF */
