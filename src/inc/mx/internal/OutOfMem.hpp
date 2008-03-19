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

    Out of memory exception (interface).

    @author Emil Maskovsky
*/


#ifndef MXCPP_SYSDEFS
#include "mx/sysdefs.hpp"
#endif


#ifndef MXCPP_OUT_OF_MEMORY_EXCEPTION_HPP_INCLUDE_GUARD
#define MXCPP_OUT_OF_MEMORY_EXCEPTION_HPP_INCLUDE_GUARD


#ifndef MXCPP_TYPES
#include "mx/types.hpp"
#endif

#include "mx/Memory.hpp"


namespace mx
{


/**
    MemoryException for low memory situations.

    The exception is hidden in the implementation file, the usage of this
    exception is only in our memory handler. Otherwise you should not throw
    this exception, and it can be caught as MemoryException.
*/
class MXCPP_DLL_EXPORT OutOfMemory
    : public MemoryException
{

    MX_DECLARE_EXCEPTION_CLASS(OutOfMemory, MemoryException);

// Construction, destruction.

public:

    explicit MX_INLINE OutOfMemory(
            const Size iSizeRequested);


// Class instance methods.

public:

    MX_OVERRIDDEN MX_INLINE const char * what() const;


// Class instance attributes.

private:

    /// Size of memory that was requested and failed to be allocated.
    Size m_iSizeRequested;


}; // class OutOfMemory


} // namespace mx


// Define inline methods here if inlining is enabled.
#ifdef MX_INLINE_ENABLED
#include "mx/internal/OutOfMem.inl"
#endif


#endif // MXCPP_OUT_OF_MEMORY_EXCEPTION_HPP_INCLUDE_GUARD

/* EOF */
