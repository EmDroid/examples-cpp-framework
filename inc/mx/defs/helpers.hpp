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

    System helper macros.

    @author Emil Maskovsky
*/


#ifndef MXCPP_SYSDEF_HELPERS_HPP_INCLUDE_GUARD
#define MXCPP_SYSDEF_HELPERS_HPP_INCLUDE_GUARD


/* Standard headers. */
#ifndef MXCPP_FIX_USE_OLD_C_HEADERS

#include <new>
#include <cstdlib>
#include <cstdio>
#include <cstdarg>
#include <cstring>
#include <cerrno>
#include <cwchar>
#include <exception>
#include <cassert>  // for assert() macro override

#ifndef MXCPP_FIX_HAS_NOT_STD_NAMESPACE
using namespace std;
#endif // MXCPP_FIX_HAS_NOT_STD_NAMESPACE


#else // MXCPP_FIX_USE_OLD_C_HEADERS

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include <wchar.h>
#include <assert.h>  // for assert() macro override


// Implementation of exception classes for compilers, which lack it.
namespace std
{


// Implementation of std::exception class.
class exception
{
public:

    inline exception()
    {}

    virtual inline ~exception()
    {}

    virtual inline const char * what() const
    {
        return NULL;
    }

};


}


#endif // MXCPP_FIX_USE_OLD_C_HEADERS


/**
    @internal

    Global inlining flag.

    Values:
    @li @c 0: inlining always disabled
    @li @c 1: inlinig always enabled
    @li any other: use inlining setup from system definitions
*/
#define MXCPP_INLINE_GLOBAL  1

/// @addtogroup build_config
///@{
/**
    @def MX_INLINE_ENABLED

    Defined if inlining is enabled.
*/
#if (MXCPP_INLINE_GLOBAL == 1)
#define MX_INLINE_ENABLED
#endif
///@}

#ifdef MX_INLINE_ENABLED
#if (MXCPP_INLINE_GLOBAL == 0)
#undef MX_INLINE_ENABLED
#endif
#endif

#undef MXCPP_INLINE_GLOBAL


/**
    @def MX_DLL_EXPORT

    Define how to export the functions or classes.

    Can be used by the projects dependent on the library to conveniently export
    from libraries.
*/

/**
    @def MX_DLL_EXPORT_DATA

    Define how to export the data.

    @param [in] type The type of data to be exported.

    Can be used by the projects dependent on the library to conveniently export
    from libraries.
*/

#if !defined(MX_DLL_EXPORT)
#define MX_DLL_EXPORT
#endif

#if !defined(MX_DLL_EXPORT_DATA)
#define MX_DLL_EXPORT_DATA(type)  type
#endif


/**
    @internal

    @def MXCPP_DLL_EXPORT

    Define how to export the functions or classes from the @project.

    Should not be used outside the @project itself, you might want to use the
    #MX_DLL_EXPORT convenience macro instead..
*/

/**
    @internal

    @def MXCPP_DLL_EXPORT_DATA

    Define how to export the data from the @project.

    @param [in] type The type of data to be exported.

    Should not be used outside the @project itself, you might want to use the
    #MX_DLL_EXPORT_DATA convenience macro instead..
*/

#if !defined(MXCPP_DLL_EXPORT)
#define MXCPP_DLL_EXPORT
#endif

#if !defined(MXCPP_DLL_EXPORT_DATA)
#define MXCPP_DLL_EXPORT_DATA(type)  type
#endif


#ifdef _T
#undef _T
#endif

/**
    @def _T

    Synonym for mxT().

    @param [in] x The input literal.
*/
#ifndef MXCPP_UNICODE
#define _T(x)  x
#else
#define _T(x)  L ## x
#endif

#ifdef _TEXT
#undef _TEXT
#endif

/**
    Another synonym for mxT().
*/
#define _TEXT(x)  _T(x)


/* Although global macros with such names are normally bad, we want to have
    another name for _T() which should be used to avoid confusion between _T()
    and _() in @project sources.
*/

/**
    Generic text mapping macro.

    @param [in] x The input literal.

    Can be used with character and string literals (in other words, 'x' or "foo")
    to automatically convert them to Unicode in Unicode build configuration.
    Please see @ref unicode for more information.

    This macro simply returns the value passed to it without changes in ASCII
    build. In fact, its definition is:
    @code
    #ifdef UNICODE
    #define mxT(x) L ## x
    #else // !Unicode
    #define mxT(x) x
    #endif
    @endcode

    @warning
    This macro cannot be used to convert strings or characters stored in
    variables to unicode!

    @see @ref unicode
*/
#define mxT(x)  _T(x)


/**
    Translate string.

    The translation engine is not available in this demo, all it the function
    does is rerutning the string unchanged.

    @param [in] str The string to be translated.

    @return
    The translated string.

    @see mxTranslate()
    @see mx::GetTranslation()
*/
#define _(str)  mxT(str)


/**
    Unicode friendly __FILE__ analog.
*/
#define MXCPP_FILE  mxT(__FILE__)


/**
    Does not perform actual translation, but marks strings to be translated.

    This macro is supposed to be used in the case, if we want to define string to
    be translated, but we do not want the actual translation to be done (e.g.
    i18n subsystem not yet set up).

    The actual translation shoud be then done using mx::GetTranslation()
    function.

    @param [in] str The string to be translated.

    @return
    The original string.

    @see _()
    @see mx::GetTranslation()
*/
#define mxTranslate(str)  mxT(str)


/**
    @def MX_INLINE

    Inline method declaration.

    This macro is used in declarations of inlined methods.

    For example,
    @code
    class SomeClass {
    public:
         MX_INLINE void fnc(void);
    };
    @endcode

    The implementation of inline methods is put into separate
    file with @c .inl suffix and is included in either the
    header file or the C++ source file, depending on whether the
    #MX_INLINE_ENABLED macro is defined or not.

    @see template.cpp, template.h and template.inl for
    how the inline files are included.
*/
#ifndef MX_INLINE_ENABLED

#ifdef MX_INLINE
#undef MX_INLINE
#endif
#define MX_INLINE

#else // MX_INLINE_ENABLED

#ifndef MX_INLINE
#define MX_INLINE  inline
#endif

#endif // MX_INLINE_ENABLED


/**
    @def MX_NORETURN_TYPE

    Mark functions which never return. Unlike #MX_NORETURN, this macro takes an
    argument of @a Type that is used in the function declaration as a return
    type.

    It may seem that it is useless to mark functions that return anything else
    than void as noreturn, however this is neccessary in some special cases.
    Suppose you have several functions with the same prototype - because you
    need to take pointer to that function - and one of them never returns.
    In such a case, you will use this macro.

    This macro is used in declarations and definitions of functions which never
    return.

    For example,
    @code
    MX_NORETURN_TYPE(bool) die(void);    // prototype
    ...
    MX_NORETURN_TYPE(bool) die(void)     // implementation
    {
         ...
         exit(EXIT_FAILURE) ;
    }
    @endcode
*/
#ifndef MX_NORETURN_TYPE
#define MX_NORETURN_TYPE(Type)  Type
#endif


/**
    @def MX_NORETURN

    Mark functions which never return.

    This macro is used in declarations and definitions of functions which never
    return.

    For example,
    @code
    MX_NORETURN die(void);    // prototype
    ...
    MX_NORETURN die(void)     // implementation
    {
         ...
         exit(EXIT_FAILURE);
    }
    @endcode

    @see #MX_NORETURN_TYPE for a similar macro that allows you to specify return
         type other that void.
*/
#ifndef MX_NORETURN
#define MX_NORETURN  MX_NORETURN_TYPE(void)
#endif


/**
    @def MX_UNUSED

    The method/function parameter is never used in the function body.

    @param [in] parameter Name of the parameter, that is unused.

    Whenever you have a prototype that contains parameters that are not
    used in the function body, mark them as unused. The documentation
    may then refer to them by name, and compiler will not complain.

    For example,
    @code
    int return_first_parameter(int first, int MX_UNUSED(second))
    {
        return first;
    }
    @endcode
*/
#define MX_UNUSED(parameter)


// Handy macros.

/**
    Calculate number of elements in @a array.

    This macro evaluates to number of elements in given array.

    @param [in] array The array which length is to be calculated.

    It is especially useful for checking if the array index is within the
    limits for the given array.
*/
#define mxArrayLength(array) \
    (sizeof((array)) / sizeof(*(array)))


/**
    @def MX_PRINTFLIKE

    Declaration of @c printf(3) like functions.

    @param [in] format_index    Index of formatting string parameter.
    @param [in] arguments_index Index of the @c ... parameter.

    This macro is used in declarations of functions which accept arguments
    formatted the same way as the @c printf(3) functions.

    If the compiler supports it, this macro will make sure that the arguments
    are checked and warning is generated if they don't match the provided
    formatting string.

    For example,
    @code
    MX_PRINTFLIKE(1,2) void custom_printf(const char * sFormat, ...);
    @endcode

    @see MX_PRINTFLIKE_METHOD() for usage within class methods.
*/

#ifndef MX_PRINTFLIKE
#define MX_PRINTFLIKE(format_index, arguments_index)
#endif

/**
    @def MX_SCANFLIKE

    Declaration of @c scanf(3) like functions.

    @param [in] format_index    Index of formatting string parameter.
    @param [in] arguments_index Index of the @c ... parameter.

    This macro is used in declarations of functions which accept arguments
    formatted the same way as the @c scanf(3) functions.

    If the compilator supports it, this macro will make sure that the
    arguments are checked and warning is generated if they don't match the
    provided formatting string.

    For example,
    @code
    int MX_SCANFLIKE(1,2) custom_scanf(const char * sFormat, ...);
    @endcode

    @see MX_SCANFLIKE_METHOD() for usage within class methods.
*/

#ifndef MX_SCANFLIKE
#define MX_SCANFLIKE(format_index, arguments_index)
#endif


/**
    @def MX_PRINTFLIKE_METHOD

    Declaration of @c printf(3) like methods.

    Like MX_PRINTFLIKE(), but for use in declarations of methods in classes.

    @see MX_PRINTFLIKE() for more info.
*/

#ifndef MX_PRINTFLIKE_METHOD
#define MX_PRINTFLIKE_METHOD(format_index, arguments_index)
#endif


/**
    @def MX_SCANFLIKE_METHOD

    Declaration of @c scanf(3) like methods.

    Like MX_SCANFLIKE(), but for use in declarations of methods in classes.

    @see MX_SCANFLIKE() for more info.
*/

#ifndef MX_SCANFLIKE_METHOD
#define MX_SCANFLIKE_METHOD(format_index, arguments_index)
#endif


/**
    @def MX_PURE

    Pure virtual method declaration.

    This macro is used in declarations of pure virtual methods in abstract
    classes.

    These methods are then the abstract methods, which must be overridden in
    class descendants.

    For example,
    @code
    class BaseClass {
    public:
         virtual void operate(void) MX_PURE;
    };
    @endcode
*/
#ifndef MX_PURE
#define MX_PURE  = 0
#endif


/**
    @def MX_OVERRIDDEN

    Overridden virtual method declaration.

    This macro is used in declarations of overridden virtual methods (aka
    reimplementations).

    For example,
    @code
    class BaseClass {
    public:
         virtual void operate(void);
    };

    class DerivedClass: public BaseClass {
    public:
         MX_OVERRIDDEN void operate(void);
    };
    @endcode

    This macro exists to distinguish between the base virtual function
    declaration and declarations of its reimplementations.

    @note
    This macro is by default defined as an alias for the @c virtual keyword.
    In case there is a compiler which has troubles when overridden virtual
    methods are declared using the @c virtual keyword, this macro can be
    eventually defined as an empty macro.
*/
#ifndef MX_OVERRIDDEN
#define MX_OVERRIDDEN  virtual
#endif


/**
    Disable implicit copy constructor.

    @param [in] type Type of the class being defined.

    Use this macro in class definition to prevent compiler from inserting
    implicit copy constructor when there should be none. Using this macro
    makes sure that a linker error is generated should the copy constructor
    for given class be used by mistake.

    For example,
    @code
    class SimpleClass {

         MX_CLASS_NO_COPY(SimpleClass);
         MX_CLASS_NO_ASSIGNMENT(SimpleClass);
    ...
    };
    @endcode

    @see MX_CLASS_NO_ASSIGNMENT() for complementary macro.
*/
#define MX_CLASS_NO_COPY(type) \
private:                       \
    type(const type &)


/**
    Disable implicit assignment operator.

    @param [in] type Type of the class being defined.

    Use this macro in class definition to prevent compiler from inserting
    implicit assignment operator when there should be none. Using this macro
    makes sure that a linker error is generated should the assignment
    operator for given class be used by mistake.

    For example,
    @code
    class SimpleClass {

         MX_CLASS_NO_COPY(SimpleClass);
         MX_CLASS_NO_ASSIGNMENT(SimpleClass);
    ...
    };
    @endcode

    @see MX_CLASS_NO_COPY() for complementary macro.
*/
#define MX_CLASS_NO_ASSIGNMENT(type) \
private:                             \
    type & operator = (const type &)


namespace mx
{


/**
    Use variable or function
    (to be always instantiated or prevent unused warning).

    @param [in] ident The identifier to be used.
*/
template< class Type >
void Use(const Type & MX_UNUSED(ident))
{}


/**
    Initializer for static arrays.

    It is designed for arrays initializer lists, to ensure that all array items
    are initialized in the statically allocated array.

    If you have an array of items with default constructor available (classes
    with default constructor or primitive types), the compiler only complain if
    there are too many initializer values, but will not give any notice in the
    case of too few initializers (which means that some values in the array will
    be initialized by default constructor, or possibly not at all in the case of
    primitive types, e.g. char *).
    This can then lead to bugs in the program, when developer extends the size of
    an array and forgets to add appropriate initializers into the array.

    The initializer class is supposed to be used following way:
    @code
    // Using the array initializer for the C-string type (char *).
    typedef ::ArrayItemInitializer< const char * > CharInitializer;
    const int STRINGS_SIZE = 3;
    const CharInitializer sMyStrings[ STRINGS_SIZE ] = {
        "String 1", // can be initialized direct through the item type
        "String 2",
        "String 3"
    };

    // Can direct use the items as contained type.
    strcpy(sMyStrings[ 2 ], sStrCopied);
    @endcode
    This avoids the posibility to have any uninitialized value in the array,
    while the ArrayItemInitializer does not have the default constructor and
    therefore all items in the array are forced by the compiler to be initialized.

    The array items can be used direct as when declared directly, because the
    initializer class has the cast-to-item-type operator.
*/
template< class ItemType >
class ArrayItemInitializer
{

    MX_CLASS_NO_ASSIGNMENT(ArrayItemInitializer);

// Construction, destruction.

public:

    /**
        Constructor taking the initializer value.

        @param [in] xInitializer The value of the initializer.
    */
    inline ArrayItemInitializer(const ItemType & xInitializer)
        : m_xInitializer(xInitializer)
    {}

    /**
        Copy constructor.

        @param [in] other The other object.
    */
    inline ArrayItemInitializer(const ArrayItemInitializer & other)
        : m_xInitializer(other.m_xInitializer)
    {}


// Class instance operators.

public:

    /**
        Cast-to-item-type operator.

        @return
        The initializer value.
    */
    inline operator const ItemType & () const
    {
        return m_xInitializer;
    }

// Class instance attributes.

private:

    /// The value of the initializer.
    const ItemType m_xInitializer;

}; // class ArrayItemInitializer< ... >


} // namespace mx


// First of all, define our own global delete operators to allow theyre proper
// inlining.

namespace mx
{


/**
    Real implementation of delete operators.
*/
class MXCPP_DLL_EXPORT OperatorDeleteImplementation
{

    MX_CLASS_NO_COPY(OperatorDeleteImplementation);
    MX_CLASS_NO_ASSIGNMENT(OperatorDeleteImplementation);

public:

    static void Delete(
            void * const pMemoryBlock,
            const bool bVectorFree = false);

}; // class OperatorDeleteImplementation


} // namespace mx


/**
    Global @c operator @c delete.

    The global @c delete operator is re-defined by the library to use the
    @project memory handling mechanism.

    @param [in] pMemoryBlock The address of allocated memory block to be deleted.
*/
inline void operator delete (void * pMemoryBlock)
throw()
{
    mx::OperatorDeleteImplementation::Delete(pMemoryBlock);
}


/**
    Global array @c operator @c delete.

    The global @c delete[] operator is re-defined by the library to use the
    @project memory handling mechanism.

    @param [in] pMemoryBlock The address of allocated memory block to be deleted.
*/
inline void operator delete[] (void * pMemoryBlock)
throw()
{
    mx::OperatorDeleteImplementation::Delete(pMemoryBlock, true);
}


// Debugging definitions.
#include "mx/Debug.hpp"

// Declaration of MemoryException to allow declaring of global new operators.
#include "mx/Except.hpp"


// Define our own global new operators.

namespace mx
{


/**
    Allocation operators real implementations.
*/
class MXCPP_DLL_EXPORT AllocOperatorsImplementation
{

    MX_CLASS_NO_COPY(AllocOperatorsImplementation);
    MX_CLASS_NO_ASSIGNMENT(AllocOperatorsImplementation);

public:

    static void * New(
            const Size iMemoryBlockSize,
            const Debug::Checkpoint & xFileInfo,
            const bool bVectorAlloc = false);

    static void Delete(
            void * const pMemoryBlock,
            const Debug::Checkpoint & xFileInfo,
            const bool bVectorFree = false);

}; // class AllocOperatorsImplementation


} // namespace mx


// The operators new and delete are always inlined, to allow usage even if the
// framework used as dll. These operators cannot be defined using the DLL
// linkage (under many compilers), therefore the indirect usage through
// AllocOperatorsImplementation is used.

/**
    Global @c operator @c new.

    The global @c new operator is re-defined by the library to use the
    @project memory handling mechanism.

    We define this @c new operator to provide some extra information into the
    memory allocation process. This is used in combination with the exception
    system to allow tracing of memory related problems.

    @param [in] iSize     Number of bytes to allocate.
    @param [in] sFileName The source file name.
    @param [in] nFileLine The source line number.

    @exception MemoryException
    Memory allocation problem occured.

    @return
    Returns address of newly allocated memory block.

    @internal

    This override of @c operator @c new is used along with the #new macro.

    @see macro #new
*/
inline void * operator new (
        // const doesn't work under some compilers (DMC).
        /* const */ mx::Size iSize,
        // There is problem using Debug::Checkpoint directly under some
        // compilers.
        const mx::Debug::Checkpoint::FileName sFileName,
        const mx::Debug::Checkpoint::FileLine nFileLine)
{
    return mx::AllocOperatorsImplementation::New(iSize,
            mx::Debug::Checkpoint(sFileName, nFileLine));
}


/**
    Global array @c operator @c new.

    The global @c new[] operator is re-defined by the library to use the
    @project memory handling mechanism.

    We define this @c new[] operator to provide some extra information into the
    memory allocation process. This is used in combination with the exception
    system to allow tracing of memory related problems.

    @param [in] iSize     Number of bytes to allocate.
    @param [in] sFileName The source file name.
    @param [in] nFileLine The source line number.

    @exception MemoryException
    Memory allocation problem occured.

    @return
    Returns address of newly allocated memory block.

    @internal

    This override of @c operator @c new is used along with the #new macro.

    @see macro #new
*/
inline void * operator new[] (
        /* const */ mx::Size iSize,
        const mx::Debug::Checkpoint::FileName sFileName,
        const mx::Debug::Checkpoint::FileLine nFileLine)
{
    return mx::AllocOperatorsImplementation::New(iSize,
            mx::Debug::Checkpoint(sFileName, nFileLine), true);
}


#ifdef MXCPP_FIX_DELETE_PARAMS_LIKE_NEW

// We do not require this, but some compilers (MSVC) must have defined
// delete operator with same parameters like new.


inline void operator delete (
        void * pMemoryBlock,
        const mx::Debug::Checkpoint::FileName sFileName,
        const mx::Debug::Checkpoint::FileLine nFileLine)
{
    mx::AllocOperatorsImplementation::Delete(pMemoryBlock,
            mx::Debug::Checkpoint(sFileName, nFileLine));
}


inline void operator delete[] (
        void * pMemoryBlock,
        const mx::Debug::Checkpoint::FileName sFileName,
        const mx::Debug::Checkpoint::FileLine nFileLine)
{
    mx::AllocOperatorsImplementation::Delete(pMemoryBlock,
            mx::Debug::Checkpoint(sFileName, nFileLine), true);
}


#endif // MXCPP_FIX_DELETE_PARAMS_LIKE_NEW


// Redefine standard new and delete operators.
#include "mx/defs/newdef.hpp"


/* Headers that are always included - redefining some standard definitions etc. */
#include "mx/Debug.hpp"
#include "mx/Memory.hpp"


#endif // MXCPP_SYSDEF_HELPERS_HPP_INCLUDE_GUARD

/* EOF */
