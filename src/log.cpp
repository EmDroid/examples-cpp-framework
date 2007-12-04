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

    Logging subsystem (implementation).

    @author Emil Maskovsky
*/


/* Framework libraries. */


/* Application specific. */
#include "mx/log.h"


void MXCPP_DLL_EXPORT mxLogMessage(
        const char * const sFileName,
        const mxSize iFileLine,
        const mxLogType iType,
        const char * const sMessage)
{}


// Define inline methods here if inlining is disabled.
#ifndef MX_INLINE_ENABLED
#include "mx/log.inl"
#endif

/* EOF */
