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

#ifdef calloc
#undef calloc
#endif

#ifdef realloc
#undef realloc
#endif

#ifdef free
#undef free
#endif


/**
    Allocate memory.

    Allocates a memory block of at least @p iSize bytes. The block may be larger
    than @p iSize bytes because of space required for alignment and maintenance
    information.

    @param [in] iSize         Number of bytes to allocate.
    @param [in] xFileLocation Source file location information (for debugging
                              purposes).

    @return
    The address of allocated memory block.

    @retval NULL The return value is @c NULL, if the @p iSize is zero. If the
                 @p iSize is not zero and the allocation cannot be done because
                 of insufficient memory space, the MemoryException will be
                 caught.

    @exception MemoryException
    Memory allocation problem occured.

    @see Reallocate()
    @see Free()
*/
/* static */ void * mx::Memory::AllocateImpl(
        const Size iSize,
        const Debug::Checkpoint & xFileLocation)
{
    if (!iSize)
    {
        // Warn about allocation of 0 bytes.
        mx::Log(mx::Log::LOG_Trace, xFileLocation).LogTrace(
                mx::Log::TRACE_Memory, mx::Log::LEVEL_Normal,
                _("Requested allocation of 0 bytes!"));
        return NULL;
    }
    void * const block = malloc(iSize);
    if (!block)
    {
        ThrowException(OutOfMemory(iSize), xFileLocation);
    }
    return block;
}


/**
    Reallocate memory.

    Reallocates a memory block (@p pMemoryBlock) that was previously allocated by
    a call to Allocate() or Reallocate().

    @param [in] pMemoryBlock  The address of previously allocated memory block.
    @param [in] iSize         New size in bytes.
    @param [in] xFileLocation Source file location information (for debugging
                              purposes).

    @note
    If the @p pMemoryBlock is @c NULL, Reallocate() behaves the same way as
    Allocate() and allocates a new block of @p iSize bytes.

    @note
    If the @p pMemoryBlock is not @c NULL, it should be a pointer returned by
    a previous call to Allocate() or Reallocate().

    @warning
    Do not ever try to reallocate pointer returned by AllocateOnStack()!

    @warning
    Attempting to reallocate an invalid pointer (a pointer to a memory block that
    was not allocated by Allocate() or Reallocate()) may affect subsequent
    allocation requests and cause errors.

    @return
    The address of reallocated (and possibly moved) memory block.

    @retval NULL The return value is @c NULL, if the @p iSize is zero. In that
                 case the @p pMemoryBlock will be freed. If the @p iSize is not
                 zero and the allocation cannot be done because of insufficient
                 memory space, the MemoryException will be caught.

    @exception MemoryException
    Memory allocation problem occured.

    @see Allocate()
    @see Free()
*/
/* static */ void * mx::Memory::ReallocateImpl(
        void * const pMemoryBlock,
        const Size iSize,
        const Debug::Checkpoint & xFileLocation)
{
    if (!pMemoryBlock)
    {
        // Warn about reallocation of NULL pointer.
        mx::Log(mx::Log::LOG_Trace, xFileLocation).LogTrace(
                mx::Log::TRACE_Memory, mx::Log::LEVEL_Normal,
                _("Requested reallocation of NULL pointer!"));
    }
    if (!iSize)
    {
        // Warn about allocation of 0 bytes.
        mx::Log(mx::Log::LOG_Trace, xFileLocation).LogTrace(
                mx::Log::TRACE_Memory, mx::Log::LEVEL_Normal,
                _("Requested allocation of 0 bytes!"));
        if (pMemoryBlock)
        {
            // Avoid the message about freeing NULL pointer.
            FreeImpl(pMemoryBlock, xFileLocation);
        }
        return NULL;
    }
    void * const block = realloc(pMemoryBlock, iSize);
    if (!block)
    {
        ThrowException(OutOfMemory(iSize), xFileLocation);
    }
    return block;
}


/**
    Free memory.

    Deallocates a memory block (@p pMemoryBlock) that was previously allocated by
    a call to Allocate() or Reallocate(). The number of bytes freed is equivalent
    to the number of bytes requested when the block was allocated (or
    reallocated, in the case of Reallocate()).

    @param [in] pMemoryBlock The address of allocated memory block to be freed.
    @param [in] xFileLocation Source file location information (for debugging
                              purposes).

    @note
    If @p pMemoryBlock is @c NULL, the pointer is ignored and Free() returns
    immediately.

    @note
    If the @p pMemoryBlock is not @c NULL, it should be a pointer returned by
    a previous call to Allocate() or Reallocate().

    @warning
    Do not ever try to free pointer returned by AllocateOnStack()!

    @warning
    Attempting to free an invalid pointer (a pointer to a memory block that
    was not allocated by Allocate() or Reallocate()) may affect subsequent
    allocation requests and cause errors.

    @see Allocate()
    @see Reallocate()
*/
/* static */ void mx::Memory::FreeImpl(
        void * const pMemoryBlock,
        const Debug::Checkpoint & xFileLocation)
{
    if (!pMemoryBlock)
    {
        // Warn about de-allocation of NULL pointer.
        mx::Log(mx::Log::LOG_Trace, xFileLocation).LogTrace(
                mx::Log::TRACE_Memory, mx::Log::LEVEL_Normal,
                _("Requested deallocation of NULL pointer!"));
    }
    free(pMemoryBlock);
}


// Define inline methods here if inlining is disabled.
#ifndef MX_INLINE_ENABLED
#include "mx/Memory.inl"
#endif

/* EOF */
