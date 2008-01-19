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

    Common IBM AIX (xlC) C++ compiler specific definitions.

    @author Emil Maskovsky
*/


#ifndef MX_PLATFORM_COMPILER_XLC

#define MX_PLATFORM_COMPILER_XLC


#if (__XLC__ < 2)
    #error This project requires at least IBM AIX (xlC) C++ Compiler 2.0 to compile.
#else /* XLC < 2.0 */
#endif /* XLC < 2.0 */


/* Define how to declare functions/methods with printf(3) like semantics. */
#define MX_PRINTFLIKE(format_index, arguments_index) \
    __attribute__((format(printf, (format_index), (arguments_index))))
#define MX_PRINTFLIKE_METHOD(format_index, arguments_index) \
    MX_PRINTFLIKE((format_index) + 1, (arguments_index) + 1)

/* Define how to declare functions/methods with scanf(3) like semantics. */
#define MX_SCANFLIKE(format_index, arguments_index) \
    __attribute__((format(scanf, (format_index), (arguments_index))))
#define MX_SCANFLIKE_METHOD(format_index, arguments_index) \
    MX_SCANFLIKE((format_index) + 1, (arguments_index) + 1)


#endif /* MX_PLATFORM_COMPILER_XLC */

/* EOF */
