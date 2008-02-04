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

    description (inline methods).

    @author Emil Maskovsky
*/


/**
    Get the attribute.

    @return
    The value of the attribute.
*/
/* static */ MX_INLINE int mx::Template::getStaticAttribute()
{
    return sm_iStaticAttribute;
}


/**
    Set the attribute.

    @param [in] iValue @copydoc sm_iStaticAttribute

    @return
    The old value of the attribute.
*/
/* static */ MX_INLINE int mx::Template::setStaticAttribute(const int iValue)
{
    const int iOldValue = sm_iStaticAttribute;
    sm_iStaticAttribute = iValue;
    return iOldValue;
}


/**
    Default constructor.

    @param [in] iValue @copydoc m_iAttributeName
*/
/* explicit */ MX_INLINE mx::Template::Template(const int iValue)
    : m_iAttributeName(iValue)
{}


/**
    Destructor.
*/
virtual MX_INLINE mx::Template::~Template()
{}


/**
    Copy constructor.
*/
MX_INLINE mx::Template::Template(const Template & other)
    : m_iAttributeName(other.m_iAttributeName)
{}


/**
    Get the attribute.

    @return
    The value of the attribute.
*/
MX_INLINE int mx::Template::getAttribute() const
{
    return m_iAttributeName;
}


/**
    Set the attribute.

    @param [in] iValue @copydoc m_iAttributeName

    @return
    The old value of the attribute.
*/
MX_INLINE int mx::Template::setAttribute(const int iValue)
{
    const int iOldValue = m_iAttributeName;
    m_iAttributeName = iValue;
    return iOldValue;
}


/* EOF */
