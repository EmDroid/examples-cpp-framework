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

    Logging subsystem (interface).

    @author Emil Maskovsky
*/


#ifndef MXCPP_LOG_HPP_INCLUDE_GUARD
#define MXCPP_LOG_HPP_INCLUDE_GUARD


#include "mx/sysdefs.hpp"

#include "mx/types.hpp"


#define LogWarning \
    Log::Starter(Log::Warning, __FILE__, __LINE__).LogMessage

#define LogError \
    Log::Starter(Log::Error, __FILE__, __LINE__).LogMessage

#define LogFatalError \
    Log::Starter(Log::FatalError, __FILE__, __LINE__).LogMessage


namespace mx
{


class MXCPP_DLL_EXPORT Log
{

    MX_CLASS_NO_COPY(Log);
    MX_CLASS_NO_ASSIGNMENT(Log);

// Types, constants etc.

public:

    typedef enum
    {
        InvalidType = 0,
        Inform,
        Notify,
        Warning,
        Check,
        // Next log types cannot be disabled.
        Assert,
        Error,
        FatalError,
        Debug,
        Trace,
        LogType_COUNT
    } LogType;


    /**
        Log starter object.

        Used to setup and start logging event.
    */
    class MXCPP_DLL_EXPORT Starter
    {

        MX_CLASS_NO_COPY(Starter);
        MX_CLASS_NO_ASSIGNMENT(Starter);

        // Construction, destruction.

    public:

        explicit MX_INLINE Starter(
                const LogType iType,
                const char * const sFileName = NULL,
                const Size iFileLine = 0);


        // Class instance methods.

    public:

        MX_PRINTFLIKE_METHOD(1, 2) void LogMessage(
                const char * sFormat, ...);


        // Class instance attributes.

    private:

        /// The log message type.
        const LogType m_iType;

        /// The log message file name.
        const char * const m_sFileName;

        /// The log message file line.
        const Size m_iFileLine;


    }; // class Log::Starter


// Class methods (static).

public:

    static MX_INLINE Log * GetActiveTarget();

    static MX_INLINE Log * SetActiveTarget(
            Log * const pTarget);


// Class attributes (static).

private:

    static Log * sm_pTarget;


// Construction, destruction.

protected:

    Log();

    virtual ~Log();


// Class instance methods.

public:

    MX_PRINTFLIKE_METHOD(4, 5) void DoLog(
            const char * const sFileName,
            const Size iFileLine,
            const LogType iType,
            const char * sFormat, ...);

    MX_PRINTFLIKE_METHOD(2, 3) void DoLog(
            const LogType iType,
            const char * sFormat, ...);

    void DoLogV(
            const char * const sFileName,
            const Size iFileLine,
            const LogType iType,
            const char * sFormat, va_list pArgs);

    MX_INLINE void DoLogV(
            const LogType iType,
            const char * sFormat, va_list pArgs);

protected:

    virtual void OnLog(
            const char * const sFileName,
            const Size iFileLine,
            const LogType iType,
            const char * const sTypeString,
            const char * sFormat, va_list pArgs) MX_PURE;

}; // class Log


} // namespace mx


// Define inline methods here if inlining is enabled.
#ifdef MX_INLINE_ENABLED
#include "mx/Log.inl"
#endif

#endif // MXCPP_LOG_HPP_INCLUDE_GUARD

/* EOF */
