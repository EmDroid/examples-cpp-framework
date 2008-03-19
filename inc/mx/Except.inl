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

    Exception support (inline methods).

    @author Emil Maskovsky
*/


/**
    Constructor.

    @param [in] sMessage The exception message.
*/
/* explicit */ MX_INLINE mx::Exception::Exception(
        const Char * const sMessage)
    : m_sMessage(sMessage)
{}


MX_INLINE void mx::Exception::SetDebugInfo(
        const Debug::Checkpoint & xFileLocation) const
{
    m_xFileLocation = xFileLocation;
}


/**
    Get the exception message, if some set.

    @return
    The message associated with the exception.

    @warning
    The returned value is @c NULL, if none message was set.
    If you want to get memory-safe message (which will never be @c NULL), use
    the what() method.

    @see what()
*/
MX_INLINE const mx::Char * mx::Exception::message() const
{
    return m_sMessage;
}


/**
    Constructor.

    @param [in] sMessage The exception message.
*/
/* explicit */ MX_INLINE mx::SystemException::SystemException(
        const Char * const sMessage)
    : Super(sMessage)
{}


/**
    Constructor.

    @param [in] sMessage The exception message.
*/
/* explicit */ MX_INLINE mx::KernelException::KernelException(
        const Char * const sMessage)
    : Super(sMessage)
{}


/**
    Constructor.

    @param [in] sMessage The exception message.
*/
/* explicit */ MX_INLINE mx::MemoryException::MemoryException(
        const Char * const sMessage)
    : Super(sMessage)
{}


/**
    Constructor.

    @param [in] sMessage The exception message.
*/
/* explicit */ MX_INLINE mx::IOException::IOException(
        const Char * const sMessage)
    : Super(sMessage)
{}


/* EOF */
