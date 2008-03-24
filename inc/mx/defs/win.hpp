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

    Windows system specific definitions.

    @author Emil Maskovsky
*/


#ifndef MXCPP_SYSDEF_WINDOWS_HPP_INCLUDE_GUARD
#define MXCPP_SYSDEF_WINDOWS_HPP_INCLUDE_GUARD


// Enable inlining for the Windows platform by default.
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

#else // __BCPLUSPLUS__

#ifdef __WATCOM_CPLUSPLUS__

/* Watcom C++ Compiler definitions. */
#include "mx/defs/watcom.hpp"

#else // __WATCOM_CPLUSPLUS__

    #error Unsupported compiler for Windows platform. \
    See mx/defs/win.hpp for the list of supported compilers.

#endif // __WATCOM_CPLUSPLUS__

#endif // __BCPLUSPLUS__

#endif // __DMC__

#endif // __GNUC__

#endif // _MSC_VER


/* Use Windows libraries. */
/// Exclude rarely-used stuff from Windows-32 headers.
#define WIN32_LEAN_AND_MEAN
#include <windows.h>


#endif // MXCPP_SYSDEF_WINDOWS_HPP_INCLUDE_GUARD

/* EOF */
