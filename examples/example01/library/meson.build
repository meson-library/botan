
name = 'example01_library'




example01_library_shared = shared_library(name,
                                          sources      : ['library.cpp', 'library.h'],
                                          cpp_args     : ['-DXCORE_BUILDING_SHARED_LIBRARY'],
                                          link_args    : link_args,
                                          dependencies : [xcore_dep],
                                          install      : true)

example01_library_dep = declare_dependency(include_directories : include_directories('.'),
                                           dependencies        : [xcore_dep],
                                           link_with           : example01_library_shared)