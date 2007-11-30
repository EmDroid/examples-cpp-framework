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

    Exception support (implementation).

    @author Emil Maskovsky
*/


/* Framework libraries. */
#include "mx.h"


/* Application specific. */
#include "mx/Except.hpp"


/**
    @page exceptions_implementation Exceptions

    All framework exceptions are based on Exception base class.
    This base class extends the standard std::exception class (for compilers,
    which support it), to allow usage of abstract catch clause to catch all
    possible exceptions.

    @section exceptions_constructs Exception constructs

    The preferred framework way for throwing and catching exceptions is to use
    following exception support constructs:
    @li mxThrow() - exception throw construct

    as follows:
    @include ExceptionExample.cpp

    @subsection exceptions_throwing Throwing exceptions

    You can, however, use any way of throwing exceptions, which is possible in
    C++ (see http://www.parashift.com/c++-faq-lite/exceptions.html#faq-17.6 for
    further details), and even mix them (but this is very strongly discouraged).
    But if you want to use the @ref exceptions_handling
    "extended exception hadling" provided by the framework, you should use the
    @ref exceptions_constructs "provided constructs".

    Next example shows how to throw/catch any Exception based exception by
    pointer or reference:
    @include ExceptionPointerOrReference.cpp

    @note
    You can safely delete all Exception based exceptions thrown by pointer.
    Even in the case of some special exception classes, like OutOfMemory,
    while they should have overriden new and delete operators, if they use some
    non-standard allocation.

    @section exceptions_handling Framework extended exception handling

    The framework provides some special exception handling techniques, which are
    implemented by @ref exceptions_constructs "special exception constructs".
    The key benefits of usage of these constructs are following:
    @li @b File-Line @b tracking: You will be able to gain the filename and
        line, where the exception was originated (thrown).

    @section exceptions_user Declare user own exceptions

    The framework user can declare its own exception classes based on
    Exception. Application exception should extend the ApplicationException
    class, only in special cases you might want to extend SystemException.
    All exceptions derived from Exception should be declared using
    MX_DECLARE_EXCEPTION_CLASS() and MX_IMPLEMENT_EXCEPTION_CLASS() macros,
    otherwise some extensions used in exception handling (e.g. @ref RTTI) will
    not work correctly.
*/


/**
    @name Exception system constructs.
*/
///@{

/**
    @def mxThrow

    Exception throw @ref exceptions_constructs "construct".

    @param [in] exception The exception to be thrown.

    This construct is to be used to throw exceptions derived from the
    Exception class.
    For example, to throw and catch EndOfFile exception, use:
    @code
    try {
        mxThrow(EndOfFile());
    } catch (const EndOfFile & e) {
        // Procss the exception.
        ...
        throw;  // Possibly re-throw the exception.
    }
    @endcode

    You can, however, throw any Exception using standard @c throw statement, as
    follows:
    @include ExceptionPointerOrReference.cpp

    But using of mxThrow(exception) is the CppFramework recommended way of
    throwing exceptions based on Exception, and only then you can gain from
    framework @ref exceptions_handling "extended exception processing".
*/

///@}


// Start the exception implementation.
MX_IMPLEMENT_EXCEPTION_CLASS(mx::Exception);


/**
    Pointer to last raised exception, set until it is destroyed.

    This pointer is kept for purposes of our ExceptionHandler, which uses it
    to find the last raised exception when either terminate() or unexpected()
    functions are triggered.
*/
/* static */ mx::Exception * mx::Exception::sm_xLastRaisedException = NULL;


/**
    Constructor.


    @param [in] pWrappedException Exception to be wrapped inside
                                  this exception.
*/
mx::Exception::Exception()
    : m_sFileName(NULL)
    , m_iFileLine(0)
{
    sm_xLastRaisedException = this;
}


/**
    Destructor.
*/
/* virtual */ mx::Exception::~Exception()
{}


int mx::Exception::WriteMessage(FILE * const stream) const
{
    int iBytesWritten = doWriteMessage(stream);
    if (m_sFileName)
    {
        iBytesWritten += std::fprintf(stream, ", thrown in '%s(%lu)'",
                m_sFileName, m_iFileLine);
    }
    iBytesWritten += std::fprintf(stream, ".\n");
    return iBytesWritten;
}


MX_NORETURN mx::Exception::Fail() const
{
    WriteMessage(stderr);
    exit(1);
}


/* virtual */ int mx::Exception::doWriteMessage(FILE * const stream) const
{
    return std::fprintf(stream, "Exception %s caught", GetName());
}


// Start the exception implementation.
MX_IMPLEMENT_EXCEPTION_CLASS(mx::ApplicationException);


// Start the exception implementation.
MX_IMPLEMENT_EXCEPTION_CLASS(mx::SystemException);


// Start the exception implementation.
MX_IMPLEMENT_EXCEPTION_CLASS(mx::KernelException);


// Start the exception implementation.
MX_IMPLEMENT_EXCEPTION_CLASS(mx::MemoryException);


// Start the exception implementation.
MX_IMPLEMENT_EXCEPTION_CLASS(mx::StreamException);


// Start the exception implementation.
MX_IMPLEMENT_EXCEPTION_CLASS(mx::EndOfFile);

void EndOfFileImp()
{
    mxThrow(mx::EndOfFile());
}


namespace mx
{


// Uncaught (aka default) exception handler.
// Declared only internaly (cannot be used outside).

/**
    Helper class for setting the default exception handlers.
*/
class UncaughtExceptionHandler
{

    MX_CLASS_NO_COPY(UncaughtExceptionHandler);
    MX_CLASS_NO_ASSIGNMENT(UncaughtExceptionHandler);


// Class attributes (static).

private:

    /**
        Instance of UncaughtExceptionHandler to enforce invocation
        of its constructor.
    */
    static const UncaughtExceptionHandler sm_xInitializer;


// Class functions (static).

private:

    static MX_NORETURN HandleTerminate();

    static MX_NORETURN HandleUnexpected();


// Construction, destruction.
#ifndef MXCPP_FIX_STATIC_CANT_ACCESS_PRIVATE_CONSTRUCTOR

protected:

    /**
        Suppress warning about private-only member functions by declaring a fake
        friend.
    */
    friend class NonExistingFakeClass;

#else // MXCPP_FIX_STATIC_CANT_ACCESS_PRIVATE_CONSTRUCTOR

public:

#endif // MXCPP_FIX_STATIC_CANT_ACCESS_PRIVATE_CONSTRUCTOR

    UncaughtExceptionHandler();


}; // class UncaughtExceptionHandler


} // namespace mx


// Initialize the only instance and run the constructor.
const mx::UncaughtExceptionHandler
mx::UncaughtExceptionHandler::sm_xInitializer;


// Framework signature.
static const char mxCppFrameworkSignature[]
    = "This application uses Demo C++ Framework,"
      " (C) 1996-2008 Emil Maskovsky";

/**
    Initialize exception handlers.
*/
mx::UncaughtExceptionHandler::UncaughtExceptionHandler()
{
    // Use the signature to be always contributed in the output.
    mxUse(mxCppFrameworkSignature);

#ifndef MXCPP_FIX_EH_UNSUPPORTED
    set_terminate(&HandleTerminate);
    set_unexpected(&HandleUnexpected);
#endif // MXCPP_FIX_EH_UNSUPPORTED
}


/**
    Our handler for uncaught exceptions.
*/
MX_NORETURN mx::UncaughtExceptionHandler::HandleTerminate()
{
    HandleUnexpected();
}


/**
    Our handler for unexpected exceptions.
*/
MX_NORETURN mx::UncaughtExceptionHandler::HandleUnexpected()
{
    // See if we know what the last thrown exception was. If not, fail with
    // generic error message.
    Exception * const pException
        = Exception::GetLastRaisedException();

    if (!pException)
    {
        fprintf(stderr, "Weird exception caught!");
    }

    // Otherwise provide the user with the most detailed information about
    // the exception we can get.
    fprintf(stderr, "\nUnhandled exception caught!\n");
    pException->WriteMessage(stderr);

    // Always abort, if not aborted by exception handler.
    abort();
    // On some platforms abort() can return.
    exit(-1);
}


// Define inline methods here if inlining is disabled.
#ifndef MX_INLINE_ENABLED
#include "mx/Except.inl"
#endif

/* EOF */
