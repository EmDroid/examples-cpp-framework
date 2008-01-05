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

    @brief Demo C++ Framework.

    @author Emil Maskovsky
*/


#ifndef MXCPP_H_INCLUDE_GUARD
#define MXCPP_H_INCLUDE_GUARD


/* C and C++ headers. */

#include "mx/sysdefs.h"
#include "mx/types.h"

#include "mx/debug.h"
#include "mx/malloc.h"


#ifdef __cplusplus
// C++ only headers.

// Core library headers.
#include "mx/Except.hpp"
#include "mx/new.hpp"
#include "mx/Memory.hpp"
#include "mx/Stream.hpp"
#include "mx/FileStrm.hpp"
#include "mx/StdStrm.hpp"

// System library headers.
#include "mx/System/Error.hpp"


#endif /* __cplusplus */


#endif /* MXCPP_H_INCLUDE_GUARD*/

/* EOF */
