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
#include "mx/sysdefs.hpp"

#include "mx/types.hpp"


/* Application specific. */


/**
    @mainpage @project
    @author @company
    @author &copy; @company 2007
    @version 0.1

    <b>@project</b> is a portable C/C++ framework.

    @section contents Contents:
    @li @subpage copyright
    @li @subpage suppcpp
    @li @subpage build
*/

/**
    @page copyright Copyright notice

    &copy; @company 2007
*/


/**
    @page suppcpp Supported and unsupported C++ features

    @li @subpage exceptions
    @li @subpage namespaces
    @li @subpage typeinfo
*/


/**
    @page namespaces Namespaces

    We support using of namespaces.
*/


/**
    @page build Building using makefiles

    @section build_make The make build tool - GNU make

    There have been considered multiple scenarios, how to provide makefile
    processing (which is the most flexible way of building of any project),
    including writing own portable makefile tool based on the framework itself
    (which of course can then be used to do the same things as with any makefile
    processing tool). The main aim is to have portable makefile tool, which can
    then be used on near any platform, and which can provide some extended
    processing tasks.

    At last, there have been made choice to use the <b><i>GNU makefile processing
    tool</i></b>, because of its portability (it is available for many platforms,
    Windows and Unixes at least) and extreme flexibility (can e.g. dynamically
    create makefile rules, supports sub-routines etc.).

    The advantage is, that ve can provide only one makefile for each platform and
    compiler and not bother with another makefile build tools (nmake, Borland
    make, Digital Mars make etc.), but it can be used to build on near any
    platform supported by framework.

    The minimal version of GNU make required to build provided makefiles is 3.81
    (use @code (g)make --version @endcode to see version of installed GNU makefile
    tool).

    @see http://make.gnu.org/

    @section build_compilers Supported compilers

    Currently following C++ compilers are supported:
    @li @ref build_msvc - versions 6.0 and later
    @li @ref build_gcc - Windows, Unix, DOS (DJGPP); versions 2.x and later
    @li @ref build_dmc - 32-bit Windows, 16-bit DOS
    @li @ref build_bcc - version 5.5 and later
    @li @ref build_watcom - 32-bit Windows, 16-bit DOS
    @li @ref build_ibmcpp - MVS/TSO (OS390)

    @subsection build_msvc Microsoft Visual C++ (MSVC)
    Building using MSVC:@n
    Run @ref build_make "(g)make" from the @c 'make\\msw\\win32\\msvc(X)'
    directory.

    Environment variables to be set:
    @li @c INCLUDE: MSVC include files
                    (formatted as <code>"dir1;dir2"</code>).
    @li @c LIB: MSVC library path
                (formatted as <code>"dir1;dir2"</code>).

    @subsection build_gcc GNU C++ compiler (G++)
    (http://gcc.gnu.org/)

    Building using G++:@n
    Run @ref build_make "(g)make" from the @c
    'make\\&lt;platform&gt;\\&lt;system&gt;\\gcc' directory.

    Environment variables to be set:
    @li @c C_INCLUDE_PATH: GCC include files (pure C)
                           (formatted as <code>"dir1;dir2"</code>).
    @li @c CPLUS_INCLUDE_PATH: G++ include files (C++)
                               (formatted as <code>"dir1;dir2"</code>).
    @li @c LIBRARY_PATH: GCC/G++ libraries
                         (formatted as <code>"dir1;dir2"</code>).

    @subsection build_dmc Digital Mars C++ compiler (DMC)
    (http://www.digitalmars.com/)

    Building using DMC:@n
    Run @ref build_make "(g)make" from the @c 'make\\msw\\&lt;system&gt;\\dmc'
    directory.

    Include, library etc. paths must be set in the initialization file in the
    compiler directory.

    @subsection build_bcc Borland C++ Compiler (bcc32)
    Building using bcc32:@n
    Run @ref build_make "(g)make" from the @c 'make\\msw\\win32\\bcc' directory.

    Include, library etc. paths must be set in the initialization file in the
    compiler directory.

    @subsection build_watcom Watcom C++ compiler
    (http://www.openwatcom.org/)

    Building using Watcom:@n
    Run @ref build_make "(g)make" from the @c 'make\\msw\\&lt;system&gt;\\watcom'
    directory.

    Environment variables to be set:
    @li @c WATCOM Watcom root directory.
    @li @c INCLUDE Watcom include files
                   (formatted as <code>"dir1;dir2"</code>).

    @subsection build_ibmcpp IBM Mainframe C++ compiler
    Building using IBM CPP:@n
    Some scripts are prepared in the @c 'make\\zos\\os390' directory, you
    might want to adapt it to your conditions.
*/


/**
    @page unicode Unicode support in @project

    This section briefly describes the state of the Unicode support in the
    @project. Read it if you want to know more about how to write programs able
    to work with characters from languages other than English.

    @ref unicode_what

    @section unicode_what What is Unicode?

    Unicode is a standard for character encoding which addresses the shortcomings
    of the previous, 8 bit standards, by using at least 16 (and possibly 32) bits
    for encoding each character. This allows to have at least 65536 characters
    (what is called the BMP, or basic multilingual plane) and possible 2^32 of
    them instead of the usual 256 and is sufficient to encode all of the world
    languages at once. More details about Unicode may be found at
    www.unicode.org.

    As this solution is obviously preferable to the previous ones (think of
    incompatible encodings for the same language, locale chaos and so on), many
    modern operating systems support it. The probably first example is Windows NT
    which uses only Unicode internally since its very first version.

    Writing internationalized programs is much easier with Unicode and, as the
    support for it improves, it should become more and more so. Moreover, in the
    Windows NT/2000 case, even the program which uses only standard ASCII can
    profit from using Unicode because they will work more efficiently - there
    will be no need for the system to convert all strings the program uses
    to/from Unicode each time a system call is made.
*/


/**
    @page terms Defined terms

    @anchor RTTI @b RTTI: (R)un-(T)ime (T)ype (I)dentification
                          (@ref typeinfo "info")
*/


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
        const DWORD MX_UNUSED(dwReason),
        const LPVOID MX_UNUSED(lpReserved))
{
#if 0   // Not used at the moment.

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
#endif // if 0

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
