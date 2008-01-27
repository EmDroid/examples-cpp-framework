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

    Input/Output streams (interface).

    @author Emil Maskovsky
*/


#ifndef MXCPP_STREAM_HPP_INCLUDE_GUARD
#define MXCPP_STREAM_HPP_INCLUDE_GUARD


#ifndef __cplusplus
#error This header file requires C++ to compile!
#endif


#include "mx/sysdefs.h"

#include "mx/types.h"

#include "mx/Except.hpp"


namespace mx
{


/**
    Generic stream class.
*/
class MXCPP_DLL_EXPORT Stream
{

    MX_CLASS_NO_COPY(Stream);
    MX_CLASS_NO_ASSIGNMENT(Stream);

// Construction, destruction.

public:

    Stream();

    virtual ~Stream();


// Class instance methods.

public:

    /**
        Get the open status of the stream.

        @return
        Returns @c true if the stream is open (= ready for I/O operations),
        or @c false if the file is not open.

        @note
        This method must be overridden by derived classes.
    */
    virtual bool IsOpen() const MX_PURE;

    /**
        Flush the stream.

        Flushes any unwritten data.

        @note
        This method must be overridden by derived classes.
    */
    virtual void Flush() MX_PURE;

    /**
        Close the stream.

        @note
        This method must be overridden by derived classes.
    */
    virtual void Close() MX_PURE;

    MX_PRINTFLIKE_METHOD(1, 2) Size Printf(const char * const sFormat, ...);

    /**
        Formatted printing into the stream (vararg version).

        @param [in] sFormat    @c printf(3) like formatting string.
        @param [in] pArguments Argument list matching the @a sFormat string.

        @exception MemoryException
        Memory allocation problem occured.

        @exception IOException
        Input/Output problem occured.

        @note
        This method must be overridden by derived classes.
    */
    virtual Size PrintfV(const char * const sFormat,
            va_list pArguments) MX_PURE;


}; // class Stream


class MXCPP_DLL_EXPORT StreamException
    : public KernelException
{

    MX_DECLARE_EXCEPTION_CLASS(StreamException, KernelException);

// Construction, destruction.

protected:

    // Protected constructor to prevent direct throwing of the exception.
    MX_INLINE StreamException(const char * const sMessage = NULL);


}; // class StreamException


} // namespace mx


// Define inline methods here if inlining is enabled.
#ifdef MX_INLINE_ENABLED
#include "mx/Stream.inl"
#endif

#endif // MXCPP_STREAM_HPP_INCLUDE_GUARD

/* EOF */
