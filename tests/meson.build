
if get_option('build_tests')
    gtest_main_dep = subproject('gtest').get_variable('gtest_main_dep')

    sources       = []
    dependencies  = []

    subdir('Common')
    subdir('DLL')
    subdir('Plugin')

    executable('Tests',
            sources      : sources,
            dependencies : dependencies + [xcore_dep, gtest_main_dep],
            install      : true,
            install_dir  : install_dir_tests)
endif
