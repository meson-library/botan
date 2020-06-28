
name = 'example04_host'




example04_host = executable(name,
                            sources      : ['host.cpp', 'my_plugin.h'],
                            dependencies : [xcore_dep],
                            install      : true)

example04_host_dep = declare_dependency(include_directories : include_directories('.'))