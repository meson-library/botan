#
#
# GENERATION OF THE AMALGAMATION SOURCE CODE.
#
#


#
# Find the tools.
#
mkdir  = find_program('mkdir', required : true)
cp     = find_program('cp', required : true)
fs     = import('fs')


#
# Declare some useful global variables.
#
amalgamation_name = proj_name+'_'
amalgamation_name_with_options_digest = amalgamation_name + amalgamation_digest

output_text = ''
error_text = ''
error_count = 0


#
# Generate the amalgamation source code.
#
if build_identifier == 'windows_x86_64_msvc_shared' + '_' + amalgamation_digest
    run_cmd = run_command(python, meson.current_source_dir()/'configure.py', '--os=windows', '--cc=msvc', '--amalgamation', '--name-amalgamation=' + amalgamation_name_with_options_digest, '--disable-modules=pkcs11')
    error_count += (run_cmd.returncode() != 0? 1: 0)
    output_text += run_cmd.stdout().strip()
    error_text += run_cmd.stderr().strip()

elif  build_identifier == 'windows_x86_64_msvc_static' + '_' + amalgamation_digest
    run_cmd = run_command(python, meson.current_source_dir()/'configure.py', '--os=windows', '--cc=msvc', '--amalgamation', '--name-amalgamation=' + amalgamation_name_with_options_digest, '--disable-shared-library', '--disable-modules=pkcs11')
    error_count += (run_cmd.returncode() != 0? 1: 0)
    output_text += run_cmd.stdout().strip()
    error_text += run_cmd.stderr().strip()

else
     error('[' + proj_name + '] Script "meson.build" not prepared for your configuration yet.')
endif


if fs.exists(meson.current_source_dir()/amalgamation_name_with_options_digest+'.h') and fs.exists(meson.current_source_dir()/amalgamation_name_with_options_digest+'.cpp')
    run_cmd = run_command(mkdir, '-p', root_dir/include_dir_proj)
    error_count += (run_cmd.returncode() != 0? 1: 0)
    error_text += run_cmd.stderr().strip()

    run_cmd = run_command(cp, meson.current_source_dir()/amalgamation_name_with_options_digest+'.h', root_dir/include_dir_proj/proj_name+'.h')
    error_count += (run_cmd.returncode() != 0? 1: 0)
    error_text += run_cmd.stderr().strip()
endif


if get_option('log_error')
    if error_count > 0
        message(error_text)
    endif
endif

if get_option('log_output')
    message(output_text)
endif




#
#
# BUILD DEFINITIONS FOR THE LIBRARY.
#
#


#
# Define sources, compile flags and so on...
#
sources = [proj_name+'_' + amalgamation_digest + '.cpp']

extra_files = [proj_name+'_' + amalgamation_digest + '.h']

specific_cpp_args = []
specific_dependencies = []
if build_machine.system() == 'windows' and meson.get_compiler('cpp').get_id() == 'msvc'
    specific_cpp_args += ['/bigobj', '/wd4250', '/wd4251', '/wd4275', '/wd4127']

    specific_dependencies += meson.get_compiler('cpp').find_library('crypt32', required : true)
    specific_dependencies += meson.get_compiler('cpp').find_library('user32', required : true)
    specific_dependencies += meson.get_compiler('cpp').find_library('ws2_32', required : true)
endif


#
# Build definitions.
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
                                  include_directories : ['.'],
                                  sources             : sources,
                                  extra_files         : extra_files,
                                  cpp_args            : specific_cpp_args,
                                  dependencies        : [],
                                  install             : true)

    botan_static_dep = declare_dependency(include_directories : ['..'/'..'/include_dir_root],
                                          link_with           : botan_static,
                                          compile_args        : [],
                                          dependencies        : [] + specific_dependencies)

elif get_option('default_library') == 'shared'
    shared_lib_name = proj_name

    botan_shared = shared_library(shared_lib_name,
                                  include_directories : ['.'],
                                  sources             : sources,
                                  extra_files         : extra_files,
                                  cpp_args            : ['-DBOTAN_DLL=__declspec(dllexport)'] + specific_cpp_args,
                                  dependencies        : [] + specific_dependencies,
                                  install             : true)

    botan_shared_dep = declare_dependency(include_directories : ['..'/'..'/include_dir_root],
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
install_subdir('..'/'..'/include_dir_proj,
               install_dir : include_dir)

install_data(['..'/'..'/'LICENSE.GPL3'],
              install_dir : install_dir_licenses)
