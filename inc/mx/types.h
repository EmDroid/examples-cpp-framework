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

    Standardized basic data types.

    @author Emil Maskovsky
*/


#ifndef MXCPP_TYPES_H_INCLUDE_GUARD
#define MXCPP_TYPES_H_INCLUDE_GUARD


/**
    Standard size type.

    Will become 4 B (long) on 32-bit systems, 2 B (short) on 16-bit systems
    (the total range the system can address).

    @note
    This type is always unsigned, some algorithms rely on it (e.g.
    (Size)(-1) for maximal size can be used). This can faster and simplify
    some algorithms (avoid some checks).
*/
typedef size_t mxSize;


#ifdef __cplusplus

// C++ only declarations.


namespace mx
{


/**
    Synonym for mxSize type for the C++ language.

    It is encouraged to use this type under C++ instead of mxSize.
*/
typedef mxSize Size;


} // namespace mx


#endif /* __cplusplus */


#endif /* MXCPP_TYPES_H_INCLUDE_GUARD */

/* EOF */
