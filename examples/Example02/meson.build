
install_dir_example02 = install_dir_examples/'example02'

subdir('library')
subdir('host')

install_data(['README.md'],
               install_dir : install_dir_docs/'examples'/'02')

if build_machine.system() == 'windows'
    install_data(['run.cmd'],
        install_dir : install_dir_example02)
endif
