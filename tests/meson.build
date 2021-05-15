
if get_option('build_tests')
    gtest_main_dep = subproject('gtest').get_variable('gtest_main_dep')

    sources       = []
    dependencies  = []

    subdir('dll')

    e = executable('tests',
            sources      : sources,
            dependencies : dependencies + [xcore_dep, gtest_main_dep],
            install_dir  : install_dir_tests,
            install      : true)

    if build_machine.system() == 'windows'
        install_data(['run.cmd'],
            install_dir : install_dir_tests)
    endif
endif
