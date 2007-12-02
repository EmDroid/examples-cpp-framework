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

    Out of memory exception (implementation).

    @author Emil Maskovsky
*/


/* Framework libraries. */
#include "mx.h"


/* Application specific. */
#include "mx/internal/OutOfMem.hpp"

#include "mx/defs/newundef.hpp"


// Start the exception implementation.
MX_IMPLEMENT_EXCEPTION_CLASS(mx::OutOfMemory);


/**
    Constructor.
*/
mx::OutOfMemory::OutOfMemory(
        const Size iSizeRequested,
        const char * const sFileName,
        const Size iFileLine)
    : Super("Out of memory")
    , m_iSizeRequested(iSizeRequested)
    , m_sAllocFileName(sFileName)
    , m_iAllocFileLine(iFileLine)
{}


// Define inline methods here if inlining is disabled.
#ifndef MX_INLINE_ENABLED
#include "mx/internal/OutOfMem.inl"
#endif

/* EOF */
