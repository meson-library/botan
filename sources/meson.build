#
# Define sources, includes, compile flags and so on...
#
includes = ['..'/include_dir_root]

sources = ['DLL.cpp',

           'Common'/'Types'/'Guid.cpp',

           'Common'/'Core'/'STL.cpp',
           'Common'/'Core'/'Utils.cpp',
           'Common'/'Core'/'Platform'/'Windows.cpp',
           'Common'/'Core'/'Platform'/'Linux.cpp',
           'Common'/'Core'/'Platform'/'OSX.cpp',

           'Log'/'Logger.cpp',
           'Log'/'Registry.cpp',
           'Log'/'ConsoleSink.cpp',
           'Log'/'FileSink.cpp',
           'Log'/'Internal.cpp',

           'Plugin'/'Plugable.cpp']

extra_files = ['..'/include_dir_proj/'XCore.h',

               '..'/include_dir_proj/'FS.h',
               '..'/include_dir_proj/'DLL.h',
               '..'/include_dir_proj/'Math.h',

               '..'/include_dir_proj/'Log.h',
               '..'/include_dir_proj/'Log'/'Level.h',
               '..'/include_dir_proj/'Log'/'Sinkable.h',
               '..'/include_dir_proj/'Log'/'Loggable.h',
               '..'/include_dir_proj/'Log'/'Logger.h',
               '..'/include_dir_proj/'Log'/'Registry.h',
               '..'/include_dir_proj/'Log'/'ConsoleSink.h',
               '..'/include_dir_proj/'Log'/'FileSink.h',
               '..'/include_dir_proj/'Log'/'Macros.h',
               '..'/sources_dir/'Log'/'Internal.h',

               '..'/include_dir_proj/'Plugin.h',
               '..'/include_dir_proj/'Plugin'/'Plugable.h',

               '..'/include_dir_proj/'Common.h',
               '..'/include_dir_proj/'Common'/'Core.h',
               '..'/include_dir_proj/'Common'/'Types.h',
               '..'/include_dir_proj/'Common'/'Types'/'AssetInfo.h',
               '..'/include_dir_proj/'Common'/'Types'/'SemVer.h',
               '..'/include_dir_proj/'Common'/'Types'/'Disposable.h',
               '..'/include_dir_proj/'Common'/'Types'/'Guid.h',

               '..'/include_dir_proj/'Common'/'Core'/'Utils.h',
               '..'/include_dir_proj/'Common'/'Core'/'STL.h',
               '..'/include_dir_proj/'Common'/'Core'/'Macros.h',
               '..'/include_dir_proj/'Common'/'Core'/'FileSystem.h',
               '..'/include_dir_proj/'Common'/'Core'/'Platform.h',
               '..'/include_dir_proj/'Common'/'Core'/'Platform'/'Linux.h',
               '..'/include_dir_proj/'Common'/'Core'/'Platform'/'OSX.h',
               '..'/include_dir_proj/'Common'/'Core'/'Platform'/'Windows.h']


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
                              dependencies        : [filesystem_dep, eastl_dep, eigen_dep, spdlog_dep],
                              install             : true)

xcore_static_dep = declare_dependency(include_directories : includes,
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
