#
# Define sources, compile flags and so on...
#
sources = [build_identifier/'botan.cpp']

extra_files = ['..'/include_dir_proj/'botan.h']

specific_cpp_args = []
specific_dependencies = []
if build_machine.system() == 'windows' and meson.get_compiler('cpp').get_id() == 'msvc'
    specific_cpp_args += ['/bigobj']

    specific_dependencies += meson.get_compiler('cpp').find_library('crypt32', required : true)
    specific_dependencies += meson.get_compiler('cpp').find_library('user32', required : true)
    specific_dependencies += meson.get_compiler('cpp').find_library('ws2_32', required : true)
endif


#
# Lib build definitions.
#
if get_option('default_library') == 'static'
    static_lib_name        = proj_name
    static_lib_name_prefix = []
    static_lib_name_suffix = []

    if build_machine.system() == 'windows' and meson.get_compiler('cpp').get_id() == 'msvc'
        static_lib_name       += '_static'
        static_lib_name_prefix = ''
        static_lib_name_suffix = 'lib'
    endif

    botan_static = static_library(static_lib_name,
                                  name_prefix         : static_lib_name_prefix,
                                  name_suffix         : static_lib_name_suffix,
                                  include_directories : ['..'/include_dir_root/'botan'],
                                  sources             : sources,
                                  extra_files         : extra_files,
                                  cpp_args            : specific_cpp_args,
                                  dependencies        : [],
                                  install             : true)

    botan_static_dep = declare_dependency(include_directories : ['..'/include_dir_root],
                                          link_with           : botan_static,
                                          compile_args        : [],
                                          dependencies        : [] + specific_dependencies)

elif get_option('default_library') == 'shared'
    shared_lib_name = proj_name

    botan_shared = shared_library(shared_lib_name,
                                  include_directories : ['..'/include_dir_root/'botan'],
                                  sources             : sources,
                                  extra_files         : extra_files,
                                  cpp_args            : ['-DBOTAN_DLL=__declspec(dllexport)'] + specific_cpp_args,
                                  dependencies        : [] + specific_dependencies,
                                  install             : true)

    botan_shared_dep = declare_dependency(include_directories : ['..'/include_dir_root],
                                          link_with           : botan_shared,
                                          compile_args        : [],
                                          dependencies        : [])
else
    error('[' + proj_name + '] The option "default_library" has an inválid value.')
endif


#
# With these lines we, connotatively, export botan_dep, botan_static_dep and botan_shared_dep to the
# outside world.
#
if get_option('default_library') == 'static'
    botan_dep = botan_static_dep
elif get_option('default_library') == 'shared'
    botan_dep = botan_shared_dep
endif


#
# Install lib data (headers for the external API, docs, licenses and so on...)
#
install_subdir('..'/include_dir_proj,
               install_dir : include_dir)

install_data(['..'/'LICENSE.GPL3'],
              install_dir : install_dir_licenses)
