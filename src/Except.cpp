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

#include <typeinfo.h>
#include <eh.h>

#else

#include <typeinfo>
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


// Start the exception implementation.
MX_IMPLEMENT_EXCEPTION_CLASS(mx::Exception);


namespace mx
{


template< class ExceptionType >
class FailureHandler
{

    MX_CLASS_NO_COPY(FailureHandler);
    MX_CLASS_NO_ASSIGNMENT(FailureHandler);

public:

    inline FailureHandler(const ExceptionType * const pException)
        : m_pException(pException)
    {}

public:

    MX_NORETURN HandleFailure(const bool bDestroy)
    {
        ProcessErrors(bDestroy);
        exit(Application::RC_FAILURE);
    }

    MX_NORETURN HandleUncaughtException(const bool bDestroy)
    {
        mxLogTrace(Log::TRACE_Exception, Log::LEVEL_Highest,
                _("Unexpected termination handler entered!"));
        ProcessErrors(bDestroy, true);
        abort();
    }

private:

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

private:

    const ExceptionType * const m_pException;

}; // class FailureHandler< ... >


/*
static MX_NORETURN doHandleUncaughtException(
        const ExceptionType * const pException)
{
    abort();
}
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

#ifdef MXCPP_PRAGMA_NORETURN
    #pragma MXCPP_PRAGMA_NORETURN(mx::Exception::HandleUncaughtException)
#endif

/* static */ MX_NORETURN mx::Exception::HndlUncaughtException(
        const Exception * const pException)
{
    FailureHandler< Exception >(pException).HandleUncaughtException(false);
}


#ifdef MXCPP_PRAGMA_NORETURN
    #pragma MXCPP_PRAGMA_NORETURN(mx::Exception::HandleFailure)
#endif

/* static */ MX_NORETURN mx::Exception::HndlFailure(
        const Exception * const pException,
        bool bDestroy)
{
    FailureHandler< Exception >(pException).HandleFailure(bDestroy);
}


#ifdef MXCPP_PRAGMA_NORETURN
    #pragma MXCPP_PRAGMA_NORETURN(mx::Exception::HandleFailure)
#endif

/* static */ MX_NORETURN mx::Exception::HndlFailure(
        const std::exception * const pException,
        bool bDestroy)
{
    FailureHandler< std::exception >(pException).HandleFailure(bDestroy);
}


/* static */ mx::Size mx::Exception::GlobalLogMessage(
        const Exception & pException,
        const Log::LogType iLogType)
{
    return doLogMessage(pException.getName(), pException.message(),
            pException.m_xFileInfo, iLogType);
}


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


mx::Size mx::Exception::LogMessage(const Log::LogType iLogType) const
{
    return GlobalLogMessage(*this, iLogType);
}


MX_NORETURN mx::Exception::Fail() const
{
    LogMessage();
    exit(mx::Application::RC_FAILURE);
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
    Exception::HndlUncaughtException(
            /* Exception::getLastRaisedException() */);
    // Disabled to detect last raised exception for now - can have problems
    // if RTTI does not work.
}


// Define inline methods here if inlining is disabled.
#ifndef MX_INLINE_ENABLED
#include "mx/Except.inl"
#endif

/* EOF */
