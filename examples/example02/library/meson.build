
name = 'example02_library'




example02_library_shared = shared_library(name,
                                          sources      : ['library.cpp', 'library.h'],
                                          cpp_args     : ['-DXCORE_BUILDING_SHARED_LIBRARY'],
                                          link_args    : link_args,
                                          dependencies : [xcore_dep],
                                          install      : true)