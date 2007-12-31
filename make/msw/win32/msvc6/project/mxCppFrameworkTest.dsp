# Microsoft Developer Studio Project File - Name="mxCppFrameworkTest" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=mxCppFrameworkTest - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "mxCppFrameworkTest.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "mxCppFrameworkTest.mak" CFG="mxCppFrameworkTest - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "mxCppFrameworkTest - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "mxCppFrameworkTest - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE "mxCppFrameworkTest - Win32 Unicode Release" (based on "Win32 (x86) Console Application")
!MESSAGE "mxCppFrameworkTest - Win32 Unicode Debug" (based on "Win32 (x86) Console Application")
!MESSAGE "mxCppFrameworkTest - Win32 Multithread Release" (based on "Win32 (x86) Console Application")
!MESSAGE "mxCppFrameworkTest - Win32 Multithread Debug" (based on "Win32 (x86) Console Application")
!MESSAGE "mxCppFrameworkTest - Win32 Multithread Unicode Release" (based on "Win32 (x86) Console Application")
!MESSAGE "mxCppFrameworkTest - Win32 Multithread Unicode Debug" (based on "Win32 (x86) Console Application")
!MESSAGE "mxCppFrameworkTest - Win32 DLL Release" (based on "Win32 (x86) Console Application")
!MESSAGE "mxCppFrameworkTest - Win32 DLL Debug" (based on "Win32 (x86) Console Application")
!MESSAGE "mxCppFrameworkTest - Win32 DLL Unicode Release" (based on "Win32 (x86) Console Application")
!MESSAGE "mxCppFrameworkTest - Win32 DLL Unicode Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "mxCppFrameworkTest - Win32 Release"

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
# ADD BASE CPP /nologo /W3 /GX /O2 /D "NDEBUG" /D "_MBCS" /D "WIN32" /D "MXCPP_PCH" /Fp"../obj/link/mxprec.pch" /YX /FD /GF /c
# ADD CPP /nologo /W3 /GR /GX /O2 /I "../../../../../inc" /D "NDEBUG" /D "_MBCS" /D "WIN32" /Fr /FD /GF /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"mxCppFramework.bsc"
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:console /machine:I386
# ADD LINK32 /nologo /subsystem:console /machine:I386 /out:"../obj/test/Test.exe"
# Begin Special Build Tool
TargetPath=\Work\demo\make\msw\win32\msvc6\obj\test\Test.exe
SOURCE="$(InputPath)"
PostBuild_Cmds=cd ..	$(TargetPath)
# End Special Build Tool

!ELSEIF  "$(CFG)" == "mxCppFrameworkTest - Win32 Debug"

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
# ADD BASE CPP /nologo /W4 /Gm /GX /ZI /Od /D "_DEBUG" /D "_MBCS" /D "WIN32" /D "MXCPP_PCH" /Fp"../objd/link/mxprec.pch" /YX /FD /GF /GZ /c
# ADD CPP /nologo /W4 /Gm /GR /GX /ZI /Od /I "../../../../../inc" /D "_DEBUG" /D "_MBCS" /D "WIN32" /Fr /FD /GF /GZ /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"mxCppFramework.bsc"
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:console /debug /machine:I386 /out:"../objd/test/Test.exe" /pdbtype:sept
# Begin Special Build Tool
TargetPath=\Work\demo\make\msw\win32\msvc6\objd\test\Test.exe
SOURCE="$(InputPath)"
PostBuild_Cmds=cd ..	$(TargetPath)
# End Special Build Tool

!ELSEIF  "$(CFG)" == "mxCppFrameworkTest - Win32 Unicode Release"

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
# ADD BASE CPP /nologo /W3 /GX /O2 /D "NDEBUG" /D "UNICODE" /D "WIN32" /D "MXCPP_PCH" /Fp"../obju/link/mxprec.pch" /YX /FD /GF /c
# ADD CPP /nologo /W3 /GR /GX /O2 /I "../../../../../inc" /D "NDEBUG" /D "UNICODE" /D "WIN32" /Fr /FD /GF /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "UNICODE"
# ADD RSC /l 0x409 /d "NDEBUG" /d "UNICODE"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"mxCppFramework.bsc"
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:console /machine:I386
# ADD LINK32 /nologo /subsystem:console /machine:I386 /out:"../obju/test/Test.exe"
# Begin Special Build Tool
TargetPath=\Work\demo\make\msw\win32\msvc6\obju\test\Test.exe
SOURCE="$(InputPath)"
PostBuild_Cmds=cd ..	$(TargetPath)
# End Special Build Tool

!ELSEIF  "$(CFG)" == "mxCppFrameworkTest - Win32 Unicode Debug"

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
# ADD BASE CPP /nologo /W4 /Gm /GX /ZI /Od /D "_DEBUG" /D "UNICODE" /D "WIN32" /D "MXCPP_PCH" /Fp"../objud/link/mxprec.pch" /YX /FD /GF /GZ /c
# ADD CPP /nologo /W4 /Gm /GR /GX /ZI /Od /I "../../../../../inc" /D "_DEBUG" /D "UNICODE" /D "WIN32" /Fr /FD /GF /GZ /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "UNICODE"
# ADD RSC /l 0x409 /d "_DEBUG" /d "UNICODE"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"mxCppFramework.bsc"
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:console /debug /machine:I386 /out:"../objud/test/Test.exe" /pdbtype:sept
# Begin Special Build Tool
TargetPath=\Work\demo\make\msw\win32\msvc6\objud\test\Test.exe
SOURCE="$(InputPath)"
PostBuild_Cmds=cd ..	$(TargetPath)
# End Special Build Tool

!ELSEIF  "$(CFG)" == "mxCppFrameworkTest - Win32 Multithread Release"

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
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "_MBCS" /D "WIN32" /D "MXCPP_PCH" /Fp"../obj_mt/link/mxprec.pch" /YX /FD /GF /c
# ADD CPP /nologo /MT /W3 /GR /GX /O2 /I "../../../../../inc" /D "NDEBUG" /D "_MBCS" /D "WIN32" /Fr /FD /GF /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"mxCppFramework.bsc"
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:console /machine:I386
# ADD LINK32 /nologo /subsystem:console /machine:I386 /out:"../obj_mt/test/Test.exe"
# Begin Special Build Tool
TargetPath=\Work\demo\make\msw\win32\msvc6\obj_mt\test\Test.exe
SOURCE="$(InputPath)"
PostBuild_Cmds=cd ..	$(TargetPath)
# End Special Build Tool

!ELSEIF  "$(CFG)" == "mxCppFrameworkTest - Win32 Multithread Debug"

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
# ADD BASE CPP /nologo /MTd /W4 /Gm /GX /ZI /Od /D "_DEBUG" /D "_MBCS" /D "WIN32" /D "MXCPP_PCH" /Fp"../objd_mt/link/mxprec.pch" /YX /FD /GF /GZ /c
# ADD CPP /nologo /MTd /W4 /Gm /GR /GX /ZI /Od /I "../../../../../inc" /D "_DEBUG" /D "_MBCS" /D "WIN32" /Fr /FD /GF /GZ /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"mxCppFramework.bsc"
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:console /debug /machine:I386 /out:"../objd_mt/test/Test.exe" /pdbtype:sept
# Begin Special Build Tool
TargetPath=\Work\demo\make\msw\win32\msvc6\objd_mt\test\Test.exe
SOURCE="$(InputPath)"
PostBuild_Cmds=cd ..	$(TargetPath)
# End Special Build Tool

!ELSEIF  "$(CFG)" == "mxCppFrameworkTest - Win32 Multithread Unicode Release"

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
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "NDEBUG" /D "UNICODE" /D "WIN32" /D "MXCPP_PCH" /Fp"../obju_mt/link/mxprec.pch" /YX /FD /GF /c
# ADD CPP /nologo /MT /W3 /GR /GX /O2 /I "../../../../../inc" /D "NDEBUG" /D "UNICODE" /D "WIN32" /Fr /FD /GF /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "UNICODE"
# ADD RSC /l 0x409 /d "NDEBUG" /d "UNICODE"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"mxCppFramework.bsc"
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:console /machine:I386
# ADD LINK32 /nologo /subsystem:console /machine:I386 /out:"../obju_mt/test/Test.exe"
# Begin Special Build Tool
TargetPath=\Work\demo\make\msw\win32\msvc6\obju_mt\test\Test.exe
SOURCE="$(InputPath)"
PostBuild_Cmds=cd ..	$(TargetPath)
# End Special Build Tool

!ELSEIF  "$(CFG)" == "mxCppFrameworkTest - Win32 Multithread Unicode Debug"

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
# ADD BASE CPP /nologo /MTd /W4 /Gm /GX /ZI /Od /D "_DEBUG" /D "UNICODE" /D "WIN32" /D "MXCPP_PCH" /Fp"../objud_mt/link/mxprec.pch" /YX /FD /GF /GZ /c
# ADD CPP /nologo /MTd /W4 /Gm /GR /GX /ZI /Od /I "../../../../../inc" /D "_DEBUG" /D "UNICODE" /D "WIN32" /Fr /FD /GF /GZ /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "UNICODE"
# ADD RSC /l 0x409 /d "_DEBUG" /d "UNICODE"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"mxCppFramework.bsc"
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:console /debug /machine:I386 /out:"../objud_mt/test/Test.exe" /pdbtype:sept
# Begin Special Build Tool
TargetPath=\Work\demo\make\msw\win32\msvc6\objud_mt\test\Test.exe
SOURCE="$(InputPath)"
PostBuild_Cmds=cd ..	$(TargetPath)
# End Special Build Tool

!ELSEIF  "$(CFG)" == "mxCppFrameworkTest - Win32 DLL Release"

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
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "_MBCS" /D "_WINDOWS" /D "MXCPP_USEDLL" /D "WIN32" /D "MXCPP_PCH" /Fp"../obj_dll/link/mxprec.pch" /YX /FD /GF /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /I "../../../../../inc" /D "NDEBUG" /D "_MBCS" /D "_WINDOWS" /D "MXCPP_USEDLL" /D "WIN32" /Fr /FD /GF /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"mxCppFramework.bsc"
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:console /machine:I386
# ADD LINK32 /nologo /subsystem:console /machine:I386 /out:"../obj_dll/test/Test.exe"
# Begin Special Build Tool
TargetPath=\Work\demo\make\msw\win32\msvc6\obj_dll\test\Test.exe
SOURCE="$(InputPath)"
PostBuild_Cmds=cd ..	$(TargetPath)
# End Special Build Tool

!ELSEIF  "$(CFG)" == "mxCppFrameworkTest - Win32 DLL Debug"

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
# ADD BASE CPP /nologo /MDd /W4 /Gm /GX /ZI /Od /D "_DEBUG" /D "_MBCS" /D "_WINDOWS" /D "MXCPP_USEDLL" /D "WIN32" /D "MXCPP_PCH" /Fp"../objd_dll/link/mxprec.pch" /YX /FD /GF /GZ /c
# ADD CPP /nologo /MDd /W4 /Gm /GR /GX /ZI /Od /I "../../../../../inc" /D "_DEBUG" /D "_MBCS" /D "_WINDOWS" /D "MXCPP_USEDLL" /D "WIN32" /Fr /FD /GF /GZ /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"mxCppFramework.bsc"
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:console /debug /machine:I386 /out:"../objd_dll/test/Test.exe" /pdbtype:sept
# Begin Special Build Tool
TargetPath=\Work\demo\make\msw\win32\msvc6\objd_dll\test\Test.exe
SOURCE="$(InputPath)"
PostBuild_Cmds=cd ..	$(TargetPath)
# End Special Build Tool

!ELSEIF  "$(CFG)" == "mxCppFrameworkTest - Win32 DLL Unicode Release"

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
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "UNICODE" /D "_WINDOWS" /D "MXCPP_USEDLL" /D "WIN32" /D "MXCPP_PCH" /Fp"../obju_dll/link/mxprec.pch" /YX /FD /GF /c
# ADD CPP /nologo /MD /W3 /GR /GX /O2 /I "../../../../../inc" /D "NDEBUG" /D "UNICODE" /D "_WINDOWS" /D "MXCPP_USEDLL" /D "WIN32" /Fr /FD /GF /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "UNICODE"
# ADD RSC /l 0x409 /d "NDEBUG" /d "UNICODE"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"mxCppFramework.bsc"
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:console /machine:I386
# ADD LINK32 /nologo /subsystem:console /machine:I386 /out:"../obju_dll/test/Test.exe"
# Begin Special Build Tool
TargetPath=\Work\demo\make\msw\win32\msvc6\obju_dll\test\Test.exe
SOURCE="$(InputPath)"
PostBuild_Cmds=cd ..	$(TargetPath)
# End Special Build Tool

!ELSEIF  "$(CFG)" == "mxCppFrameworkTest - Win32 DLL Unicode Debug"

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
# ADD BASE CPP /nologo /MDd /W4 /Gm /GX /ZI /Od /D "_DEBUG" /D "UNICODE" /D "_WINDOWS" /D "MXCPP_USEDLL" /D "WIN32" /D "MXCPP_PCH" /Fp"../objud_dll/link/mxprec.pch" /YX /FD /GF /GZ /c
# ADD CPP /nologo /MDd /W4 /Gm /GR /GX /ZI /Od /I "../../../../../inc" /D "_DEBUG" /D "UNICODE" /D "_WINDOWS" /D "MXCPP_USEDLL" /D "WIN32" /Fr /FD /GF /GZ /c
# SUBTRACT CPP /YX
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "UNICODE"
# ADD RSC /l 0x409 /d "_DEBUG" /d "UNICODE"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"mxCppFramework.bsc"
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:console /debug /machine:I386 /out:"../objud_dll/test/Test.exe" /pdbtype:sept
# Begin Special Build Tool
TargetPath=\Work\demo\make\msw\win32\msvc6\objud_dll\test\Test.exe
SOURCE="$(InputPath)"
PostBuild_Cmds=cd ..	$(TargetPath)
# End Special Build Tool

!ENDIF 

# Begin Target

# Name "mxCppFrameworkTest - Win32 Release"
# Name "mxCppFrameworkTest - Win32 Debug"
# Name "mxCppFrameworkTest - Win32 Unicode Release"
# Name "mxCppFrameworkTest - Win32 Unicode Debug"
# Name "mxCppFrameworkTest - Win32 Multithread Release"
# Name "mxCppFrameworkTest - Win32 Multithread Debug"
# Name "mxCppFrameworkTest - Win32 Multithread Unicode Release"
# Name "mxCppFrameworkTest - Win32 Multithread Unicode Debug"
# Name "mxCppFrameworkTest - Win32 DLL Release"
# Name "mxCppFrameworkTest - Win32 DLL Debug"
# Name "mxCppFrameworkTest - Win32 DLL Unicode Release"
# Name "mxCppFrameworkTest - Win32 DLL Unicode Debug"
# End Target
# End Project
