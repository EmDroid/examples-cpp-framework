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

    Borland C++ compiler specific definitions.

    @author Emil Maskovsky
*/


#ifndef MXCPP_SYSDEF_BCC_H_INCLUDE_GUARD
#define MXCPP_SYSDEF_BCC_H_INCLUDE_GUARD


#ifndef MX_PLATFORM_COMPILER_BORLANDC
#define MX_PLATFORM_COMPILER_BORLANDC
#endif


/* Borland C++ Compiler specific settings.
        __BCPLUSPLUS__  Borland C++ Compiler version.
*/
#if !defined(__BORLANDC__) || (__BORLANDC__ < 0x0551)
#error This project requires at least Borland C++ 5.5 to compile.
#else /* __BCPLUSPLUS__ < 0x0551 */
#endif /* __BCPLUSPLUS__ < 0x0551 */


/* Uses standard __declspec(dllexport/dllimport) DLL exports. */
#include "mx/defs/stddllexp.h"


/* Define how to declare functions/methods which never return. */
#define MX_NORETURN_TYPE(Type)  __declspec(noreturn) Type


#endif /* MXCPP_SYSDEF_BCC_H_INCLUDE_GUARD */

/* EOF */
