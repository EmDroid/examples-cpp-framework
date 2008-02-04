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

    description (implementation).

    @author Emil Maskovsky
*/


/* Framework libraries. */


/* Application specific. */
#include "mx/template.hpp"


/// Description.
/* static */ int mx::Template::sm_iStaticAttribute = 0;


/**
    Assignment operator.

    @param [in] other The other instnce, which will be assigned to the object.

    @return
    Reference to current object.
*/
const mx::Template &
mx::Template::operator = (const Template & other)
{
    // Do not touch the object, if assigned to itself.
    if (this != &other)
    {

        /* If the class contains any attribute, whose copy operation might fail
            (throw an exception, exit, or whatever), use following scheme for the
            copy operations.

            This scheme can be simplified by using direct assignment of
            attributes, only if there is none attribute, whose copy operation
            might fail (this means, all attributes are simple types or simple
            classes, whose copy constructors cannot fail or throw).
        */

        // Check attribute values.

        // Create new set of attributes.
        // (this is to prevent to leave the object in inconsistent state, if the
        // copy operation, allocation or whatever might potentialy fail)
        const int iAttributeNew = other.m_iAttributeName;

        // Store old set of attributes.
        const int iAttributeOld = m_iAttributeName;

        // Assing the new set of attributes to the object now.
        m_iAttributeName = iAttributeNew;

        // Destroy the old set of attributes.
        // (this is for attributes, whose destruction might fail - destroying
        // after the object is in the new consistent state)
    }
    return *this;
}


// Define inline methods here if inlining is disabled.
#ifndef MX_INLINE_ENABLED
#include "mx/template.inl"
#endif

/* EOF */
