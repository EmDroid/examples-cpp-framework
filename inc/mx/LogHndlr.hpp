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

    Log handler base (interface).

    @author Emil Maskovsky
*/


#ifndef MXCPP_SYSDEFS
#include "mx/sysdefs.hpp"
#endif


#ifndef MXCPP_LOG_HANDLER_HPP_INCLUDE_GUARD
#define MXCPP_LOG_HANDLER_HPP_INCLUDE_GUARD


#ifndef MXCPP_TYPES
#include "mx/types.hpp"
#endif


namespace mx
{


/**
    The log handler base.
*/
class MXCPP_DLL_EXPORT LogHandler
{

    MX_CLASS_NO_COPY(LogHandler);
    MX_CLASS_NO_ASSIGNMENT(LogHandler);

// Construction, destruction.

protected:

    MX_INLINE LogHandler();

    virtual MX_INLINE ~LogHandler();


// Class instance methods.

public:

    void Flush();

    MX_PRINTFLIKE_METHOD(3, 4) Size DoLog(
            const Debug::Checkpoint & xFileInfo,
            const Log::LogType iType,
            const Char * sFormat, ...);

    MX_PRINTFLIKE_METHOD(2, 3) Size DoLog(
            const Log::LogType iType,
            const Char * sFormat, ...);

    Size DoLog(
            const Debug::Checkpoint & xFileInfo,
            const Log::LogType iType,
            const Char * sFormat, va_list pArgs);

    MX_INLINE Size DoLog(
            const Log::LogType iType,
            const Char * sFormat, va_list pArgs);

protected:

    /**
        Log the message event handler.

        @param [in] xFileInfo   Source file location information.
        @param [in] iType       Type of log message.
        @param [in] sTypeString The string representation of the message type.
        @param [in] sFormat     @c printf(3) like formatting string.
        @param [in] pArguments  Argument list matching the @a sFormat string.

        @exception SystemException
        System problem occured.

        @return
    */
    // This method has to be overridden by derived classes.
    virtual Size OnLog(
            const Debug::Checkpoint & xFileInfo,
            const Log::LogType iType,
            const Char * const sTypeString,
            const Char * sFormat, va_list pArguments) MX_PURE;

    /**
        Flush the log handler.

        Flushes any unwritten data.

        @exception SystemException
        System problem occured.
    */
    // This method has to be overridden by derived classes.
    virtual void OnFlush() MX_PURE;


}; // class LogHandler


} // namespace mx


// Define inline methods here if inlining is enabled.
#ifdef MX_INLINE_ENABLED
#include "mx/LogHndlr.inl"
#endif

#endif // MXCPP_LOG_HANDLER_HPP_INCLUDE_GUARD

/* EOF */
