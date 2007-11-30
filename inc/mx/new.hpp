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


#ifndef MXCPP_NEW_HPP_INCLUDE_GUARD
#define MXCPP_NEW_HPP_INCLUDE_GUARD


#include "mx/sysdefs.h"

#include "mx/types.h"


namespace mx
{


MXCPP_DLL_EXPORT void * OperatorNewImplementation(
        const Size iMemoryBlockSize,
        const char * const sFileName,
        const Size iFileLine,
        const bool bVectorAlloc = false);

MXCPP_DLL_EXPORT void OperatorDeleteImplementation(
        void * const pMemoryBlock,
        const bool bVectorFree = false);


} // namespace mx


MX_INLINE void * operator new (
        const mx::Size iMemoryBlockSize,
        const char * const sFileName,
        const mx::Size iFileLine);


MX_INLINE void * operator new[] (
        const mx::Size iMemoryBlockSize,
        const char * const sFileName,
        const mx::Size iFileLine);


MX_INLINE void operator delete (
        void * pMemoryBlock);

MX_INLINE void operator delete[] (
        void * pMemoryBlock);


#ifdef MXCPP_FIX_DELETE_PARAMS_LIKE_NEW

// We do not require this, bu some compilers (MSVC) must have defined
// delete operator with same parameters like new.

MX_INLINE void operator delete (
        void * pMemoryBlock,
        const char * const sFileName,
        const mx::Size iFileLine);

MX_INLINE void operator delete[] (
        void * pMemoryBlock,
        const char * const sFileName,
        const mx::Size iFileLine);

#endif // MXCPP_FIX_DELETE_PARAMS_LIKE_NEW


// Define inline methods here if inlining is enabled.
#ifdef MX_INLINE_ENABLED
#include "mx/new.inl"
#endif


#include "mx/defs/newdef.hpp"


#endif // MXCPP_NEW_HPP_INCLUDE_GUARD

/* EOF */
