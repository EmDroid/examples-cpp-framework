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

    Log message handler printing to standard error (implementation).

    @author Emil Maskovsky
*/


/* Framework libraries. */
#include "mx/StdStrm.hpp"


/* Application specific. */
#include "mx/LogStdE.hpp"


/**
    Get the default instance.

    Because this is the default log handler, we need some statically allocated
    instance which lasts the entire application time.

    @return
    The default instance of the LogStdErr log handler.
*/
/* static */ mx::LogStdErr * mx::LogStdErr::Instance()
{
    static LogStdErr * const sm_instance = new LogStdErr();
    return sm_instance;
}


// Define inline methods here if inlining is disabled.
#ifndef MX_INLINE_ENABLED
#include "mx/LogStdE.inl"
#endif

/* EOF */
