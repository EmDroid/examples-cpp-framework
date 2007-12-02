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

    Memory handling for pure ANSI C (implementation).

    @author Emil Maskovsky
*/


/* Framework libraries. */
#include "mx.h"


/* Application specific. */
#include "mx/malloc.h"
#include "mx/Memory.hpp"


extern "C" {


MXCPP_DLL_EXPORT void * mxAllocateMemory(
        const mxSize iSizeRequested,
        const char * const sFileName,
        const mxSize iFileLine)
{
    return mx::Memory::Allocate(
            iSizeRequested, sFileName, iFileLine);
}


MXCPP_DLL_EXPORT void * mxReallocateMemory(
        void * const pMemoryBlock,
        const mxSize iSizeRequested,
        const char * const sFileName,
        const mxSize iFileLine)
{
    return mx::Memory::Reallocate(
            pMemoryBlock, iSizeRequested, sFileName, iFileLine);
}


MXCPP_DLL_EXPORT void mxFreeMemory(
        void * const pMemoryBlock)
{
    mx::Memory::Free(pMemoryBlock);
}


} // extern "C"


/* EOF */
