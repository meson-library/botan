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

#include <XCore/XCore.h>
#include <gtest/gtest.h>

TEST(DLLTests, WhenTryingToLoadExistentDllReturnedHandlerShouldNotBeNull)
{
    XCORE_DLL_HANDLER dllHandler = XCore::DLL::Load("data/ExampleDLL");
    EXPECT_TRUE(dllHandler != nullptr);
}

TEST(DLLTests, WhenTryingToLoadNonexistentDllReturnedHandlerShouldBeNull)
{
    XCORE_DLL_HANDLER dllHandler = XCore::DLL::Load("data/NonexistentExampleDLL");
    EXPECT_TRUE(dllHandler == nullptr);
}

TEST(DLLTests, WhenTryingToGetExistentSymbolPointerFromDllReturnedPointerShouldNotBeNull)
{
    XCORE_DLL_HANDLER dllHandler = XCore::DLL::Load("data/ExampleDLL");

    XCORE_DLL_SYMBOL_POINTER symbolPointer = XCore::DLL::GetSymbolPointer(
        dllHandler, "get_helloworld_from_shared_library");
    EXPECT_TRUE(symbolPointer != nullptr);
}

TEST(DLLTests, WhenTryingToGetNonexistentSymbolPointerFromDllReturnedPointerShouldBeNull)
{
    XCORE_DLL_HANDLER dllHandler = XCore::DLL::Load("data/ExampleDLL");

    XCORE_DLL_SYMBOL_POINTER symbolPointer = XCore::DLL::GetSymbolPointer(
        dllHandler, "nonexistent_get_helloworld_from_shared_library");
    EXPECT_TRUE(symbolPointer == nullptr);
}

TEST(DLLTests, CallFunctionFromDllMustBeSuccessful)
{
    XCORE_DLL_HANDLER        dllHandler    = XCore::DLL::Load("data/ExampleDLL");
    XCORE_DLL_SYMBOL_POINTER symbolPointer = XCore::DLL::GetSymbolPointer(
        dllHandler, "get_helloworld_from_shared_library");

    typedef char* (*get_helloworld_from_shared_library)(void);
    auto function_pointer = ((get_helloworld_from_shared_library)symbolPointer);
    auto data             = function_pointer();
    ASSERT_STREQ(data, "Hello World from shared library.\n");
}

TEST(DLLTests, WhenTryingToUnloadAnAlreadyLoadedDllHandlerShouldBeNull)
{
    XCORE_DLL_HANDLER dllHandler = XCore::DLL::Load("data/ExampleDLL");

    EXPECT_TRUE(dllHandler != nullptr);
    XCore::DLL::Unload(dllHandler);
    EXPECT_TRUE(dllHandler == nullptr);
}
