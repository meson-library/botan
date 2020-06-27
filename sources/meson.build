
includes = ['../include'] 

sources = ['dll.cpp',
           'plugable.cpp']

extra_files = ['../include/corelib/corelib.h',
               '../include/corelib/common.h',
               '../include/corelib/asset_info.h',
               '../include/corelib/semver.h',
               '../include/corelib/dll.h',
               '../include/corelib/disposable.h',
               '../include/corelib/plugable.h']




static_lib_name        = name
static_lib_name_prefix = []
static_lib_name_suffix = []

if system == 'windows' and cppc_id == 'msvc'  
    static_lib_name       += '_static'
    static_lib_name_prefix = ''
    static_lib_name_suffix = 'lib'
endif




corelib_static = static_library(static_lib_name,
                                name_prefix         : static_lib_name_prefix, 
                                name_suffix         : static_lib_name_suffix,
                                include_directories : includes,
                                sources             : sources,
                                extra_files         : extra_files,
                                cpp_args            : cpp_args, 
                                link_args           : link_args,
                                install             : true)
  
corelib_static_dep = declare_dependency(include_directories : includes,
                                        compile_args        : cpp_args,
                                        link_with           : corelib_static)




corelib_dep = corelib_static_dep