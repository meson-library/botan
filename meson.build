#
# Project info.
#
project('botan', ['cpp'],
         version       : '2.18.1',
         license       : ['BSD2'],
         meson_version : '>= 0.55.0')


#
# Declare some useful global variables.
#
proj_name                 = meson.project_name()
root_dir                  = meson.current_source_dir()
root_build_dir            = meson.current_build_dir()
build_identifier          = build_machine.system() + '_' + build_machine.cpu_family() + '_' + meson.get_compiler('cpp').get_id() + '_' + get_option('default_library')
include_dir               = 'include'
include_dir_root          = include_dir/build_identifier
include_dir_proj          = include_dir_root/proj_name
sources_dir               = 'sources'
sources_dir_root          = sources_dir/build_identifier
sources_dir_original      = 'sources-original'
examples_dir              = 'examples'
docs_dir                  = 'docs'
dependencies_dir          = 'subprojects'
install_dir_share         = 'share'
install_dir_licenses      = install_dir_share/'licenses'/proj_name
install_dir_docs          = install_dir_share/'docs'/proj_name
install_dir_examples      = 'bin'/examples_dir/proj_name
install_dir_examples_data = install_dir_examples/'data'
install_headers_subdir    = proj_name


#
# Some pre-validations before project setup.
#
if build_machine.system() not in ['windows']
    error('[' + proj_name + '] Script "meson.build" not prepared for your platform yet.')
endif

if build_machine.system() == 'windows' and meson.get_compiler('cpp').get_id() not in ['msvc']
    error('[' + proj_name + '] Script "meson.build" not prepared for your compiler yet.')
endif


#
# Delegate the rest of configuration to the rigth place.
#
subdir(sources_dir_original)
subdir(sources_dir)
subdir(examples_dir)
subdir(docs_dir)
