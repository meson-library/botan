#
# Find the tools tha will be used to generate the botan amalgamation source code.
#
python = find_program('python', required : true)
mkdir  = find_program('mkdir', required : true)
cp     = find_program('cp', required : true)
fs     = import('fs')

output_text = ''
error_text = ''

error_count = 0


if build_identifier == 'windows_x86_64_msvc_shared'
    run_cmd = run_command(python, meson.current_source_dir()/'configure.py', '--os=windows', '--cc=msvc', '--amalgamation', '--name-amalgamation=botan', '--disable-modules=pkcs11')
    error_count += (run_cmd.returncode() != 0? 1: 0)
    output_text += run_cmd.stdout().strip()
    error_text += run_cmd.stderr().strip()

elif  build_identifier == 'windows_x86_64_msvc_static'
    run_cmd = run_command(python, meson.current_source_dir()/'configure.py', '--os=windows', '--cc=msvc', '--amalgamation', '--name-amalgamation=botan', '--disable-shared-library', '--disable-modules=pkcs11')
    error_count += (run_cmd.returncode() != 0? 1: 0)
    output_text += run_cmd.stdout().strip()
    error_text += run_cmd.stderr().strip()

else
     error('[' + proj_name + '] Script "meson.build" not prepared for your configuration yet.')
endif


if fs.exists(meson.current_source_dir()/'botan.h') and fs.exists(meson.current_source_dir()/'botan.cpp')
    run_cmd = run_command(mkdir, '-p', root_dir/include_dir_proj)
    error_count += (run_cmd.returncode() != 0? 1: 0)
    error_text += run_cmd.stderr().strip()

    run_cmd = run_command(mkdir, '-p', root_dir/sources_dir_root)
    error_count += (run_cmd.returncode() != 0? 1: 0)
    error_text += run_cmd.stderr().strip()

    run_cmd = run_command(cp, meson.current_source_dir()/'botan.h', root_dir/include_dir_proj)
    error_count += (run_cmd.returncode() != 0? 1: 0)
    error_text += run_cmd.stderr().strip()

    run_cmd = run_command(cp, meson.current_source_dir()/'botan.cpp', root_dir/sources_dir_root)
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
