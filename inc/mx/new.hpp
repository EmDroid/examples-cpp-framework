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


MXCPP_DLL_EXPORT void * OperatorNewImplementation(
        const Size iMemoryBlockSize,
        const Debug::Checkpoint & xFileInfo,
        const bool bVectorAlloc = false);

MXCPP_DLL_EXPORT void OperatorDeleteImplementation(
        void * const pMemoryBlock,
        const bool bVectorFree = false);


} // namespace mx


// Declaration of memory operator overrides.

inline void * operator new (
        // const doesn't work under some compilers (DMC).
        /* const */ mx::Size iMemoryBlockSize,
        const mx::Debug::Checkpoint::FileName sFileName,
        const mx::Debug::Checkpoint::FileLine iFileLine);

inline void * operator new[] (
        /* const */ mx::Size iMemoryBlockSize,
        const mx::Debug::Checkpoint::FileName sFileName,
        const mx::Debug::Checkpoint::FileLine iFileLine);

inline void operator delete (
        void * pMemoryBlock);

inline void operator delete[] (
        void * pMemoryBlock);

#ifndef MXCPP_FIX_USE_OLD_C_HEADERS

#include <new> // std::bad_alloc

#endif // MXCPP_FIX_USE_OLD_C_HEADERS


// The operators new and delete are always inlined, to allow usage even if the
// framework used as dll. These operators cannot be defined using the DLL
// linkage (under many compilers), so the indirect usage through
// OperatorNewImplementation() and OperatorDeleteImplementation() is used.

inline void * operator new (
        // const doesn't work under some compilers (DMC).
        /* const */ mx::Size iMemoryBlockSize,
        const mx::Debug::Checkpoint::FileName sFileName,
        const mx::Debug::Checkpoint::FileLine iFileLine)
{
    return mx::OperatorNewImplementation(iMemoryBlockSize,
            mx::Debug::Checkpoint(sFileName, iFileLine));
}


inline void * operator new[] (
        /* const */ mx::Size iMemoryBlockSize,
        const mx::Debug::Checkpoint::FileName sFileName,
        const mx::Debug::Checkpoint::FileLine iFileLine)
{
    return mx::OperatorNewImplementation(iMemoryBlockSize,
            mx::Debug::Checkpoint(sFileName, iFileLine), true);
}


inline void operator delete (
        void * pMemoryBlock)
{
    mx::OperatorDeleteImplementation(pMemoryBlock);
}


inline void operator delete[] (
        void * pMemoryBlock)
{
    mx::OperatorDeleteImplementation(pMemoryBlock, true);
}


#ifdef MXCPP_FIX_DELETE_PARAMS_LIKE_NEW

// We do not require this, bu some compilers (MSVC) must have defined
// delete operator with same parameters like new.


inline void operator delete (
        void * pMemoryBlock,
        const mx::Debug::Checkpoint::FileName MX_UNUSED(sFileName),
        const mx::Debug::Checkpoint::FileLine MX_UNUSED(iFileLine))
{
    mx::OperatorDeleteImplementation(pMemoryBlock);
}


inline void operator delete[] (
        void * pMemoryBlock,
        const mx::Debug::Checkpoint::FileName MX_UNUSED(sFileName),
        const mx::Debug::Checkpoint::FileLine MX_UNUSED(iFileLine))
{
    mx::OperatorDeleteImplementation(pMemoryBlock, true);
}


#endif // MXCPP_FIX_DELETE_PARAMS_LIKE_NEW


// Redefine standard new and delete operators.
#include "mx/defs/newdef.hpp"


#endif // MXCPP_NEW_HPP_INCLUDE_GUARD

/* EOF */
