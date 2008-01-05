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

    Watcom C++ compiler specific definitions.

    @author Emil Maskovsky
*/


#ifndef MXCPP_SYSDEF_WATCOM_H_INCLUDE_GUARD
#define MXCPP_SYSDEF_WATCOM_H_INCLUDE_GUARD


#ifndef MX_PLATFORM_COMPILER_WATCOM
#define MX_PLATFORM_COMPILER_WATCOM
#endif


/* Watcom C++ Compiler specific settings.
        __WATCOM_CPLUSPLUS__    Watcom C++ Compiler version.
*/
#if !defined(__WATCOM_CPLUSPLUS__) || (__WATCOM_CPLUSPLUS__ < 1100)
#error This project requires at least Watcom C++ 11.00 to compile.
#endif /* __WATCOM_CPLUSPLUS__ < 1100 */


/* Uses standard __declspec(dllexport/dllimport) DLL exports. */
#include "mx/defs/stddllexp.h"

/*
#ifdef MX_INLINE_ENABLED
#undef MX_INLINE_ENABLED
#endif
*/


#define MXCPP_FIX_STATIC_CANT_ACCESS_PRIVATE_CONSTRUCTOR

#define MXCPP_FIX_USE_OLD_C_HEADERS

#define MXCPP_FIX_TEMPLATE_METHODS_NOT_SUPPORTED


#endif /* MXCPP_SYSDEF_WATCOM_H_INCLUDE_GUARD */

/* EOF */
