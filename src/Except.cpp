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


#ifndef MXCPP_FIX_USE_OLD_C_HEADERS

#include <typeinfo>
#include <exception>

#ifndef MXCPP_FIX_HAS_NOT_STD_NAMESPACE
using namespace std;
#endif

#else // MXCPP_FIX_USE_OLD_C_HEADERS

#include <typeinfo.h>

#ifndef MXCPP_FIX_EH_UNSUPPORTED
#include <eh.h>
#endif

#endif // MXCPP_FIX_USE_OLD_C_HEADERS


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


// Start the exception implementation.
MX_IMPLEMENT_EXCEPTION_CLASS(mx::Exception);


/**
    Destructor.
*/
/* virtual */ mx::Exception::~Exception()
{}


namespace mx
{


/**
    The exception failure handler.

    @tparam ExceptionType The exception type.
*/
template< class ExceptionType >
class FailureHandler
{

    MX_CLASS_NO_COPY(FailureHandler);
    MX_CLASS_NO_ASSIGNMENT(FailureHandler);

// Construction, destruction.

public:

    /**
        Constructor taking the exception pointer.

        @param [in] pException The exception pointer.
    */
    explicit inline FailureHandler(const ExceptionType * const pException)
        : m_pException(pException)
    {}


// Class instance methods.

public:

    /**
        Normal handling of the exception.

        Designed for handling of expected exceptions.

        @param [in] bDestroy Destroy the exception after handling.

        This handler does not return, always causes the application shutdown.
    */
    MX_NORETURN HandleFailure(const bool bDestroy)
    {
        ProcessErrors(bDestroy);
        exit(Application::RC_FAILURE);
    }

    /**
        Handling of unexpected exception.

        Designed for handling of unexpected (uncaught) exceptions.

        @param [in] bDestroy Destroy the exception after handling.

        This handler does not return, always causes the application shutdown via
        the standard @c abort() function.
    */
    MX_NORETURN HandleUncaughtException(const bool bDestroy)
    {
        mxLogTrace(Log::TRACE_Exception, Log::LEVEL_Highest,
                _("Unexpected termination handler entered!"));
        ProcessErrors(bDestroy, true);
        abort();
    }

private:

    /**
        Process the exception handling.

        @param [in] bDestroy   Destroy the exception after handling.
        @param [in] bUnhandled Handling of unexpected exception (optional).

        @return
        Returns the @ref logging_macros "result of logging" the exception
        message.
    */
    Size ProcessErrors(const bool bDestroy, const bool bUnhandled = false)
    {
        if (!m_pException)
        {
            return mxLogFatalError(_("Weird exception caught!"));
        }

        // Otherwise provide the user with the most detailed information about
        // the exception we can get.
        if (bUnhandled)
        {
            mxLogError(_("Unhandled exception caught!"));
        }
        const Size iReturnCode = Exception::GlobalLogMessage(*m_pException);
        if (bDestroy)
        {
            delete const_cast< ExceptionType * >(m_pException);
        }
        return iReturnCode;
    }

// Class instance attributes.

private:

    /// The exception which is being handled.
    const ExceptionType * const m_pException;


}; // class FailureHandler< ... >


/**
    Default logging of the exception message.

    @param [in] sExceptionName The name of the exception.
    @param [in] sMessage       The exception message (may be @c NULL).
    @param [in] xFileInfo      Source file location information.
    @param [in] iLogType       Type of log message.


    @return
    Returns the @ref logging_macros "result of logging" the exception message.
*/
static Size doLogMessage(
        const char * const sExceptionName,
        const Char * sMessage,
        const Debug::Checkpoint & xFileInfo,
        const Log::LogType iLogType)
{
#ifndef MXCPP_UNICODE
    const char * const sClassName = sExceptionName;
#else
    Char sClassName[64];
    mbstowcs(sClassName, sExceptionName, sizeof(sClassName) - 1);
#endif
    mxAssert(sExceptionName != NULL);
    return Log(iLogType, xFileInfo).LogMessage(
#ifndef MXCPP_UNICODE
            _("Exception '%s' caught%s%s")
#else
            _("Exception '%ls' caught%ls%ls")
#endif
            , sClassName,
            sMessage ? _(" with message: ") : _T(""),
            sMessage ? sMessage : _T(""));
}


} // namespace mx

/**
    Uncaught exception handler.

    Handles the exception and terminates the application using standard function
    @c abort().

    @param [in] pException The exception pointer.
*/
/* static */ MX_NORETURN mx::Exception::HandleUncaughtException(
        const Exception * const pException)
{
    FailureHandler< Exception >(pException).HandleUncaughtException(false);
}


/**
    Exception failure handler.

    Handles the exception and terminates the application.

    @param [in] pException The exception pointer.
*/
/* static */ MX_NORETURN mx::Exception::HandleFailure(
        const Exception * const pException)
{
    FailureHandler< Exception >(pException).HandleFailure(false);
}


/**
    Exception failure handler (the std::exception variant).

    Handles the exception and terminates the application.

    @param [in] pException The exception pointer.
*/
/* static */ MX_NORETURN mx::Exception::HandleFailure(
        const std::exception * const pException)
{
    FailureHandler< std::exception >(pException).HandleFailure(false);
}


/**
    Handle the exception failure and destroy the exception.

    This handler is to be used along with exceptions, which are thrown and caught
    by pointer.

    @param [in] pException The exception pointer.

    @warning
    Should not be used with exceptions which are not dynamically allocated using
    the @c new operator! In the case of statically allocated exceptions, use
    Exception::HandleFailure() instead!

    @see Exception::HandleFailure()
*/
/* static */ MX_NORETURN mx::Exception::FailAndDestroy(
        const Exception * const pException)
{
    FailureHandler< Exception >(pException).HandleFailure(true);
}


/**
    Handle the exception failure and destroy the exception
    (the std::exception variant).

    This handler is to be used along with exceptions, which are thrown and caught
    by pointer.

    @param [in] pException The exception pointer.

    @warning
    Should not be used with exceptions which are not dynamically allocated using
    the @c new operator! In the case of statically allocated exceptions, use
    Exception::HandleFailure() instead!

    @see Exception::HandleFailure()
*/
/* static */ MX_NORETURN mx::Exception::FailAndDestroy(
        const std::exception * const pException)
{
    FailureHandler< std::exception >(pException).HandleFailure(true);
}


/**
    Log the message of an exception.

    @param [in] pException The exception instance.
    @param [in] iLogType   Type of log message.


    @return
    Returns the @ref logging_macros "result of logging" the exception message.
*/
/* static */ mx::Size mx::Exception::GlobalLogMessage(
        const Exception & pException,
        const Log::LogType iLogType)
{
    return doLogMessage(pException.getName(), pException.message(),
            pException.m_xFileLocation, iLogType);
}


/**
    Log the message of an exception (the std::exception variant).

    @param [in] pException The exception instance.
    @param [in] iLogType   Type of log message.


    @return
    Returns the @ref logging_macros "result of logging" the exception message.
*/
/* static */ mx::Size mx::Exception::GlobalLogMessage(
        const std::exception & pException,
        const Log::LogType iLogType)
{
#ifndef MXCPP_UNICODE
    const char * const sMessage = pException.what();
#else
    Char sMessage[128];
    mbstowcs(sMessage, pException.what(), sizeof(sMessage) - 1);
#endif
    return doLogMessage(Class::FilterTypeName(typeid(pException).name()),
            sMessage,
            // The file information is empty.
            Debug::Checkpoint(), iLogType);
}


/**
    Get the message associated with the exception.
*/
/* MX_OVERRIDDEN */ const char * mx::Exception::what() const
{
    /*
    const Char * const sMessage = message();
    if (sMessage)
    {
        // Use the associated message, if any set.
        return sMessage;
    }
    */

    // Otherwise, show the name of the exception.
    return getName();
}


/**
    Log the exception message.

    @param [in] iLogType Type of log message.


    @return
    Returns the @ref logging_macros "result of logging" the exception message.
*/
mx::Size mx::Exception::LogMessage(const Log::LogType iLogType) const
{
    return GlobalLogMessage(*this, iLogType);
}


/**
    Handle the exception failure.

    Logs the exception message via LogMessage() and terminates the application.
*/
MX_NORETURN mx::Exception::Fail() const
{
    LogMessage();
    exit(mx::Application::RC_FAILURE);
}


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

    static const UncaughtExceptionHandler sm_xInitializer;


// Class functions (static).

private:

    static inline MX_NORETURN HandleTerminate();

    static inline MX_NORETURN HandleUnexpected();


// Construction, destruction.

public:

    UncaughtExceptionHandler();


}; // class UncaughtExceptionHandler


} // namespace mx


/**
    Instance of UncaughtExceptionHandler to enforce invocation of its
    constructor.
*/
const mx::UncaughtExceptionHandler
mx::UncaughtExceptionHandler::sm_xInitializer;


/// Signature of the @project to appear in executables.
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
    // Cast to the target type needed for using with some compilers
    // (e.g. Watcom has problems with "noreturn" specification).
    set_terminate(reinterpret_cast< void (*)() >(&HandleTerminate));
    set_unexpected(reinterpret_cast< void (*)() >(&HandleUnexpected));
#endif // MXCPP_FIX_EH_UNSUPPORTED
}


/**
    Our handler for uncaught exceptions.
*/
/* static */ inline MX_NORETURN mx::UncaughtExceptionHandler::HandleTerminate()
{
    HandleUnexpected();
}


/**
    Our handler for unexpected exceptions.
*/
/* static */ inline MX_NORETURN mx::UncaughtExceptionHandler::HandleUnexpected()
{
    Exception::HandleUncaughtException(
            /* Exception::getLastRaisedException() */);
    // Disabled to detect last raised exception for now - can have problems
    // if RTTI does not work.
}


// Define inline methods here if inlining is disabled.
#ifndef MX_INLINE_ENABLED
#include "mx/Except.inl"
#endif

/* EOF */
