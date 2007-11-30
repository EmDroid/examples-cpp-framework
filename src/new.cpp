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

    Global new and delete operators (implementation).

    @author Emil Maskovsky
*/


/* Framework libraries. */
#include "mx.h"


/* Application specific. */
#include "mx/new.hpp"


#include "mx/defs/newundef.hpp"


MXCPP_DLL_EXPORT void * mx::OperatorNewImplementation(
        const Size iMemoryBlockSize,
        const char * const sFileName,
        const Size iFileLine,
        const bool MX_UNUSED(bVectorAlloc))
{
    return Memory::Allocate(sFileName, iFileLine, iMemoryBlockSize);
}


MXCPP_DLL_EXPORT void mx::OperatorDeleteImplementation(
        void * const pMemoryBlock,
        const bool MX_UNUSED(bVectorFree))
{
    Memory::Free(pMemoryBlock);
}


// Define inline methods here if inlining is disabled.
#ifndef MX_INLINE_ENABLED
#include "mx/new.inl"
#endif

/* EOF */
