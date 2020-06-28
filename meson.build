project('xcore', ['cpp'],
         version       : '0.1.0',
         license       : ['GPL3'],
         meson_version : '>= 0.49.0')




name = 'xcore'




system     = build_machine.system()
cpu        = build_machine.cpu()
cpu_family = build_machine.cpu_family()

cppc    = meson.get_compiler('cpp')
cppc_id = cppc.get_id()

includes  = []
sources   = []
cpp_args  = []
link_args = []




if system not in ['windows']
    error('Script (meson.build) not prepared for your platform yet.')
endif

if system == 'windows' and cppc_id not in ['msvc']
    error('Script (meson.build) not prepared for your compiler yet.')
endif




subdir('sources')

if get_option('build_examples')
    if not meson.is_subproject()
        subdir('examples')
    else
        warning('The option ' + name + ':' + 'build_examples' + ' not work in subproject.')
    endif
endif




install_headers('include/xcore/xcore.h',
                'include/xcore/common.h',
                'include/xcore/asset_info.h',
                'include/xcore/semver.h',
                'include/xcore/dll.h',
                'include/xcore/disposable.h',
                'include/xcore/plugable.h',
                 subdir : 'xcore')

install_data(['LICENSE.GPL3'],
               rename      : ['LICENSE.GPL3'],
               install_dir :  'share/licenses/xcore')