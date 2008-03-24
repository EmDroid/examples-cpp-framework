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

    DOS system specific definitions.

    @author Emil Maskovsky
*/


#ifndef MXCPP_SYSDEF_DOS_H_INCLUDE_GUARD
#define MXCPP_SYSDEF_DOS_H_INCLUDE_GUARD


// Enable inlining for the DOS platform by default.
#ifndef MX_INLINE_ENABLED
#define MX_INLINE_ENABLED
#endif

#ifdef _MSC_VER

/* Microsoft Visual C++ Compiler definitions. */
#include "mx/defs/msvc.hpp"

#else // _MSC_VER

#ifdef __GNUC__

/* GNU C++ Compiler definitions. */
#include "mx/defs/gcc.hpp"

#else // __GNUC__

#ifdef __DMC__

/* Digital Mars Compiler definitions. */
#include "mx/defs/dmc.hpp"

#else // __DMC__

#ifdef __BCPLUSPLUS__

/* Borland C++ Compiler definitions. */
#include "mx/defs/bcc.hpp"

#else // __BORLANDC__

#ifdef __WATCOM_CPLUSPLUS__

/* Watcom C++ Compiler definitions. */
#include "mx/defs/watcom.hpp"

#else  // __WATCOM_CPLUSPLUS__

    #error Unsupported compiler for DOS platform. \
    See mx/defs/dos.hpp for the list of supported compilers.

#endif // __WATCOM_CPLUSPLUS__

#endif // __BCPLUSPLUS__

#endif // __DMC__

#endif // __GNUC__

#endif // _MSC_VER


#endif // MXCPP_SYSDEF_DOS_H_INCLUDE_GUARD

/* EOF */
