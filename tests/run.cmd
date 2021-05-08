@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

SET "root_path=%~dp0"
SET "PATH=%root_path%..\..\;%PATH%"

ECHO.
ECHO.RUNNING TEST FROM: %root_path%

IF EXIST meson.build (
    ECHO.RUNNING TEST INFO: Tests cannot be run from this directory^^! They must be run from
    ECHO.                   the artifact directory.

    EXIT /B !ERRORLEVEL!
)

IF NOT EXIST tests.exe (
    ECHO.RUNNING TEST INFO: The executable 'tests.exe' was not found in the tests directory^^!

    EXIT /B !ERRORLEVEL!
)

tests.exe

ENDLOCAL
