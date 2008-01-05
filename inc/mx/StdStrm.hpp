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


#ifndef MXCPP_STANDARD_STREAM_HPP_INCLUDE_GUARD
#define MXCPP_STANDARD_STREAM_HPP_INCLUDE_GUARD


#include "mx/sysdefs.h"

#include "mx/types.h"

#include "mx/FileStrm.hpp"


namespace mx
{


// Set of standard FileStreams.

extern MXCPP_DLL_EXPORT FileStream & StandardInput;
extern MXCPP_DLL_EXPORT FileStream & StandardOutput;
extern MXCPP_DLL_EXPORT FileStream & StandardError;


} // namespace mx


#endif // MXCPP_STANDARD_STREAM_HPP_INCLUDE_GUARD

/* EOF */
