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
    @internal

    @file

    Global new and delete operators (interface).

    @author Emil Maskovsky
*/


#ifndef MXCPP_SYSDEFS
#include "mx/sysdefs.hpp"
#endif


#ifndef MXCPP_NEW_HPP_INCLUDE_GUARD
#define MXCPP_NEW_HPP_INCLUDE_GUARD


#ifndef MXCPP_TYPES
#include "mx/types.hpp"
#endif

#include "mx/Except.hpp"


namespace mx
{


/**
    Allocation operators real implementations.
*/
class MXCPP_DLL_EXPORT AllocOperatorsImplementation
{

    MX_CLASS_NO_COPY(AllocOperatorsImplementation);
    MX_CLASS_NO_ASSIGNMENT(AllocOperatorsImplementation);

public:

    static MX_INLINE void * New(
            const Size iMemoryBlockSize,
            const Debug::Checkpoint & xFileInfo,
            const bool bVectorAlloc = false);

    static MX_INLINE void Delete(
            void * const pMemoryBlock,
            const bool bVectorFree = false);

}; // class AllocOperatorsImplementation


} // namespace mx


// The operators new and delete are always inlined, to allow usage even if the
// framework used as dll. These operators cannot be defined using the DLL
// linkage (under many compilers), therefore the indirect usage through
// OperatorNewImplementation() and OperatorDeleteImplementation() is used.

/**
    Global @c operator @c new.

    The global @c new operator is re-defined by the library to use the
    @project memory handling mechanism.

    We define this @c new operator to provide some extra information into the
    memory allocation process. This is used in combination with the exception
    system to allow tracing of memory related problems.

    @param [in] iSize     Number of bytes to allocate.
    @param [in] sFileName The source file name.
    @param [in] nFileLine The source line number.

    @exception MemoryException
    Memory allocation problem occured.

    This override of @c operator @c new is used along with the #new macro.

    @see macro #new
*/
inline void * operator new (
        // const doesn't work under some compilers (DMC).
        /* const */ mx::Size iSize,
        // There is problem using Debug::Checkpoint directly under some
        // compilers.
        const mx::Debug::Checkpoint::FileName sFileName,
        const mx::Debug::Checkpoint::FileLine nFileLine)
{
    return mx::AllocOperatorsImplementation::New(iSize,
            mx::Debug::Checkpoint(sFileName, nFileLine));
}


/**
    Global array @c operator @c new.

    The global @c new[] operator is re-defined by the library to use the
    @project memory handling mechanism.

    We define this @c new[] operator to provide some extra information into the
    memory allocation process. This is used in combination with the exception
    system to allow tracing of memory related problems.

    @param [in] iSize     Number of bytes to allocate.
    @param [in] sFileName The source file name.
    @param [in] nFileLine The source line number.

    @exception MemoryException
    Memory allocation problem occured.

    This override of @c operator @c new is used along with the #new macro.

    @see macro #new
*/
inline void * operator new[] (
        /* const */ mx::Size iSize,
        const mx::Debug::Checkpoint::FileName sFileName,
        const mx::Debug::Checkpoint::FileLine nFileLine)
{
    return mx::AllocOperatorsImplementation::New(iSize,
            mx::Debug::Checkpoint(sFileName, nFileLine), true);
}


/**
    Global @c operator @c delete.

    The global @c delete operator is re-defined by the library to use the
    @project memory handling mechanism.

    @param [in] pMemoryBlock The address of allocated memory block to be deleted.
*/
inline void operator delete (void * pMemoryBlock)
throw()
{
    mx::AllocOperatorsImplementation::Delete(pMemoryBlock);
}


/**
    Global array @c operator @c delete.

    The global @c delete[] operator is re-defined by the library to use the
    @project memory handling mechanism.

    @param [in] pMemoryBlock The address of allocated memory block to be deleted.
*/
inline void operator delete[] (void * pMemoryBlock)
throw()
{
    mx::AllocOperatorsImplementation::Delete(pMemoryBlock, true);
}


#ifdef MXCPP_FIX_DELETE_PARAMS_LIKE_NEW

// We do not require this, but some compilers (MSVC) must have defined
// delete operator with same parameters like new.


inline void operator delete (
        void * pMemoryBlock,
        const mx::Debug::Checkpoint::FileName MX_UNUSED(sFileName),
        const mx::Debug::Checkpoint::FileLine MX_UNUSED(nFileLine))
{
    mx::AllocOperatorsImplementation::Delete(pMemoryBlock);
}


inline void operator delete[] (
        void * pMemoryBlock,
        const mx::Debug::Checkpoint::FileName MX_UNUSED(sFileName),
        const mx::Debug::Checkpoint::FileLine MX_UNUSED(nFileLine))
{
    mx::AllocOperatorsImplementation::Delete(pMemoryBlock, true);
}


#endif // MXCPP_FIX_DELETE_PARAMS_LIKE_NEW


// Redefine standard new and delete operators.
#include "mx/defs/newdef.hpp"


// Define inline methods here if inlining is enabled.
#ifdef MX_INLINE_ENABLED
#include "mx/new.inl"
#endif

#endif // MXCPP_NEW_HPP_INCLUDE_GUARD

/* EOF */
