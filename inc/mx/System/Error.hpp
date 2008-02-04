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

    System error handling (interface).

    @author Emil Maskovsky
*/


#ifndef MXCPP_SYSDEFS
#include "mx/sysdefs.hpp"
#endif

#ifndef MXCPP_TYPES
#include "mx/types.hpp"
#endif


#ifndef MXCPP_SYSTEM_EXCEPTION_HPP_INCLUDE_GUARD
#define MXCPP_SYSTEM_EXCEPTION_HPP_INCLUDE_GUARD


#include "mx/Except.hpp"


namespace mx
{


/**
    System API related exception.
*/
class MXCPP_DLL_EXPORT SystemApiException
    : public SystemException
{

    MX_DECLARE_EXCEPTION_CLASS(SystemApiException, SystemException);

// Construction, destruction.

public:

    MX_INLINE SystemApiException(const char * const sApiFuncName);


}; // class SystemApiException


} // namespace mx


// Define inline methods here if inlining is enabled.
#ifdef MX_INLINE_ENABLED
#include "mx/System/Error.inl"
#endif

#endif // MXCPP_SYSTEM_EXCEPTION_HPP_INCLUDE_GUARD

/* EOF */
