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

    Digital Mars compiler specific definitions.

    @author Emil Maskovsky
*/


#pragma once


#ifndef MX_PLATFORM_COMPILER_DMC

#define MX_PLATFORM_COMPILER_DMC


/* Digital Mars Compiler specific settings.
        __DMC__     Digital Mars Compiler version.
*/
#if (__DMC__ < 0x700)
    #error This project requires at least Digital Mars Compiler 7.00 to compile.
#endif // __DMC__ < 0x700


#ifndef MX_PLATFORM_OS_WIN32

/* C++-style DMC headers are incompatible with outside WIN32. */
/// The compiler does not support new C++ style headers.
#define MXCPP_FIX_USE_OLD_C_HEADERS

/// The compiler does not have standard C++ exceptions defined.
#define MXCPP_FIX_NO_STD_EXCEPTION

#else // PLATFORM_OS_WIN32

// Uses standard __declspec(dllexport/dllimport) DLL exports.
#include "mx/defs/stddllexp.hpp"

/// Pass string to the debugger.
#define MX_DEBUGGER_OUTPUT  OutputDebugString

#endif // PLATFORM_OS_WIN32


#endif // MX_PLATFORM_COMPILER_DMC

/* EOF */
