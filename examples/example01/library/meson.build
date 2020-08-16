
example01_library_shared = shared_library('Example01Library',
                                          sources      : ['Library.cpp', 'Library.h'],
                                          cpp_args     : ['-DXCORE_BUILD_SHARED_LIBRARY'],
                                          dependencies : [xcore_dep],
                                          install      : true)

example01_library_dep = declare_dependency(include_directories : include_directories('.'),
                                           link_with           : example01_library_shared,
                                           dependencies        : [xcore_dep])