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


/* System library. */
#include "mx.h"


/* Framework library. */
#include "mx/internal/OutOfMem.hpp"


/* Application specific. */


namespace mx
{

namespace test
{


class TestException
    : public ApplicationException
{

    MX_DECLARE_EXCEPTION_CLASS(TestException, ApplicationException);

public:

    MX_INLINE TestException()
    {}

};


MX_IMPLEMENT_EXCEPTION_CLASS(TestException);


int RunTest()
{
    /* Testing some standard exception. */

    // Test framework recommended way of throwing exceptions.
    try
    {
        mxThrow(EndOfFile());
        return EXIT_FAILURE;
    }
    catch (const EndOfFile & e)
    {
        e.WriteMessage(stdout);
    }
    // Check catching as arbitrary exception.
    try
    {
        mxThrow(EndOfFile());
        return EXIT_FAILURE;
    }
    catch (const Exception & e)
    {
        e.WriteMessage(stdout);
    }
    catch (...)
    {
        fprintf(stderr, "Weird exception caught in '%s(%lu)'\n",
                __FILE__, __LINE__);
        return EXIT_FAILURE;
    }

    // Test throwing exceptions by value, catching by reference.
    try
    {
        throw EndOfFile();
        return EXIT_FAILURE;
    }
    catch (const EndOfFile & e)
    {
        e.WriteMessage(stdout);
    }
    // Check catching as arbitrary exception.
    try
    {
        throw EndOfFile();
        return EXIT_FAILURE;
    }
    catch (const Exception & e)
    {
        e.WriteMessage(stdout);
    }
    catch (...)
    {
        fprintf(stderr, "Weird exception caught in '%s(%lu)'\n",
                __FILE__, __LINE__);
        return EXIT_FAILURE;
    }


    /* Testing some non-standard exception. */

    // Test framework recommended way of throwing exceptions.
    try
    {
        mxThrow(OutOfMemory((Size) - 1, __FILE__, __LINE__));
        return EXIT_FAILURE;
    }
    catch (const OutOfMemory & e)
    {
        e.WriteMessage(stdout);
    }
    // Check catching as arbitrary exception.
    try
    {
        mxThrow(OutOfMemory((Size) - 1, __FILE__, __LINE__));
        return EXIT_FAILURE;
    }
    catch (const Exception & e)
    {
        e.WriteMessage(stdout);
    }
    catch (...)
    {
        fprintf(stderr, "Weird exception caught in '%s(%lu)'\n",
                __FILE__, __LINE__);
        return EXIT_FAILURE;
    }

    // Test throwing exceptions by value, catching by reference.
    try
    {
        throw OutOfMemory((Size) - 1, __FILE__, __LINE__);
        return EXIT_FAILURE;
    }
    catch (const OutOfMemory & e)
    {
        e.WriteMessage(stdout);
    }
    // Check catching as arbitrary exception.
    try
    {
        throw OutOfMemory((Size) - 1, __FILE__, __LINE__);
        return EXIT_FAILURE;
    }
    catch (const Exception & e)
    {
        e.WriteMessage(stdout);
    }
    catch (...)
    {
        fprintf(stderr, "Weird exception caught in '%s(%lu)'\n",
                __FILE__, __LINE__);
        return EXIT_FAILURE;
    }


    /* Check exception re-throwing. */
    try
    {
        try
        {
            mxThrow(EndOfFile());
            return EXIT_FAILURE;
        }
        catch (const Exception &)
        {
            throw;
        }
        catch (...)
        {
            fprintf(stderr, "Weird exception caught in '%s(%lu)'\n",
                    __FILE__, __LINE__);
            return EXIT_FAILURE;
        }
    }
    catch (const Exception & e)
    {
        e.WriteMessage(stdout);
    }
    catch (...)
    {
        fprintf(stderr, "Weird exception caught in '%s(%lu)'\n",
                __FILE__, __LINE__);
        return EXIT_FAILURE;
    }

    /* Uncomment following line to check uncaught exception handler. */
//    mxThrow(EndOfFile());

    return EXIT_SUCCESS;
}


} // namespace mx::test

} // namespace mx


int main(void)
{
    return mx::test::RunTest();
}


/* EOF */
