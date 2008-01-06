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

    Digital Mars compiler specific definitions.

    @author Emil Maskovsky
*/


#pragma once


#ifndef MXCPP_SYSDEF_DMC_H_INCLUDE_GUARD
#define MXCPP_SYSDEF_DMC_H_INCLUDE_GUARD


#ifndef MX_PLATFORM_COMPILER_DMC
#define MX_PLATFORM_COMPILER_DMC
#endif

/* Digital Mars Compiler specific settings.
        __DMC__     Digital Mars Compiler version.
*/
#if (__DMC__ < 0x700)
#error This project requires at least Digital Mars Compiler 7.00 to compile.
#else /* __DMC__ < 0x700 */
#endif /* __DMC__ < 0x700 */


#ifdef MX_PLATFORM_OS_WIN32

/* Uses standard __declspec(dllexport/dllimport) DLL exports. */
#include "mx/defs/stddllexp.h"

#else /* PLATFORM_OS_WIN32 */

/* C++-style DMC headers are incompatible with outside WIN32. */
#define MXCPP_FIX_USE_OLD_C_HEADERS

#endif /* PLATFORM_OS_WIN32 */


#endif /* MXCPP_SYSDEF_DMC_H_INCLUDE_GUARD */

/* EOF */
