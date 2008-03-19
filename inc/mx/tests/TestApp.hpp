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
*/
class TestApp
    : public Application
{

    MX_CLASS_NO_COPY(TestApp);
    MX_CLASS_NO_ASSIGNMENT(TestApp);


// Construction, destruction.

public:

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

    const Char * SetTestName();

    MX_INLINE const Char * GetTestName()
    {
        static const Char * const sTestName = SetTestName();
        mxAssert(sTestName != NULL);
        return sTestName;
    }

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

    virtual ReturnCode OnRunTests();


}; // class TestApp


} // namespace mx


#endif // MXCPP_TEST_APPLICATION_HPP_INCLUDE_GUARD

/* EOF */
