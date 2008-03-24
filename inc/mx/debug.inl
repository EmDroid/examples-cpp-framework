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

    Debugging functions (inline methods).

    @author Emil Maskovsky
*/


#ifndef MXCPP_SYSDEFS
// Required for proper documentation creation.
#include "mx/sysdefs.hpp"
#endif


/**
    Constructor.

    @param [in] sFile The checkpointed file name.
    @param [in] nLine The checkpointed line number.
*/
MX_INLINE mx::Debug::Checkpoint::Checkpoint(
        const FileName sFile,
        const FileLine nLine)
    : m_sFile(sFile)
    , m_nLine(nLine)
{}


/**
    Get the checkpointed file name.
*/
MX_INLINE mx::Debug::Checkpoint::FileName
mx::Debug::Checkpoint::getFile() const
{
    return m_sFile;
}


/**
    Get the checkpointed line number.
*/
MX_INLINE mx::Debug::Checkpoint::FileLine
mx::Debug::Checkpoint::getLine() const
{
    return m_nLine;
}


/**
    Check if the checkpointed information is empty.

    @return
    Returns @c true, if the checkpoint does not contain valid file-line
    information, @c false if it contains valid non-empty information.
*/
MX_INLINE bool mx::Debug::Checkpoint::Empty() const
{
    return !getFile();
}


/* EOF */
