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


#ifndef MXCPP_SYSDEF_HELPERS_H_INCLUDE_GUARD
#define MXCPP_SYSDEF_HELPERS_H_INCLUDE_GUARD


#ifndef __cplusplus

/* does not work in borlandc
 #define const */

#endif /* __cplusplus */


#if (!defined(MXCPP_FIX_USE_OLD_C_HEADERS) && defined(__cplusplus))

#include <cstdlib>
#include <cstdio>
#include <cstdarg>
#include <cerrno>

#else /* MXCPP_FIX_USE_OLD_C_HEADERS */

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <errno.h>

#endif /* MXCPP_FIX_USE_OLD_C_HEADERS */


#ifdef __cplusplus

// C++ only standard headers.


#if (!defined(MXCPP_FIX_USE_OLD_C_HEADERS) \
    && !defined(MXCPP_FIX_HAS_NOT_STD_NAMESPACE))

using namespace std;

/*
namespace std
{
    extern "C" int fprintf(FILE *, const char *, ...);
}
*/

#endif // MXCPP_FIX_HAS_NOT_STD_NAMESPACE

#endif /* __cplusplus */


#ifndef MX_DLL_EXPORT
#define MX_DLL_EXPORT
#endif

#ifndef MXCPP_DLL_EXPORT
#define MXCPP_DLL_EXPORT
#endif


#ifndef MXCPP_UNICODE
#define mxT(string)  string
#else
#define mxT(string)  L ## string
#endif

#define _(string)  string

#define _T(string)  mxT(string)


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
#ifdef MX_INLINE_ENABLED
#define MX_INLINE  inline
#else
#define MX_INLINE
#endif


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
#ifdef DOXYGEN
#define MX_UNUSED(parameter)  parameter
#else
#define MX_UNUSED(parameter)
#endif


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

    @param format_index    Index of formatting string parameter.
    @param arguments_index Index of the @c ... parameter.

    This macro is used in declarations of functions which accept arguments
    formatted the same way as the @c printf(3) functions.

    If the compilator supports it, this macro will make sure that the
    arguments are checked and warning is generated if they don't match the
    provided formatting string.

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

    @param format_index    Index of formatting string parameter.
    @param arguments_index Index of the @c ... parameter.

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


#ifdef __cplusplus

// C++ only declarations.


/**
    Use variable or function
    (to be always instantiated or prevent unused warning).
*/
template< class Type >
void mxUse(Type)
{}


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
         virtual void fce(void);
    };

    class DerivedClass: public BaseClass {
    public:
         MX_OVERRIDDEN void fce(void);
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
    @def MX_FINAL

    Final method declaration.

    This macro is used in declarations of final methods.

    These methods are not overridable.

    For example,
    @code
    class MyClass {
    public:
         MX_FINAL void operate(void);
    };
    @endcode
*/
#ifndef MX_FINAL
#define MX_FINAL
#endif


/**
    Disable implicit copy constructor.

    @param type Type of the class being defined.

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

    @param type Type of the class being defined.

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


#endif /* __cplusplus */


#endif /* MXCPP_SYSDEF_HELPERS_H_INCLUDE_GUARD */

/* EOF */
