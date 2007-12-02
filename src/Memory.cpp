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

    Memory handling base (implementation).

    @author Emil Maskovsky
*/


/* Framework libraries. */
#include "mx.h"


/* Application specific. */
#include "mx/Memory.hpp"
#include "mx/internal/OutOfMem.hpp"


#ifdef Allocate
#undef Allocate
#endif

#ifdef Reallocate
#undef Reallocate
#endif

#ifdef Free
#undef Free
#endif


#ifdef malloc
#undef malloc
#endif

#ifdef realloc
#undef realloc
#endif

#ifdef free
#undef free
#endif


/* static */ void * mx::Memory::Allocate(
        const Size iSizeRequested,
        const char * const sFileName,
        const Size iFileLine)
{
    if (0 == iSizeRequested)
    {
        return NULL;
    }
    void * const block = malloc(iSizeRequested);
    if (!block)
    {
        ThrowException(OutOfMemory(iSizeRequested), sFileName, iFileLine);
    }
    return block;
}


/* static */ void * mx::Memory::Reallocate(
        void * const pMemoryBlock,
        const Size iSizeRequested,
        const char * const sFileName,
        const Size iFileLine)
{
    void * const block = realloc(pMemoryBlock, iSizeRequested);
    if (!block)
    {
        ThrowException(OutOfMemory(iSizeRequested), sFileName, iFileLine);
    }
    return block;
}


/* static */ void mx::Memory::Free(
        void * const pMemoryBlock)
{
    free(pMemoryBlock);
}


// Define inline methods here if inlining is disabled.
#ifndef MX_INLINE_ENABLED
#include "mx/Memory.inl"
#endif

/* EOF */
