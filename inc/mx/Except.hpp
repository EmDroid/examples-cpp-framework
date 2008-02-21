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

    Exception support (interface).

    @author Emil Maskovsky
*/


#ifndef MXCPP_SYSDEFS
#include "mx/sysdefs.hpp"
#endif


#ifndef MXCPP_EXCEPTION_HPP_INCLUDE_GUARD
#define MXCPP_EXCEPTION_HPP_INCLUDE_GUARD


#ifndef MXCPP_TYPES
#include "mx/types.hpp"
#endif

#include "mx/Debug.hpp"

#include "mx/Class.hpp"

#include "mx/Log.hpp"


namespace mx
{


/**
    @name Exception system constructs.
*/
///@{

/**
    Exception throwing @ref exceptions_throwing "construct".

    @param [in] exception The exception to be thrown.

    This construct is to be used to throw exceptions derived from the
    mx::Exception class.
    For example, to throw and catch mx::EndOfFile exception, use:
    @code
    try {
        mxThrow(mx::EndOfFile() );
    } catch (mx::EndOfFile & e) {
        // Process the exception.
        ...
        throw;  // Possibly re-throw the exception.
    }
    @endcode

    You can, however, throw any mx::Exception using standard @c throw statement,
    as follows:
    @include ExceptionPointerOrReference.cpp

    But using of mxThrow(exception) is the framework recommended way of
    throwing exceptions based on mx::Exception, and only then you can gain from
    framework @ref exceptions_handling "extended exception processing".
*/
#define mxThrow(exception) \
    mx::ThrowException(exception, __mxDebugCheckpoint__())

///@}


/**
    Exception class declaration.

    Used inside an exception declaration to declare extensions used in exceptions
    derived from Exception.

    @param [in] name Name of the exception class.
    @param [in] base Name of the parent exception class.

    Example:
    @code
    class MyDerivedException: public mx::ApplicationException {

        MX_DECLARE_EXCEPTION_CLASS(MyDerivedException,
            mx::ApplicationException);

    public:
        ...
    };
    @endcode

    @note
    The exception class must be "implemented" in the exception class
    implementation file using MX_IMPLEMENT_EXCEPTION_CLASS().

    @see MX_IMPLEMENT_EXCEPTION_CLASS()
    @see Exception
*/
#define MX_DECLARE_EXCEPTION_CLASS(name, base) \
    MX_CLASS_NO_ASSIGNMENT(name);              \
private:                                       \
    typedef class base Super


/**
    Exception class implementation.

    Used in a C++ implementation file to complete the declaration of extensions
    used in exceptions derived from Exception.

    @param [in] name Name of the exception class.

    Example:
    @code
    class MyDerivedException: public mx::ApplicationException {

        MX_DECLARE_EXCEPTION_CLASS(MyDerivedException,
            mx::ApplicationException);

    public:
        ...
    };

    MX_IMPLEMENT_EXCEPTION_CLASS(MyDerivedException);
    @endcode

    @note
    The exception class must be "declared" inside the exception class
    declaration using MX_DECLARE_EXCEPTION_CLASS().

    @see MX_DECLARE_EXCEPTION_CLASS()
    @see Exception
*/
#define MX_IMPLEMENT_EXCEPTION_CLASS(name)


// Core of the exception system.

/**
    Base class for all our exception.

    This class serves as a base class for any exceptions the framework and its
    based application ever throw.

    @warning
    Exception of this type itself should never be thrown. Always throw
    one of the derived types.

    @note
    Application should use @ref exceptions_throwing
    "framework exception constructs" to throw and catch mx::Exception based
    exceptions. See mxThrow() for further details.

    @note
    Exception classes should normally be based on the std::exception class, but
    because of different implementation under various compilers (and e.g. no
    presence under some compilers at all), we decided to not use std::exception
    based exception system.
    There is even the problem, that some compilers copy the message sent to
    std::exception constructor locally, which is unacceptable for some of our
    exception classes, e.g. when reporting memory related problems with heap (in
    that case it is essential, to make none additional allocation at least inside
    the exception core during the exception lifetime, this means even in the
    constructor).

    @see @ref exceptions_implementation
*/
class MXCPP_DLL_EXPORT Exception
    : public Class
{

    MX_DECLARE_EXCEPTION_CLASS(Exception, Class);


// Class methods (static).

public:

    static MX_NORETURN HandleUncaughtException(
            const Exception * const pException = NULL);

    static MX_NORETURN HandleFailure(
            const Exception * const pException = NULL);

    static MX_NORETURN HandleFailure(
            const std::exception * const pException);

    static MX_NORETURN FailAndDestroy(
            const Exception * const pException);

    static MX_NORETURN FailAndDestroy(
            const std::exception * const pException);

    static Size GlobalLogMessage(
            const Exception & pException,
            const Log::LogType iLogType = Log::LOG_Error);

    static Size GlobalLogMessage(
            const std::exception & pException,
            const Log::LogType iLogType = Log::LOG_Error);


// Construction, destruction.

protected:

    // Protected constructor to prevent direct throwing of the exception.
    MX_INLINE Exception(const Char * const sMessage = NULL);

    // Automatic copy and assignment constructor is ok for us
    // (shallow copy of file name and line information).

public:

    virtual MX_INLINE ~Exception();

// Class instance methods.

public:

    // Overridden std::exception::what() method.
    MX_OVERRIDDEN const char * what() const;

    Size LogMessage(const Log::LogType iLogType = Log::LOG_Error) const;

    MX_NORETURN Fail() const;

    MX_INLINE void SetDebugInfo(
            const Debug::Checkpoint & xFileLocation) const;

protected:

    MX_INLINE const Char * message() const;


// Class instance attributes.

private:

    /// The message associated with the exception.
    const Char * const m_sMessage;

    /// Source file location information (for debugging purposes).
    mutable Debug::Checkpoint m_xFileLocation;


}; // class Exception


// Next is the thrower of exceptions based on mx::Exception class.
//
// The thrower has to be generic template function, because otherwise we will
// not be able to throw correct exception type.
// The alternative approach is to have virtual or static throwing function in
// each exception class, which would work too, but there are several
// disadvantages of such virtual throwing functions:
//     - it must be overriden in each exception class (this is additional
//       overhead when implementing derived exceptions, and potential cause of
//       bugs - if the developer forgets to override it, the throwing will still
//       work, but will throw an exception of type other than desired)
//
// The thrower should be implemented inside the mx::Exception class normally,
// but there is problem when using as dynamic-linked library (DLL), while the
// method is generic (template) and is therefore reported as unresolved external
// for user-defined exceptions.

/**
    Setup and raise the exception.

    Sets up the exception @p pException and throws it.

    @tparam ExceptionType The type of exception being raised.

    @param [in] pException    The exception being raised.
    @param [in] xFileLocation Source file location information (for debugging
                              purposes).


    This thrower is not supposed to be called directly, you may want to use the
    mxThrow() macro to throw exceptions based on mx::Exception.

    @warning
    The parameter @p sFileName is expected to last until the exception is
    destroyed, because the information is not copied to avoid problems in low
    memory conditions (the case of OutOfMemory exception).
    Therefore it is the best if it is a C string literal (like @c __FILE__, which
    is supposed to be used here).

    @return
    This function never returns, always throwing the supplied exception.
*/
template< class ExceptionType >
static MX_NORETURN ThrowException(
        const ExceptionType & pException,
        const Debug::Checkpoint & xFileLocation)
{
    // Setup the exception.
    pException.SetDebugInfo(xFileLocation);

    // Throw the exception now.
    throw pException;
}


// Derived exceptions.

/**
    System related exception.

    This class serves as a base class for any system related exceptions.
    Currently, these include only mx::KernelException, but other system
    components (like other subsystems) are expected to follow. This class is
    supposed to be used in declaration of function which throw either of these
    more specific exceptions. It can also be used in catch blocks for catching
    either of these more specific exceptions.

    @note
    Exception of this type itself should never be thrown. Always throw
    one of the more specific types.
*/
class MXCPP_DLL_EXPORT SystemException
    : public Exception
{

    MX_DECLARE_EXCEPTION_CLASS(SystemException, Exception);

// Construction, destruction.

protected:

    // Protected constructor to prevent direct throwing of the exception.
    MX_INLINE SystemException(const Char * const sMessage = NULL);

public:

    MX_OVERRIDDEN MX_INLINE ~SystemException();


}; // class SystemException


/**
    Kernel related exception.

    This class serves as a base class for any kernel related exceptions.
    Currently, these are mx::IOException and mx::MemoryException. This class is
    supposed to be used in declaration of function which throw either of
    these more specific exceptions. It can also be used in catch blocks for
    catching either of these more specific exceptions.

    @note
    Exception of this type itself should never be thrown. Always throw
    one of the more specific types.
*/
class MXCPP_DLL_EXPORT KernelException
    : public SystemException
{

    MX_DECLARE_EXCEPTION_CLASS(KernelException, SystemException);

// Construction, destruction.

protected:

    // Protected constructor to prevent direct throwing of the exception.
    MX_INLINE KernelException(const Char * const sMessage = NULL);

public:

    MX_OVERRIDDEN MX_INLINE ~KernelException();


}; // class KernelException


/**
    Memory related exception.

    This class serves as a base class for any memory related exceptions.
    This class is supposed to be used in declaration of function which throw
    either of these more specific exceptions. It can also be used in catch
    blocks for catching either of these more specific exceptions.

    @note
    Exception of this type itself should never be thrown. Always throw
    one of the more specific types.
*/
class MXCPP_DLL_EXPORT MemoryException
    : public KernelException
{

    MX_DECLARE_EXCEPTION_CLASS(MemoryException, KernelException);

// Construction, destruction.

protected:

    // Protected constructor to prevent direct throwing of the exception.
    MX_INLINE MemoryException(const Char * const sMessage = NULL);

public:

    MX_OVERRIDDEN MX_INLINE ~MemoryException();


}; // class MemoryException


/**
    Input/Output exception.
*/
class MXCPP_DLL_EXPORT IOException
    : public KernelException
{

    MX_DECLARE_EXCEPTION_CLASS(IOException, KernelException);

// Construction, destruction.

protected:

    // Protected constructor to prevent direct throwing of the exception.
    MX_INLINE IOException(const Char * const sMessage = NULL);

public:

    MX_OVERRIDDEN MX_INLINE ~IOException();


}; // class IOException


} // namespace mx


// Define inline methods here if inlining is enabled.
#ifdef MX_INLINE_ENABLED
#include "mx/Except.inl"
#endif

#endif // MXCPP_EXCEPTION_HPP_INCLUDE_GUARD

/* EOF */
