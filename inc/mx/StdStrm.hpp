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

    Standard Input/Output streams (interface).

    @author Emil Maskovsky
*/


#ifndef MXCPP_SYSDEFS
#include "mx/sysdefs.hpp"
#endif


#ifndef MXCPP_STANDARD_STREAM_HPP_INCLUDE_GUARD
#define MXCPP_STANDARD_STREAM_HPP_INCLUDE_GUARD


#ifndef MXCPP_TYPES
#include "mx/types.hpp"
#endif

#include "mx/FileStrm.hpp"


namespace mx
{


// Set of standard FileStreams.

extern MXCPP_DLL_EXPORT_DATA(FileStream &) StandardInput;
extern MXCPP_DLL_EXPORT_DATA(FileStream &) StandardOutput;
extern MXCPP_DLL_EXPORT_DATA(FileStream &) StandardError;


} // namespace mx


/// @todo Replace standard C++ stream implementations using these.


// Define inline methods here if inlining is enabled.
#ifdef MX_INLINE_ENABLED
#include "mx/StdStrm.inl"
#endif

#endif // MXCPP_STANDARD_STREAM_HPP_INCLUDE_GUARD

/* EOF */
