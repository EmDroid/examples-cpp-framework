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

    Log message handler printing to stream (interface).

    @author Emil Maskovsky
*/


#ifndef MXCPP_SYSDEFS
#include "mx/sysdefs.hpp"
#endif


#ifndef MXCPP_LOG_STREAM_HPP_INCLUDE_GUARD
#define MXCPP_LOG_STREAM_HPP_INCLUDE_GUARD


#ifndef MXCPP_TYPES
#include "mx/types.hpp"
#endif

#include "mx/LogHndlr.hpp"


namespace mx
{


// Forward declaration.
class Stream;


/**
    Log message handler printing to stream.
*/
class MXCPP_DLL_EXPORT LogStream
    : public LogHandler
{

    MX_CLASS_NO_COPY(LogStream);
    MX_CLASS_NO_ASSIGNMENT(LogStream);


// Construction, destruction.

public:

    explicit MX_INLINE LogStream(Stream * const pStream);

    virtual MX_INLINE ~LogStream();


// Class instance methods.

protected:

    MX_OVERRIDDEN MX_INLINE Size OnLog(
            const Debug::Checkpoint & xFileInfo,
            const Log::LogType iType,
            const Char * const sTypeString,
            const Char * sFormat, va_list pArguments);

    MX_OVERRIDDEN MX_INLINE void OnFlush();

    Size OnLog(
            const Debug::Checkpoint & xFileInfo,
            Stream * const pStream,
            const Char * const sTypeString,
            const Char * sFormat, va_list pArguments);

    void OnFlush(
            Stream * const pStream);


// Class instance attributes.

private:

    /// The associated stream.
    Stream * const m_pStream;


}; // class LogStdErr


} // namespace mx


// Define inline methods here if inlining is enabled.
#ifdef MX_INLINE_ENABLED
#include "mx/LogStrm.inl"
#endif

#endif // MXCPP_LOG_STREAM_HPP_INCLUDE_GUARD

/* EOF */
