
name = 'example04'




example04_plugin = shared_library(name,
                                  name_suffix  : 'plugin',
                                  sources      : ['plugin.cpp', 'plugin.h'],
                                  cpp_args     : ['-DXCORE_BUILDING_SHARED_LIBRARY'],
                                  link_args    : link_args,
                                  dependencies : [xcore_dep, example04_host_dep],
                                  install      : true)