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

    File streams (inline methods).

    @author Emil Maskovsky
*/


#ifndef MXCPP_SYSDEFS
// Required for proper documentation creation.
#include "mx/sysdefs.hpp"
#endif


/**
    Constructor.
*/
MX_INLINE mx::EndOfFile::EndOfFile()
{}


/**
    Constructor.

    @param iErrno [in] Error value as obtained from system @c errno variable.
*/
/* explicit */ MX_INLINE mx::GenericIOException::GenericIOException(
        const int iErrno)
    : m_iErrno((iErrno) ? iErrno : errno)
{}


/* EOF */
