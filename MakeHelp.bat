@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by SSL.HPJ. >"hlp\ssl.hm"
echo. >>"hlp\ssl.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\ssl.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\ssl.hm"
echo. >>"hlp\ssl.hm"
echo // Prompts (IDP_*) >>"hlp\ssl.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\ssl.hm"
echo. >>"hlp\ssl.hm"
echo // Resources (IDR_*) >>"hlp\ssl.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\ssl.hm"
echo. >>"hlp\ssl.hm"
echo // Dialogs (IDD_*) >>"hlp\ssl.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\ssl.hm"
echo. >>"hlp\ssl.hm"
echo // Frame Controls (IDW_*) >>"hlp\ssl.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\ssl.hm"
REM -- Make help for Project SSL


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\ssl.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\ssl.hlp" goto :Error
if not exist "hlp\ssl.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\ssl.hlp" Debug
if exist Debug\nul copy "hlp\ssl.cnt" Debug
if exist Release\nul copy "hlp\ssl.hlp" Release
if exist Release\nul copy "hlp\ssl.cnt" Release
echo.
goto :done

:Error
echo hlp\ssl.hpj(1) : error: Problem encountered creating help file

:done
echo.
