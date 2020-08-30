
#
# Declare the tests.
#
GuidTest = executable('GuidTest',
                     sources      : ['GuidTest.cpp'],
                     dependencies : [gtest_main_dep, xcore_dep])

test('Tests for the common types',
      GuidTest,
      suite: 'Common-Types',
      protocol:'gtest')
