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

    Standardized basic data types.

    @author Emil Maskovsky
*/


#ifndef MXCPP_TYPES
#define MXCPP_TYPES


/**
    Main namespace of @project.

    Namespaces are used by @project to prevent confusion of names.
*/
namespace mx
{


/**
    Standard size type.

    Will become 4 B (long) on 32-bit systems, 2 B (short) on 16-bit systems
    (the total range the system can address).

    @note
    This type is always unsigned, some algorithms rely on it (e.g.
    (Size)(-1) for maximal size can be used). This can faster and simplify
    some algorithms (avoid some checks).
*/
typedef size_t Size;


/**
    @type Char

    Independent character type.

    This is character type compatible between ANSI and UNICODE builds - it is
    defined as single-byte character in ANSI mode and multi-byte in UNICODE
    builds.

    @see @ref unicode
*/

#ifndef MXCPP_UNICODE

typedef char Char;

#else // MXCPP_UNICODE

typedef wchar_t Char;

#endif // MXCPP_UNICODE


/**
    Get translation of the string.

    Returns the translation of string @p str in the current locale. If the string
    is not found in any of the loaded message catalogs the original string is
    returned.

    @param [in] str The string to be translated.

    As this function is used very often, an alternative (and also common in Unix
    world) syntax is provided: the _() macro is defined to do the same thing as
    GetTranslation().

    @return
    The translated string.

    @see _()
    @see mxTranslate()
*/
inline const Char * GetTranslation(const Char * const str)
{
    return str;
}


} // namespace mx


#endif // MXCPP_TYPES

/* EOF */
