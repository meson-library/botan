
name = 'example03_plugin'




example03_plugin = shared_library(name,
                                  sources      : ['plugin.cpp', 'plugin.h'],
                                  cpp_args     : ['-DBUILDING_SHARED_LIBRARY'], 
                                  link_args    : link_args,
                                  dependencies : [corelib_dep],
                                  install      : true)