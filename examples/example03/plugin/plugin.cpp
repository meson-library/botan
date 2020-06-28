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

#include "plugin.h"

const std::string Plugin::GetPluginUID()
{
    return "79896acc-8e99-481d-bc3e-5a7e150ddd71";
}

const std::string Plugin::GetPluginGroupUID()
{
    return "a7b048fe-179d-459b-86c3-28a1c644b931";
}

const xcore::AssetInfo Plugin::GetPluginInfo()
{
    return xcore::AssetInfo("Plugin Demo", "XNerv", "GPL3", "A demo plugin.");
}

const xcore::Semver Plugin::GetPluginVersion()
{
    return xcore::Semver(1, 2, 3, "z");
}

const xcore::Semver Plugin::GetPluginHostVersion()
{
    return xcore::Semver(1, 2, 3, "build.1");
}

void Plugin::Dispose()
{
    std::cout << "Dispose Plugin (Clean Resources).";
}
