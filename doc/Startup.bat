@echo off

rem Run and setup the command line to build the documentation under MS Windows.


if "%1"=="SetVars"	goto SetVars

%comspec% /K %0 SetVars

goto End


:SetVars
set RM=del
set RD=rd

:End