#
# Find the tools tha will be used to generate documentation.
#
bash = find_program('bash', required : true)
dot = find_program('dot', required : true)


#
# Configure and generate documentation.
#
cdata = configuration_data()
cdata.set('PROJECT_NAME',              proj_name)
cdata.set('PROJECT_VERSION',           meson.project_version())
cdata.set('PROJECT_TAGFILE',           proj_name + '.doxytag')
cdata.set('PROJECT_EXTERNAL_TAGFILES', '')
cdata.set('PROJECT_ROOT_DIR',          root_dir)
cdata.set('PROJECT_BUILD_DIR',         root_build_dir)
cdata.set('PROJECT_INCLUDE_DIR',       (meson.is_subproject()?'..'/'..'/'':'') + '..'/'..'/'..'/'..'/'..'/'..'/'' + (meson.is_subproject()?'subprojects'/proj_name/'':'') + include_dir_root)
cdata.set('PROJECT_SOURCES_DIR',       (meson.is_subproject()?'..'/'..'/'':'') + '..'/'..'/'..'/'..'/'..'/'..'/'' + (meson.is_subproject()?'subprojects'/proj_name/'':'') + sources_dir)
cdata.set('PROJECT_EXAMPLES_DIR',      (meson.is_subproject()?'..'/'..'/'':'') + '..'/'..'/'..'/'..'/'..'/'..'/'' + (meson.is_subproject()?'subprojects'/proj_name/'':'') + examples_dir)
cdata.set('PROJECT_DOCS_DIR',          (meson.is_subproject()?'..'/'..'/'':'') + '..'/'..'/'..'/'..'/'..'/'..'/'' + (meson.is_subproject()?'subprojects'/proj_name/'':'') + docs_dir)
cdata.set('PROJECT_DEPENDENCIES_DIR',  (meson.is_subproject()?'..'/'..'/'':'') + '..'/'..'/'..'/'..'/'..'/'..'/'' + (meson.is_subproject()?'subprojects'/proj_name/'':'') + dependencies_dir)
cdata.set('PROJECT_BRIEF',             '')
cdata.set('HAVE_DOT',                  dot.found() ? 'YES':'NO')

doxyfile = configure_file(input         : 'doxygen.config.in',
                          output        : 'doxygen.config',
                          configuration : cdata,
                          install       : false)

custom_target('api-reference',
              input              : doxyfile,
              output             : 'html',
              command            : [bash, 'wrapper_doxygen', '--workfolder', root_build_dir/docs_dir/'api-reference', '--config-file', root_build_dir/docs_dir/'api-reference'/'doxygen.config'],
              build_always_stale : true,
              install            : true,
              install_dir        : install_dir_docs/'api-reference')
