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


#ifndef MXCPP_MEMORY_HPP_INCLUDE_GUARD
#define MXCPP_MEMORY_HPP_INCLUDE_GUARD


#ifndef MXCPP_TYPES
#include "mx/types.hpp"
#endif

#include "mx/Except.hpp"


namespace mx
{

/**
    Basic memory manipulations.
*/
class MXCPP_DLL_EXPORT Memory
{

    MX_CLASS_NO_COPY(Memory);
    MX_CLASS_NO_ASSIGNMENT(Memory);

// Class methods (static).

public:

    static void * AllocateImpl(
            const Size iSizeRequested,
            const Debug::Checkpoint & xFileLocation);

    static void * ReallocateImpl(
            void * const pMemoryBlock,
            const Size iSizeRequested,
            const Debug::Checkpoint & xFileLocation);

    static void FreeImpl(
            void * const pMemoryBlock,
            const Debug::Checkpoint & xFileLocation);


}; // class Memory


} // namespace mx


// Convenience macros.

#ifdef Allocate
#undef Allocate
#endif

#define Allocate(size) \
    AllocateImpl(size, __mxDebugCheckpoint__())


#ifdef Reallocate
#undef Reallocate
#endif

#define Reallocate(block, size) \
    ReallocateImpl(block, size, __mxDebugCheckpoint__())


#ifdef Free
#undef Free
#endif

#define Free(block) \
    FreeImpl(block, __mxDebugCheckpoint__())


// Replade standard ANSI-C memory allocation functions.

#ifdef malloc
#undef malloc
#endif

#define malloc(size)  mx::Memory::Allocate(size)


#ifdef realloc
#undef realloc
#endif

#define realloc(block, size)  mx::Memory::Reallocate(block, size)


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
