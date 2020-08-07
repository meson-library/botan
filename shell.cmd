@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION



:PROCESS_CMD
    SET "current_folder=%~dp0"
    
    SET "build_for_os=windows"
    SET "build_for_vs_version=[16.6,)"
    SET "build_for_arch=x64"
    SET "build_for_type=debug"
    SET "help_val=false"
    :LOOP
        SET current_arg=%1
        IF [%current_arg%] EQU [-h] (
            SET help_val=true
        )
        IF [%current_arg%] EQU [--help] (
            SET help_val=true
        )
        IF [%current_arg%] EQU [--vs-version] (
            SHIFT
            CALL SET "build_for_vs_version=%%1"
        )
        IF [%current_arg%] EQU [--build-arch] (
            SHIFT
            CALL SET "build_for_arch=%%1"
        )
        IF [%current_arg%] EQU [--build-type] (
            SHIFT
            CALL SET "build_for_type=%%1"
        )
        SHIFT
    IF NOT "%~1"=="" GOTO :LOOP

    IF [%help_val%] EQU [true] (
        CALL :SHOW_HELP
    ) ELSE (
        CALL :MAIN
        IF !ERRORLEVEL! NEQ 0 (
            EXIT /B !ERRORLEVEL!
        )
    )
EXIT /B 0



:MAIN
    ECHO.
    ECHO PREPARING THE ENVIRONMENT BEFORE STARTING SHELL.
    ECHO.
    CALL :LOAD_TOOLS

    ECHO.
    ECHO STARTING THE SHELL...
    bash.exe --minimal-search-path
    ECHO ENDING SHELL...
    ECHO.
EXIT /B 0



:LOAD_TOOLS
    CALL "tools\toolset\win-utils\setup.cmd" cecho ninja
    CALL "tools\toolset\win-doxygen\setup.cmd"
    CALL "tools\toolset\win-meson\setup.cmd"
    CALL "tools\toolset\win-git\setup.cmd" --mode 3
    CALL "tools\toolset\win-msvc\setup.cmd" --vs-version "%build_for_vs_version%" --arch %build_for_arch%

    SET "tools_script_folder=%current_folder%tools\scripts"
    IF "!PATH:%tools_script_folder%=!" EQU "%PATH%" (
        SET "PATH=%tools_script_folder%;%PATH%"
    )
EXIT /B 0



:SHOW_HELP
    SET "script_name=%~n0%~x0"
    ECHO #######################################################################
    ECHO #                                                                     #
    ECHO #                        SHELL COMMAND PROMPT                         #
    ECHO #                                                                     #
    ECHO #         '%SCRIPT_NAME%' is a utility script that can be used to         # 
    ECHO #          assist us in the development cicles of this project.       # 
    ECHO #          All this script does is set up our environment and         # 
    ECHO #          bring us a unix-like shell where we can play.              # 
    ECHO #                                                                     #
    ECHO # USAGE:                                                              #
    ECHO #     %SCRIPT_NAME% {[-h^|--help] ^| [--vs-version "version"]               #
    ECHO #         [--build-arch arch] [--build-type type]}                    #
    ECHO #                                                                     #
    ECHO # EXAMPLES:                                                           #
    ECHO #     %script_name%                                                       #
    ECHO #     %script_name% -h                                                    #
    ECHO #     %script_name% --vs-version "[15.0,]" --build-arch x64               #
    ECHO #     %script_name% --build-type release                                  #
    ECHO #                                                                     #
    ECHO # ARGUMENTS:                                                          #
    ECHO #     -h^|--help    Print this help and exit.                          #
    ECHO #                                                                     #
    ECHO #     --vs-version    A version range for instances of VS to          #
    ECHO #         find. Example: '[16.6,)' will find a VS with version equal  # 
    ECHO #         to or greater than '16.6'. OBS: Arg must be "quoted". More  #
    ECHO #         info about this version format can be found at the          #
    ECHO #         following url                                               #
    ECHO #         https://github.com/microsoft/vswhere/wiki/Examples. Default #
    ECHO #         to '[16.6,)'.                                               #
    ECHO #                                                                     #
    ECHO #     --build-arch    The build architecture should be one of the     #
    ECHO #         following values: x64. Default to 'x64'.                    #
    ECHO #                                                                     #
    ECHO #     --build-type    The build type should be one of the             #
    ECHO #         following values: 'debug', 'release' or 'debugoptimized'.   # 
    ECHO #         Default to 'debug'.                                         #
    ECHO #                                                                     #
    ECHO #######################################################################
EXIT /B 0