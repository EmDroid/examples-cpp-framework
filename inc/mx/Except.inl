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


/* static */ MX_INLINE void mx::Exception::setLastRaisedException(
        const Exception & theException)
{
    sm_pLastRaisedException = &theException;
}


/**
    Get the pointer to the last exception raised, if any.
*/
/* static */ MX_INLINE const mx::Exception *
mx::Exception::getLastRaisedException()
{
    return sm_pLastRaisedException;
}


/**
    Constructor.

    @param [in] sMessage The exception message.
*/
MX_INLINE mx::Exception::Exception(
        const char * const sMessage)
    : m_sMessage(sMessage)
{}


MX_INLINE void mx::Exception::SetDebugInfo(
        const Debug::Checkpoint & xFileInfo) const
{
    m_xFileInfo = xFileInfo;
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
MX_INLINE const char * mx::Exception::message() const
{
    return m_sMessage;
}


/**
    Constructor.

    @param [in] sMessage The exception message.
*/
MX_INLINE mx::SystemException::SystemException(
        const char * const sMessage)
    : Super(sMessage)
{}


/**
    Constructor.

    @param [in] sMessage The exception message.
*/
MX_INLINE mx::KernelException::KernelException(
        const char * const sMessage)
    : Super(sMessage)
{}


/**
    Constructor.

    @param [in] sMessage The exception message.
*/
MX_INLINE mx::MemoryException::MemoryException(
        const char * const sMessage)
    : Super(sMessage)
{}


/**
    Constructor.

    @param [in] sMessage The exception message.
*/
MX_INLINE mx::IOException::IOException(
        const char * const sMessage)
    : Super(sMessage)
{}


/* EOF */
