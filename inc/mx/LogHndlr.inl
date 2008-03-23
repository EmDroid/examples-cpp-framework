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

    Log handler base (inline methods).

    @author Emil Maskovsky
*/


/**
    Default constructor.
*/
MX_INLINE mx::LogHandler::LogHandler()
{}


/**
    Destructor.
*/
/* virtual */ MX_INLINE mx::LogHandler::~LogHandler()
{
    Log::UnregisterTarget(this);
}


/**
    Log the message (vararg version).

    @param [in] iType      Type of log message.
    @param [in] sFormat    @c printf(3) like formatting string.
    @param [in] pArguments Argument list matching the @a sFormat string.

    @return
    See DoLog() for description of return values.
*/
MX_INLINE mx::Size mx::LogHandler::DoLog(
        const Log::LogType iType,
        const Char * sFormat, va_list pArguments)
{
    // The file-line logging not used.
    return DoLog(Debug::Checkpoint(), iType, sFormat, pArguments);
}


/* EOF */
