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


/* Framework libraries. */


/* Application specific. */
#include "mx/Debug.hpp"


/**
    Handle check failure.

    @internal

    This handler is raised in case of the check failure, i.e. the check
    condition evaluated to @c false.

    @param [in] xFileInfo  Debug checkpoint information.
    @param [in] sCondition The string representation of the condition, which was
                           failed.
    @param [in] sMessage The extra message (optional).
*/
/**
    @note
    This handler is not to be used directly, use the @ref debugging_macros
    "debugging macros" instead.

    @see mxCheck()
*/
/* static */ void mx::Debug::HandleCheck(
        const Checkpoint & xFileInfo,
        const Char * const sCondition,
        const Char * const sMessage)
{
    // This is the check of the condition string. It will be always set, if the
    // method is used properly through mxCheck() etc., but when
    // used improperly (direct call of the function) we must be sure that
    // following code will not trigger segmentation fault.
    //
    // We use mxReleaseAssert() here for the test, because the method is
    // available even in release builds.
    mxReleaseAssert(sCondition != NULL);
    Log(Log::LOG_Check, xFileInfo).LogMessage(
            sMessage ? _T("%s (%s)") : _T("%s"),
            sCondition, sMessage);
}


/**
    Handle assertion failure.

    @internal

    This handler is raised in case of the assertion failure, i.e. the assert
    condition evaluated to @c false.

    @param [in] xFileInfo  Debug checkpoint information.
    @param [in] sCondition The string representation of the condition, which was
                           failed.
    @param [in] sMessage The extra message (optional).

    This handler never returns and causes the application to be shut down
    (abort).
*/
/**
    @note
    This handler is not to be used directly, use the @ref debugging_macros
    "debugging macros" instead.

    @see mxAssert(), mxReleaseAssert(), mxTest()
*/
/* static */ MX_NORETURN mx::Debug::HandleAssert(
        const Checkpoint & xFileInfo,
        const Char * const sCondition,
        const Char * const sMessage)
{
    // This is the check of the condition string. It will be always set, if the
    // method is used properly through mxAssert(), mxTest() etc., but when
    // used improperly (direct call of the function) we must be sure that
    // following code will not trigger segmentation fault.
    //
    // We use mxReleaseAssert() here for the test, because the method is
    // available even in release builds.
    mxReleaseAssert(sCondition != NULL);
    Log(Log::LOG_Assert, xFileInfo).LogAssert(
            sMessage ? _T("%s (%s)") : _T("%s"),
            sCondition, sMessage);
}


// Define inline methods here if inlining is disabled.
#ifndef MX_INLINE_ENABLED
#include "mx/Debug.inl"
#endif

/* EOF */
