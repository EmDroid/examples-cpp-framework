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


#endif // MXCPP_MAKEDLL


/* EOF */
