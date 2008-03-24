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
    @fn mx::Memory::Allocate(Size)

    Allocate memory block.

    Allocates a memory block of at least @p iSize bytes. The block may be larger
    than @p iSize bytes because of space required for alignment and maintenance
    information.

    @param [in] iSize Number of bytes to allocate.

    @note
    In regular cases, you should use the new C++ style operators
    @c new or @c new[] for dynamic allocation (and @c delete or @c delete[]
    operators for de-allocation).

    @return
    The address of allocated memory block.

    @retval NULL The return value is @c NULL, if the @p iSize is zero. If the
                 @p iSize is not zero and the allocation cannot be done because
                 of insufficient memory space, the MemoryException will be
                 caught.

    @exception MemoryException
    Memory allocation problem occured.

    @see Memory::Reallocate(), Memory::Free()

    @internal

    @note
    The Memory::Allocate() is in the fact "fake" method, which is not really
    implemented, and with cooperation of the macro Allocate() it is remaped to
    the Memory::AllocateImpl() method.
    But we define this method to provide it along with the Memory interface, to
    allow e.g. code completation when used.

    @see Allocate(), Memory::AllocateImpl()
*/

/**
    @fn mx::Memory::Reallocate(void *, Size)

    Reallocate memory block.

    Reallocates a memory block (@p pMemoryBlock) that was previously allocated by
    a call to Memory::Allocate() or Memory::Reallocate().

    @param [in] pMemoryBlock The address of previously allocated memory block.
    @param [in] iSize        New size in bytes.

    @note
    If the @p pMemoryBlock is @c NULL, Memory::Reallocate() behaves the same way
    as Memory::Allocate() and allocates a new block of @p iSize bytes.

    @note
    If the @p pMemoryBlock is not @c NULL, it should be a pointer returned by
    a previous call to Memory::Allocate() or Memory::Reallocate().

    @warning
    Do not ever try to reallocate pointer returned by Memory::AllocateOnStack()!

    @warning
    Attempting to reallocate an invalid pointer (a pointer to a memory block that
    was not allocated by Memory::Allocate() or Memory::Reallocate()) may affect
    subsequent allocation requests and cause errors.

    @return
    The address of reallocated (and possibly moved) memory block.

    @retval NULL The return value is @c NULL, if the @p iSize is zero. In that
                 case the @p pMemoryBlock will be freed. If the @p iSize is not
                 zero and the allocation cannot be done because of insufficient
                 memory space, the MemoryException will be caught.

    @exception MemoryException
    Memory allocation problem occured.

    @see Memory::Allocate(), Memory::Free()

    @internal

    @note
    The Memory::Reallocate() is in the fact "fake" method, which is not really
    implemented, and with cooperation of the macro Reallocate() it is remaped to
    the Memory::ReallocateImpl() method.
    But we define this method to provide it along with the Memory interface, to
    allow e.g. code completation when used.

    @see Reallocate(), Memory::ReallocateImpl()
*/

/**
    @fn mx::Memory::Free(void *)

    Free memory block.

    Deallocates a memory block (@p pMemoryBlock) that was previously allocated by
    a call to Memory::Allocate() or Memory::Reallocate(). The number of bytes
    freed is equivalent to the number of bytes requested when the block was
    allocated (or reallocated, in the case of Memory::Reallocate()).

    @param [in] pMemoryBlock The address of allocated memory block to be freed.

    @note
    If @p pMemoryBlock is @c NULL, the pointer is ignored and Memory::Free()
    returns immediately.

    @note
    If the @p pMemoryBlock is not @c NULL, it should be a pointer returned by
    a previous call to Memory::Allocate() or Memory::Reallocate().

    @warning
    Do not ever try to free pointer returned by Memory::AllocateOnStack()!

    @warning
    Attempting to free an invalid pointer (a pointer to a memory block that
    was not allocated by Memory::Allocate() or Memory::Reallocate()) may affect
    subsequent allocation requests and cause errors.

    @see Memory::Allocate(), Memory::Reallocate()

    @internal

    @note
    The Memory::Free() is in the fact "fake" method, which is not really
    implemented, and with cooperation of the macro Free() it is remaped to
    the Memory::FreeImpl() method.
    But we define this method to provide it along with the Memory interface, to
    allow e.g. code completation when used.

    @see Free(), Memory::FreeImpl()
*/


namespace mx
{


/**
    Memory handler.
*/
class MemoryHandler
{

    MX_CLASS_NO_COPY(MemoryHandler);
    MX_CLASS_NO_ASSIGNMENT(MemoryHandler);

// Class methods (static).

public:

    static void * Allocate(
            const Size iSize,
            const Debug::Checkpoint & xFileLocation = Debug::Checkpoint());

    static void * Reallocate(
            void * const pMemoryBlock,
            const Size iSize,
            const Debug::Checkpoint & xFileLocation = Debug::Checkpoint());

    static void Free(
            void * const pMemoryBlock,
            const Debug::Checkpoint & xFileLocation = Debug::Checkpoint());


}; // class MemoryHandler


} // namespace mx


/**
    @internal

    Allocate memory block (the real worker).

    This worker is used to provide extra debugging information to the memory
    handling operations.

    @param [in] iSize         Number of bytes to allocate.
    @param [in] xFileLocation Source file location information (for debugging
                              purposes).

    @note
    This method is not to be used directly, it is designed to work along with the
    "fake" method Memory::Allocate() and the macro Allocate().

    @return
    See Memory::Allocate() for description of return values.

    @see Memory::Allocate(), Allocate()
    @see ReallocateImpl(), FreeImpl()
*/
/* static */ void * mx::Memory::AllocateImpl(
        const Size iSize,
        const Debug::Checkpoint & xFileLocation)
{
    return MemoryHandler::Allocate(iSize, xFileLocation);
}


/**
    @internal

    Reallocate memory block (the real worker).

    This worker is used to provide extra debugging information to the memory
    handling operations.

    @param [in] pMemoryBlock  The address of previously allocated memory block.
    @param [in] iSize         New size in bytes.
    @param [in] xFileLocation Source file location information (for debugging
                              purposes).

    @note
    This method is not to be used directly, it is designed to work along with the
    "fake" method Memory::Reallocate() and the macro Reallocate().

    @return
    See Memory::Reallocate() for description of return values.

    @see Memory::Reallocate(), Reallocate()
    @see AllocateImpl(), FreeImpl()
*/
/* static */ void * mx::Memory::ReallocateImpl(
        void * const pMemoryBlock,
        const Size iSize,
        const Debug::Checkpoint & xFileLocation)
{
    return MemoryHandler::Reallocate(pMemoryBlock, iSize, xFileLocation);
}


/**
    @internal

    Free memory block (the real worker).

    This worker is used to provide extra debugging information to the memory
    handling operations.

    @param [in] pMemoryBlock  The address of allocated memory block to be freed.
    @param [in] xFileLocation Source file location information (for debugging
                              purposes).

    @note
    This method is not to be used directly, it is designed to work along with the
    "fake" method Memory::Free() and the macro Free().

    @return
    See Memory::Free() for description of return values.

    @see Memory::Free(), Free()
    @see AllocateImpl(), ReallocateImpl()
*/
/* static */ void mx::Memory::FreeImpl(
        void * const pMemoryBlock,
        const Debug::Checkpoint & xFileLocation)
{
    MemoryHandler::Free(pMemoryBlock, xFileLocation);
}


/**
    The real implementation of the global @c new operators.


    @param [in] iSize     Number of bytes to allocate.
    @param [in] xFileInfo Source file location information (for debugging
                          purposes).
    @param [in] bVector   Allocated as vector (using the @c new[] operator).
*/
/* static */ void * mx::AllocOperatorsImplementation::New(
        const Size iSize,
        const Debug::Checkpoint & xFileInfo,
        const bool MX_UNUSED(bVector))
{
    return MemoryHandler::Allocate(iSize, xFileInfo);
}


/**
    The real implementation of the global @c delete operators.


    @param [in] pMemoryBlock The address of allocated memory block to be deleted.
    @param [in] xFileInfo    Source file location information (for debugging
                             purposes).
    @param [in] bVector      Deleted as vector (using the @c delete[] operator).
*/
/* static */ void mx::AllocOperatorsImplementation::Delete(
        void * const pMemoryBlock,
        const Debug::Checkpoint & xFileInfo,
        const bool MX_UNUSED(bVector))
{
    MemoryHandler::Free(pMemoryBlock, xFileInfo);
}


/**
    The real implementation of the global @c delete operators.


    @param [in] pMemoryBlock The address of allocated memory block to be deleted.
    @param [in] bVector      Deleted as vector (using the @c delete[] operator).
*/
/* static */ void mx::OperatorDeleteImplementation::Delete(
        void * const pMemoryBlock,
        const bool MX_UNUSED(bVector))
{
    MemoryHandler::Free(pMemoryBlock);
}


/**
    Allocate memory block.

    @param [in] iSize         Number of bytes to allocate.
    @param [in] xFileLocation Source file location information (for debugging
                              purposes).

    @return
    See Memory::Allocate() for description of return values.

    @see Memory::Allocate()
*/
/* static */ void * mx::MemoryHandler::Allocate(
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
    Reallocate memory block.

    @param [in] pMemoryBlock  The address of previously allocated memory block.
    @param [in] iSize         New size in bytes.
    @param [in] xFileLocation Source file location information (for debugging
                              purposes).

    @return
    See Memory::Reallocate() for description of return values.

    @see Memory::Reallocate()
*/
/* static */ void * mx::MemoryHandler::Reallocate(
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
            Free(pMemoryBlock, xFileLocation);
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
    Free memory block.

    @param [in] pMemoryBlock  The address of allocated memory block to be freed.
    @param [in] xFileLocation Source file location information (for debugging
                              purposes).

    @return
    See Memory::Free() for description of return values.

    @see Memory::Free()
*/
/* static */ void mx::MemoryHandler::Free(
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
