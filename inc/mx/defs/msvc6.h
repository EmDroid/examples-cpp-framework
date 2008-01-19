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

    Microsoft Visual C++ 6.0 compiler specific definitions.

    @author Emil Maskovsky
*/


#ifndef MXCPP_SYSDEF_MSVC6_H_INCLUDE_GUARD
#define MXCPP_SYSDEF_MSVC6_H_INCLUDE_GUARD


/** The compiler does not have the "std::" namespace. */
#define MXCPP_FIX_HAS_NOT_STD_NAMESPACE

/* Disable warning: typedef-name used as synonym for class-name */
    #pragma warning(disable : 4097)


#endif /* MXCPP_SYSDEF_MSVC6_H_INCLUDE_GUARD */

/* EOF */
