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

    IBM Mainframe system specific definitions.

    @author Emil Maskovsky
*/


#ifndef MXCPP_SYSDEF_MVS_HPP_INCLUDE_GUARD
#define MXCPP_SYSDEF_MVS_HPP_INCLUDE_GUARD


// Enable inlining for the MVS/TSO platforms by default.
#ifndef MX_INLINE_ENABLED
#define MX_INLINE_ENABLED
#endif


#ifdef __IBMCPP__

/* IBM C++ Compiler definitions. */
#include "mx/defs/ibmcpp.hpp"

#else // __IBMCPP__

    #error Unsupported compiler for MVS/TSO platform. \
    See mx/defs/mvs.hpp for the list of supported compilers.

#endif // __IBMCPP__


#endif // MXCPP_SYSDEF_MVS_HPP_INCLUDE_GUARD

/* EOF */
