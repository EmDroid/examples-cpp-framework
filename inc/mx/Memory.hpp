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

    Memory handling base (interface).

    @author Emil Maskovsky
*/


#ifndef MXCPP_MEMORY_HPP_INCLUDE_GUARD
#define MXCPP_MEMORY_HPP_INCLUDE_GUARD


#include "mx/sysdefs.h"

#include "mx/types.h"


namespace mx
{


class MXCPP_DLL_EXPORT Memory
{

    MX_CLASS_NO_COPY(Memory);
    MX_CLASS_NO_ASSIGNMENT(Memory);

// Class methods (static).

public:

    static void * Allocate(
            const char * const sFileName,
            const Size iFileLine,
            const Size iSizeRequested,
            Size * const iSizeAllocated = NULL);

    static void Free(
            void * const pMemoryBlock);

    static void * Reallocate(
            const char * const sFileName,
            const Size iFileLine,
            void * const pMemoryBlock,
            const Size iSizeRequested,
            Size * const iSizeAllocated = NULL);


}; // class Memory


} // namespace mx


#ifdef Alloc
#undef Alloc
#endif

#define Alloc(size) \
    Allocate(__FILE__, __LINE__, size)


#ifdef AllocRet
#undef AllocRet
#endif

#define AllocRet(size, allocated) \
    Allocate(__FILE__, __LINE__, size, allocated)


#ifdef Realloc
#undef Realloc
#endif

#define Realloc(block, size) \
    Reallocate(__FILE__, __LINE__, block, size)


#ifdef ReallocRet
#undef ReallocRet
#endif

#define ReallocRet(block, size, allocated) \
    Reallocate(__FILE__, __LINE__, block, size, allocated)


#ifdef Free
#undef Free
#endif


#ifdef malloc
#undef malloc
#endif

#define malloc(size)  mx::Memory::Alloc(size)


#ifdef realloc
#undef realloc
#endif

#define realloc(block, size)  mx::Memory::Realloc(block, size)


#ifdef free
#undef free
#endif

#define free(block)  mx::Memory::Free(size)


// Define inline methods here if inlining is enabled.
#ifdef MX_INLINE_ENABLED
#include "mx/Memory.inl"
#endif

#endif // MXCPP_MEMORY_HPP_INCLUDE_GUARD

/* EOF */
