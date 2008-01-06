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


/* Check the Windows32 system flags. */
#if (defined(_WIN32) && !defined(WIN32))
#define WIN32  _WIN32
#endif


/* Check the DOS system flags. */
#if (defined(_MSDOS) && !defined(_DOS))
#define _DOS  _MSDOS
#endif

#if (defined(MSDOS) && !defined(DOS))
#define DOS  MSDOS
#endif

#if (defined(_DOS) && !defined(DOS))
#define DOS  _DOS
#endif


/* Check the DEBUG flags. */
#if (defined(_DEBUG) && !defined(DEBUG))
#define DEBUG  _DEBUG
#endif
#if (defined(_DEBUG_) && !defined(DEBUG))
#define DEBUG  _DEBUG_
#endif
#if (defined(__DEBUG) && !defined(DEBUG))
#define DEBUG  __DEBUG
#endif
#if (defined(__DEBUG__) && !defined(DEBUG))
#define DEBUG  __DEBUG__
#endif

#ifndef DEBUG
/* Debugging is disabled. */
#define MXCPP_DEBUG_DISABLED
#else /* DEBUG */
#if (defined(_NDEBUG) || defined(NDEBUG))
#error Debug definition mismatch - both DEBUG and NDEBUG defined.
#endif
#endif /* DEBUG */


/* Check the UNICODE flags. */
#if (defined(_UNICODE) || defined(UNICODE))
#define MXCPP_UNICODE
#endif


/* Check the MULTITHREAD flags. */
#ifdef _MT
/* We run multi-threaded. */
#define MXCPP_MULTITHREAD
#endif /* _MT */


#ifdef WIN32

/* Windows-32 system definitions. */
#include "mx/defs/win32.h"

#else /* WIN32 */

#ifdef DOS

/* DOS system definitions. */
#include "mx/defs/dos.h"

#else /* MSDOS */

#if (defined(UNIX) || defined(LINUX))

/* Unix/Linux system definitions. */
#include "mx/defs/unix.h"

#else /* UNIX || LINUX */

/* IBM mainframe (OS/390 etc.) */
#ifdef __MVS__

#ifndef MX_PLATFORM_OS_MVS
#define MX_PLATFORM_OS_MVS
#endif

/* Unix/Linux system definitions. */
#include "mx/defs/mvs.h"

#else /* __MVS__ */

#ifdef MXCPP_GEN_DEPEND

#else /* MXCPP_GEN_DEPEND */

#error Unsupported platform. See sysdefs.h for a list of supported platforms.

#endif /* MXCPP_GEN_DEPEND */

#endif /* __MVS__ */

#endif /* UNIX || LINUX */

#endif /* MSDOS */

#endif /* WIN32 */


/* System helper macros. */
#include "mx/defs/helpers.h"


#endif /* MXCPP_SYSDEFS_H_INCLUDE_GUARD */

/* EOF */
