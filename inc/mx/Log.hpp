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


#ifndef MXCPP_LOG_HPP_INCLUDE_GUARD
#define MXCPP_LOG_HPP_INCLUDE_GUARD


#ifndef MXCPP_TYPES
#include "mx/types.hpp"
#endif

#include "mx/Debug.hpp"


/**
    @internal

    Log checkpoint initializer.

    Initializes the log message with current source file name and line number
    as provided by the preprocessors macros @c __FILE__ and @c __LINE__, if the
    file-line logging is enabled by the logging facility.

    @note
    This macro is designed to be used by loggig macros defined in Log.hpp.
    Except very special cases it should not be used directly.
*/
#define __mxLogCheckpoint__()   \
    (mx::Log::FileInfoEnabled() \
     ? __mxDebugCheckpoint__()  \
     : mx::Debug::Checkpoint())


/**
    @addtogroup logging_macros Logging macros and functions

    These functions provide a variety of logging functions.
*/
///@{

/**
    Log informational message.

    Logs message of type Log::LOG_Message.

    Has the same syntax as the @c printf() or @c vprintf(), i.e. takes the format
    string as the first argument and respectively a variable number of arguments
    or a variable argument list pointer.

    @return
*/
#define mxLogMessage \
    mx::Log(mx::Log::LOG_Message, __mxLogCheckpoint__()).LogMessage

/**
    Log warning message.

    Logs message of type Log::LOG_Warning.

    Has the same syntax as the @c printf() or @c vprintf(), i.e. takes the format
    string as the first argument and respectively a variable number of arguments
    or a variable argument list pointer.

    @return
*/
#define mxLogWarning \
    mx::Log(mx::Log::LOG_Warning, __mxLogCheckpoint__()).LogMessage

/**
    Log error message.

    Logs message of type Log::LOG_Error.

    Has the same syntax as the @c printf() or @c vprintf(), i.e. takes the format
    string as the first argument and respectively a variable number of arguments
    or a variable argument list pointer.

    @return
*/
#define mxLogError \
    mx::Log(mx::Log::LOG_Error, __mxLogCheckpoint__()).LogMessage

/**
    Log fatal message and abort the application execution.

    Logs message of type Log::LOG_FatalError and terminates the application using
    the standard function @c abort().

    Has the same syntax as the @c printf() or @c vprintf(), i.e. takes the format
    string as the first argument and respectively a variable number of arguments
    or a variable argument list pointer.

    @return
    This function does not return.
*/
#define mxLogFatalError \
    mx::Log(mx::Log::LOG_FatalError, __mxLogCheckpoint__()).LogFatal


/**
    Log debugging message.

    Logs message of type Log::LOG_Debug.

    This is the right function for debug output. It only does anything at all in
    the debug mode (when the preprocessor symbol MXCPP_DEBUG_ENABLED is
    defined) and expands to nothing in release mode (otherwise).

    Has the same syntax as the @c printf() or @c vprintf(), i.e. takes the format
    string as the first argument and respectively a variable number of arguments
    or a variable argument list pointer.

    @return
*/
#ifndef MXCPP_DEBUG_ENABLED

#define mxLogDebug \
    mx::Log::LogDebug
// The checkpoint is not initialized.

#else // MXCPP_DEBUG_ENABLED

#define mxLogDebug \
    mx::Log(mx::Log::LOG_Debug, __mxLogCheckpoint__()).LogDebug

#endif // MXCPP_DEBUG_ENABLED

/**
    Log tracing message.

    Logs message of type Log::LOG_Trace.

    Has the same syntax as the @c printf() or @c vprintf(), i.e. takes the format
    string as the first argument and respectively a variable number of arguments
    or a variable argument list pointer.

    @warning
    The penalty for tracing flexibility is, that it can lead to function
    signature confusion in some cases - if the fuction is called with first
    formatting parameter "%s" and the second string parameter, the parameters
    will be confused with the function which takes the first string mask and
    second formatting parameter instead. In that case, the string parameter
    should be used directly instead of formatting.

    @return
*/
#define mxLogTrace \
    mx::Log(mx::Log::LOG_Trace, __mxLogCheckpoint__()).LogTrace

///@}


namespace mx
{


// Forward declarations.
class LogHandler;


class MXCPP_DLL_EXPORT Log
{

    MX_CLASS_NO_COPY(Log);
    MX_CLASS_NO_ASSIGNMENT(Log);

// Types, constants etc.

public:

    /// Log message type.
    typedef enum
    {
        LOG_Message,    ///< Informational message.
        LOG_Warning,    ///< Warning message.
        LOG_Check,      ///< Check failure message.
        // Next log types cannot be disabled.
        LOG_Assert,     ///< Assertion failure message.
        LOG_Error,      ///< Error message.
        LOG_FatalError, ///< Fatal error message.
        LOG_Debug,      ///< Debug message.
        LOG_Trace,      ///< Trace message.
        LOG_COUNT
    } LogType;

    /// Trace class.
    typedef enum
    {
        TRACE_User = 0,     ///< User tracing.
        TRACE_Debug,        ///< Debugging subsystem itself.
        TRACE_Memory,       ///< Memory management.
        TRACE_Exception,    ///< Exception handling subsystem.
        TRACE_GUI,          ///< Graphical User Interface.
        TRACE_COUNT
    } TraceClass;

    /// Trace priority level.
    typedef enum
    {

        // Internal (library) trace levels:
        LEVEL_InternalLowest,   ///< Lowest internal trace priority.
        LEVEL_InternalLow,      ///< Low internal trace priority.
        LEVEL_InternalLower,    ///< Lower internal trace priority.
        LEVEL_Internal,         ///< Normal internal trace priority.
        LEVEL_InternalHigher,   ///< Higher internal trace priority.
        LEVEL_InternalHigh,     ///< High internal trace priority.
        LEVEL_InternalHighest,  ///< Highest internal trace priority.

        // User trace levels:
        LEVEL_Lowest,   ///< Lowest trace priority.
        LEVEL_Low,      ///< Low trace priority.
        LEVEL_Lower,    ///< Lower trace priority.
        LEVEL_Normal,   ///< Normal trace priority.
        LEVEL_Higher,   ///< Higher trace priority.
        LEVEL_High,     ///< High trace priority.
        LEVEL_Highest,  ///< Highest trace priority.

        LEVEL_COUNT
    } TraceLevel;


// Class methods (static).

public:

    static MX_INLINE LogHandler * GetActiveTarget();

    static MX_INLINE LogHandler * SetActiveTarget(
            LogHandler * const pTarget);

    static bool UnregisterTarget(const LogHandler * const pTarget);

    static void Flush();


    // Predefined constant class tracing.

    static MX_INLINE bool TracingEnabled(
            const TraceClass iClass = TRACE_User,
            const TraceLevel = LEVEL_Normal);


    // User-based class tracing.

    static MX_INLINE bool TracingEnabled(
            const Char * const sClass,
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
            const Char * sFormat, ...) const;

    Size LogMessage(
            const Char * sFormat, va_list pArguments) const;

    MX_PRINTFLIKE_METHOD(1, 2) MX_NORETURN_TYPE(Size) LogFatal(
            const Char * sFormat, ...) const;

    MX_INLINE MX_NORETURN_TYPE(Size) LogFatal(
            const Char * sFormat, va_list pArguments) const;

    MX_PRINTFLIKE_METHOD(1, 2) MX_NORETURN_TYPE(Size) LogAssert(
            const Char * sFormat, ...) const;

    MX_INLINE MX_NORETURN_TYPE(Size) LogAssert(
            const Char * sFormat, va_list pArguments) const;

#ifndef MXCPP_DEBUG_ENABLED
    static inline MX_PRINTFLIKE(1, 2)
#else
    MX_PRINTFLIKE_METHOD(1, 2)
#endif
    Size LogDebug(
            const Char * sFormat, ...)
#ifdef MXCPP_DEBUG_ENABLED
    const
#endif
    ;

#ifndef MXCPP_DEBUG_ENABLED
    static inline
#else
    MX_INLINE
#endif
    Size LogDebug(
            const Char * sFormat, va_list pArguments)
#ifdef MXCPP_DEBUG_ENABLED
    const
#endif
    ;

    MX_PRINTFLIKE_METHOD(1, 2) Size LogTrace(
            const Char * sFormat, ...) const;

    MX_INLINE Size LogTrace(
            const Char * sFormat, va_list pArguments) const;

    MX_PRINTFLIKE_METHOD(2, 3) Size LogTrace(
            const TraceClass iClass,
            const Char * sFormat, ...) const;

    MX_INLINE Size LogTrace(
            const TraceClass iClass,
            const Char * sFormat, va_list pArguments) const;

    MX_PRINTFLIKE_METHOD(3, 4) Size LogTrace(
            const TraceClass iClass,
            const TraceLevel iLevel,
            const Char * sFormat, ...) const;

    MX_INLINE Size LogTrace(
            const TraceClass iClass,
            const TraceLevel iLevel,
            const Char * sFormat, va_list pArguments) const;

    MX_PRINTFLIKE_METHOD(2, 3) Size LogTrace(
            const Char * const sClass,
            const Char * sFormat, ...) const;

    MX_INLINE Size LogTrace(
            const Char * const sClass,
            const Char * sFormat, va_list pArguments) const;

    MX_PRINTFLIKE_METHOD(3, 4) Size LogTrace(
            const Char * const sClass,
            const TraceLevel iLevel,
            const Char * sFormat, ...) const;

    MX_INLINE Size LogTrace(
            const Char * const sClass,
            const TraceLevel iLevel,
            const Char * sFormat, va_list pArguments) const;


// Class instance attributes.

private:

    /// The log message type.
    const LogType m_iType;

    /// The log file information.
    const Debug::Checkpoint m_xFileInfo;


}; // class Log


} // namespace mx


#ifndef MXCPP_DEBUG_ENABLED

// Debug logging functions do nothing in release mode.
// They are inlined to avoid the extra function calling overhead

/* static */ inline mx::Size mx::Log::LogDebug(
        const Char *, ...)
{
    return 0;
}


/* static */ inline mx::Size mx::Log::LogDebug(
        const Char *, va_list)
{
    return 0;
}


#endif // MXCPP_DEBUG_ENABLED


// Define inline methods here if inlining is enabled.
#ifdef MX_INLINE_ENABLED
#include "mx/Log.inl"
#endif

#endif // MXCPP_LOG_HPP_INCLUDE_GUARD

/* EOF */
