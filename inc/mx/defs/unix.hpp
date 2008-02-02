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

    Unix/Linux system specific definitions.

    @author Emil Maskovsky
*/


#ifndef MXCPP_SYSDEF_UNIX_H_INCLUDE_GUARD
#define MXCPP_SYSDEF_UNIX_H_INCLUDE_GUARD


// Enable inlining for the Unix platforms by default.
#define MX_INLINE_ENABLED


#ifdef __GNUC__

/* GNU C++ Compiler definitions. */
#include "mx/defs/gcc.hpp"

#else // __GNUC__

#ifdef __xlC__

/* IBM VisualAge C++ Compiler definitions. */
#include "mx/defs/xlc.hpp"

#else // __xlC__

#ifdef __HP_aCC

/* HP C++ Compiler (aCC) definitions. */
#include "mx/defs/acc.hpp"

#else // __HP_aCC

    #error Unsupported compiler for Unix platform. \
    See mx/defs/unix.hpp for the list of supported compilers.

#endif // __HP_aCC

#endif // __xlC__

#endif // __GNUC__


#endif // MXCPP_SYSDEF_UNIX_H_INCLUDE_GUARD

/* EOF */
