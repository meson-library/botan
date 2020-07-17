#
# Define sources, includes, compile flags and so on...
#
includes = ['..'/include_dir_root]

sources = ['dll.cpp',
           'stl'/'ea.cpp',
           'log'/'logger.cpp',
           'log'/'console_sink.cpp',
           'log'/'file_sink.cpp',
           'log'/'internal.cpp',
           'plugin'/'plugable.cpp']

extra_files = ['..'/include_dir_proj/'xcore.h',

               '..'/include_dir_proj/'fs.h',
               '..'/include_dir_proj/'dll.h',
               '..'/include_dir_proj/'math.h',
               
               '..'/include_dir_proj/'stl.h',
               '..'/include_dir_proj/'stl'/'std.h',
               '..'/include_dir_proj/'stl'/'ea.h',

               '..'/include_dir_proj/'log.h',
               '..'/include_dir_proj/'log'/'level.h',
               '..'/include_dir_proj/'log'/'sink.h',
               '..'/include_dir_proj/'log'/'loggable.h',
               '..'/include_dir_proj/'log'/'logger.h',
               '..'/include_dir_proj/'log'/'console_sink.h',
               '..'/include_dir_proj/'log'/'file_sink.h',
               '..'/sources_dir/'log'/'internal.h',

                '..'/include_dir_proj/'plugin.h',
                '..'/include_dir_proj/'plugin'/'plugable.h',

               '..'/include_dir_proj/'common'/'common.h',
               '..'/include_dir_proj/'common'/'asset_info.h',
               '..'/include_dir_proj/'common'/'semver.h',
               '..'/include_dir_proj/'common'/'disposable.h']

cpp_args = ['-DXCORE_STL_IMPLEMENTATION=' + get_option('stl_implementation')]



#
# Import dependencies.
#
filesystem_dep = subproject('filesystem').get_variable('filesystem_dep')
eastl_dep      = subproject('eastl').get_variable('eastl_dep')
eigen_dep      = subproject('eigen').get_variable('eigen_dep')
spdlog_dep     = subproject('spdlog').get_variable('spdlog_dep')



#
# Build lib(s).
#
static_lib_name        = proj_name
static_lib_name_prefix = ''
static_lib_name_suffix = ''

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
                              cpp_args            : cpp_args,
                              dependencies        : [filesystem_dep, eastl_dep, eigen_dep, spdlog_dep],
                              install             : true)

xcore_static_dep = declare_dependency(include_directories : includes,
                                      compile_args        : cpp_args,
                                      link_with           : xcore_static,
                                      dependencies        : [filesystem_dep, eastl_dep, eigen_dep, spdlog_dep])

# With this line we, connotatively, export xcore_dep and xcore_static_dep to the outside world.
xcore_dep = xcore_static_dep



#
# Install lib data (headers for the external API, docs, licenses and so on...)
#
install_subdir('..'/include_dir_proj,
               install_dir : include_dir_root)

install_data(['..'/'LICENSE.GPL3'],
              install_dir : install_dir_licenses)