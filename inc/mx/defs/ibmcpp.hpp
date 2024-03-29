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
    @internal

    @file

    Common IBM CPP (Mainframe MVS/TSO) compiler specific definitions.

    @author Emil Maskovsky
*/


#ifndef MX_PLATFORM_COMPILER_IBM

#define MX_PLATFORM_COMPILER_IBM


#if (__IBMCPP__ < 41020)
    #error This project requires at least IBM C++ Compiler 1.2 to compile.
#endif // __IBMCPP__ < 41020


#endif // MX_PLATFORM_COMPILER_IBM

/* EOF */
