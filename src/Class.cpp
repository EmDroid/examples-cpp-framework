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
#include "mx/debug.h"


/* Application specific. */
#include "mx/Class.hpp"


#ifndef MXCPP_FIX_USE_OLD_C_HEADERS

#include <typeinfo>

#else /* MXCPP_FIX_USE_OLD_C_HEADERS */

#include <typeinfo.h>

#endif /* MXCPP_FIX_USE_OLD_C_HEADERS */


/* virtual */ mx::Class::~Class()
{}


const char * mx::Class::getName() const
{
    // Instead of implementing virtual GetName() method in all derived
    // classes, we have decided to use the name() provided by the run-time
    // type identification system. However, that name is mangled and the
    // mangling is compiler dependent (it actually does not have to be a
    // name at all, just something unique). However, the heuristics used
    // below seems to work reasonably well for now.
    const char * const sTypeidName = typeid(*this).name();
    mxAssert(sTypeidName != NULL);
    /**
        @todo
        typeid() fails to work under some compilers (Watcom Win16 for now), maybe
        we can implement some our own RTTI?
    */

    static const char * const sUnknown = "Unknown";
    const char * sClassName = (sTypeidName ? sTypeidName : sUnknown);

    // Strip the prefix up to the last digit. The rest should be the name of
    // the class itself.
    for (const char * s = sTypeidName; *s; ++s)
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
        sClassName = sTypeidName;
    }

    // Return whatever we think the name is.
    return sClassName;
}


// Define inline methods here if inlining is disabled.
#ifndef MX_INLINE_ENABLED
#include "mx/Class.inl"
#endif

/* EOF */
