#
# Define sources, includes, compile flags and so on...
#
includes = ['..'/include_dir_root]

sources = ['dll.cpp',
           'stl.cpp',
           'common'/'platform'/'win.cpp',
           'common'/'platform'/'lnx.cpp',
           'common'/'platform'/'osx.cpp']

extra_files = ['..'/include_dir_proj/'xcore.h',

               '..'/include_dir_proj/'fs.h',
               '..'/include_dir_proj/'dll.h',
               '..'/include_dir_proj/'stl.h',
               '..'/include_dir_proj/'common.h',

               '..'/include_dir_proj/'common'/'macros.h',
               '..'/include_dir_proj/'common'/'platform.h',
               '..'/include_dir_proj/'common'/'platform'/'lnx.h',
               '..'/include_dir_proj/'common'/'platform'/'osx.h',
               '..'/include_dir_proj/'common'/'platform'/'win.h']


#
# Import dependencies.
#
filesystem_dep = subproject('filesystem').get_variable('filesystem_dep')
eastl_dep      = subproject('eastl').get_variable('eastl_dep')
spdlog_dep      = subproject('spdlog').get_variable('spdlog_dep')


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

    xcore_static = static_library(static_lib_name,
                                  name_prefix         : static_lib_name_prefix,
                                  name_suffix         : static_lib_name_suffix,
                                  include_directories : includes,
                                  sources             : sources,
                                  extra_files         : extra_files,
                                  cpp_args            : ['-DXCORE_BUILD_STATIC_LIBRARY'],
                                  dependencies        : [filesystem_dep, eastl_dep, spdlog_dep],
                                  install             : true)

    xcore_static_dep = declare_dependency(include_directories : includes,
                                          link_with           : xcore_static,
                                          compile_args        : ['-DXCORE_USE_STATIC_LIBRARY'],
                                          dependencies        : [filesystem_dep, eastl_dep, spdlog_dep])

elif get_option('default_library') == 'shared'
    shared_lib_name = proj_name

    xcore_shared = shared_library(shared_lib_name,
                                  include_directories : includes,
                                  sources             : sources,
                                  extra_files         : extra_files,
                                  cpp_args            : ['-DXCORE_BUILD_SHARED_LIBRARY'],
                                  dependencies        : [filesystem_dep, eastl_dep, spdlog_dep],
                                  install             : true)

    xcore_shared_dep = declare_dependency(include_directories : includes,
                                          link_with           : xcore_shared,
                                          compile_args        : ['-DXCORE_USE_SHARED_LIBRARY'],
                                          dependencies        : [filesystem_dep, eastl_dep, spdlog_dep])
else
    error('[' + proj_name + '] The option "default_library" has an inválid value.')
endif


#
# With these lines we, connotatively, export xcore_dep, xcore_static_dep and xcore_shared_dep to the
# outside world.
#
if get_option('default_library') == 'static'
    xcore_dep = xcore_static_dep
elif get_option('default_library') == 'shared'
    xcore_dep = xcore_shared_dep
endif


#
# Install lib data (headers for the external API, docs, licenses and so on...)
#
install_subdir('..'/include_dir_proj,
               install_dir : include_dir_root)

install_data(['..'/'LICENSE.GPL3'],
              install_dir : install_dir_licenses)
