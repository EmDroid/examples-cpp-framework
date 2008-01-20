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

    Entry point handling (interface).

    @author Emil Maskovsky
*/


#ifndef MXCPP_ENTRY_H_INCLUDE_GUARD
#define MXCPP_ENTRY_H_INCLUDE_GUARD


#include "mx/sysdefs.h"

#include "mx/types.h"


#ifdef __cplusplus
extern "C" {
#endif


typedef int (* mxFuncMainA)(int argv, char ** argc);

int mxMainA(int argv, char * argc[]);


MXCPP_DLL_EXPORT int mxEntryMainA(
        const mxFuncMainA pMainFunc,
        int argc,
        char * argv[]);


#ifdef __cplusplus
}
#endif


/* Redefine standard entry routines, to use library handling. */

#ifdef __cplusplus
#define MXCPP_MAIN_EXTERN  extern "C"
#else
#define MXCPP_MAIN_EXTERN  extern
#endif


#define MXCPP_MAIN_PREVIOUS  main

#ifdef main
#undef main
#endif

#define main                                      \
                                                  \
    MXCPP_MAIN_PREVIOUS(int argc, char * argv[])  \
    {                                             \
        return mxEntryMainA(mxMainA, argc, argv); \
    }                                             \
                                                  \
    MXCPP_MAIN_EXTERN                             \
    int mxMainA


/*
#ifdef WinMain
#undef WinMain
#endif

#define WinMain
 */


#endif /* MXCPP_ENTRY_H_INCLUDE_GUARD */

/* EOF */
