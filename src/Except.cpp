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


/* System libraries. */


/* Framework libraries. */
#include "mx/StdStrm.hpp"
#include "mx/App/App.hpp"


/* Application specific. */
#include "mx/Except.hpp"


#ifdef MXCPP_FIX_USE_OLD_C_HEADERS

#include <eh.h>

#else

#include <exception>
#ifndef MXCPP_FIX_HAS_NOT_STD_NAMESPACE
using namespace std;
#endif

#endif


/**
    @page exceptions C++ Exception handling

    We support C++ Exceptions handling, it seems that it is supported by
    wide-range compilers, and C++ Exception usage is very convenient.

    @note
    We support even uncaught exception handler (exceptions that were not caught
    in the application); nearly all compilers look as they support it (have
    required functions defined), but it seems that only Digital Mars C++ compiler
    supports this functionality correctly for now.

    The default application catches all, even weird, exceptions (and derived
    application @b should do it too, if reimplemented), so the uncaught exception
    handler functionality is not critical. But, if you want to be absolutely
    sure, you might want to use the compiler which suports it.

    Additional information:
    @li @subpage exceptions_implementation

    @section exceptions_cpp Compilers that can support uncaught exception handlers
    @li @ref build_dmc - 32-bit Windows, 16-bit DOS
*/


/**
    @page exceptions_implementation Exceptions

    All framework exceptions are based on mx::Exception class.
    This base class extends the standard std::exception class (for compilers,
    which support it), to allow usage of abstract catch clause to catch all
    possible exceptions.

    @section exceptions_throwing Throwing exceptions

    If you want to use the @ref exceptions_handling "extended exception hadling"
    provided by the framework, you should use the construct mxThrow() to throw
    an exception.

    You can however use any way of throwing exceptions, which is possible in
    C++ (see http://www.parashift.com/c++-faq-lite/exceptions.html#faq-17.6 for
    further details), and even mix them (but this is very strongly discouraged).

    Next example shows how to throw/catch any mx::Exception based exception by
    pointer or reference:
    @include ExceptionPointerOrReference.cpp

    @section exceptions_handling Framework extended exception handling

    The framework provides some special exception handling techniques, which are
    implemented by @ref exceptions_throwing "special exception constructs".
    The key benefits of usage of these constructs are following:
    @li @b File-Line @b tracking: You will be able to gain the filename and
        line, where the exception was originated (thrown).

    @section exceptions_user Declare user exceptions

    The framework user can declare its own exception classes based on
    mx::Exception. Application exception should extend the
    mx::ApplicationException class, only in special cases you might want to
    extend mx::SystemException.
    All exceptions derived from mx::Exception should be declared using
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

    Exception throw @ref exceptions_throwing "construct".

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

///@}


// Start the exception implementation.
MX_IMPLEMENT_EXCEPTION_CLASS(mx::Exception);


/**
    Pointer to last raised exception, set until it is destroyed.

    This pointer is kept for purposes of our ExceptionHandler, which uses it
    to find the last raised exception when either terminate() or unexpected()
    functions are triggered.
*/
/* static */ const mx::Exception *
mx::Exception::sm_pLastRaisedException = NULL;


/* static */ MX_NORETURN mx::Exception::HandleUncaughtException(
        const Exception * const pException)
{
    StandardError.Printf("\nUnexpected termination handler entered!\n");
    if (!pException)
    {
        mxLogFatalError(_("Weird exception caught!"));
    }

    // Otherwise provide the user with the most detailed information about
    // the exception we can get.
    mxLogError(_("Unhandled exception caught!"));
    pException->Fail();
}


/**
    Destructor.
*/
/* virtual */ mx::Exception::~Exception()
{
    if (this == sm_pLastRaisedException)
    {
        sm_pLastRaisedException = NULL;
    }
}


/* MX_OVERRIDDEN */ const char * mx::Exception::what() const
{
    const char * const sMessage = message();
    if (sMessage)
    {
        // Use the associated message, if any set.
        return sMessage;
    }

    // Otherwise, show the name of the exception.
    return getName();
}


mx::Size mx::Exception::WriteMessage(Stream & stream) const
{
    Size iBytesWritten = doWriteMessage(stream);
    if (!m_xFileInfo.Empty())
    {
        iBytesWritten += stream.Printf(", thrown in '%s(%lu)'",
                m_xFileInfo.getFile(), m_xFileInfo.getLine());
    }
    iBytesWritten += stream.Printf(".\n");
    return iBytesWritten;
}


MX_NORETURN mx::Exception::Fail() const
{
    WriteMessage(StandardError);
    exit(mx::Application::RC_FAILURE);
}


/* virtual */ mx::Size mx::Exception::doWriteMessage(Stream & stream) const
{
    int iBytesWritten
        = stream.Printf("Exception [%s] caught", getName());

    // Append the message, if some set.
    const char * const sMessage = message();
    if (sMessage)
    {
        iBytesWritten
            += stream.Printf(" with message: '%s'", sMessage);
    }

    return iBytesWritten;
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
MX_IMPLEMENT_EXCEPTION_CLASS(mx::IOException);


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

public:

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
    Use(mxCppFrameworkSignature);

#ifndef MXCPP_FIX_EH_UNSUPPORTED
    set_terminate(&HandleTerminate);
    set_unexpected(&HandleUnexpected);
#endif // MXCPP_FIX_EH_UNSUPPORTED
}


/**
    Our handler for uncaught exceptions.
*/
/* static */ MX_NORETURN mx::UncaughtExceptionHandler::HandleTerminate()
{
    HandleUnexpected();
}


/**
    Our handler for unexpected exceptions.
*/
/* static */ MX_NORETURN mx::UncaughtExceptionHandler::HandleUnexpected()
{
    Exception::HandleUncaughtException( /*Exception::getLastRaisedException()*/);
    // Disabled to detect last raised exception for now - can have problems
    // if RTTI does not work.
}


// Define inline methods here if inlining is disabled.
#ifndef MX_INLINE_ENABLED
#include "mx/Except.inl"
#endif

/* EOF */
