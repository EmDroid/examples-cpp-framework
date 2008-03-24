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

    static void * Allocate(
            const Size iSize);

    static void * Reallocate(
            void * const pMemoryBlock,
            const Size iSize);

    static void Free(
            void * const pMemoryBlock);


    static void * AllocateImpl(
            const Size iSize,
            const Debug::Checkpoint & xFileLocation);

    static void * ReallocateImpl(
            void * const pMemoryBlock,
            const Size iSize,
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

/**
    @internal

    Remapping of the Memory::Allocate() to Memory::AllocateImpl().

    This macro ensures, that the call of Memory::Allocate() will call in the fact
    the method Memory::AllocateImpl() with proper debugging information set up.

    @param [in] size Number of bytes to allocate.

    @return
    See Memory::Allocate() for description of return values.

    @see Memory::Allocate(), Memory::AllocateImpl()
*/
#define Allocate(size) \
    AllocateImpl(size, __mxDebugCheckpoint__())


#ifdef Reallocate
#undef Reallocate
#endif

/**
    @internal

    Remapping of the Memory::Reallocate() to Memory::ReallocateImpl().

    This macro ensures, that the call of Memory::Reallocate() will call in the
    fact the method Memory::ReallocateImpl() with proper debugging information set
    up.

    @param [in] block The address of previously allocated memory block.
    @param [in] size  New size in bytes.

    @return
    See Memory::Reallocate() for description of return values.

    @see Memory::Reallocate(), Memory::ReallocateImpl()
*/
#define Reallocate(block, size) \
    ReallocateImpl(block, size, __mxDebugCheckpoint__())


#ifdef Free
#undef Free
#endif

/**
    @internal

    Remapping of the Memory::Free() to Memory::FreeImpl().

    This macro ensures, that the call of Memory::Free() will call in the fact
    the method Memory::FreeImpl() with proper debugging information set up.

    @param [in] block The address of allocated memory block to be freed.

    @return
    See Memory::Free() for description of return values.

    @see Memory::Free(), Memory::FreeImpl()
*/
#define Free(block) \
    FreeImpl(block, __mxDebugCheckpoint__())


// Replade standard ANSI-C memory allocation functions.

#ifdef malloc
#undef malloc
#endif

/**
    Allocate memory block.

    @param [in] size Number of bytes to allocate.

    The standard ANSI-C malloc() function is redefined to be synonym of the
    Memory::Allocate() method.

    @return
    See Memory::Allocate() for description of return values.

    @see Memory::Allocate()
*/
#define malloc(size)  mx::Memory::Allocate(size)


#ifdef realloc
#undef realloc
#endif

/**
    Reallocate memory block.

    @param [in] block The address of previously allocated memory block.
    @param [in] size  New size in bytes.

    The standard ANSI-C realloc() function is redefined to be synonym of the
    Memory::Reallocate() method.

    @return
    See Memory::Reallocate() for description of return values.

    @see Memory::Reallocate()
*/
#define realloc(block, size)  mx::Memory::Reallocate(block, size)


#ifdef free
#undef free
#endif

/**
    Free memory block.

    @param [in] block The address of allocated memory block to be freed.

    The standard ANSI-C free() function is redefined to be synonym of the
    Memory::Free() method.

    @return
    See Memory::Free() for description of return values.

    @see Memory::Free()
*/
#define free(block)  mx::Memory::Free(block)


// Define inline methods here if inlining is enabled.
#ifdef MX_INLINE_ENABLED
#include "mx/Memory.inl"
#endif

#endif // MXCPP_MEMORY_HPP_INCLUDE_GUARD

/* EOF */
