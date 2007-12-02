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

*/


/* System library. */
#include "mx.h"


/* Framework library. */


/* Application specific. */


int main(void)
{
#define TestType  int

    TestType * pIntegers;

    printf("\n\nRunning pure ANSI C tests ...\n\n");
    fflush(stdout);


    /* Testing standard memory allocations. */
    pIntegers = (TestType *)malloc(sizeof(TestType));
    *pIntegers = 10;
    pIntegers = (TestType *)realloc(pIntegers, sizeof(TestType) * 10);
//    assert(*pIntegers == 10);
    free(pIntegers);

    printf("\n\n... tests successfully done.\n");

    return EXIT_SUCCESS;
}


/* EOF */
