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

    Pure ANSI C tests.

    @author Emil Maskovsky
*/


/* System library. */
#include "mx.h"


/* Framework library. */


/* Application specific. */


int main(int argc, char ** argv)
{
#define TestType  int

    TestType * pIntegers;

    printf("--- Running the [Pure ANSI C] tests ... ---\n");
    fflush(stdout);  /* make sure the message is displayed */

    /* Write out size of pointer. */
    printf("Size of pointer:\t%u\n", sizeof(void *));

    /* Testing standard memory allocations. */
    pIntegers = (TestType *)malloc(sizeof(TestType));
    *pIntegers = 10;
    pIntegers = (TestType *)realloc(pIntegers, sizeof(TestType) * 10);
    mxTest(*pIntegers == 10);
    free(pIntegers);

    printf("--- ... the [Pure ANSI C] tests passed successfully. ---\n");

    return EXIT_SUCCESS;
}


/* EOF */
