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

    Common Microsoft Visual C++ compiler specific definitions.

    @author Emil Maskovsky
*/


#ifndef MX_PLATFORM_COMPILER_MSVC

#define MX_PLATFORM_COMPILER_MSVC


/* Microsoft Visual C++ specific settings.
         _MSC_VER    Microsoft Visual C++ compiler version:
             1000 ... MSVC 4.0
             1020 ... MSVC 4.2
             1100 ... MSVC 5.0
             1200 ... MSVC 6.0
             1300 ... MSVC 7.0 (.NET)
             1310 ... MSVC 7.1 (.NET)
             1400 ... MSVC 8.0 (.NET)
*/
#if (_MSC_VER < 1200)
    #error This project requires at least MSVC version 6.0 to compile.
#else // MSVC < 6.0
#if (_MSC_VER < 1300)
/* MSVC 6.0 */
#include "mx/defs/msvc6.hpp"
#else // MSVC 7.0
#if (_MSC_VER < 1310)
/* MSVC 7.0 */
#include "mx/defs/msvc7.hpp"
#else // MSVC 7.1
#if (_MSC_VER < 1400)
/* MSVC 7.1 */
#include "mx/defs/msvc7.hpp"
#else // MSVC 8.0
/* MSVC 8.0 */
#include "mx/defs/msvc8.hpp"
#endif // MSVC 8.0
#endif // MSVC 7.1
#endif // MSVC 7.0
#endif // MSVC < 6.0


// Uses standard __declspec(dllexport/dllimport) DLL exports.
#include "mx/defs/stddllexp.hpp"


/// Operator @c delete has the same parameters as the operator @c new.
#define MXCPP_FIX_DELETE_PARAMS_LIKE_NEW


/** @cond disabled_helper_defs */

// Define how to declare functions/methods which never return.
#define MX_NORETURN_TYPE(Type)  __declspec(noreturn) Type

/** @endcond */


// Disable warning: C++ Exception Specification ignored
    #pragma warning(disable : 4290)


#endif // MX_PLATFORM_COMPILER_MSVC

/* EOF */
