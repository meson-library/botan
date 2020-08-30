#
# Project info.
#
project('XCore', ['cpp'],
         version       : '0.1.0',
         license       : ['GPL3'],
         meson_version : '>= 0.55.0')


#
# Declare some useful global variables.
#
proj_name              = meson.project_name().to_lower()
root_dir               = meson.current_source_dir()
root_build_dir         = meson.current_build_dir()
include_dir_root       = 'include'
include_dir_proj       = include_dir_root/proj_name
sources_dir            = 'sources'
examples_dir           = 'examples'
tests_dir              = 'tests'
docs_dir               = 'docs'
dependencies_dir       = 'subprojects'
install_dir_general    = 'share'
install_dir_licenses   = install_dir_general/'licenses'/proj_name
install_dir_docs       = install_dir_general/'docs'/proj_name
install_headers_subdir = proj_name


#
# Some pre-validations before project setup.
#
if build_machine.system() not in ['windows']
    error('[' + proj_name + '] Script (meson.build) not prepared for your platform yet.')
endif

if build_machine.system() == 'windows' and meson.get_compiler('cpp').get_id() not in ['msvc']
    error('[' + proj_name + '] Script (meson.build) not prepared for your compiler yet.')
endif


#
# Delegate the rest of configuration to the rigth place.
#
subdir(sources_dir)
subdir(tests_dir)
subdir(examples_dir)
subdir(docs_dir)
