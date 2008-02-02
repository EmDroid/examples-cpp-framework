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

    Class base (interface).

    @author Emil Maskovsky
*/


#ifndef MXCPP_CLASSBASE_HPP_INCLUDE_GUARD
#define MXCPP_CLASSBASE_HPP_INCLUDE_GUARD


#include "mx/sysdefs.hpp"

#include "mx/types.hpp"


namespace mx
{

/**
    Base class for all our dynamic classes.
*/
class MXCPP_DLL_EXPORT Class
{


// Construction, destruction.

public:

    virtual MX_INLINE ~Class();

// Class instance methods.

public:

    const char * getName() const;


}; // class Class


} // namespace mx


// Define inline methods here if inlining is enabled.
#ifdef MX_INLINE_ENABLED
#include "mx/Class.inl"
#endif

#endif // MXCPP_CLASSBASE_HPP_INCLUDE_GUARD

/* EOF */
