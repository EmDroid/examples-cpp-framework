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

    new/delete operator override definitions (define).

    @author Emil Maskovsky

    @see mx/defs/newundef.hpp
*/


#include "mx/defs/newundef.hpp"

// We redefine the standard new operator to be able to get the information
// where the out of memory exception occured.
//
// It is done in both debug and release modes,
// in both modes we throw the exception.


#ifndef mxDebugCheckpoint
    #error mxDebugCheckpoint() not defined!
#endif

/**
    @internal

    The new operator.

    The new operator overridden to be called along with the file name and line
    information.

    Some compilers have problems when using mxDebugCheckpoint()
    (MSVC 6.0 so far), therefore we use normal file-line logging.
*/
#define new  new (__FILE__, __LINE__)


/* EOF */
