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

    Standard Input/Output streams (implementation).

    @author Emil Maskovsky
*/


/* Framework libraries. */


/* Application specific. */
#include "mx/StdStrm.hpp"


namespace mx
{


// Undefine possibly overridden names.

#ifdef StandardInput
#undef StandardInput
#endif

#ifdef StandardOutput
#undef StandardOutput
#endif

#ifdef StandardError
#undef StandardError
#endif


// Do not use debug version of new here - otherwise the system it will report
// the memory leaks, which we intend to use here..
#include "mx/defs/newundef.hpp"
// #define new     new(__FILE__, __LINE__, NonMemDbg)


// We want the stream to be usable all the time, even in case of program unwind
// (exit, de-initialization). Because of this requirement, we have to:
//    a) use function to access the stream, in order to create the stream
//       immediately before the first use
//       (this will prevent "static initialization fiasco" - that term means,
//       that during initialization of another static object, which wants to use
//       the stream, the stream might not have been created yet)
//    b) use dynamic allocation to create the stream on the heap
//       (to prevent operations on already destroyed stream when exiting the
//       application)
//    c) leave the memory freeing of the allocated memory on the system


/**
    Standard input FileStream.

    This FileStream is connected to program's standard input. It is ready to
    be read from immediatelly after program start (after constructors of
    static data were called, that is).

    This means, the stream can be used during program init and exit stages.
*/
static FileStream & _StandardInput()
{
    static FileStream * const stdStream = new FileStream(stdin);
    return *stdStream;
}


/**
    Standard output FileStream.

    This FileStream is connected to program's standard output. It is ready to
    be written to immediatelly after program start (after constructors of
    static data were called, that is).

    This means, the stream can be used during program init and exit stages.
*/
static FileStream & _StandardOutput()
{
    static FileStream * const stdStream = new FileStream(stdout);
    return *stdStream;
}


// We cannot use tracing when creating StandardError
// - we trace to StandardError.
#include "mx/defs/newundef.hpp"
// #define new     new(__FILE__, __LINE__, cxNonMemDbg, cxNonMemTrace)


/**
    Standard error FileStream.

    This FileStream is connected to program's standard error output. It is
    ready to be written to immediatelly after program start (after
    constructors of static data were called, that is).

    This means, the stream can be used during program init and exit stages.
*/
static FileStream & _StandardError()
{
    static FileStream * const stdStream = new FileStream(stderr);
    return *stdStream;
}


} // namespace mx


MXCPP_DLL_EXPORT_DATA(mx::FileStream &) mx::StandardInput
    = mx::_StandardInput();
MXCPP_DLL_EXPORT_DATA(mx::FileStream &) mx::StandardOutput
    = mx::_StandardOutput();
MXCPP_DLL_EXPORT_DATA(mx::FileStream &) mx::StandardError
    = mx::_StandardError();


/* EOF */
