// +---------------------------------------------------------------------------
// |
// |   XCore GPL Source Code
// |   Copyright (c) 2020 XNerv Ltda (http://xnerv.com). All rights reserved.
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

TEST(PluginTests, CheckIfPluginWasStarted)
{
    XCORE_DLL_HANDLER handler = XCore::DLL::Load("data/ExamplePlugin.dll");

    XCORE_START_PLUGIN(handler);
    EXPECT_TRUE(XCORE_IS_PLUGIN_STARTED(handler));
}

TEST(PluginTests, CheckIfPluginWasStopped)
{
    XCORE_DLL_HANDLER handler = XCore::DLL::Load("data/ExamplePlugin.dll");

    XCORE_START_PLUGIN(handler);
    XCORE_STOP_PLUGIN(handler);
    EXPECT_TRUE(XCORE_IS_PLUGIN_STOPPED(handler));
}

TEST(PluginTests, WhenTryingToStartExistentPluginTheReturnedPluginPointerShouldNotBeNull)
{
    XCORE_DLL_HANDLER handler = XCore::DLL::Load("data/ExamplePlugin.dll");

    XCore::Plugin::Plugable* plugin = XCORE_START_PLUGIN(handler);
    EXPECT_TRUE(plugin != nullptr);
}

TEST(PluginTests, ShouldThrowWhenTryingToStartNonexistentPlugin)
{
    XCORE_DLL_HANDLER handler = XCore::DLL::Load("data/NonexistentExamplePlugin.dll");

    EXPECT_THROW(XCORE_START_PLUGIN(handler), std::runtime_error);
}

TEST(PluginTests, ShouldThrowWhenTryingToStopNonexistentPlugin)
{
    XCORE_DLL_HANDLER handler = XCore::DLL::Load("data/NonexistentExamplePlugin.dll");

    EXPECT_THROW(XCORE_STOP_PLUGIN(handler), std::runtime_error);
}

TEST(PluginTests, ShouldThrowWhenTryingToCheckIfIsStartedNonexistentPlugin)
{
    XCORE_DLL_HANDLER handler = XCore::DLL::Load("data/NonexistentExamplePlugin.dll");

    EXPECT_THROW(XCORE_IS_PLUGIN_STARTED(handler), std::runtime_error);
}

TEST(PluginTests, ShouldThrowWhenTryingToCheckIfIsStoppedNonexistentPlugin)
{
    XCORE_DLL_HANDLER handler = XCore::DLL::Load("data/NonexistentExamplePlugin.dll");

    EXPECT_THROW(XCORE_IS_PLUGIN_STOPPED(handler), std::runtime_error);
}
