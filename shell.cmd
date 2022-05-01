@ECHO OFF
SETLOCAL ENABLEDELAYEDEXPANSION

:PROCESS_CMD
    SET "script_name=%~n0%~x0"
    SET "root_path=%~dp0"

    SET "build_for_os=windows"
    SET "build_for_vs_version=[16.6,)"
    SET "build_for_arch=x64"
    SET "build_for_type=debug"
    SET "build_for_link=shared"
    SET "exec_cmd="
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
        IF [%current_arg%] EQU [--build-link] (
            SHIFT
            CALL SET "build_for_link=%%1"
        )
        IF [%current_arg%] EQU [--exec-cmd] (
            SHIFT
            CALL SET "exec_cmd=%%1"
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
    ECHO.PREPARING THE ENVIRONMENT BEFORE STARTING SHELL.
    ECHO.
    CALL :LOAD_TOOLS

    ECHO.
    ECHO.****************************************************
    ECHO.*                  ENVIRONMENT
    ECHO.*
    ECHO.*    OPERATIONAL SYSTEM: %build_for_os%
    ECHO.*    LINK              : %build_for_link%
    ECHO.*    ARCHITECTURE      : %build_for_arch%
    ECHO.*    TYPE              : %build_for_type%
    ECHO.*    VS VERSION        : %build_for_vs_version%
    ECHO.*
    cecho *                         {navy}              (o_{default}{\n}
    cecho *                         {navy}      c_   \\\_\{default}{\n}
    cecho *                         {navy}    \\)    ^<____){default}{\n}
    ECHO.****************************************************
    ECHO.

    IF [%exec_cmd%] EQU [] (
        ECHO.ENVIRONMENT READY FOR USE. STARTING SHELL...
        ECHO.
        ECHO.Some useful commands available in this shell:
        ECHO.    project_configurator # Command used to configure project.
        ECHO.    project_builder      # Command used to build project.
        ECHO.    project_cleaner      # Command used to clean project.
        ECHO.    project_formatter    # Command used to format source code.
        ECHO.

        ECHO.Important:
        ECHO.     * You can start the above useful commands with the '--help'
        ECHO.       argument to see more options.
        ECHO.     * You can start this script '%SCRIPT_NAME%' with the '--help'
        ECHO.       argument to see more options.

        bash.exe --minimal-search-path
    ) ELSE (
       ECHO.ENVIRONMENT READY FOR USE. STARTING SHELL TO RUN A COMMAND AND EXIT.
       ECHO.COMMAND TO RUN: %exec_cmd%
       ECHO.
       bash.exe --minimal-search-path -c %exec_cmd%
    )
    ECHO.
    ECHO.ENDING SHELL...
EXIT /B 0


:LOAD_TOOLS
    CALL "tools\toolset\win-utils\setup.cmd" cecho ninja
    CALL "tools\toolset\win-clang-tools\setup.cmd"
    CALL "tools\toolset\win-doxygen\setup.cmd"
    CALL "tools\toolset\win-python\setup.cmd"
    CALL "tools\toolset\win-meson\setup.cmd"
    CALL "tools\toolset\win-git\setup.cmd" --mode 3
    CALL "tools\toolset\win-msvc\setup.cmd" --vs-version "%build_for_vs_version%" --arch %build_for_arch%

    SET "tools_script_folder=%root_path%tools\scripts"
    IF "!PATH:%tools_script_folder%=!" EQU "%PATH%" (
        SET "PATH=%tools_script_folder%;%PATH%"
    )
EXIT /B 0


:SHOW_HELP
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
    ECHO #         [--build-link link] [--build-arch arch]                     #
    ECHO #         [--build-type type]}                                        #
    ECHO #                                                                     #
    ECHO # EXAMPLES:                                                           #
    ECHO #     %script_name%                                                       #
    ECHO #     %script_name% -h                                                    #
    ECHO #     %script_name% --vs-version "[15.0,]" --build-arch x64               #
    ECHO #     %script_name% --build-type release                                  #
    ECHO #     %script_name% --build-link static                                   #
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
    echo #                                                                     #
    echo #     --build-link    The linkage type should be one of the           #
    ECHO #         following values: 'static' or 'shared'. Default             #
    ECHO #         to 'shared'.                                                #
    ECHO #                                                                     #
    ECHO #     --build-arch    The build architecture should be one of the     #
    ECHO #         following values: 'x64'. Default to 'x64'.                  #
    ECHO #                                                                     #
    ECHO #     --build-type    The build type should be one of the             #
    ECHO #         following values: 'debug', 'release' or 'debugoptimized'.   #
    ECHO #         Default to 'debug'.                                         #
    ECHO #                                                                     #         
    ECHO #     --exec-cmd      A command to run in this environment and exit.  #
    ECHO #                                                                     #
    ECHO #                                                                     #
    ECHO #######################################################################
EXIT /B 0
