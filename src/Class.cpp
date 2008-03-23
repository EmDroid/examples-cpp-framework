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

    Class base (implementation).

    @author Emil Maskovsky
*/


/* System libraries. */


/* Framework libraries. */
#include "mx/Debug.hpp"


/* Application specific. */
#include "mx/Class.hpp"


#ifndef MXCPP_FIX_USE_OLD_C_HEADERS
#include <typeinfo>
#else
#include <typeinfo.h>
#endif


/**
    @page typeinfo Runtime type information (RTTI)

    We support using of typeinfo. The application must be build with @ref RTTI
    enabled.
*/


/**
    Filter the name provided by the compiler RTTI subsystem.

    Tries to de-mangle the name provided by the C++ typeid() construct. The
    typeid().name() returns compiler-dependent unique class identifier, which is
    mangled class name in most cases. This filter de-mangles it, where possible.

    @param [in] sTypeName The mangled type name, typically provided by the
                          typeid().name() construct.

    It is designed to be (e.g.) used following way:
    @code
    SomeClass theClassInstance;
    ...
    const char * const sClassName =
        Class::FilterTypeName(typeid(instance).name() );
    @endcode

    @return
    Filtered class name.
*/
/* static */ const char * mx::Class::FilterTypeName(
        const char * const sTypeName)
{
    mxAssert(sTypeName != NULL);

    static const char * const sUnknown = "Unknown";
    const char * sClassName = (sTypeName ? sTypeName : sUnknown);

    // Strip the prefix up to the last digit. The rest should be the name of
    // the class itself.
    for (const char * s = sClassName; *s; ++s)
    {
        const char c = *s;
        const bool bDigitFound = ((c >= '0') && (c <= '9'));
        const bool bSpaceFound = (' ' == c);
        if (bDigitFound || bSpaceFound)
        {
            sClassName = (s + 1);
        }
    }

    // In case the string ended with a digit, the heuristics above did not
    // work. In such case, return the whole string instead of the useless
    // empty string.
    const bool bNameIsEmpty = ('\0' == *sClassName);
    if (bNameIsEmpty)
    {
        sClassName = sTypeName;
    }

    // Return whatever we think the name is.
    return sClassName;
}


/**
    Get the class "name".

    @return
    The class identifier (aka "name").
*/
const char * mx::Class::getName() const
{
    // Instead of implementing virtual GetName() method in all derived
    // classes, we have decided to use the name() provided by the run-time
    // type identification system. However, that name is mangled and the
    // mangling is compiler dependent (it actually does not have to be a
    // name at all, just something unique). However, the heuristics used
    // below seems to work reasonably well for now.
    return FilterTypeName(typeid(*this).name());
    /**
        @todo
        typeid() fails to work under some compilers (Watcom Win16 for now), maybe
        we can implement some our own RTTI?
    */
}


// Define inline methods here if inlining is disabled.
#ifndef MX_INLINE_ENABLED
#include "mx/Class.inl"
#endif

/* EOF */
