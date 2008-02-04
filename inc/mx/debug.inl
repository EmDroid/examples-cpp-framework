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


/* explicit */ MX_INLINE mx::Debug::Checkpoint::Checkpoint(
        const FileName sFile,
        const FileLine iLine)
    : m_sFile(sFile)
    , m_iLine(iLine)
{}


MX_INLINE mx::Debug::Checkpoint::FileName
mx::Debug::Checkpoint::getFile() const
{
    return m_sFile;
}


MX_INLINE mx::Debug::Checkpoint::FileLine
mx::Debug::Checkpoint::getLine() const
{
    return m_iLine;
}


MX_INLINE bool mx::Debug::Checkpoint::Empty() const
{
    return !getFile();
}


/* static */ MX_INLINE void mx::Debug::Check(
        /*  Note using "int" and not "bool" for cond to avoid VC++ warnings about
             implicit conversions when doing "mxAssert(pointer)" and also use of
             "!!cond" below to ensure that everything is converted to int
        */
        const int bCondition,
        const Checkpoint & xFileInfo,
        const char * const sCondition,
        const char * const sMessage)
{
    if (!sCondition)
    {
        Log(Log::LOG_Assert, mxDebugCheckpoint()).LogAssert(
                "sCondition != NULL");
        return;
    }
    if (!bCondition)
    {
        Log(Log::LOG_Assert, xFileInfo).LogAssert(
                sMessage ? "%s (%s)" : "%s",
                sCondition, sMessage);
    }
}


/* EOF */
