
name = 'example03_plugin'




example03_plugin = shared_library(name,
                                  sources      : ['plugin.cpp', 'plugin.h'],
                                  cpp_args     : ['-DXCORE_BUILDING_SHARED_LIBRARY'],
                                  link_args    : link_args,
                                  dependencies : [xcore_dep],
                                  install      : true)