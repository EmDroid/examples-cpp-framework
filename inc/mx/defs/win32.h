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

    Windows-32 system specific definitions.

    @author Emil Maskovsky
*/


#ifndef MXCPP_SYSDEF_WIN32_H_INCLUDE_GUARD
#define MXCPP_SYSDEF_WIN32_H_INCLUDE_GUARD


#ifndef MX_PLATFORM_OS_WIN32
#define MX_PLATFORM_OS_WIN32
#endif


/* Enable inlining for the Windows-32 platform by default. */
#define MX_INLINE_ENABLED

#ifdef _MSC_VER

/* Microsoft Visual C++ Compiler definitions. */
#include "mx/defs/msvc.h"

#else /* _MSC_VER */

#ifdef __GNUC__

/* GNU C++ Compiler definitions. */
#include "mx/defs/gcc.h"

#else /* __GNUC__ */

#ifdef __DMC__

/* Digital Mars Compiler definitions. */
#include "mx/defs/dmc.h"

#else /* __DMC__ */

#ifdef __BORLANDC__

#ifndef MX_PLATFORM_COMPILER_BORLANDC
#define MX_PLATFORM_COMPILER_BORLANDC
#endif

/* Borland C++ Compiler specific settings.
        __BCPLUSPLUS__  Borland C++ Compiler version.
*/
#if !defined(__BCPLUSPLUS__) || (__BCPLUSPLUS__ < 0x0551)
#error This project requires at least Borland C++ 5.5 to compile.
#else /* __BCPLUSPLUS__ < 0x0551 */
#include "mx/defs/bcc.h"
#endif /* __BCPLUSPLUS__ < 0x0551 */

#else /* __BORLANDC__ */

#ifdef __WATCOMC__

#ifndef MX_PLATFORM_COMPILER_WATCOM
#define MX_PLATFORM_COMPILER_WATCOM
#endif

/* Borland C++ Compiler specific settings.
        __WATCOM_CPLUSPLUS__  Watcom C++ Compiler version.
*/
#if !defined(__WATCOM_CPLUSPLUS__) || (__WATCOM_CPLUSPLUS__ < 1100)
#error This project requires at least Watcom C++ 11.00 to compile.
#else /* __WATCOM_CPLUSPLUS__ < 1100 */
#include "mx/defs/watcom.h"
#endif /* __WATCOM_CPLUSPLUS__ < 1100 */

#else /* __WATCOMC__ */

#error Unsupported compiler for Windows32 platform. \
    See mx/defs/win32.h for the list of supported compilers.

#endif /* __WATCOMC__ */

#endif /* __BORLANDC__ */

#endif /* __DMC__ */

#endif /* __GNUC__ */

#endif /* _MSC_VER */


/* Use Win32 libraries. */
#define WIN32_LEAN_AND_MEAN  /**< Exclude rarely-used stuff from Windows headers. */
#include <windows.h>


#endif /* MXCPP_SYSDEF_WIN32_H_INCLUDE_GUARD */

/* EOF */
