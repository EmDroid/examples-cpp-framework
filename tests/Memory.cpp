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

    Memory sybsystem tests.

    @author Emil Maskovsky
*/


/* Framework library. */
#include "mx/tests/TestApp.hpp"


/* Application specific. */
#include "mx/Memory.hpp"


const mx::Char * mx::TestApp::SetTestName()
{
    return _T("Memory");
}


mx::TestApp::ReturnCode mx::TestApp::OnRunTests()
{
    /* Write out size of pointer. */
    mxLogMessage(_T("Size of pointer: %u"),
            static_cast< unsigned int >(sizeof(void *)));
    mxLogMessage(_T("Size of integer: %u"),
            static_cast< unsigned int >(sizeof(int)));
    mxLogMessage(_T("Size of long:    %u"),
            static_cast< unsigned int >(sizeof(long)));

    typedef int TestType;
    TestType * pIntegers;


    /* Testing standard memory allocations. */
    pIntegers = static_cast< TestType * >(malloc(sizeof(TestType)));
    *pIntegers = 10;
    pIntegers
        = static_cast< TestType * >(realloc(pIntegers, sizeof(TestType) * 10));
    mxTest(*pIntegers == 10);
    free(pIntegers);


    /* Testing new and delete. */
    // Normal allocation.
    pIntegers = new TestType;
    *pIntegers = 20;
    delete pIntegers;

    // Array allocation.
    pIntegers = new TestType[50];
    pIntegers[5] = 15;
    delete[] pIntegers;

    return RC_SUCCESS;
}


/* EOF */
