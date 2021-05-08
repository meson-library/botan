// +---------------------------------------------------------------------------
// |
// |   XCore GPL Source Code
// |   Copyright (c) 2021 XNerv Ltda (http://xnerv.com). All rights reserved.
// |
// |   This file is part of the XCore GPL Source Code.
// |
// |   XCore Source Code is free software: you can redistribute it and/or
// |   modify it under the terms of the GNU General Public License
// |   as published by the Free Software Foundation, either version 3
// |   of the License, or (at your option) any later version.
// |
// |   XCore Source Code is distributed in the hope that it will be useful,
// |   but WITHOUT ANY WARRANTY; without even the implied warranty of
// |   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// |   GNU General Public License for more details.
// |
// |   You should have received a copy of the GNU General Public License
// |   along with XCore Source Code. If not, see <http://www.gnu.org/licenses/>.
// |
// +---------------------------------------------------------------------------

#pragma once

#include <gtest/gtest.h>
#include <xcore/xcore.h>


TEST(dll_tests, when_trying_to_load_existent_dll_returned_handler_should_not_be_null)
{
    XCORE_DLL_HANDLER dllHandler = xcore::dll::load(
        xcore::stl::to_xcore_string("data/example_library.dll"));
    EXPECT_TRUE(dllHandler != nullptr);
}

TEST(dll_tests, when_trying_to_load_nonexistent_dll_returned_handler_should_be_null)
{
    XCORE_DLL_HANDLER dllHandler = xcore::dll::load(
        xcore::stl::to_xcore_string("data/nonexistent_example_library"));
    EXPECT_TRUE(dllHandler == nullptr);
}

TEST(dll_tests,
     when_trying_to_get_existent_symbol_pointer_from_dll_returned_pointer_should_not_be_null)
{
    XCORE_DLL_HANDLER dllHandler = xcore::dll::load(
        xcore::stl::to_xcore_string("data/example_library.dll"));

    XCORE_DLL_SYMBOL_POINTER symbolPointer = xcore::dll::get_symbol_pointer(
        dllHandler, "get_helloworld_from_shared_library");
    EXPECT_TRUE(symbolPointer != nullptr);
}

TEST(dll_tests, when_trying_to_get_nonexistent_symbol_pointer_from_dll_returned_pointer_should_be_null)
{
    XCORE_DLL_HANDLER dllHandler = xcore::dll::load(
        xcore::stl::to_xcore_string("data/example_library.dll"));

    XCORE_DLL_SYMBOL_POINTER symbolPointer = xcore::dll::get_symbol_pointer(
        dllHandler, "nonexistent_get_helloworld_from_shared_library");
    EXPECT_TRUE(symbolPointer == nullptr);
}

TEST(dll_tests, call_function_from_dll_must_be_successful)
{
    XCORE_DLL_HANDLER dllHandler = xcore::dll::load(
        xcore::stl::to_xcore_string("data/example_library.dll"));

    XCORE_DLL_SYMBOL_POINTER symbolPointer = xcore::dll::get_symbol_pointer(
        dllHandler, "get_helloworld_from_shared_library");

    typedef char* (*get_helloworld_from_shared_library)(void);
    auto function_pointer = ((get_helloworld_from_shared_library)symbolPointer);
    auto data             = function_pointer();
    ASSERT_STREQ(data, "Hello World from shared library.\n");
}

TEST(dll_tests, when_trying_to_unload_an_already_loaded_dll_handler_should_be_null)
{
    XCORE_DLL_HANDLER dllHandler = xcore::dll::load(
        xcore::stl::to_xcore_string("data/example_library.dll"));

    EXPECT_TRUE(dllHandler != nullptr);
    xcore::dll::unload(dllHandler);
    EXPECT_TRUE(dllHandler == nullptr);
}
