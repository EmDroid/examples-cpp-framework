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


#ifndef MXCPP_SYSDEFS_H_INCLUDE_GUARD
#define MXCPP_SYSDEFS_H_INCLUDE_GUARD


/* Check the Windows-64 system flags. */
#if (!defined(WIN64) && defined(_WIN64))
#define WIN64
#endif


#ifdef WIN64

#define MX_PLATFORM_OS_WIN64

#ifndef MX_PLATFORM_OS_WINDOWS
#define MX_PLATFORM_OS_WINDOWS
#endif

#endif


/* Check the Windows-32 system flags. */
#if (!defined(WIN32) && defined(_WIN32))
#define WIN32
#endif


#ifdef WIN32

#define MX_PLATFORM_OS_WIN32

#ifndef MX_PLATFORM_OS_WINDOWS
#define MX_PLATFORM_OS_WINDOWS
#endif

#endif


/* Check the Windows-16 system flags. */
#if (!defined(WIN16) && (defined(_WINDOWS) /*|| defined(__WINDOWS)*/))
#define WIN16
#endif


#ifdef WIN16

#define MX_PLATFORM_OS_WIN16

#ifndef MX_PLATFORM_OS_WINDOWS
#define MX_PLATFORM_OS_WINDOWS
#endif

#endif


/* Check the DOS system flags. */
#if (!defined(DOS) && (defined(_DOS) || defined(MSDOS) || defined(_MSDOS)))
#define DOS
#endif


#ifdef DOS

#define MX_PLATFORM_OS_DOS

#endif


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
#endif /* _MT */


#ifdef MX_PLATFORM_OS_WINDOWS

/* Windows-32 system definitions. */
#include "mx/defs/win.h"

#else /* MX_PLATFORM_OS_WINDOWS */

#ifdef MX_PLATFORM_OS_DOS

/* DOS system definitions. */
#include "mx/defs/dos.h"

#else /* MX_PLATFORM_OS_DOS */

#ifdef MX_PLATFORM_OS_UNIX

/* Unix/Linux system definitions. */
#include "mx/defs/unix.h"

#else /* MX_PLATFORM_OS_UNIX */

/* IBM mainframe (OS/390 etc.) */
#ifdef MX_PLATFORM_OS_MVS

/* Unix/Linux system definitions. */
#include "mx/defs/mvs.h"

#else /* MX_PLATFORM_OS_MVS */

#ifdef MXCPP_GEN_DEPEND

#else /* MXCPP_GEN_DEPEND */

#error Unsupported platform. See sysdefs.h for a list of supported platforms.

#endif /* MXCPP_GEN_DEPEND */

#endif /* MX_PLATFORM_OS_MVS */

#endif /* MX_PLATFORM_OS_UNIX */

#endif /* MX_PLATFORM_OS_DOS */

#endif /* MX_PLATFORM_OS_WINDOWS */


/* System helper macros. */
#include "mx/defs/helpers.h"


#endif /* MXCPP_SYSDEFS_H_INCLUDE_GUARD */

/* EOF */
