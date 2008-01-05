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


#include "mx/sysdefs.h"

#include "mx/types.h"

#include "mx/Except.hpp"


namespace mx
{


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

    virtual bool IsOpen() const MX_PURE;

    virtual void Flush() MX_PURE;

    virtual void Close() MX_PURE;

    MX_PRINTFLIKE_METHOD(1, 2) Size Printf(const char * const sFormat, ...);

    virtual Size PrintfV(const char * const sFormat, va_list pArgs) MX_PURE;


}; // class Stream


class MXCPP_DLL_EXPORT StreamException
    : public KernelException
{

    MX_DECLARE_EXCEPTION_CLASS(StreamException, KernelException);

// Construction, destruction.

protected:

    // Protected constructor to prevent direct throwing of the exception.
    MX_INLINE StreamException(const char * sMessage = NULL);


}; // class StreamException


class MXCPP_DLL_EXPORT EndOfFile
    : public StreamException
{

    MX_DECLARE_EXCEPTION_CLASS(EndOfFile, StreamException);

}; // class EndOfFile


class MXCPP_DLL_EXPORT GenericIOException
    : public StreamException
{

    MX_DECLARE_EXCEPTION_CLASS(GenericIOException, StreamException);


// Construction, destruction.

public:

    // Protected constructor to prevent direct throwing of the exception.
    MX_INLINE GenericIOException(const int iErrno = 0);


// Class instance attributes.

private:

    const int m_iErrno;


}; // class GenericIOException


} // namespace mx


// Define inline methods here if inlining is enabled.
#ifdef MX_INLINE_ENABLED
#include "mx/Stream.inl"
#endif

#endif // MXCPP_STREAM_HPP_INCLUDE_GUARD

/* EOF */
