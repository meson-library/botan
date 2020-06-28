
includes = ['../include']

sources = ['dll.cpp',
           'plugable.cpp']

extra_files = ['../include/xcore/xcore.h',
               '../include/xcore/common.h',
               '../include/xcore/asset_info.h',
               '../include/xcore/semver.h',
               '../include/xcore/dll.h',
               '../include/xcore/disposable.h',
               '../include/xcore/plugable.h']




static_lib_name        = name
static_lib_name_prefix = []
static_lib_name_suffix = []

if system == 'windows' and cppc_id == 'msvc'
    static_lib_name       += '_static'
    static_lib_name_prefix = ''
    static_lib_name_suffix = 'lib'
endif




xcore_static = static_library(static_lib_name,
                              name_prefix         : static_lib_name_prefix,
                              name_suffix         : static_lib_name_suffix,
                              include_directories : includes,
                              sources             : sources,
                              extra_files         : extra_files,
                              cpp_args            : cpp_args,
                              link_args           : link_args,
                              install             : true)

xcore_static_dep = declare_dependency(include_directories : includes,
                                      compile_args        : cpp_args,
                                      link_with           : xcore_static)




xcore_dep = xcore_static_dep