project('corelib', ['cpp'], 
         version        : '0.1.0',  
         license        : ['GPL3'],
         meson_version  : '>= 0.49.0')




name = 'corelib'




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




install_headers('include/corelib/corelib.h',
                'include/corelib/common.h',
                'include/corelib/asset_info.h',
                'include/corelib/semver.h',
                'include/corelib/dll.h',
                'include/corelib/disposable.h',
                'include/corelib/plugable.h', 
                 subdir : 'corelib')

install_data(['LICENSE.GPL3'],
               rename      : ['LICENSE.GPL3'],
               install_dir :  'share/licenses/corelib')