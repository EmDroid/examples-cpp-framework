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


#ifndef MXCPP_TEST_APPLICATION_HPP_INCLUDE_GUARD
#define MXCPP_TEST_APPLICATION_HPP_INCLUDE_GUARD


#include "mx/sysdefs.h"

#include "mx/types.h"

#include "mx/App/App.hpp"


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
        fprintf(stderr, "\nError - bad RUN called.\n");
        return RC_FAILURE;
    }

private:

    MX_OVERRIDDEN MX_INLINE ReturnCode OnRun()
    {
        return OnRunTests();
    }

protected:

    virtual ReturnCode OnRunTests();


}; // class TestApp


} // namespace mx


#endif // MXCPP_TEST_APPLICATION_HPP_INCLUDE_GUARD

/* EOF */