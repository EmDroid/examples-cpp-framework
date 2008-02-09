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

    description (interface).

    @author Emil Maskovsky
*/


#ifndef MXCPP_SYSDEFS
#include "mx/sysdefs.hpp"
#endif


#ifndef MXCPP_TEMPLATE_HPP_INCLUDE_GUARD
#define MXCPP_TEMPLATE_HPP_INCLUDE_GUARD


#ifndef MXCPP_TYPES
#include "mx/types.hpp"
#endif


namespace mx
{


/**
    description.
*/
class MXCPP_DLL_EXPORT Template
{

    MX_CLASS_NO_COPY(Template);
    MX_CLASS_NO_ASSIGNMENT(Template);

// Types, constants etc.

public:

// Class methods (static).

public:

    static MX_INLINE int getStaticAttribute();

    static MX_INLINE int setStaticAttribute(const int iValue = 0);

protected:

private:

// Class attributes (static).

protected:

private:

    static int sm_iStaticAttribute;


// Construction, destruction.

public:

    explicit MX_INLINE Template(const int iValue = 0);

    virtual MX_INLINE ~Template();

    MX_INLINE Template(const Template & other);


// Operators.

public:

    const Template &
    operator = (const Template & other);


// Class instance methods.

public:

    MX_INLINE int getAttribute() const;

    MX_INLINE int setAttribute(const int iValue = 0);

protected:

private:

// Class instance attributes.

protected:

private:

    /// Description.
    const int m_iAttributeName;


}; // class Template


} // namespace mx


// Define inline methods here if inlining is enabled.
#ifdef MX_INLINE_ENABLED
#include "mx/template.inl"
#endif

#endif // MXCPP_TEMPLATE_HPP_INCLUDE_GUARD

/* EOF */
