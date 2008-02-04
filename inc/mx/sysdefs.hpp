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

    The framefork system definitions.

    @author Emil Maskovsky
*/


#ifndef MXCPP_SYSDEFS
#define MXCPP_SYSDEFS


#ifndef __cplusplus
    #error This C++ Framework cannot be used within ANSI-C programs \
    - use C++ compiler instead!
#endif


#define MX_MAKESTRING(value)   #value
#define MX_MAKE_STRING(value)  MX_MAKESTRING(value)


/* Make sure we have not defined the system flag. */
#ifdef MX_PLATFORM_OS_WINDOWS
    #pragma message(__FILE__ "(" MX_MAKE_STRING(__LINE__) "): " \
    "WARNING: The flag MX_PLATFORM_OS_WINDOWS already defined!" \
    " (will be discarded)")
#undef MX_PLATFORM_OS_WINDOWS
#endif

#ifdef MX_PLATFORM_OS_DOS
    #pragma message(__FILE__ "(" MX_MAKE_STRING(__LINE__) "): " \
    "WARNING: The flag MX_PLATFORM_OS_DOS already defined!"     \
    " (will be discarded)")
#undef MX_PLATFORM_OS_DOS
#endif

#ifdef MX_PLATFORM_OS_UNIX
    #pragma message(__FILE__ "(" MX_MAKE_STRING(__LINE__) "): " \
    "WARNING: The flag MX_PLATFORM_OS_UNIX already defined!"    \
    " (will be discarded)")
#undef MX_PLATFORM_OS_UNIX
#endif

#ifdef MX_PLATFORM_OS_MVS
    #pragma message(__FILE__ "(" MX_MAKE_STRING(__LINE__) "): " \
    "WARNING: The flag MX_PLATFORM_OS_MVS already defined!"     \
    " (will be discarded)")
#undef MX_PLATFORM_OS_MVS
#endif


/* Check the Windows-64 system flags. */
#if (!defined(WIN64) && defined(_WIN64))
#define WIN64
#define MXCPP_WIN64_UNDEF
#endif


#ifdef WIN64

#ifndef MX_PLATFORM_OS_WINDOWS

#define MX_PLATFORM_OS_WINDOWS
#define MX_PLATFORM_OS_WIN64

#else // MX_PLATFORM_OS_WINDOWS
/* We have MX_PLATFORM_OS_WINDOWS already defined - this means that flag
    of newer system was already found.
*/

#ifdef MXCPP_WIN64_UNDEF
#undef WIN64
#endif

#endif // MX_PLATFORM_OS_WINDOWS

#ifdef MXCPP_WIN64_UNDEF
#undef MXCPP_WIN64_UNDEF
#endif

#endif // WIN64


/* Check the Windows-32 system flags. */
#if (!defined(WIN32) && defined(_WIN32))
#define WIN32
#define MXCPP_WIN32_UNDEF
#endif


#ifdef WIN32

#ifndef MX_PLATFORM_OS_WINDOWS

#define MX_PLATFORM_OS_WINDOWS
#define MX_PLATFORM_OS_WIN32

#else // MX_PLATFORM_OS_WINDOWS
/* We have MX_PLATFORM_OS_WINDOWS already defined - this means that flag
    of newer system was already found.
*/

#ifdef MXCPP_WIN32_UNDEF
#undef WIN32
#endif

#endif // MX_PLATFORM_OS_WINDOWS

#ifdef MXCPP_WIN32_UNDEF
#undef MXCPP_WIN32_UNDEF
#endif

#endif // WIN32


/* Check the Windows-16 system flags. */
#if (!defined(WIN16) && (defined(_WINDOWS) || defined(__WINDOWS__)))
#define WIN16
#define MXCPP_WIN16_UNDEF
#endif


#ifdef WIN16

#ifndef MX_PLATFORM_OS_WINDOWS

#define MX_PLATFORM_OS_WINDOWS
#define MX_PLATFORM_OS_WIN16

#else // MX_PLATFORM_OS_WINDOWS
/* We have MX_PLATFORM_OS_WINDOWS already defined - this means that flag
    of newer system was already found.
*/

#ifdef MXCPP_WIN16_UNDEF
#undef WIN16
#endif

#endif // MX_PLATFORM_OS_WINDOWS

#ifdef MXCPP_WIN16_UNDEF
#undef MXCPP_WIN16_UNDEF
#endif

#endif // WIN16


/* Check the DOS system flags. */
#if (!defined(DOS) && (defined(_DOS) || defined(MSDOS) || defined(_MSDOS)))
#define DOS
#endif


#ifdef DOS

#ifdef MX_PLATFORM_OS_WINDOWS
    #error System definition mismatch!
#endif

#define MX_PLATFORM_OS_DOS

#endif // DOS


/* Check the Linux system flags. */
#if (!defined(LINUX) && (defined(_LINUX) || defined(_LINUX_)))
#define LINUX
#define MXCPP_LINUX_UNDEF
#endif


#ifdef LINUX

#ifndef MX_PLATFORM_OS_UNIX

/* Check mismatch with another platforms. */
#if (defined(MX_PLATFORM_OS_DOS) \
    || defined(MX_PLATFORM_OS_WINDOWS))
    #error System definition mismatch!
#endif

#define MX_PLATFORM_OS_UNIX
#define MX_PLATFORM_OS_LINUX

#else // MX_PLATFORM_OS_UNIX
/* We have MX_PLATFORM_OS_UNIX already defined - this means that flag
    of other system was already found.
*/
    #error System definition mismatch!

#ifdef MXCPP_LINUX_UNDEF
#undef LINUX
#endif

#endif // MX_PLATFORM_OS_UNIX

#ifdef MXCPP_LINUX_UNDEF
#undef MXCPP_LINUX_UNDEF
#endif

#endif // LINUX


/* Check the Sparc system flags. */
#if (!defined(SPARC) && (defined(_SPARC) || defined(_SPARC_)))
#define SPARC
#define MXCPP_SPARC_UNDEF
#endif


#ifdef SPARC

#ifndef MX_PLATFORM_OS_UNIX

/* Check mismatch with another platforms. */
#if (defined(MX_PLATFORM_OS_DOS) \
    || defined(MX_PLATFORM_OS_WINDOWS))
    #error System definition mismatch!
#endif

#define MX_PLATFORM_OS_UNIX
#define MX_PLATFORM_OS_SPARC

#else // MX_PLATFORM_OS_UNIX
/* We have MX_PLATFORM_OS_UNIX already defined - this means that flag
    of other system was already found.
*/
    #error System definition mismatch!

#ifdef MXCPP_SPARC_UNDEF
#undef SPARC
#endif

#endif // MX_PLATFORM_OS_UNIX

#ifdef MXCPP_SPARC_UNDEF
#undef MXCPP_SPARC_UNDEF
#endif

#endif // SPARC


/* Check the HP-Unix system flags. */
#if (!defined(HPUX) && (defined(_HPUX) || defined(_HPUX_)))
#define HPUX
#define MXCPP_HPUX_UNDEF
#endif


#ifdef HPUX

#ifndef MX_PLATFORM_OS_UNIX

/* Check mismatch with another platforms. */
#if (defined(MX_PLATFORM_OS_DOS) \
    || defined(MX_PLATFORM_OS_WINDOWS))
    #error System definition mismatch!
#endif

#define MX_PLATFORM_OS_UNIX
#define MX_PLATFORM_OS_HPUX

#else // MX_PLATFORM_OS_UNIX
/* We have MX_PLATFORM_OS_UNIX already defined - this means that flag
    of other system was already found.
*/
    #error System definition mismatch!

#ifdef MXCPP_HPUX_UNDEF
#undef HPUX
#endif

#endif // MX_PLATFORM_OS_UNIX

#ifdef MXCPP_HPUX_UNDEF
#undef MXCPP_HPUX_UNDEF
#endif

#endif // HPUX


/* Check the AIX system flags. */
#if (!defined(AIX) && (defined(_AIX) || defined(_AIX_)))
#define AIX
#define MXCPP_AIX_UNDEF
#endif


#ifdef AIX

#ifndef MX_PLATFORM_OS_UNIX

/* Check mismatch with another platforms. */
#if (defined(MX_PLATFORM_OS_DOS) \
    || defined(MX_PLATFORM_OS_WINDOWS))
    #error System definition mismatch!
#endif

#define MX_PLATFORM_OS_UNIX
#define MX_PLATFORM_OS_AIX

#else // MX_PLATFORM_OS_UNIX
/* We have MX_PLATFORM_OS_UNIX already defined - this means that flag
    of other system was already found.
*/
    #error System definition mismatch!

#ifdef MXCPP_AIX_UNDEF
#undef AIX
#endif

#endif // MX_PLATFORM_OS_UNIX

#ifdef MXCPP_AIX_UNDEF
#undef MXCPP_AIX_UNDEF
#endif

#endif // AIX


/* Check the MVS/ZOS system flags. */
#if (!defined(MVS) && (defined(_MVS) || defined(_MVS_)))
#define MVS
#endif


#ifdef MVS

/* Check mismatch with another platforms. */
#if (defined(MX_PLATFORM_OS_DOS)       \
    || defined(MX_PLATFORM_OS_WINDOWS) \
    || defined(MX_PLATFORM_OS_UNIX))
    #error System definition mismatch!
#endif

#define MX_PLATFORM_OS_MVS

#endif // MVS


/* Check the DEBUG flags. */

/* Make sure both DEBUG and _DEBUG flags defined consistently.
    (both of them are often checked)
*/
#if (!defined(DEBUG) && defined(_DEBUG))
#define DEBUG  _DEBUG
#endif
#if (!defined(_DEBUG) && defined(DEBUG))
#define _DEBUG  DEBUG
#endif

#ifdef DEBUG
#define MXCPP_DEBUG
#endif

#ifdef MXCPP_DEBUG
#define MXCPP_DEBUG_ENABLED
#endif


/* Check the UNICODE flags. */

/* Make sure both UNICODE and _UNICODE flags defined consistently.
    (both of them are checked inside Windows header files)
*/
#if (defined(_UNICODE) && !defined(UNICODE))
#define UNICODE
#endif
#if (defined(UNICODE) && !defined(_UNICODE))
#define _UNICODE
#endif

#ifdef UNICODE
#define MXCPP_UNICODE
#endif


/* Check the MULTITHREAD flags. */
#if (!defined(MT) && defined(_MT))
#define MT
#endif

#ifdef MT
/** We run in multi-threaded mode. */
#define MXCPP_MULTITHREAD
#endif


#ifdef MX_PLATFORM_OS_WINDOWS

/* Windows-32 system definitions. */
#include "mx/defs/win.hpp"

#else // MX_PLATFORM_OS_WINDOWS

#ifdef MX_PLATFORM_OS_DOS

/* DOS system definitions. */
#include "mx/defs/dos.hpp"

#else /* MX_PLATFORM_OS_DOS */

#ifdef MX_PLATFORM_OS_UNIX

/* Unix/Linux system definitions. */
#include "mx/defs/unix.hpp"

#else // MX_PLATFORM_OS_UNIX

/* IBM mainframe (OS/390 etc.) */
#ifdef MX_PLATFORM_OS_MVS

/* Unix/Linux system definitions. */
#include "mx/defs/mvs.hpp"

#else // MX_PLATFORM_OS_MVS

#ifdef MXCPP_GEN_DEPEND

#else // MXCPP_GEN_DEPEND

    #error Unsupported platform - see sysdefs.h for a list of supported platforms.

#endif // MXCPP_GEN_DEPEND

#endif // MX_PLATFORM_OS_MVS

#endif // MX_PLATFORM_OS_UNIX

#endif // MX_PLATFORM_OS_DOS

#endif // MX_PLATFORM_OS_WINDOWS


/* System helper macros. */
#include "mx/defs/helpers.hpp"


#endif // MXCPP_SYSDEFS

/* EOF */
