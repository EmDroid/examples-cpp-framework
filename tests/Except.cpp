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


void LogTest()
{
    mxLogWarning(_T("Some warning."));
    const char * const pString = "Some string.";
    mxAssert(pString != NULL);
    mxLogTrace(mx::Log::TRACE_User, mx::Log::LEVEL_Normal,
            _T("Tracing - file: %s(%u)"),
            __FILE__, __LINE__);
}


namespace mx
{


/**
    Testing exception.

    This exception is used to check if user-defined exceptions are working.
*/
class TestException
    : public ApplicationException
{

    MX_DECLARE_EXCEPTION_CLASS(TestException, ApplicationException);

public:

    MX_INLINE TestException(const Char * const sMessage)
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
        e.LogMessage(Log::LOG_Message);
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
        e.LogMessage(Log::LOG_Message);
    }
    catch (...)
    {
        mxLogError(_("Weird exception caught!"));
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
        e.LogMessage(Log::LOG_Message);
    }
    // Check catching as arbitrary exception.
    try
    {
        const ExceptionType e = theException;
        throw e;
    }
    catch (const Exception & e)
    {
        e.LogMessage(Log::LOG_Message);
    }
    catch (...)
    {
        mxLogError(_("Weird exception caught!"));
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}


} // namespace mx


MX_IMPLEMENT_EXCEPTION_CLASS(mx::TestException);


const mx::Char * mx::TestApp::SetTestName()
{
    return _T("Exception");
}


mx::TestApp::ReturnCode mx::TestApp::OnRunTests()
{
    LogTest();

    /* Testing some standard exception. */

    if (EXIT_SUCCESS != SingleExceptionTest(EndOfFile()))
    {
        return RC_FAILURE;
    }

    /* Testing some non-standard exception. */

    if (EXIT_SUCCESS != SingleExceptionTest(
                OutOfMemory(10)))
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
        }
        catch (const Exception &)
        {
            throw;
        }
        catch (...)
        {
            mxLogError(_("Weird exception caught!"));
            return RC_FAILURE;
        }
    }
    catch (const Exception & e)
    {
        e.LogMessage(Log::LOG_Message);
    }
    catch (...)
    {
        mxLogError(_("Weird exception caught!"));
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
            mxLogError(_("Weird exception caught!"));
            return RC_FAILURE;
        }
    }
    catch (const Exception & e)
    {
        e.LogMessage(Log::LOG_Message);
    }
    catch (...)
    {
        mxLogError(_("Weird exception caught!"));
        return RC_FAILURE;
    }


    /* Check application-defined exception. */

    if (EXIT_SUCCESS != SingleExceptionTest(
                TestException(_T("Test message"))))
    {
        return RC_FAILURE;
    }


    /* Uncomment following line to check uncaught exception handler. */
//    mxThrow(EndOfFile());

    return RC_SUCCESS;
}


MX_IMPLEMENT_APP(mx::TestApp)


/* EOF */
