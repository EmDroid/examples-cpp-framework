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

    Out of memory exception (inline methods).

    @author Emil Maskovsky
*/


/**
    Constructor.

    @param [in] iSizeRequested @copydoc m_iSizeRequested
*/
/* explicit */ MX_INLINE mx::OutOfMemory::OutOfMemory(
        const Size iSizeRequested)
    : m_iSizeRequested(iSizeRequested)
{}


/* MX_OVERRIDDEN */ MX_INLINE const char * mx::OutOfMemory::what() const
{
    return Super::what();
}


/* EOF */
