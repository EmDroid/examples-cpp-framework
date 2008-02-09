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

    Common GNU C++ compiler specific definitions.

    @author Emil Maskovsky
*/


#ifndef MX_PLATFORM_COMPILER_GCC

#define MX_PLATFORM_COMPILER_GCC


/* GNU C++ Compiler specific settings.
        __GNUC__        Main GNU C++ Compiler version.
        __GNUC_MINOR__  Minor GNU C++ Compiler version.
*/
#if (__GNUC__ < 2)
    #error This project requires at least GNU C++ Compiler 2.0 to compile.
#else // GNUC < 2.0
#if (__GNUC__ < 3)
/* GNUC 2.0 */
#include "mx/defs/gcc2.hpp"
#else // GNUC 3.0
#if (__GNUC__ < 4)
/* GNUC 3.0 */
#include "mx/defs/gcc3.hpp"
#else // GNUC 4.0
/* GNUC 4.0 */
#include "mx/defs/gcc4.hpp"
#endif // GNUC 4.0
#endif // GNUC 3.0
#endif // GNUC < 2.0


// Uses standard __declspec(dllexport/dllimport) DLL exports.
#include "mx/defs/stddllexp.hpp"


#if (defined(MX_PLATFORM_OS_WINDOWS) \
    || defined(MX_PLATFORM_OS_UNIX))

/// Pass string to the debugger.
#define MX_DEBUGGER_OUTPUT  OutputDebugString

#endif


/** @cond disabled_helper_defs */

// Define how to declare functions/methods with printf(3) like semantics.

#ifndef MXCPP_UNICODE

#define MX_PRINTFLIKE(format_index, arguments_index) \
    __attribute__((__format__(__printf__, (format_index), (arguments_index))))

#else // MXCPP_UNICODE

#define MX_PRINTFLIKE(format_index, arguments_index) \
    __attribute__((__format__(__printfw__, (format_index), (arguments_index))))

#endif // MXCPP_UNICODE

#define MX_PRINTFLIKE_METHOD(format_index, arguments_index) \
    MX_PRINTFLIKE((format_index) + 1, (arguments_index) + 1)

// Define how to declare functions/methods with scanf(3) like semantics.
#ifndef MXCPP_UNICODE

#define MX_SCANFLIKE(format_index, arguments_index) \
    __attribute__((__format__(__scanf__, (format_index), (arguments_index))))

#else // MXCPP_UNICODE

#define MX_SCANFLIKE(format_index, arguments_index) \
    __attribute__((__format__(__scanfw__, (format_index), (arguments_index))))

#endif // MXCPP_UNICODE

#define MX_SCANFLIKE_METHOD(format_index, arguments_index) \
    MX_SCANFLIKE((format_index) + 1, (arguments_index) + 1)


// Define how to declare functions/methods which never return.
#define MX_NORETURN_TYPE(Type)  Type __attribute__((__noreturn__))

/** @endcond */


#endif // MX_PLATFORM_COMPILER_GCC

/* EOF */
