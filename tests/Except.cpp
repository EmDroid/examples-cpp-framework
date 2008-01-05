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

    Exception test.

*/


/* Framework library. */
#include "mx/tests/TestApp.hpp"


/* Application specific. */
#include "mx/Except.hpp"
#include "mx/internal/OutOfMem.hpp"


namespace mx
{


class TestException
    : public ApplicationException
{

    MX_DECLARE_EXCEPTION_CLASS(TestException, ApplicationException);

public:

    MX_INLINE TestException(const char * const sMessage)
        : Super(sMessage)
    {}

};


template< class ExceptionType >
int SingleExceptionTest(const ExceptionType & theException)
{
    // Test framework recommended way of throwing exceptions.
    try
    {
        const ExceptionType e = theException;
        mxThrow(e);
        return EXIT_FAILURE;
    }
    catch (const ExceptionType & e)
    {
        e.WriteMessage(StandardOutput);
    }
    // Check catching as arbitrary exception.
    try
    {
        const ExceptionType e = theException;
        mxThrow(e);
        return EXIT_FAILURE;
    }
    catch (const Exception & e)
    {
        e.WriteMessage(StandardOutput);
    }
    catch (...)
    {
        StandardError.Printf("Weird exception caught in '%s(%u)'\n",
                __FILE__, __LINE__);
        return EXIT_FAILURE;
    }

    // Test throwing exceptions by value, catching by reference.
    try
    {
        const ExceptionType e = theException;
        throw e;
    }
    catch (const ExceptionType & e)
    {
        e.WriteMessage(StandardOutput);
    }
    // Check catching as arbitrary exception.
    try
    {
        const ExceptionType e = theException;
        throw e;
    }
    catch (const Exception & e)
    {
        e.WriteMessage(StandardOutput);
    }
    catch (...)
    {
        StandardError.Printf("Weird exception caught in '%s(%u)'\n",
                __FILE__, __LINE__);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}


} // namespace mx


MX_IMPLEMENT_EXCEPTION_CLASS(mx::TestException);


MX_INLINE const char * mx::TestApp::SetTestName()
{
    return "Exception";
}


mx::TestApp::ReturnCode mx::TestApp::OnRunTests()
{

    /* Testing some standard exception. */

    if (EXIT_SUCCESS != SingleExceptionTest(EndOfFile()))
    {
        return RC_FAILURE;
    }


    /* Testing some non-standard exception. */

    if (EXIT_SUCCESS != SingleExceptionTest(
                OutOfMemory((Size) - 1)))
    {
        return RC_FAILURE;
    }


    /* Check exception re-throwing. */

    // Test framework recommended way of throwing exceptions.
    try
    {
        try
        {
            mxThrow(EndOfFile());
            return RC_FAILURE;
        }
        catch (const Exception &)
        {
            throw;
        }
        catch (...)
        {
            StandardError.Printf("Weird exception caught in '%s(%u)'\n",
                    __FILE__, __LINE__);
            return RC_FAILURE;
        }
    }
    catch (const Exception & e)
    {
        e.WriteMessage(StandardOutput);
    }
    catch (...)
    {
        StandardError.Printf("Weird exception caught in '%s(%u)'\n",
                __FILE__, __LINE__);
        return RC_FAILURE;
    }

    // Test throwing exceptions by value, catching by reference.
    try
    {
        try
        {
            throw EndOfFile();
        }
        catch (const Exception &)
        {
            throw;
        }
        catch (...)
        {
            StandardError.Printf("Weird exception caught in '%s(%u)'\n",
                    __FILE__, __LINE__);
            return RC_FAILURE;
        }
    }
    catch (const Exception & e)
    {
        e.WriteMessage(StandardOutput);
    }
    catch (...)
    {
        StandardError.Printf("Weird exception caught in '%s(%u)'\n",
                __FILE__, __LINE__);
        return RC_FAILURE;
    }


    /* Check application-defined exception. */

    if (EXIT_SUCCESS != SingleExceptionTest(
                TestException("Test message")))
    {
        return RC_FAILURE;
    }


    /* Uncomment following line to check uncaught exception handler. */
//    mxThrow(EndOfFile());

    return RC_SUCCESS;
}


MX_IMPLEMENT_APP(mx::TestApp)


/* EOF */
