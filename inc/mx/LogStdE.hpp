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

    Log message handler printing to standard error (interface).

    @author Emil Maskovsky
*/


#ifndef MXCPP_SYSDEFS
#include "mx/sysdefs.hpp"
#endif

#ifndef MXCPP_TYPES
#include "mx/types.hpp"
#endif


#ifndef MXCPP_LOG_STANDARD_ERROR_HPP_INCLUDE_GUARD
#define MXCPP_LOG_STANDARD_ERROR_HPP_INCLUDE_GUARD


#include "mx/Log.hpp"


namespace mx
{


/**
    Log message handler printing to standard error.
*/
class MXCPP_DLL_EXPORT LogStdErr
    : public LogHandler
{

    MX_CLASS_NO_COPY(LogStdErr);
    MX_CLASS_NO_ASSIGNMENT(LogStdErr);

// Construction, destruction.

public:

    MX_INLINE LogStdErr();

    virtual MX_INLINE ~LogStdErr();


// Class instance methods.

protected:

    MX_OVERRIDDEN Size OnLog(
            const Debug::Checkpoint & xFileInfo,
            const Log::LogType iType,
            const char * const sTypeString,
            const char * sFormat, va_list pArgs);


}; // class LogStdErr


} // namespace mx


// Define inline methods here if inlining is enabled.
#ifdef MX_INLINE_ENABLED
#include "mx/LogStdE.inl"
#endif

#endif // MXCPP_LOG_STANDARD_ERROR_HPP_INCLUDE_GUARD

/* EOF */
