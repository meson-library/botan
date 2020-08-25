#
# Define sources, compile flags and so on...
#

sources = ['Test01.cpp']

extra_files = []


#
# Import dependencies.
#
gtest_main_dep = subproject('gtest').get_variable('gtest_main_dep')


executable('Test01',
            sources      : ['Test01.cpp'],
            dependencies : [gtest_main_dep],
            install      : true)
