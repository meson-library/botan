
name = 'example04_plugin'




example04_plugin = shared_library(name,
                                  sources      : ['plugin.cpp', 'plugin.h'],
                                  cpp_args     : ['-DBUILDING_SHARED_LIBRARY'], 
                                  link_args    : link_args,
                                  dependencies : [corelib_dep, example04_host_dep],
                                  install      : true)