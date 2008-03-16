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

    Common IBM CPP (Mainframe MVS/TSO) compiler specific definitions.

    @author Emil Maskovsky
*/


#ifndef MX_PLATFORM_COMPILER_IBM

#define MX_PLATFORM_COMPILER_IBM


#if (__IBMCPP__ < 41020)
// There is an old compiler version on the mainframe.

/// The compiler does not support new C++ style headers.
#define MXCPP_FIX_USE_OLD_C_HEADERS

/// The compiler does not have standard C++ exceptions defined.
#define MXCPP_FIX_NO_STD_EXCEPTION

/// The compiler does not have standard C++ cast operators defined.
#define MXCPP_FIX_DOES_NOT_HAVE_STANDARD_CAST_OPERATORS

/// Exception handlers are not supported by the compiler.
#define MXCPP_FIX_EH_UNSUPPORTED

// Compiler does't have boolean type.
#define MXCPP_FIX_DOES_NOT_HAVE_BOOL

// The compiler doesn't know "inline" keyword.
#define MXCPP_FIX_DOES_NOT_HAVE_INLINE

// The compiler doesn't know "explicit" keyword.
#define MXCPP_FIX_DOES_NOT_HAVE_EXPLICIT

// The compiler doesn't know "mutable" keyword.
#define MXCPP_FIX_DOES_NOT_HAVE_MUTABLE

// The compiler doesn't know "typename" keyword.
#define MXCPP_FIX_DOES_NOT_HAVE_TYPENAME


#endif // xlC < 0x0405


#endif // MX_PLATFORM_COMPILER_IBM

/* EOF */
