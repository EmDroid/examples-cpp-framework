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


#ifndef MXCPP_EXCEPTION_HPP_INCLUDE_GUARD
#define MXCPP_EXCEPTION_HPP_INCLUDE_GUARD


#include "mx/sysdefs.h"

#include "mx/types.h"

#include "mx/Class.hpp"


namespace mx
{


#define mxThrow(exception) \
    mx::ThrowException(exception, __FILE__, __LINE__)


// Forward declaration.
class Stream;


/**
    Exception class declaration.

    Used inside an exception declaration to declare extensions used in exceptions
    derived from Exception.

    @param [in] name Name of the exception class.
    @param [in] base Name of the parent exception class.

    Example:
    @code
    class MyDerivedException: public ApplicationException {

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
    class MyDerivedException: public ApplicationException {

          MX_DECLARE_EXCEPTION_CLASS(MyDerivedException,
              ApplicationException);

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
    Application should use @ref exceptions_constructs
    "framework exception constructs" to throw and catch Exception based
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

private:

    static MX_INLINE void setLastRaisedException(
            const Exception & theException);

    static MX_INLINE const Exception * getLastRaisedException();

    /// Only our exception handler is supposed to use the last raised exception.
    friend class UncaughtExceptionHandler;


// Class attributes (static).

private:

    static const Exception * sm_pLastRaisedException;


// Construction, destruction.

protected:

    // Protected constructor to prevent direct throwing of the exception.
    MX_INLINE Exception(const char * sMessage = NULL);

    // Automatic copy and assignment constructor is ok for us
    // (shallow copy of file name and line information).

public:

    MX_OVERRIDDEN ~Exception();

// Class instance methods.

public:

    // Overridden std::exception::what() method.
    virtual const char * what() const;

    int WriteMessage(Stream & stream) const;

    MX_NORETURN Fail(const char * const sMessage = NULL) const;

protected:

    MX_INLINE const char * message() const;

    virtual int doWriteMessage(Stream & stream) const;


// Class instance attributes.

private:

    /// The message associated with the exception.
    const char * const m_sMessage;

    /// Name of the source file, where the exception was raised.
    mutable const char * m_sFileName;

    /// Line number in the source file, where the exception was raised.
    mutable Size m_iFileLine;

    // Only our thrower is supposed to setup the exception.
    template< typename ExceptionType >
    friend MX_NORETURN ThrowException(const ExceptionType &,
            const char * const, const Size);


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

    The template is required to throw proper exception type.

    @param [in] pException The exception being raised.
    @param [in] sFileName  Name of the source file to be remembered.
    @param [in] iFileLine  Line number within the source file.

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
template< typename ExceptionType >
MX_NORETURN ThrowException(
        const ExceptionType & pException,
        const char * const sFileName = NULL,
        const Size iFileLine = 0)
{
    // Setup the exception using Exception typed reference, to allow setting
    // of its private members.
    // (In the case of catching by reference, the cast-to-pointer operator is
    // used.)
    const Exception * const pExceptionBase = &pException;
    pExceptionBase->m_sFileName = sFileName;
    pExceptionBase->m_iFileLine = iFileLine;

    Exception::setLastRaisedException(pException);

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
    MX_INLINE SystemException(const char * sMessage = NULL);


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
    MX_INLINE KernelException(const char * sMessage = NULL);


}; // class KernelException


} // namespace mx


// Define inline methods here if inlining is enabled.
#ifdef MX_INLINE_ENABLED
#include "mx/Except.inl"
#endif

#endif // MXCPP_EXCEPTION_HPP_INCLUDE_GUARD

/* EOF */
