# Microsoft Developer Studio Project File - Name="mxCppFrameworkTestExcept" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=mxCppFrameworkTestExcept - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "mxCppFrameworkTestExcept.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "mxCppFrameworkTestExcept.mak" CFG="mxCppFrameworkTestExcept - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "mxCppFrameworkTestExcept - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "mxCppFrameworkTestExcept - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE "mxCppFrameworkTestExcept - Win32 Unicode Release" (based on "Win32 (x86) Console Application")
!MESSAGE "mxCppFrameworkTestExcept - Win32 Unicode Debug" (based on "Win32 (x86) Console Application")
!MESSAGE "mxCppFrameworkTestExcept - Win32 Multithread Release" (based on "Win32 (x86) Console Application")
!MESSAGE "mxCppFrameworkTestExcept - Win32 Multithread Debug" (based on "Win32 (x86) Console Application")
!MESSAGE "mxCppFrameworkTestExcept - Win32 Multithread Unicode Release" (based on "Win32 (x86) Console Application")
!MESSAGE "mxCppFrameworkTestExcept - Win32 Multithread Unicode Debug" (based on "Win32 (x86) Console Application")
!MESSAGE "mxCppFrameworkTestExcept - Win32 DLL Release" (based on "Win32 (x86) Console Application")
!MESSAGE "mxCppFrameworkTestExcept - Win32 DLL Debug" (based on "Win32 (x86) Console Application")
!MESSAGE "mxCppFrameworkTestExcept - Win32 DLL Unicode Release" (based on "Win32 (x86) Console Application")
!MESSAGE "mxCppFrameworkTestExcept - Win32 DLL Unicode Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "mxCppFrameworkTestExcept - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "../obj/test"
# PROP BASE Intermediate_Dir "../obj/test"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../obj/test"
# PROP Intermediate_Dir "../obj/test"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /GF /O2 /D "NDEBUG" /D "_MBCS" /D "WIN32" /D "MXCPP_PCH" /Fp"../obj/link/mxprec.pch" /YX /FD /c
# ADD CPP /nologo /W3 /GR /GX /GF /O2 /I "../../../../../inc" /I "../../../../../src/inc" /D "NDEBUG" /D "_MBCS" /D "WIN32" /Fr /FD /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"mxCppFramework.bsc"
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:console /machine:I386
# ADD LINK32 /nologo /subsystem:console /machine:I386 /out:"../obj/test/Except.exe"
# Begin Special Build Tool
TargetPath=\Work\demo\make\msw\msvc6\obj\test\Except.exe
SOURCE="$(InputPath)"
PostBuild_Cmds=cd ..	$(TargetPath)
# End Special Build Tool

!ELSEIF  "$(CFG)" == "mxCppFrameworkTestExcept - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "../objd/test"
# PROP BASE Intermediate_Dir "../objd/test"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../objd/test"
# PROP Intermediate_Dir "../objd/test"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W4 /Gm /GX /GF /ZI /Od /D "_DEBUG" /D "_MBCS" /D "WIN32" /D "MXCPP_PCH" /Fp"../objd/link/mxprec.pch" /YX /FD /GZ /c
# ADD CPP /nologo /W4 /Gm /GR /GX /GF /ZI /Od /I "../../../../../inc" /I "../../../../../src/inc" /D "_DEBUG" /D "_MBCS" /D "WIN32" /Fr /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"mxCppFramework.bsc"
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:console /debug /machine:I386 /out:"../objd/test/Except.exe" /pdbtype:sept
# Begin Special Build Tool
TargetPath=\Work\demo\make\msw\msvc6\objd\test\Except.exe
SOURCE="$(InputPath)"
PostBuild_Cmds=cd ..	$(TargetPath)
# End Special Build Tool

!ELSEIF  "$(CFG)" == "mxCppFrameworkTestExcept - Win32 Unicode Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "../obju/test"
# PROP BASE Intermediate_Dir "../obju/test"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../obju/test"
# PROP Intermediate_Dir "../obju/test"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /GF /O2 /D "NDEBUG" /D "UNICODE" /D "WIN32" /D "MXCPP_PCH" /Fp"../obju/link/mxprec.pch" /YX /FD /c
# ADD CPP /nologo /W3 /GR /GX /GF /O2 /I "../../../../../inc" /I "../../../../../src/inc" /D "NDEBUG" /D "UNICODE" /D "WIN32" /Fr /FD /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "UNICODE"
# ADD RSC /l 0x409 /d "NDEBUG" /d "UNICODE"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"mxCppFramework.bsc"
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:console /machine:I386
# ADD LINK32 /nologo /subsystem:console /machine:I386 /out:"../obju/test/Except.exe"
# Begin Special Build Tool
TargetPath=\Work\demo\make\msw\msvc6\obju\test\Except.exe
SOURCE="$(InputPath)"
PostBuild_Cmds=cd ..	$(TargetPath)
# End Special Build Tool

!ELSEIF  "$(CFG)" == "mxCppFrameworkTestExcept - Win32 Unicode Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "../objud/test"
# PROP BASE Intermediate_Dir "../objud/test"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../objud/test"
# PROP Intermediate_Dir "../objud/test"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W4 /Gm /GX /GF /ZI /Od /D "_DEBUG" /D "UNICODE" /D "WIN32" /D "MXCPP_PCH" /Fp"../objud/link/mxprec.pch" /YX /FD /GZ /c
# ADD CPP /nologo /W4 /Gm /GR /GX /GF /ZI /Od /I "../../../../../inc" /I "../../../../../src/inc" /D "_DEBUG" /D "UNICODE" /D "WIN32" /Fr /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "UNICODE"
# ADD RSC /l 0x409 /d "_DEBUG" /d "UNICODE"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"mxCppFramework.bsc"
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:console /debug /machine:I386 /out:"../objud/test/Except.exe" /pdbtype:sept
# Begin Special Build Tool
TargetPath=\Work\demo\make\msw\msvc6\objud\test\Except.exe
SOURCE="$(InputPath)"
PostBuild_Cmds=cd ..	$(TargetPath)
# End Special Build Tool

!ELSEIF  "$(CFG)" == "mxCppFrameworkTestExcept - Win32 Multithread Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "../obj_mt/test"
# PROP BASE Intermediate_Dir "../obj_mt/test"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../obj_mt/test"
# PROP Intermediate_Dir "../obj_mt/test"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /GF /O2 /D "NDEBUG" /D "_MBCS" /D "WIN32" /D "MXCPP_PCH" /Fp"../obj_mt/link/mxprec.pch" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GR /GX /GF /O2 /I "../../../../../inc" /I "../../../../../src/inc" /D "NDEBUG" /D "_MBCS" /D "WIN32" /Fr /FD /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"mxCppFramework.bsc"
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:console /machine:I386
# ADD LINK32 /nologo /subsystem:console /machine:I386 /out:"../obj_mt/test/Except.exe"
# Begin Special Build Tool
TargetPath=\Work\demo\make\msw\msvc6\obj_mt\test\Except.exe
SOURCE="$(InputPath)"
PostBuild_Cmds=cd ..	$(TargetPath)
# End Special Build Tool

!ELSEIF  "$(CFG)" == "mxCppFrameworkTestExcept - Win32 Multithread Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "../objd_mt/test"
# PROP BASE Intermediate_Dir "../objd_mt/test"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../objd_mt/test"
# PROP Intermediate_Dir "../objd_mt/test"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W4 /Gm /GX /GF /ZI /Od /D "_DEBUG" /D "_MBCS" /D "WIN32" /D "MXCPP_PCH" /Fp"../objd_mt/link/mxprec.pch" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W4 /Gm /GR /GX /GF /ZI /Od /I "../../../../../inc" /I "../../../../../src/inc" /D "_DEBUG" /D "_MBCS" /D "WIN32" /Fr /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"mxCppFramework.bsc"
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:console /debug /machine:I386 /out:"../objd_mt/test/Except.exe" /pdbtype:sept
# Begin Special Build Tool
TargetPath=\Work\demo\make\msw\msvc6\objd_mt\test\Except.exe
SOURCE="$(InputPath)"
PostBuild_Cmds=cd ..	$(TargetPath)
# End Special Build Tool

!ELSEIF  "$(CFG)" == "mxCppFrameworkTestExcept - Win32 Multithread Unicode Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "../obju_mt/test"
# PROP BASE Intermediate_Dir "../obju_mt/test"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../obju_mt/test"
# PROP Intermediate_Dir "../obju_mt/test"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /GF /O2 /D "NDEBUG" /D "UNICODE" /D "WIN32" /D "MXCPP_PCH" /Fp"../obju_mt/link/mxprec.pch" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GR /GX /GF /O2 /I "../../../../../inc" /I "../../../../../src/inc" /D "NDEBUG" /D "UNICODE" /D "WIN32" /Fr /FD /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "UNICODE"
# ADD RSC /l 0x409 /d "NDEBUG" /d "UNICODE"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"mxCppFramework.bsc"
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:console /machine:I386
# ADD LINK32 /nologo /subsystem:console /machine:I386 /out:"../obju_mt/test/Except.exe"
# Begin Special Build Tool
TargetPath=\Work\demo\make\msw\msvc6\obju_mt\test\Except.exe
SOURCE="$(InputPath)"
PostBuild_Cmds=cd ..	$(TargetPath)
# End Special Build Tool

!ELSEIF  "$(CFG)" == "mxCppFrameworkTestExcept - Win32 Multithread Unicode Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "../objud_mt/test"
# PROP BASE Intermediate_Dir "../objud_mt/test"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../objud_mt/test"
# PROP Intermediate_Dir "../objud_mt/test"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W4 /Gm /GX /GF /ZI /Od /D "_DEBUG" /D "UNICODE" /D "WIN32" /D "MXCPP_PCH" /Fp"../objud_mt/link/mxprec.pch" /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W4 /Gm /GR /GX /GF /ZI /Od /I "../../../../../inc" /I "../../../../../src/inc" /D "_DEBUG" /D "UNICODE" /D "WIN32" /Fr /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "UNICODE"
# ADD RSC /l 0x409 /d "_DEBUG" /d "UNICODE"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"mxCppFramework.bsc"
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:console /debug /machine:I386 /out:"../objud_mt/test/Except.exe" /pdbtype:sept
# Begin Special Build Tool
TargetPath=\Work\demo\make\msw\msvc6\objud_mt\test\Except.exe
SOURCE="$(InputPath)"
PostBuild_Cmds=cd ..	$(TargetPath)
# End Special Build Tool

!ELSEIF  "$(CFG)" == "mxCppFrameworkTestExcept - Win32 DLL Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "../obj_dll/test"
# PROP BASE Intermediate_Dir "../obj_dll/test"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../obj_dll/test"
# PROP Intermediate_Dir "../obj_dll/test"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /GF /O2 /D "NDEBUG" /D "_MBCS" /D "_WINDOWS" /D "MXCPP_USEDLL" /D "WIN32" /D "MXCPP_PCH" /Fp"../obj_dll/link/mxprec.pch" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /GF /O2 /I "../../../../../inc" /I "../../../../../src/inc" /D "NDEBUG" /D "_MBCS" /D "_WINDOWS" /D "MXCPP_USEDLL" /D "WIN32" /Fr /FD /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"mxCppFramework.bsc"
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:console /machine:I386
# ADD LINK32 /nologo /subsystem:console /machine:I386 /out:"../obj_dll/test/Except.exe"
# Begin Special Build Tool
TargetPath=\Work\demo\make\msw\msvc6\obj_dll\test\Except.exe
SOURCE="$(InputPath)"
PostBuild_Cmds=cd ..	$(TargetPath)
# End Special Build Tool

!ELSEIF  "$(CFG)" == "mxCppFrameworkTestExcept - Win32 DLL Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "../objd_dll/test"
# PROP BASE Intermediate_Dir "../objd_dll/test"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../objd_dll/test"
# PROP Intermediate_Dir "../objd_dll/test"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W4 /Gm /GX /GF /ZI /Od /D "_DEBUG" /D "_MBCS" /D "_WINDOWS" /D "MXCPP_USEDLL" /D "WIN32" /D "MXCPP_PCH" /Fp"../objd_dll/link/mxprec.pch" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W4 /Gm /GR /GX /GF /ZI /Od /I "../../../../../inc" /I "../../../../../src/inc" /D "_DEBUG" /D "_MBCS" /D "_WINDOWS" /D "MXCPP_USEDLL" /D "WIN32" /Fr /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"mxCppFramework.bsc"
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:console /debug /machine:I386 /out:"../objd_dll/test/Except.exe" /pdbtype:sept
# Begin Special Build Tool
TargetPath=\Work\demo\make\msw\msvc6\objd_dll\test\Except.exe
SOURCE="$(InputPath)"
PostBuild_Cmds=cd ..	$(TargetPath)
# End Special Build Tool

!ELSEIF  "$(CFG)" == "mxCppFrameworkTestExcept - Win32 DLL Unicode Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "../obju_dll/test"
# PROP BASE Intermediate_Dir "../obju_dll/test"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../obju_dll/test"
# PROP Intermediate_Dir "../obju_dll/test"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /GF /O2 /D "NDEBUG" /D "UNICODE" /D "_WINDOWS" /D "MXCPP_USEDLL" /D "WIN32" /D "MXCPP_PCH" /Fp"../obju_dll/link/mxprec.pch" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GR /GX /GF /O2 /I "../../../../../inc" /I "../../../../../src/inc" /D "NDEBUG" /D "UNICODE" /D "_WINDOWS" /D "MXCPP_USEDLL" /D "WIN32" /Fr /FD /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "UNICODE"
# ADD RSC /l 0x409 /d "NDEBUG" /d "UNICODE"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"mxCppFramework.bsc"
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:console /machine:I386
# ADD LINK32 /nologo /subsystem:console /machine:I386 /out:"../obju_dll/test/Except.exe"
# Begin Special Build Tool
TargetPath=\Work\demo\make\msw\msvc6\obju_dll\test\Except.exe
SOURCE="$(InputPath)"
PostBuild_Cmds=cd ..	$(TargetPath)
# End Special Build Tool

!ELSEIF  "$(CFG)" == "mxCppFrameworkTestExcept - Win32 DLL Unicode Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "../objud_dll/test"
# PROP BASE Intermediate_Dir "../objud_dll/test"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../objud_dll/test"
# PROP Intermediate_Dir "../objud_dll/test"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W4 /Gm /GX /GF /ZI /Od /D "_DEBUG" /D "UNICODE" /D "_WINDOWS" /D "MXCPP_USEDLL" /D "WIN32" /D "MXCPP_PCH" /Fp"../objud_dll/link/mxprec.pch" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W4 /Gm /GR /GX /GF /ZI /Od /I "../../../../../inc" /I "../../../../../src/inc" /D "_DEBUG" /D "UNICODE" /D "_WINDOWS" /D "MXCPP_USEDLL" /D "WIN32" /Fr /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "UNICODE"
# ADD RSC /l 0x409 /d "_DEBUG" /d "UNICODE"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"mxCppFramework.bsc"
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:console /debug /machine:I386 /out:"../objud_dll/test/Except.exe" /pdbtype:sept
# Begin Special Build Tool
TargetPath=\Work\demo\make\msw\msvc6\objud_dll\test\Except.exe
SOURCE="$(InputPath)"
PostBuild_Cmds=cd ..	$(TargetPath)
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "mxCppFrameworkTestExcept - Win32 Release"
# Name "mxCppFrameworkTestExcept - Win32 Debug"
# Name "mxCppFrameworkTestExcept - Win32 Unicode Release"
# Name "mxCppFrameworkTestExcept - Win32 Unicode Debug"
# Name "mxCppFrameworkTestExcept - Win32 Multithread Release"
# Name "mxCppFrameworkTestExcept - Win32 Multithread Debug"
# Name "mxCppFrameworkTestExcept - Win32 Multithread Unicode Release"
# Name "mxCppFrameworkTestExcept - Win32 Multithread Unicode Debug"
# Name "mxCppFrameworkTestExcept - Win32 DLL Release"
# Name "mxCppFrameworkTestExcept - Win32 DLL Debug"
# Name "mxCppFrameworkTestExcept - Win32 DLL Unicode Release"
# Name "mxCppFrameworkTestExcept - Win32 DLL Unicode Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\..\..\..\..\tests\Except.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
