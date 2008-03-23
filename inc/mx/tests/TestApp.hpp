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

    Test application class (interface).

    @author Emil Maskovsky

    This header is to be included in test implementations only, and then proper
    methods of the mx::TestApp should be implemented. Do not include in normal
    applications.
*/


#ifndef MXCPP_SYSDEFS
#include "mx/sysdefs.hpp"
#endif


#ifndef MXCPP_TEST_APPLICATION_HPP_INCLUDE_GUARD
#define MXCPP_TEST_APPLICATION_HPP_INCLUDE_GUARD


#ifndef MXCPP_TYPES
#include "mx/types.hpp"
#endif

#include "mx/App/App.hpp"

#include "mx/LogStd.hpp"


namespace mx
{


/**
    Testing application.

    The test implementation should directly implement SetTestName() and
    OnRunTests() methods, to avoid needless code redundacy in tests.
*/
class TestApp
    : public Application
{

    MX_CLASS_NO_COPY(TestApp);
    MX_CLASS_NO_ASSIGNMENT(TestApp);


// Construction, destruction.

public:

    /**
        Default constructor.
    */
    MX_INLINE TestApp()
    {}

// Class instance functions.

public:

    // This is to check, if the override block works.
    int Run()
    {
        mxLogError(_("Invalid Run() called!"));
        return RC_FAILURE;
    }

private:

    /**
        Set up the name of the test.

        The test application must implement this method to provide the test name.

        @return
        The implementation should return the C-string of the test name.
        Must not return @c NULL (the return value is checked and in that case
        the error message is triggered and the test application is aborted).
    */
    const Char * SetTestName();

    /**
        Get the name of the test.
    */
    MX_INLINE const Char * GetTestName()
    {
        static const Char * const sTestName = SetTestName();
        mxReleaseAssert(sTestName != NULL);
        return sTestName;
    }

    /**
        Special App::OnRun() handler for test applications.

        @return
        The test return code, as implemented in the OnRunTests().
    */
    MX_OVERRIDDEN ReturnCode OnRun()
    {
        Log::SetActiveTarget(LogStandard::Instance());
        Log(Log::LOG_Message, Debug::Checkpoint()).LogMessage(
#ifndef MXCPP_UNICODE
                _("--- Running the [%s] tests ... ---")
#else
                _("--- Running the [%ls] tests ... ---")
#endif
                , GetTestName());
        // Make sure the startup message is always displayed, even in the case
        // of a nasty failure in the testing environment.
        Log::Flush();
        const ReturnCode iReturnCode = OnRunTests();
        Log(Log::LOG_Message, Debug::Checkpoint()).LogMessage(
#ifndef MXCPP_UNICODE
                _("--- ... the [%s] tests passed successfully. ---")
#else
                _("--- ... the [%ls] tests passed successfully. ---")
#endif
                , GetTestName());
        return iReturnCode;
    }

protected:

    /**
        Run the tests.

        The test application must implement this method to run the tests.

        @return
        The implementation should return #RC_SUCCESS (or zero, which is
        equivalent) on success (when all the tests succeed). If any test failed,
        the implementation should return #RC_FAILURE (or in exceptional cases any
        other non-zero value).
        But the preferred method of reporting the test failures is the usage of
        mxTest() macro,
    */
    ReturnCode OnRunTests();


}; // class TestApp


} // namespace mx


// The test application initialization.
MX_IMPLEMENT_APP(mx::TestApp)


#endif // MXCPP_TEST_APPLICATION_HPP_INCLUDE_GUARD

/* EOF */
