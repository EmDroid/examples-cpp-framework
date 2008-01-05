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

    Standard DLL exports.

    @author Emil Maskovsky
*/


#pragma once


#ifndef MXCPP_SYSDEF_STANDARD_DLL_EXPORTS_H_INCLUDE_GUARD
#define MXCPP_SYSDEF_STANDARD_DLL_EXPORTS_H_INCLUDE_GUARD


#ifdef MX_PLATFORM_OS_WIN32


#ifdef MX_MAKEDLL
    #define MX_DLL_EXPORT  __declspec(dllexport)
#else
#ifdef MX_USEDLL
    #define MX_DLL_EXPORT  __declspec(dllimport)
#else
    #define MX_DLL_EXPORT
#endif
#endif


#ifdef MXCPP_MAKEDLL
    #define MXCPP_DLL_EXPORT  __declspec(dllexport)
#else
#ifdef MXCPP_USEDLL
    #define MXCPP_DLL_EXPORT  __declspec(dllimport)
#else
    #define MXCPP_DLL_EXPORT
#endif
#endif


#endif /* MX_PLATFORM_OS_WIN32 */


#endif /* MXCPP_SYSDEF_STANDARD_DLL_EXPORTS_H_INCLUDE_GUARD */

/* EOF */