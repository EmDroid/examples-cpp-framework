# Microsoft Developer Studio Project File - Name="mxCppFramework" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102
# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=mxCppFramework - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "mxCppFramework.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "mxCppFramework.mak" CFG="mxCppFramework - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "mxCppFramework - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "mxCppFramework - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "mxCppFramework - Win32 Unicode Release" (based on "Win32 (x86) Static Library")
!MESSAGE "mxCppFramework - Win32 Unicode Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "mxCppFramework - Win32 Multithread Release" (based on "Win32 (x86) Static Library")
!MESSAGE "mxCppFramework - Win32 Multithread Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "mxCppFramework - Win32 Multithread Unicode Release" (based on "Win32 (x86) Static Library")
!MESSAGE "mxCppFramework - Win32 Multithread Unicode Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "mxCppFramework - Win32 DLL Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "mxCppFramework - Win32 DLL Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "mxCppFramework - Win32 DLL Unicode Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "mxCppFramework - Win32 DLL Unicode Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""

!IF  "$(CFG)" == "mxCppFramework - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ".."
# PROP BASE Intermediate_Dir "../obj"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ".."
# PROP Intermediate_Dir "../obj"
# PROP Target_Dir ""
MTL=midl.exe
CPP=cl.exe
# ADD BASE CPP /nologo /W3 /GX /GF /O2 /D "NDEBUG" /D "_MBCS" /D "WIN32" /D "MXCPP_PCH" /Fp"../obj/link/mxprec.pch" /YX /FD /c
# ADD CPP /nologo /W3 /GR /GX /GF /O2 /I "../../../../../inc" /I "../../../../../src/inc" /D "NDEBUG" /D "_MBCS" /D "WIN32" /Fr /FD /c
# SUBTRACT CPP /YX
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /i "../../../../../src/inc" /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"mxCppFramework.bsc"
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../mxcpp.lib"
# ADD LIB32 /nologo /out:"../mxcpp.lib"

!ELSEIF  "$(CFG)" == "mxCppFramework - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".."
# PROP BASE Intermediate_Dir "../objd"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ".."
# PROP Intermediate_Dir "../objd"
# PROP Target_Dir ""
MTL=midl.exe
CPP=cl.exe
# ADD BASE CPP /nologo /W4 /Gm /GX /GF /ZI /Od /D "_DEBUG" /D "_MBCS" /D "WIN32" /D "MXCPP_PCH" /FR /Fp"../objd/link/mxprec.pch" /YX /FD /GZ /c
# ADD CPP /nologo /W4 /Gm /GR /GX /GF /ZI /Od /I "../../../../../inc" /I "../../../../../src/inc" /D "_DEBUG" /D "_MBCS" /D "WIN32" /FR /FD /GZ /c
# SUBTRACT CPP /YX
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /i "../../../../../src/inc" /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"mxCppFramework.bsc"
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../mxcppd.lib"
# ADD LIB32 /nologo /out:"../mxcppd.lib"

!ELSEIF  "$(CFG)" == "mxCppFramework - Win32 Unicode Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ".."
# PROP BASE Intermediate_Dir "../obju"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ".."
# PROP Intermediate_Dir "../obju"
# PROP Target_Dir ""
MTL=midl.exe
CPP=cl.exe
# ADD BASE CPP /nologo /W3 /GX /GF /O2 /D "NDEBUG" /D "UNICODE" /D "WIN32" /D "MXCPP_PCH" /Fp"../obju/link/mxprec.pch" /YX /FD /c
# ADD CPP /nologo /W3 /GR /GX /GF /O2 /I "../../../../../inc" /I "../../../../../src/inc" /D "NDEBUG" /D "UNICODE" /D "WIN32" /Fr /FD /c
# SUBTRACT CPP /YX
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "UNICODE"
# ADD RSC /l 0x409 /i "../../../../../src/inc" /d "NDEBUG" /d "UNICODE"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"mxCppFramework.bsc"
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../mxcppu.lib"
# ADD LIB32 /nologo /out:"../mxcppu.lib"

!ELSEIF  "$(CFG)" == "mxCppFramework - Win32 Unicode Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".."
# PROP BASE Intermediate_Dir "../objud"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ".."
# PROP Intermediate_Dir "../objud"
# PROP Target_Dir ""
MTL=midl.exe
CPP=cl.exe
# ADD BASE CPP /nologo /W4 /Gm /GX /GF /ZI /Od /D "_DEBUG" /D "UNICODE" /D "WIN32" /D "MXCPP_PCH" /Fp"../objud/link/mxprec.pch" /YX /FD /GZ /c
# ADD CPP /nologo /W4 /Gm /GR /GX /GF /ZI /Od /I "../../../../../inc" /I "../../../../../src/inc" /D "_DEBUG" /D "UNICODE" /D "WIN32" /Fr /FD /GZ /c
# SUBTRACT CPP /YX
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "UNICODE"
# ADD RSC /l 0x409 /i "../../../../../src/inc" /d "_DEBUG" /d "UNICODE"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"mxCppFramework.bsc"
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../mxcppud.lib"
# ADD LIB32 /nologo /out:"../mxcppud.lib"

!ELSEIF  "$(CFG)" == "mxCppFramework - Win32 Multithread Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ".."
# PROP BASE Intermediate_Dir "../obj_mt"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ".."
# PROP Intermediate_Dir "../obj_mt"
# PROP Target_Dir ""
MTL=midl.exe
CPP=cl.exe
# ADD BASE CPP /nologo /MT /W3 /GX /GF /O2 /D "NDEBUG" /D "_MBCS" /D "WIN32" /D "MXCPP_PCH" /Fp"../obj_mt/link/mxprec.pch" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GR /GX /GF /O2 /I "../../../../../inc" /I "../../../../../src/inc" /D "NDEBUG" /D "_MBCS" /D "WIN32" /Fr /FD /c
# SUBTRACT CPP /YX
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /i "../../../../../src/inc" /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"mxCppFramework.bsc"
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../mxcppmt.lib"
# ADD LIB32 /nologo /out:"../mxcppmt.lib"

!ELSEIF  "$(CFG)" == "mxCppFramework - Win32 Multithread Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".."
# PROP BASE Intermediate_Dir "../objd_mt"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ".."
# PROP Intermediate_Dir "../objd_mt"
# PROP Target_Dir ""
MTL=midl.exe
CPP=cl.exe
# ADD BASE CPP /nologo /MTd /W4 /Gm /GX /GF /ZI /Od /D "_DEBUG" /D "_MBCS" /D "WIN32" /D "MXCPP_PCH" /Fp"../objd_mt/link/mxprec.pch" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W4 /Gm /GR /GX /GF /ZI /Od /I "../../../../../inc" /I "../../../../../src/inc" /D "_DEBUG" /D "_MBCS" /D "WIN32" /Fr /FD /GZ /c
# SUBTRACT CPP /YX
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /i "../../../../../src/inc" /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"mxCppFramework.bsc"
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../mxcppmtd.lib"
# ADD LIB32 /nologo /out:"../mxcppmtd.lib"

!ELSEIF  "$(CFG)" == "mxCppFramework - Win32 Multithread Unicode Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ".."
# PROP BASE Intermediate_Dir "../obju_mt"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ".."
# PROP Intermediate_Dir "../obju_mt"
# PROP Target_Dir ""
MTL=midl.exe
CPP=cl.exe
# ADD BASE CPP /nologo /MT /W3 /GX /GF /O2 /D "NDEBUG" /D "UNICODE" /D "WIN32" /D "MXCPP_PCH" /Fp"../obju_mt/link/mxprec.pch" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GR /GX /GF /O2 /I "../../../../../inc" /I "../../../../../src/inc" /D "NDEBUG" /D "UNICODE" /D "WIN32" /Fr /FD /c
# SUBTRACT CPP /YX
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "UNICODE"
# ADD RSC /l 0x409 /i "../../../../../src/inc" /d "NDEBUG" /d "UNICODE"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"mxCppFramework.bsc"
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../mxcppmtu.lib"
# ADD LIB32 /nologo /out:"../mxcppmtu.lib"

!ELSEIF  "$(CFG)" == "mxCppFramework - Win32 Multithread Unicode Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".."
# PROP BASE Intermediate_Dir "../objud_mt"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ".."
# PROP Intermediate_Dir "../objud_mt"
# PROP Target_Dir ""
MTL=midl.exe
CPP=cl.exe
# ADD BASE CPP /nologo /MTd /W4 /Gm /GX /GF /ZI /Od /D "_DEBUG" /D "UNICODE" /D "WIN32" /D "MXCPP_PCH" /Fp"../objud_mt/link/mxprec.pch" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W4 /Gm /GR /GX /GF /ZI /Od /I "../../../../../inc" /I "../../../../../src/inc" /D "_DEBUG" /D "UNICODE" /D "WIN32" /Fr /FD /GZ /c
# SUBTRACT CPP /YX
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "UNICODE"
# ADD RSC /l 0x409 /i "../../../../../src/inc" /d "_DEBUG" /d "UNICODE"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"mxCppFramework.bsc"
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"../mxcppmtud.lib"
# ADD LIB32 /nologo /out:"../mxcppmtud.lib"

!ELSEIF  "$(CFG)" == "mxCppFramework - Win32 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ".."
# PROP BASE Intermediate_Dir "../obj_dll"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ".."
# PROP Intermediate_Dir "../obj_dll"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /MD /W3 /GX /GF /O2 /D "NDEBUG" /D "_MBCS" /D "_WINDOWS" /D "MXCPP_MAKEDLL" /D "WIN32" /D "MXCPP_PCH" /Fp"../obj_dll/mxprec.pch" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /GF /O2 /I "../../../../../inc" /I "../../../../../src/inc" /D "NDEBUG" /D "_MBCS" /D "_WINDOWS" /D "MXCPP_MAKEDLL" /D "WIN32" /Fr /FD /c
# SUBTRACT CPP /YX
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /i "../../../../../src/inc" /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"mxCppFramework.bsc"
LINK32=link.exe
# ADD BASE LINK32 /nologo /dll /machine:I386 /out:"../mxcpp01.dll"
# ADD LINK32 user32.lib kernel32.lib /nologo /dll /machine:I386 /out:"../mxcpp01.dll"

!ELSEIF  "$(CFG)" == "mxCppFramework - Win32 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".."
# PROP BASE Intermediate_Dir "../objd_dll"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ".."
# PROP Intermediate_Dir "../objd_dll"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /MDd /W4 /Gm /GX /GF /ZI /Od /D "_DEBUG" /D "_MBCS" /D "_WINDOWS" /D "MXCPP_MAKEDLL" /D "WIN32" /D "MXCPP_PCH" /Fp"../objd_dll/mxprec.pch" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W4 /Gm /GR /GX /GF /ZI /Od /I "../../../../../inc" /I "../../../../../src/inc" /D "_DEBUG" /D "_MBCS" /D "_WINDOWS" /D "MXCPP_MAKEDLL" /D "WIN32" /Fr /FD /GZ /c
# SUBTRACT CPP /YX
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /i "../../../../../src/inc" /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"mxCppFramework.bsc"
LINK32=link.exe
# ADD BASE LINK32 /nologo /dll /debug /machine:I386 /out:"../mxcpp01d.dll" /pdbtype:sept
# ADD LINK32 user32.lib kernel32.lib /nologo /dll /debug /machine:I386 /out:"../mxcpp01d.dll" /pdbtype:sept

!ELSEIF  "$(CFG)" == "mxCppFramework - Win32 DLL Unicode Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir ".."
# PROP BASE Intermediate_Dir "../obju_dll"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir ".."
# PROP Intermediate_Dir "../obju_dll"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /MD /W3 /GX /GF /O2 /D "NDEBUG" /D "UNICODE" /D "_WINDOWS" /D "MXCPP_MAKEDLL" /D "WIN32" /D "MXCPP_PCH" /Fp"../obju_dll/mxprec.pch" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /GF /O2 /I "../../../../../inc" /I "../../../../../src/inc" /D "NDEBUG" /D "UNICODE" /D "_WINDOWS" /D "MXCPP_MAKEDLL" /D "WIN32" /Fr /FD /c
# SUBTRACT CPP /YX
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /D "UNICODE" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /D "UNICODE" /mktyplib203 /win32
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "UNICODE"
# ADD RSC /l 0x409 /i "../../../../../src/inc" /d "NDEBUG" /d "UNICODE"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"mxCppFramework.bsc"
LINK32=link.exe
# ADD BASE LINK32 /nologo /dll /machine:I386 /out:"../mxcpp01u.dll"
# ADD LINK32 user32.lib kernel32.lib /nologo /dll /machine:I386 /out:"../mxcpp01u.dll"

!ELSEIF  "$(CFG)" == "mxCppFramework - Win32 DLL Unicode Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir ".."
# PROP BASE Intermediate_Dir "../objud_dll"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir ".."
# PROP Intermediate_Dir "../objud_dll"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /MDd /W4 /Gm /GX /GF /ZI /Od /D "_DEBUG" /D "UNICODE" /D "_WINDOWS" /D "MXCPP_MAKEDLL" /D "WIN32" /D "MXCPP_PCH" /Fp"../objud_dll/mxprec.pch" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W4 /Gm /GR /GX /GF /ZI /Od /I "../../../../../inc" /I "../../../../../src/inc" /D "_DEBUG" /D "UNICODE" /D "_WINDOWS" /D "MXCPP_MAKEDLL" /D "WIN32" /Fr /FD /GZ /c
# SUBTRACT CPP /YX
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /D "UNICODE" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /D "UNICODE" /mktyplib203 /win32
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "UNICODE"
# ADD RSC /l 0x409 /i "../../../../../src/inc" /d "_DEBUG" /d "UNICODE"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"mxCppFramework.bsc"
LINK32=link.exe
# ADD BASE LINK32 /nologo /dll /debug /machine:I386 /out:"../mxcpp01ud.dll" /pdbtype:sept
# ADD LINK32 user32.lib kernel32.lib /nologo /dll /debug /machine:I386 /out:"../mxcpp01ud.dll" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "mxCppFramework - Win32 Release"
# Name "mxCppFramework - Win32 Debug"
# Name "mxCppFramework - Win32 Unicode Release"
# Name "mxCppFramework - Win32 Unicode Debug"
# Name "mxCppFramework - Win32 Multithread Release"
# Name "mxCppFramework - Win32 Multithread Debug"
# Name "mxCppFramework - Win32 Multithread Unicode Release"
# Name "mxCppFramework - Win32 Multithread Unicode Debug"
# Name "mxCppFramework - Win32 DLL Release"
# Name "mxCppFramework - Win32 DLL Debug"
# Name "mxCppFramework - Win32 DLL Unicode Release"
# Name "mxCppFramework - Win32 DLL Unicode Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "System Sources"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "msw Sources"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# End Group
# Begin Source File

SOURCE=..\..\..\..\..\src\System\Error.cpp
# End Source File
# End Group
# Begin Group "internal"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\..\..\..\..\src\inc\mx\internal\OutOfMem.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\src\inc\mx\internal\OutOfMem.inl
# End Source File
# End Group
# Begin Group "Application Sources"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\..\..\..\src\App\App.cpp
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\..\..\..\src\Class.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\src\Debug.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\src\Except.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\src\FileStrm.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\src\LibMain.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\src\Log.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\src\LogHndlr.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\src\LogStd.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\src\LogStdE.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\src\LogStrm.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\src\Memory.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\src\new.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\src\OutOfMem.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\src\StdStrm.cpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\src\Stream.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "defs"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\defs\acc.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\defs\bcc.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\defs\dmc.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\defs\dos.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\defs\gcc.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\defs\gcc2.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\defs\gcc3.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\defs\gcc4.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\defs\helpers.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\defs\ibmcpp.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\defs\msvc.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\defs\msvc6.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\defs\msvc7.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\defs\msvc8.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\defs\mvs.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\defs\newdef.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\defs\newundef.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\defs\stddllexp.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\defs\unix.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\defs\watcom.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\defs\win.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\defs\xlc.hpp
# End Source File
# End Group
# Begin Group "System"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "msw"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# End Group
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\System\Error.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\System\Error.inl
# End Source File
# End Group
# Begin Group "Application"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\App\App.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\App\App.inl
# End Source File
# End Group
# Begin Group "tests"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\tests\TestApp.hpp
# End Source File
# End Group
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\Class.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\Class.inl
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\Debug.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\Debug.inl
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\Except.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\Except.inl
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\FileStrm.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\FileStrm.inl
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\Log.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\Log.inl
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\LogHndlr.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\LogHndlr.inl
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\LogStd.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\LogStd.inl
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\LogStdE.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\LogStdE.inl
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\LogStrm.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\LogStrm.inl
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\Memory.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\Memory.inl
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\new.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\new.inl
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\StdStrm.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\StdStrm.inl
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\Stream.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\Stream.inl
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\sysdefs.hpp
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\inc\mx\types.hpp
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=..\..\..\..\..\src\res\mxCppFw.rc
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\src\inc\mx\internal\version.h
# End Source File
# End Group
# Begin Group "Template Files"

# PROP Default_Filter "cpp;c;cxx;h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\..\..\..\..\template\template.cpp
# PROP Exclude_From_Scan -1
# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\template\template.hpp
# PROP Exclude_From_Scan -1
# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=..\..\..\..\..\template\template.inl
# PROP Exclude_From_Scan -1
# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1
# End Source File
# End Group
# End Target
# End Project
