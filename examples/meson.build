
if get_option('build_examples')
    if not meson.is_subproject()
        subdir('Example01')
        subdir('Example02')
        subdir('Example03')
        subdir('Example04')
        subdir('Example05')
    else
        warning('[' + proj_name + '] The option ' + proj_name + ':build_examples not work in subproject.')
    endif
endif