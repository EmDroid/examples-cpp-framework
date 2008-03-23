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

    Application base classes (implementation).

    @author Emil Maskovsky
*/


/* System libraries. */


/* Framework libraries. */


/* Application specific. */
#include "mx/App/App.hpp"


// Start the exception implementation.
MX_IMPLEMENT_EXCEPTION_CLASS(mx::ApplicationException);


/// The application instance.
mx::Application * mx::Application::pApplicationInstance = NULL;

/**
    Default constructor.
*/
mx::Application::Application()
{
    // Can create only one application instance.
    if (pApplicationInstance)
    {
        mxLogWarning(
                _("The application instance already created using [%s]!"),
                pApplicationInstance->getName());
    }
    pApplicationInstance = this;
}


/**
    Destructor.
*/
/* virtual */ mx::Application::~Application()
{}


/**
    Runs the application main loop.

    @return
    Application return code (to be passed to system).
*/
int mx::Application::Run(void)
{
    int iReturnCode = 0;
    try
    {
        if (!Initialize())
        {
            // Initialication might throw exception, of course.
            mxLogError(_("Application initialization failed."));
            return RC_INTERNAL_ERROR;
        }
        iReturnCode = OnRun();
    }
    // Catch all framework - based exceptions thrown by reference.
    catch (const Exception & e)
    {
        Exception::HandleFailure(&e);
    }
    // Catch all framework - based exceptions thrown by pointer.
    catch (const Exception * e)
    {
        // The pointer is not '* const', because under some compilers this
        // causes loss of original exception type (see
        // 'examples/ExceptionPointerOrReference.cpp' for details).
        Exception::FailAndDestroy(e);
    }
    // Catch all std::exception based exceptions thrown by reference.
    catch (const std::exception & e)
    {
        Exception::HandleFailure(&e);
    }
    // Catch all std::exception based exceptions thrown by pointer.
    catch (const std::exception * e)
    {
        // The pointer is not '* const', because under some compilers this
        // causes loss of original exception type (see
        // 'examples/ExceptionPointerOrReference.cpp' for details).
        Exception::FailAndDestroy(e);
    }
    // Catch all other exceptions.
    catch (...)
    {
        Exception::HandleUncaughtException();
    }
    return iReturnCode;
}


/**
    Initialize the application main loop.

    @return
    The initialization status - @c true on success, @c false in case of an
    initialization error (e.g. fail in the OnInit() handler).

    @warning
    You should not override this function. You probably will override
    the OnInit() handler instead.

    @see OnInit().
*/
bool mx::Application::Initialize(void)
{
    // Run OnInit handler.
    return OnInit();
}


/**
    OnInit event handler.

    You should override this function to provide custom application
    initialization.

    @warning
    If you want to process default initialization (e.g. parsing command line),
    you must call OnInit() handler of your base class (and you @b should return
    @c false in case the initialization fails) - you probably want to use
    following code in your handler:
    @code
    bool MyApp::OnInit(void)
    {
        if (!SuperClass::OnInit()) {
            return false;
        }
        ...
        if (something_failed) {
            return false;
        }
        ...
        return true;
    }
    @endcode

    @return
    Should return initialization status - @c true on success, @c false in case
    of an initialization error. If returns @c true, the application will continue
    running the main loop; otherwise, the application will fail with an error
    message.

    @note
    You can, of course, use exceptions (derived from cxException) inside the
    handler to signalize error (and exception usage will be better in most
    cases than signalizing error through return value).
*/
/* virtual */ bool mx::Application::OnInit()
{
    return true;
}


/**
    OnRun event handler.

    You should override this function to provide custom run functionality.

    @return
    Should return the application return code (to be passed to system).
    On successfull application run, it should return #RC_SUCCESS (or @c 0, which
    is equivalent of that constant), on failure it should return any other
    non-zero value (e.g. #RC_FAILURE, or some application-defined error code
    etc.).
*/
/* virtual */ mx::Application::ReturnCode mx::Application::OnRun()
{
    return RC_SUCCESS;
}


// Implement inline methods here if inlining is disabled.
#ifndef MX_INLINE_ENABLED
#include "mx/App/App.inl"
#endif

/* EOF */
