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

    Windows-16 system specific definitions.

    @author Emil Maskovsky
*/


#ifndef MXCPP_SYSDEF_WIN16_H_INCLUDE_GUARD
#define MXCPP_SYSDEF_WIN16_H_INCLUDE_GUARD


#ifndef MX_PLATFORM_OS_WINDOWS
#define MX_PLATFORM_OS_WINDOWS
#endif

#ifndef MX_PLATFORM_OS_WIN16
#define MX_PLATFORM_OS_WIN16
#endif


/* Enable inlining for the Windows-16 platform by default. */
#define MX_INLINE_ENABLED

#ifdef __DMC__

/* Digital Mars Compiler definitions. */
#include "mx/defs/dmc.h"

#else /* __DMC__ */

#ifdef __WATCOMC__

/* Watcom C++ Compiler definitions. */
#include "mx/defs/watcom.h"

#else /* __WATCOMC__ */

#error Unsupported compiler for Windows32 platform. \
    See mx/defs/win16.h for the list of supported compilers.

#endif /* __WATCOMC__ */

#endif /* __DMC__ */


/* Use Win32 libraries. */
#include <windows.h>


#endif /* MXCPP_SYSDEF_WIN16_H_INCLUDE_GUARD */

/* EOF */
