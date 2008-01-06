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

    Common Microsoft Visual C++ compiler specific definitions.

    @author Emil Maskovsky
*/


#ifndef MXCPP_SYSDEF_MSVC_H_INCLUDE_GUARD
#define MXCPP_SYSDEF_MSVC_H_INCLUDE_GUARD


#ifndef MX_PLATFORM_COMPILER_MSVC
#define MX_PLATFORM_COMPILER_MSVC
#endif


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
#else /* MSVC < 6.0 */
#if (_MSC_VER < 1300)
/* MSVC 6.0 */
#include "mx/defs/msvc6.h"
#else
#if (_MSC_VER < 1310)
/* MSVC 7.0 */
#include "mx/defs/msvc7.h"
#else
#if (_MSC_VER < 1400)
/* MSVC 7.1 */
#include "mx/defs/msvc7.h"
#else
/* MSVC 8.0 */
#include "mx/defs/msvc8.h"
#endif /* MSVC 8.0 */
#endif /* MSVC 7.1 */
#endif /* MSVC 7.0 */
#endif /* MSVC < 6.0 */


/* Uses standard __declspec(dllexport/dllimport) DLL exports. */
#include "mx/defs/stddllexp.h"


/** Operator @c delete has the same parameters as the operator @c new. */
#define MXCPP_FIX_DELETE_PARAMS_LIKE_NEW


/* Define how to declare functions/methods which never return. */
#define MX_NORETURN_TYPE(Type)  __declspec(noreturn) Type


/* Disable warning: C++ Exception Specification ignored */
#pragma warning(disable : 4290)


#endif /* MXCPP_SYSDEF_MSVC_H_INCLUDE_GUARD */

/* EOF */
