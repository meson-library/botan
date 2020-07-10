
shared_library('example04',
                name_suffix  : 'plugin',
                sources      : ['plugin.cpp', 'plugin.h'],
                cpp_args     : ['-DXCORE_BUILD_SHARED_LIBRARY'],
                dependencies : [xcore_dep, example04_host_dep],
                install      : true)