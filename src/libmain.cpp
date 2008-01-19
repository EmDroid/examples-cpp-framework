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

    The main DLL entry point (implementation).

    @author Emil Maskovsky
*/


/* Framework libraries. */
#include "mx/sysdefs.h"

#include "mx/types.h"


/* Application specific. */


#ifdef MXCPP_MAKEDLL


#ifdef MX_PLATFORM_OS_WIN16

// Create Windows-16 style DLL library.


/**
    The DLL entry point for the Demo C++ Framework library.

    @param [in] hInstance Handle to DLL module.

    @retval TRUE  The initialization was done successfully.
    @retval FALSE The initialization has failed.
*/
extern "C" BOOL WINAPI LibMain(
        HANDLE MX_UNUSED(hInstance),
        WORD MX_UNUSED(wDataSegment),
        WORD MX_UNUSED(wHeapSize),
        LPSTR MX_UNUSED(lpszCmdLine))
{
    return TRUE;
}


#else // MX_PLATFORM_OS_WIN16


#ifdef MX_PLATFORM_OS_WINDOWS

// Create Windows-32 style DLL library.


/**
    The DLL entry point for the Demo C++ Framework library.

    @param [in] hDllInstance Handle to DLL module.
    @param [in] dwReason     Reason for calling function.
    @param [in] lpReserved   Reserved parameter.

    @retval TRUE  The initialization was done successfully.
    @retval FALSE The initialization has failed.
*/
extern "C" MXCPP_DLL_EXPORT BOOL WINAPI DllMain(
        const HINSTANCE MX_UNUSED(hDllInstance),
        const DWORD dwReason,
        const LPVOID MX_UNUSED(lpReserved))
{
    // Perform actions based on the reason for calling.
    switch (dwReason)
    {

    case DLL_PROCESS_ATTACH:
    {
        // Initialize once for each new process.
        // Return FALSE to fail DLL load.
        /*
        MessageBox(NULL, _T("Initialization of the DLL."),
                _T("Demo C++ Framework"), MB_OK);
        */
        break;
    }

    case DLL_THREAD_ATTACH:
    {
        // Do thread-specific initialization.
        break;
    }

    case DLL_THREAD_DETACH:
    {
        // Do thread-specific cleanup.
        break;
    }

    case DLL_PROCESS_DETACH:
    {
        // Perform any necessary cleanup.
        /*
        MessageBox(NULL, _T("De-initialization of the DLL."),
                _T("Demo C++ Framework"), MB_OK);
        */
        break;
    }
    }
    // Successful DLL_PROCESS_ATTACH.
    return TRUE;
}


#else // MX_PLATFORM_OS_WINDOWS


#ifdef MX_PLATFORM_OS_UNIX

// No DLL entry point under Unix/Linux.

#else // MX_PLATFORM_OS_UNIX


#error The DLL entry point is not defined for current platform!


#endif // MX_PLATFORM_OS_UNIX


#endif // MX_PLATFORM_OS_WINDOWS


#endif // MX_PLATFORM_OS_WIN16


#endif // MXCPP_MAKEDLL


/* EOF */
