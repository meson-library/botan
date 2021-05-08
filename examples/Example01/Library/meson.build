
example01_library_shared = shared_library('example01_library',
                                          sources      : ['library.cpp', 'library.h'],
                                          cpp_args     : ['-DEXAMPLE01_LIBRARY_API=XCORE_SYMBOL_EXPORT'],
                                          dependencies : [xcore_dep],
                                          install_dir  : install_dir_example01,
                                          install      : true)

example01_library_dep = declare_dependency(include_directories : include_directories('.'),
                                           link_with           : example01_library_shared,
                                           compile_args        : ['-DEXAMPLE01_LIBRARY_API=XCORE_SYMBOL_IMPORT'],
                                           dependencies        : [xcore_dep])
