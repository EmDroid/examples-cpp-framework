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
    mx::Exception::ThrowException(exception, __FILE__, __LINE__)


// Core of the exception system.


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

    @see @ref exceptions_implementation
*/
class MXCPP_DLL_EXPORT Exception
    : public Class
    , public std::exception
{

    MX_DECLARE_EXCEPTION_CLASS(Exception, std::exception);


// Class methods (static).

public:

    /**
        Setup and raise the exception.

        Sets up the exception @p pException and throws it.

        @tparam ExceptionType The type of exception being raised.

        The template is required to throw proper exception type.

        @param [in] pException The exception being raised.
        @param [in] sFileName  Name of the source file to be remembered.
                               Should last until the exception is destroyed,
                               therefore it is best if it is a C string literal
                               (like @c __FILE__).
        @param [in] iFileLine  Line number within source file @a sFileName.

        @return
        This function never returns, always throwing the supplied exception.
    */
    template< typename ExceptionType >
    static MX_NORETURN ThrowException(
            const ExceptionType & pException,
            const char * const sFileName = NULL,
            const Size iFileLine = 0)
    {
        // Setup the exception using Exception typed reference, to allow setting
        // of its private members.
        // (In the case of catching by reference, the cast-to-pointer operator
        // is used.)
        const Exception * const pExceptionBase = &pException;
        pExceptionBase->m_sFileName = sFileName;
        pExceptionBase->m_iFileLine = iFileLine;

        // Throw the exception now.
        throw pException;
    }

private:

    static MX_INLINE Exception * GetLastRaisedException();

    /// Only our exception handler is supposed to use the last raised exception.
    friend class UncaughtExceptionHandler;


// Class attributes (static).

private:

    static Exception * sm_xLastRaisedException;


// Construction, destruction.

protected:

    // Protected constructor to prevent direct throwing of the exception.
    Exception();

    // Automatic copy constructor is ok for us
    // (shallow copy of file name and line information).

public:

    MX_OVERRIDDEN ~Exception();

// Class instance methods.

public:

    int WriteMessage(FILE * const stream) const;

    MX_NORETURN Fail() const;

protected:

    virtual int doWriteMessage(FILE * const stream) const;


// Class instance attributes.

private:

    /// Name of the source code file from where the exception was raised.
    mutable const char * m_sFileName;

    /// Line number in the source code file from where the exception was raised.
    mutable Size m_iFileLine;

    /*

    template< typename ExceptionType >
    friend MX_NORETURN ThrowException(const ExceptionType &,
            const char * const, const Size);
       */


}; // class Exception


/**
    Setup and raise the exception.

    Sets up the exception @p pException and throws it.

    @tparam ExceptionType The type of exception being raised.

    The template is required to throw proper exception type.

    @param [in] pException The exception being raised.
    @param [in] sFileName  Name of the source file to be remembered.
                           Should last until the exception is destroyed,
                           therefore it is best if it is a C string literal
                           (like @c __FILE__).
    @param [in] iFileLine  Line number within source file @a sFileName.

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

    // Throw the exception now.
    throw pException;
}


// Derived exceptions.

/**
    Application related exception.

    This class serves as a base class for any application exceptions. The
    application is expected to use this and no other class as the base class
    for it's own exceptions.

    @note
    Exception of this type itself should never be thrown. Always throw
    one of the more specific types.
*/
class MXCPP_DLL_EXPORT ApplicationException
    : public Exception
{

    MX_DECLARE_EXCEPTION_CLASS(ApplicationException, Exception);


}; // class ApplicationException


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


}; // class MemoryException


class MXCPP_DLL_EXPORT StreamException
    : public KernelException
{

    MX_DECLARE_EXCEPTION_CLASS(StreamException, KernelException);


}; // class StreamException


class MXCPP_DLL_EXPORT EndOfFile
    : public StreamException
{

    MX_DECLARE_EXCEPTION_CLASS(EndOfFile, StreamException);

// Construction, destruction.

public:

    MX_INLINE EndOfFile();


}; // class EndOfFile


} // namespace mx


// Define inline methods here if inlining is enabled.
#ifdef MX_INLINE_ENABLED
#include "mx/Except.inl"
#endif

#endif // MXCPP_EXCEPTION_HPP_INCLUDE_GUARD

/* EOF */
