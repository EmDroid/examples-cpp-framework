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


#ifndef MXCPP_SYSDEFS
#include "mx/sysdefs.hpp"
#endif

#ifndef MXCPP_TYPES
#include "mx/types.hpp"
#endif


#ifndef MXCPP_LOG_HPP_INCLUDE_GUARD
#define MXCPP_LOG_HPP_INCLUDE_GUARD


#include "mx/Debug.hpp"


#define mxLogCheckpoint()       \
    (mx::Log::FileInfoEnabled() \
     ? mxDebugCheckpoint()      \
     : mx::Debug::Checkpoint())

#define mxLogWarning \
    mx::Log(mx::Log::LOG_Warning, mxLogCheckpoint()).LogMessage

#define mxLogError \
    mx::Log(mx::Log::LOG_Error, mxLogCheckpoint()).LogMessage

#define mxLogFatalError \
    mx::Log(mx::Log::LOG_FatalError, mxLogCheckpoint()).LogFatal

#define mxLogTrace \
    mx::Log(mx::Log::LOG_Trace, mxLogCheckpoint()).LogTrace


namespace mx
{


// Forward declaration.
class MXCPP_DLL_EXPORT LogHandler;


class MXCPP_DLL_EXPORT Log
{

    MX_CLASS_NO_COPY(Log);
    MX_CLASS_NO_ASSIGNMENT(Log);

// Types, constants etc.

public:

    typedef enum
    {
        LOG_Inform,
        LOG_Notify,
        LOG_Warning,
        LOG_Check,
        // Next log types cannot be disabled.
        LOG_Assert,
        LOG_Error,
        LOG_FatalError,
        LOG_Debug,
        LOG_Trace,
        LOG_COUNT
    } LogType;

    typedef enum
    {
        TRACE_User = 0,     ///< User tracing.
        TRACE_Debug,        ///< Debugging subsystem itself.
        TRACE_Memory,       ///< Memory management.
        TRACE_Exception,    ///< Exception handling subsystem.
        TRACE_GUI,          ///< Graphical User Interface.
        TRACE_COUNT
    } TraceClass;

    typedef enum
    {
        LEVEL_Normal,       ///< Normal trace level.
        LEVEL_COUNT
    } TraceLevel;


// Class methods (static).

public:

    static MX_INLINE LogHandler * GetActiveTarget();

    static MX_INLINE LogHandler * SetActiveTarget(
            LogHandler * const pTarget);


    // Predefined constant class tracing.

    static MX_INLINE bool TracingEnabled(
            const TraceClass iClass = TRACE_User,
            const TraceLevel = LEVEL_Normal);


    // User-based class tracing.

    static MX_INLINE bool TracingEnabled(
            const char * const sClass,
            const TraceLevel = LEVEL_Normal);


    // File information engine.

    static MX_INLINE void EnableFileInfo();
    static MX_INLINE void DisableFileInfo();

    static MX_INLINE bool FileInfoEnabled();


// Class attributes (static).

private:

    static LogHandler * sm_pTarget;

    static bool sm_bFileInfoEnabled;


// Construction, destruction.

public:

    MX_INLINE Log(
            const LogType iType,
            const Debug::Checkpoint & xFileInfo);


// Class instance methods.

public:

    MX_PRINTFLIKE_METHOD(1, 2) Size LogMessage(
            const char * sFormat, ...) const;

    MX_PRINTFLIKE_METHOD(1, 2) MX_NORETURN LogFatal(
            const char * sFormat, ...) const;

    MX_PRINTFLIKE_METHOD(1, 2) Size LogAssert(
            const char * sFormat, ...) const;

    Size LogMessageV(
            const char * sFormat, va_list pArguments) const;

    MX_PRINTFLIKE_METHOD(1, 2) Size LogTrace(
            const char * sFormat, ...) const;

    MX_PRINTFLIKE_METHOD(2, 3) Size LogTrace(
            const TraceClass iClass,
            const char * sFormat, ...) const;

    MX_PRINTFLIKE_METHOD(3, 4) Size LogTrace(
            const TraceClass iClass,
            const TraceLevel iLevel,
            const char * sFormat, ...) const;

    MX_PRINTFLIKE_METHOD(2, 3) Size LogTrace(
            const char * const sClass,
            const char * sFormat, ...) const;

    MX_PRINTFLIKE_METHOD(3, 4) Size LogTrace(
            const char * const sClass,
            const TraceLevel iLevel,
            const char * sFormat, ...) const;

    MX_INLINE Size LogTraceV(
            const TraceClass iClass,
            const TraceLevel iLevel,
            const char * sFormat, va_list pArguments) const;

    MX_INLINE Size LogTraceV(
            const char * const sClass,
            const TraceLevel iLevel,
            const char * sFormat, va_list pArguments) const;


// Class instance attributes.

private:

    /// The log message type.
    const LogType m_iType;

    /// The log file information.
    const Debug::Checkpoint m_xFileInfo;


}; // class Log


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

    MX_PRINTFLIKE_METHOD(3, 4) Size DoLog(
            const Debug::Checkpoint & xFileInfo,
            const Log::LogType iType,
            const char * sFormat, ...);

    MX_PRINTFLIKE_METHOD(2, 3) Size DoLog(
            const Log::LogType iType,
            const char * sFormat, ...);

    Size DoLogV(
            const Debug::Checkpoint & xFileInfo,
            const Log::LogType iType,
            const char * sFormat, va_list pArgs);

    MX_INLINE Size DoLogV(
            const Log::LogType iType,
            const char * sFormat, va_list pArgs);

protected:

    virtual Size OnLog(
            const Debug::Checkpoint & xFileInfo,
            const Log::LogType iType,
            const char * const sTypeString,
            const char * sFormat, va_list pArgs) MX_PURE;

}; // class LogHandler


} // namespace mx


// Define inline methods here if inlining is enabled.
#ifdef MX_INLINE_ENABLED
#include "mx/Log.inl"
#endif

#endif // MXCPP_LOG_HPP_INCLUDE_GUARD

/* EOF */
