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

    Memory handling for pure ANSI C (interface).

    @author Emil Maskovsky
*/


#ifndef MXCPP_MALLOC_H_INCLUDE_GUARD
#define MXCPP_MALLOC_H_INCLUDE_GUARD


#include "mx/sysdefs.h"

#include "mx/types.h"


/* Redefine standard memory operations, to use library memory handling. */

#ifdef malloc
#undef malloc
#endif

#define malloc(size)  mxMalloc(size)


#ifdef realloc
#undef realloc
#endif

#define realloc(block, size)  mxRealloc(block, size)


#ifdef free
#undef free
#endif

#define free(block)  mxFree(block)


/* Macros for convenient usage of functions supplied by the library. */

#define mxMalloc(size) \
    mxAllocateMemory(size, __FILE__, __LINE__)

#define mxRealloc(block, size) \
    mxReallocateMemory(block, size, __FILE__, __LINE__)

#define mxFree(block) \
    mxFreeMemory(block)


/* Library memory handling functions supplied for pure ANSI C. */

#ifdef __cplusplus
extern "C" {
#endif


MXCPP_DLL_EXPORT void * mxAllocateMemory(
        const mxSize iSizeRequested,
        const char * const sFileName,
        const mxSize iFileLine);

MXCPP_DLL_EXPORT void * mxReallocateMemory(
        void * const pMemoryBlock,
        const mxSize iSizeRequested,
        const char * const sFileName,
        const mxSize iFileLine);

MXCPP_DLL_EXPORT void mxFreeMemory(
        void * const pMemoryBlock);


#ifdef __cplusplus
}
#endif


#endif /* MXCPP_MALLOC_H_INCLUDE_GUARD */

/* EOF */
