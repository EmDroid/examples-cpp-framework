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
    @internal

    @file

    Standard DLL exports.

    @author Emil Maskovsky
*/


#ifndef MXCPP_SYSDEF_STANDARD_DLL_EXPORTS_HPP_INCLUDE_GUARD
#define MXCPP_SYSDEF_STANDARD_DLL_EXPORTS_HPP_INCLUDE_GUARD


#ifdef MX_PLATFORM_OS_WIN32


#ifdef MX_MAKEDLL
#   define MX_DLL_EXPORT             __declspec(dllexport)
#   define MX_DLL_EXPORT_DATA(type)  __declspec(dllexport) type
#else
#ifdef MX_USEDLL
#   define MX_DLL_EXPORT             __declspec(dllimport)
#   define MX_DLL_EXPORT_DATA(type)  __declspec(dllimport) type
#endif
#endif


#ifdef MXCPP_MAKEDLL
#   define MXCPP_DLL_EXPORT             __declspec(dllexport)
#   define MXCPP_DLL_EXPORT_DATA(type)  __declspec(dllexport) type
#else
#ifdef MXCPP_USEDLL
#   define MXCPP_DLL_EXPORT             __declspec(dllimport)
#   define MXCPP_DLL_EXPORT_DATA(type)  __declspec(dllimport) type
#endif
#endif


#else // MX_PLATFORM_OS_WIN32


#ifdef MX_PLATFORM_OS_WIN16


#ifdef MX_MAKEDLL
#   define MX_DLL_EXPORT             __declspec(dllexport) __declspec(__pascal)
#   define MX_DLL_EXPORT_DATA(type)  __declspec(dllexport) type
#else
#ifdef MX_USEDLL
#   define MX_DLL_EXPORT             __declspec(__pascal)
#   define MX_DLL_EXPORT_DATA(type)  type
#endif
#endif


#ifdef MXCPP_MAKEDLL
#   define MXCPP_DLL_EXPORT             __declspec(dllexport) __declspec(__pascal)
#   define MXCPP_DLL_EXPORT_DATA(type)  __declspec(dllexport) type
#else
#ifdef MXCPP_USEDLL
#   define MXCPP_DLL_EXPORT             __declspec(__pascal)
#   define MXCPP_DLL_EXPORT_DATA(type)  type
#endif
#endif


#endif // MX_PLATFORM_OS_WIN16

#endif // MX_PLATFORM_OS_WIN32


#endif // MXCPP_SYSDEF_STANDARD_DLL_EXPORTS_HPP_INCLUDE_GUARD

/* EOF */
