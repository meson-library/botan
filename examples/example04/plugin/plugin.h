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

#include <my_plugin.h>

#include <xcore/xcore.h>
#include <iostream>

class Plugin : public sdk::MyPlugin
{
public:
    Plugin() { };

    const std::string      GetPluginUID();
    const std::string      GetPluginGroupUID();
    const xcore::AssetInfo GetPluginInfo();
    const xcore::Semver    GetPluginVersion();
    const xcore::Semver    GetPluginHostVersion();

    void Dispose();

    const void DisplayHelloWorldFromMyPlugin();
};

XCORE_EXPORT_PLUGIN(Plugin);