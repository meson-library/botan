
install_dir_example01 = install_dir_examples/'example01'

subdir('app')

install_data(['README.md'],
               install_dir : install_dir_docs/'examples'/'01')

if build_machine.system() == 'windows'
    install_data(['run.cmd'],
        install_dir : install_dir_example01)
endif
