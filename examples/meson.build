
if get_option('build_examples')
    if not meson.is_subproject()
        subdir('example01')
        subdir('example02')
        subdir('example03')
        subdir('example04')
        subdir('example05')
    else
        warning('[' + proj_name + '] The option ' + proj_name + ':build_examples not work in subproject.')
    endif
endif