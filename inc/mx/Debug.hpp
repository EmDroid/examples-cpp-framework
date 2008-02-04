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

#ifndef MXCPP_TYPES
#include "mx/types.hpp"
#endif


#ifndef MXCPP_DEBUG_HPP_INCLUDE_GUARD
#define MXCPP_DEBUG_HPP_INCLUDE_GUARD


#define mxDebugCheckpoint() \
    mx::Debug::Checkpoint(__FILE__, __LINE__)


#ifndef MXCPP_DEBUG_ENABLED

#define mxAssert(cond)

#else // MXCPP_DEBUG_ENABLED

#define mxAssert(cond) \
    mx::Debug::Check(!!(cond), mxDebugCheckpoint(),#cond)

#endif // MXCPP_DEBUG_ENABLED


/**
    Variant of Assert() for testing programs.

    This macro is identical to Assert() except that it is always defined,
    regardless of #MXCPP_DEBUG_ENABLED setting.

    @param [in] condition Expression to evaluate.

    Unlike Assert(), it may invoke any code, including code which causes side
    effects. It is actually pretty common to use it for testing return values
    of functions.

    It should be used only in testing programs. Testing programs must use it
    instead of Assert().
*/
#define mxTest(cond) \
    mx::Debug::Check(!!(cond), mxDebugCheckpoint(),#cond)


namespace mx
{


class MXCPP_DLL_EXPORT Debug
{

    MX_CLASS_NO_COPY(Debug);
    MX_CLASS_NO_ASSIGNMENT(Debug);

// Types, constants etc.

public:

    /**
        Debug checkpoint.
    */
    class MXCPP_DLL_EXPORT Checkpoint
    {

        // Types, constants etc.

    public:

        typedef const char * FileName;

        typedef unsigned long FileLine;


        // Construction, destruction.

    public:

        explicit MX_INLINE Checkpoint(
                const FileName sFile = NULL,
                const FileLine iLine = 0);


        // Class instance methods.

    public:

        MX_INLINE FileName getFile() const;

        MX_INLINE FileLine getLine() const;

        MX_INLINE bool Empty() const;


        // Class instance attributes.

    private:

        /// The checkpointed file name.
        FileName m_sFile;

        /// The checkpointed file line.
        FileLine m_iLine;


    }; // class Debug::Checkpoint


// Class methods (static).

public:

    static MX_INLINE void Check(
            /*  Note using "int" and not "bool" for cond to avoid VC++ warnings about
                 implicit conversions when doing "mxAssert(pointer)" and also use of
                 "!!cond" below to ensure that everything is converted to int
            */
            const int bCondition,
            const Checkpoint & xFileInfo,
            const char * const sCondition,
            const char * const sMessage = NULL);


}; // class Debug


} // namespace mx


#include "mx/Log.hpp"


// Define inline methods here if inlining is enabled.
#ifdef MX_INLINE_ENABLED
#include "mx/Debug.inl"
#endif

#endif /* MXCPP_DEBUG_HPP_INCLUDE_GUARD */

/* EOF */
