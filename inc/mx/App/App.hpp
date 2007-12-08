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

    Application base classes (interface).

    @author Emil Maskovsky
*/


#ifndef MXCPP_APPLICATION_HPP_INCLUDE_GUARD
#define MXCPP_APPLICATION_HPP_INCLUDE_GUARD


#include "mx/sysdefs.h"

#include "mx/types.h"

#include "mx/debug.h"

#include "mx/Except.hpp"


/**
    @def MX_IMPLEMENT_APP

    Implement main %application (platform independent).

    Usage:
    @code
    class MyApplication: public mx::Application::Application {
       ...
    }
    ...
    MX_IMPLEMENT_APP(MyApplication)
    ...
    @endcode

    @param ApplicationMainClass The main %application class.

    @warning
    Must be present out of all namespaces, otherwise it might be compiled
    as C++ extern on some compilers (actualy known BCC32 issue).
*/
// Only console applications supported by this demo.
// Command line parameters not supported in this demo.
#define MX_IMPLEMENT_APP(ApplicationMainClass)                             \
                                                                           \
    extern "C"                                                             \
    int main(const int /* argc */, const char ** /* argv */)               \
    {                                                                      \
        ApplicationMainClass theApplication/*(argc, argv)*/;               \
        /* Make sure, that we run mx::Application::Run() and not the Run() \
           potentialy overridden by some inherited application class.      \
        */                                                                 \
        return mx::Application::getApp()->Run();                           \
    }


namespace mx
{


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

// Construction, destruction.

protected:

    // Protected constructor to prevent direct throwing of the exception.
    MX_INLINE ApplicationException(const char * sMessage = NULL);


}; // class ApplicationException


/**
    Base class of an application.
*/
class MXCPP_DLL_EXPORT Application
    : public Class
{

    MX_CLASS_NO_COPY(Application);
    MX_CLASS_NO_ASSIGNMENT(Application);

// Types, constants.

public:

    /**
        Application return code.
    */
    typedef enum
    {

        /// Application terminated as a result of an internal error.
        RC_INTERNAL_ERROR = -1,

        /// Application exit withour errors.
        RC_SUCCESS = 0,

        /// Application exit with general error.
        RC_FAILURE = 1,

    } ReturnCode;


// Class methods (static).

public:

    static MX_INLINE Application * getApp();


// Class attributes (static).

private:

    static Application * pApplicationInstance;


// Construction, destruction.

protected:

    Application();

    virtual ~Application();


// Class instance methods.

public:

    int Run();

private:

    // Only application main functions will be allowed to run the application.
    friend int main(const int, const char **);

    // Initialize() function is private to prevent it's override.
    // You should not override it.
    bool Initialize();

protected:

    // Override to provide custom initialization.
    virtual bool OnInit();

    // Override to provide custom run functionality.
    virtual ReturnCode OnRun();


// Class instance attributes.

private:

}; // class Application


} // namespace mx


// Define inline methods here if inlining is enabled.
#ifdef MX_INLINE_ENABLED
#include "mx/App/App.inl"
#endif

#endif // MXCPP_APPLICATION_HPP_INCLUDE_GUARD

/* EOF */
