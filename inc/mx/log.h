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

    Logging subsystem (interface).

    @author Emil Maskovsky
*/


#ifndef MXCPP_LOG_H_INCLUDE_GUARD
#define MXCPP_LOG_H_INCLUDE_GUARD


#include "mx/sysdefs.h"

#include "mx/types.h"


typedef enum
{
    MX_LOG_WARNING,
    MX_LOG_ERROR,
    MX_LOG_FATAL_ERROR
} mxLogType;


#define mxLogWarning(message, param) \
    mxLogMessage(__FILE__, __LINE__, MX_LOG_WARNING, message)

#define mxLogError(message) \
    mxLogMessage(__FILE__, __LINE__, MX_LOG_ERROR, message)

#define mxLogFatalError(message) \
    mxLogMessage(__FILE__, __LINE__, MX_LOG_FATAL_ERROR, message)


void MXCPP_DLL_EXPORT mxLogMessage(
        const char * const sFileName,
        const mxSize iFileLine,
        const mxLogType iType,
        const char * const sMessage);


// Define inline methods here if inlining is enabled.
#ifdef MX_INLINE_ENABLED
#include "mx/log.inl"
#endif

#endif /* MXCPP_LOG_H_INCLUDE_GUARD */

/* EOF */
