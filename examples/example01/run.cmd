@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

SET "root_path=%~dp0"
SET "PATH=%root_path%..\..\..\;%PATH%"

IF EXIST meson.build (
    ECHO.RUNNING EXAMPLE INFO: Examples cannot be run from this directory^^! They must be run from
    ECHO.                      the artifact directory.

    EXIT /B !ERRORLEVEL!
)

IF NOT EXIST app.exe (
    ECHO.RUNNING EXAMPLE INFO: The executable 'app.exe' was not found in the examples directory^^!

    EXIT /B !ERRORLEVEL!
)

app.exe

ENDLOCAL
