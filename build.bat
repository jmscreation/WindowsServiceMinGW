@echo off
cls

REM		Build Script

REM Set Compiler Settings Here


set CPP=c++
set GPP=g++
set OUTPUT=Service.exe
set DEBUGMODE=1

set REBUILD_LIBRARIES=1

set LINK_ONLY=0
set VERBOSE=0

set ASYNC_BUILD=1

set CPP_COMPILER_FLAGS=-O2 -std=c++11
set ADDITIONAL_LIBRARIES=-static -static-libstdc++ -static-libgcc
set ADDITIONAL_LIBDIRS=
set ADDITIONAL_INCLUDEDIRS=-I.


del %OUTPUT% 2>nul

setlocal enabledelayedexpansion


if %LINK_ONLY% GTR 0 (
	goto linker
)

if %DEBUGMODE% GTR 0 (
	set DEBUG_INFO=-g
) else (
	set DEBUG_INFO=
)

if %ASYNC_BUILD% GTR 0 (
	set WAIT=
) else (
	set WAIT=/WAIT
)

if %REBUILD_LIBRARIES% GTR 0 (
	del /S /Q "*.o" 2>nul
)

echo Building CPP Libraries...
for %%F in (library/*.cpp) do (
	if not exist %%~nF.o (
		echo Building %%~nF.o
		start /B %WAIT% "%%~nF.o" %CPP% %ADDITIONAL_INCLUDEDIRS% %CPP_COMPILER_FLAGS% %DEBUG_INFO% -c library/%%F -o %%~nF.o

		if %VERBOSE% GTR 0 (
			echo %CPP% %ADDITIONAL_INCLUDEDIRS% %CPP_COMPILER_FLAGS% %DEBUG_INFO% -c %%F -o %%~nF.o
		)
	)
)

echo Building Main...
for %%F in (*.cpp) do (
	if not exist %%~nF.o (
		echo Building %%~nF.o
		start /B %WAIT% "%%~nF.o" %CPP% %ADDITIONAL_INCLUDEDIRS% %CPP_COMPILER_FLAGS% %DEBUG_INFO% -c %%F -o %%~nF.o

		if %VERBOSE% GTR 0 (
			echo %CPP% %ADDITIONAL_INCLUDEDIRS% %CPP_COMPILER_FLAGS% %DEBUG_INFO% -c %%F -o %%~nF.o
		)
	)
)

REM Wait for building process to finish
:loop
set /a count=0
for /f %%G in ('tasklist ^| find /c "%CPP%"') do ( set /A count=%count%+%%G )
if %count%==0 (
	goto linker
) else (
	timeout /t 2 /nobreak>nul
	goto loop
)

:linker

set "files="
for /f "delims=" %%A in ('dir /b /a-d "*.o" ') do set "files=!files! %%A"

:link
echo Linking Executable...

if %DEBUGMODE% GTR 0 (
	set MWINDOWS=
) else (
	set MWINDOWS=-mwindows
)

if %VERBOSE% GTR 0 (
	echo %GPP% %ADDITIONAL_LIBDIRS% -o %OUTPUT% %files% %ADDITIONAL_LIBRARIES% %MWINDOWS%
)

%GPP% %ADDITIONAL_LIBDIRS% -o %OUTPUT% %files% %ADDITIONAL_LIBRARIES% %MWINDOWS%

:finish
if exist .\%OUTPUT% (
	echo Build Success!
) else (
	echo Build Failed!
)