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


#ifndef MXCPP_SYSDEFS
#include "mx/sysdefs.hpp"
#endif

#ifndef MXCPP_TYPES
#include "mx/types.hpp"
#endif


#ifndef MXCPP_MEMORY_HPP_INCLUDE_GUARD
#define MXCPP_MEMORY_HPP_INCLUDE_GUARD


#include "mx/Except.hpp"


namespace mx
{

/**
    Class for basic memory manipulations.
*/
class MXCPP_DLL_EXPORT Memory
{

    MX_CLASS_NO_COPY(Memory);
    MX_CLASS_NO_ASSIGNMENT(Memory);

// Class methods (static).

public:

    static void * Allocate(
            const Size iSizeRequested,
            const Debug::Checkpoint & xFileInfo);

    static void * Reallocate(
            void * const pMemoryBlock,
            const Size iSizeRequested,
            const Debug::Checkpoint & xFileInfo);

    static void Free(
            void * const pMemoryBlock);


}; // class Memory


} // namespace mx


// Convenience macros.

#ifdef Alloc
#undef Alloc
#endif

#define Alloc(size) \
    Allocate(size, mxDebugCheckpoint())


#ifdef Realloc
#undef Realloc
#endif

#define Realloc(block, size) \
    Reallocate(block, size, mxDebugCheckpoint())


#ifdef Free
#undef Free
#endif


// Replade standard ANSI-C memory allocation functions.

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

#define free(block)  mx::Memory::Free(block)


// Define inline methods here if inlining is enabled.
#ifdef MX_INLINE_ENABLED
#include "mx/Memory.inl"
#endif

#endif // MXCPP_MEMORY_HPP_INCLUDE_GUARD

/* EOF */
