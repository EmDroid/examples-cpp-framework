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


// Tests declared in anonymous namespace.
namespace
{


/**
    Testing mx::Exception inheritance.

    This exception is used to check if user-defined mx::Exception based
    exceptions are working.
*/
class TestException
    : public mx::ApplicationException
{

    MX_DECLARE_EXCEPTION_CLASS(TestException, mx::ApplicationException);

public:

    /**
        Constructor.

        @param [in] sMessage The exception message.
    */
    explicit MX_INLINE TestException(const mx::Char * const sMessage)
        : Super(sMessage)
    {}

};


/**
    Testing std::exception inheritance.

    This exception is used to check if user-defined std::exception based
    exceptions are working.
*/
class TestStdException
    : public std::exception
{

public:

    MX_OVERRIDDEN MX_INLINE const char * what() const
    throw()
    {
        return "Testing exception message.";
    }

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
        e.LogMessage(mx::Log::LOG_Message);
    }
    // Check catching as arbitrary exception.
    try
    {
        const ExceptionType e = theException;
        mxThrow(e);
        return EXIT_FAILURE;
    }
    catch (const mx::Exception & e)
    {
        e.LogMessage(mx::Log::LOG_Message);
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
        e.LogMessage(mx::Log::LOG_Message);
    }
    // Check catching as arbitrary exception.
    try
    {
        const ExceptionType e = theException;
        throw e;
    }
    catch (const mx::Exception & e)
    {
        e.LogMessage(mx::Log::LOG_Message);
    }
    catch (...)
    {
        mxLogError(_("Weird exception caught!"));
        return EXIT_FAILURE;
    }

    // Test throwing exceptions by pointer.
    try
    {
        throw new ExceptionType(theException);
    }
    catch (ExceptionType * e)
    {
        e->LogMessage(mx::Log::LOG_Message);
        delete e;
    }
    // Check catching as arbitrary exception.
    try
    {
        throw new ExceptionType(theException);
    }
    catch (mx::Exception * e)
    {
        e->LogMessage(mx::Log::LOG_Message);
        delete e;
    }
    catch (...)
    {
        mxLogError(_("Weird exception caught!"));
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}


} // anonymous namespace


MX_IMPLEMENT_EXCEPTION_CLASS(mx::TestException);


const mx::Char * mx::TestApp::SetTestName()
{
    return _T("Exception");
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

    // Test throwing exceptions by pointer.
    try
    {
        try
        {
            throw new EndOfFile();
        }
        catch (Exception *)
        {
            throw;
        }
        catch (...)
        {
            mxLogError(_("Weird exception caught!"));
            return RC_FAILURE;
        }
    }
    catch (Exception * e)
    {
        e->LogMessage(Log::LOG_Message);
        delete e;
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


    /* Check std::exception based exceptions. */
    // Test throwing exceptions by value, catching by reference.
    try
    {
        throw TestStdException();
    }
    catch (const TestStdException & e)
    {
        Exception::GlobalLogMessage(e, Log::LOG_Message);
    }
    // Check catching as arbitrary exception.
    try
    {
        throw TestStdException();
    }
    catch (const std::exception & e)
    {
        Exception::GlobalLogMessage(e, Log::LOG_Message);
    }
    catch (...)
    {
        mxLogError(_("Weird exception caught!"));
        return RC_FAILURE;
    }

    // Test throwing exceptions by pointer.
    try
    {
        throw new TestStdException();
    }
    catch (TestStdException * e)
    {
        Exception::GlobalLogMessage(*e, Log::LOG_Message);
        delete e;
    }
    // Check catching as arbitrary exception.
    try
    {
        throw new TestStdException();
    }
    catch (std::exception * e)
    {
        Exception::GlobalLogMessage(*e, Log::LOG_Message);
        delete e;
    }
    catch (...)
    {
        mxLogError(_("Weird exception caught!"));
        return RC_FAILURE;
    }


    /* Uncomment following line to check uncaught exception handler. */
//    mxThrow(EndOfFile());

    return RC_SUCCESS;
}


/* EOF */
