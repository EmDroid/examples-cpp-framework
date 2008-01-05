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

    Common GNU C++ compiler specific definitions.

    @author Emil Maskovsky
*/


#ifndef MXCPP_SYSDEF_GCC_H_INCLUDE_GUARD
#define MXCPP_SYSDEF_GCC_H_INCLUDE_GUARD


#ifndef MX_PLATFORM_COMPILER_GCC
#define MX_PLATFORM_COMPILER_GCC
#endif


/* GNU C++ Compiler specific settings.
        __GNUC__        Main GNU C++ Compiler version.
        __GNUC_MINOR__  Minor GNU C++ Compiler version.
*/
#if (__GNUC__ < 2)
#error This project requires at least GNU C++ Compiler 2.0 to compile.
#else /* GNUC < 2.0 */
#if (__GNUC__ < 3)
/* GNUC 2.0 */
#include "mx/defs/gcc2.h"
#else /* GNUC < 3.0 */
#if (__GNUC__ < 4)
/* GNUC 3.0 */
#include "mx/defs/gcc3.h"
#else
/* GNUC 4.0 */
#include "mx/defs/gcc4.h"
#endif
#endif
#endif /* GNUC < 2.0 */


/* Uses standard __declspec(dllexport/dllimport) DLL exports. */
#include "mx/defs/stddllexp.h"


#endif /* MXCPP_SYSDEF_GCC_H_INCLUDE_GUARD */

/* EOF */
