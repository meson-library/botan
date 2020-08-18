
shared_library('Example04',
                name_suffix  : 'plugin',
                sources      : ['Plugin.cpp', 'Plugin.h'],
                cpp_args     : ['-DXCORE_BUILD_SHARED_LIBRARY'],
                dependencies : [xcore_dep, example04_host_dep],
                install      : true)