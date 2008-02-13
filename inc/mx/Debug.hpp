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

    Debugging functions (interface).

    @author Emil Maskovsky
*/


#ifndef MXCPP_SYSDEFS
#include "mx/sysdefs.hpp"
#endif


#ifndef MXCPP_DEBUG_HPP_INCLUDE_GUARD
#define MXCPP_DEBUG_HPP_INCLUDE_GUARD


#ifndef MXCPP_TYPES
#include "mx/types.hpp"
#endif


/**
    @internal

    Shortcut wrapper around mx::Debug::Checkpoint().

    Calls mx::Debug::Checkpoint() with current source file name and line number
    as provided by the preprocessors macros @c __FILE__ and @c __LINE__.

    @warning
    This macro is to be used only by debugging macros defined in
    Debug.hpp. Never ever use this directly.
*/
#define __mxDebugCheckpoint__() \
    mx::Debug::Checkpoint(MXCPP_FILE, __LINE__)


/**
    @def mxCheck

    Print @a condition in case it does not evaluate to @c true.

    @param [in] cond Expression to evaluate.

    @note
    This macro is defined as no-op if not #MXCPP_DEBUG_ENABLED is defined.

    @warning
    The condition must not use any sideffects due to the above reason.
    In particular, avoid calling any functions and/or using @c ++ or @c --
    operators inside the @a condition expression.

    @return
    Returns @c true, if the @a condition does not fail.
    Returns @c false, if the @a condition evaluation failed (does evaluate to
    @c true).
    Can be used in @c if conditions etc., but normally it is not very common to be
    used such way.

    @see mxAssert() for more strict version of this macro.
    @see mx::Debug::Check() for implementation details.
*/

/**
    @def mxAssert

    Print @a condition and dump core in case it does not evaluate to @c true.

    @param [in] cond Expression to evaluate.

    @note
    This macro is defined as no-op if not #MXCPP_DEBUG_ENABLED is defined.

    @warning
    The condition must not use any sideffects due to the above reason.
    In particular, avoid calling any functions and/or using @c ++ or @c --
    operators inside the @a condition expression.

    @return
    Returns @c true, if the @a condition does not fail.
    Returns @c false, if the @a condition evaluation failed (does evaluate to
    @c true) - in the case it does not fail directly.
    Can be used in @c if conditions etc., but normally it is not very common to be
    used such way.

    @see mxCheck() for less strict version of this macro.
    @see mx::Debug::Assert() for implementation details.
*/
#ifndef MXCPP_DEBUG_ENABLED

#define mxCheck(cond)   ((void)0)
#define mxAssert(cond)  ((void)0)

#else // MXCPP_DEBUG_ENABLED

#define mxCheck(cond) \
    ((cond) ? (void)0 \
     : (mx::Debug::Check(__mxDebugCheckpoint__(), _T(#cond))))

#define mxAssert(cond) \
    ((cond) ? (void)0  \
     : (mx::Debug::Assert(__mxDebugCheckpoint__(), _T(#cond))))

#endif // MXCPP_DEBUG_ENABLED


/**
    Variant of mxAssert() for testing programs.

    This macro is identical to mxAssert() except that it is always defined,
    regardless of #MXCPP_DEBUG_ENABLED setting.

    @param [in] cond Expression to evaluate.

    Unlike mxAssert(), it may invoke any code, including code which causes side
    effects. It is actually pretty common to use it for testing return values
    of functions.

    It should be used only in testing programs. Testing programs must use it
    instead of mxAssert().
*/
#define mxTest(cond)  \
    ((cond) ? (void)0 \
     : (mx::Debug::Assert(__mxDebugCheckpoint__(), _T(#cond))))


namespace mx
{


/**
    The debugging sysbystem.
*/
class MXCPP_DLL_EXPORT Debug
{

    MX_CLASS_NO_COPY(Debug);
    MX_CLASS_NO_ASSIGNMENT(Debug);

// Types, constants etc.

public:

    /**
        Checkpoint for storing current source file name and line number.
    */
    class MXCPP_DLL_EXPORT Checkpoint
    {

        // Types, constants etc.

    public:

        /// The type of checkpointed file name.
        typedef const Char * FileName;

        /// The type of checkpointed line number.
        typedef unsigned long FileLine;


        // Construction, destruction.

    public:

        explicit MX_INLINE Checkpoint(
                const FileName sFile = NULL,
                const FileLine nLine = 0);


        // Class instance methods.

    public:

        MX_INLINE FileName getFile() const;

        MX_INLINE FileLine getLine() const;

        MX_INLINE bool Empty() const;


        // Class instance attributes.

    private:

        /// The checkpointed file name.
        FileName m_sFile;

        /// The checkpointed line number.
        FileLine m_nLine;


    }; // class Debug::Checkpoint


// Class methods (static).

public:

    static void Check(
            const Checkpoint & xFileInfo,
            const Char * const sCondition,
            const Char * const sMessage = NULL);

    static MX_NORETURN Assert(
            const Checkpoint & xFileInfo,
            const Char * const sCondition,
            const Char * const sMessage = NULL);


}; // class Debug


} // namespace mx


// Redefine standard assert() macros.

#ifdef assert
#undef assert
#endif


/**
    Synonym for mxAssert().

    This is an override of standard assert() macro, to always use @project
    debugging engine.
*/
#define assert(cond)  mxAssert(cond)


// Define inline methods here if inlining is enabled.
#ifdef MX_INLINE_ENABLED
#include "mx/Debug.inl"
#endif

#endif /* MXCPP_DEBUG_HPP_INCLUDE_GUARD */

/* EOF */
