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

    Watcom C++ compiler specific definitions.

    @author Emil Maskovsky
*/


#ifndef MX_PLATFORM_COMPILER_WATCOM

#define MX_PLATFORM_COMPILER_WATCOM


/* Watcom C++ Compiler specific settings.
        __WATCOM_CPLUSPLUS__    Watcom C++ Compiler version.
*/
#if !defined(__WATCOM_CPLUSPLUS__) || (__WATCOM_CPLUSPLUS__ < 1100)
    #error This project requires at least Watcom C++ 11.00 to compile.
#endif // __WATCOM_CPLUSPLUS__ < 1100


// Uses standard __declspec(dllexport/dllimport) DLL exports.
#include "mx/defs/stddllexp.hpp"


#ifdef MX_PLATFORM_OS_WIN32

/// Pass string to the debugger.
#define MX_DEBUGGER_OUTPUT  OutputDebugString

#endif // MX_PLATFORM_OS_WIN32


/** @cond disabled_helper_defs */

#ifndef MX_PLATFORM_OS_WIN16
// There are problems under Win-16 with "noreturn" specification.
//
// The code with "noreturn" specification is more efficient, because it uses jmp
// instruction instead of functional call, but this is not very big performance
// problem because the "noreturn" function gets called only once (terminates the
// program).

    #pragma aux no_return aborts

// Define how to declare functions/methods which never return.
#define MX_NORETURN_TYPE(Type)  Type __pragma("no_return")

#endif

/** @endcond */


#endif // MX_PLATFORM_COMPILER_WATCOM

/* EOF */
