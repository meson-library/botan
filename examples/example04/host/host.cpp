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

#include "my_plugin.h"

#include <xcore/xcore.h>
#include <iostream>

int main()
{
    std::string pluginPath = "example04.plugin";
    XCORE_DLL_HANDLER dll_handler = xcore::dll::load(pluginPath);
    sdk::MyPlugin* plugin = (sdk::MyPlugin*)XCORE_START_PLUGIN(dll_handler);

    std::string pluginUID = plugin->GetPluginUID();
    std::string pluginGroupUID = plugin->GetPluginGroupUID();
    xcore::Semver pluginVersion = plugin->GetPluginVersion();
    xcore::Semver pluginHostVersion = plugin->GetPluginHostVersion();
    xcore::AssetInfo pluginInfo = plugin->GetPluginInfo();


    std::cout << std::endl;
    std::cout << " ------------------------------------------------------------" << std::endl;
    std::cout << "| Loaded plugin : " + pluginPath << std::endl;
    std::cout << "|------------------------------------------------------------" << std::endl;
    std::cout << "| Plugin UID           : " + pluginUID << std::endl;
    std::cout << "| Plugin Group UID     : " + pluginGroupUID << std::endl;
    std::cout << "| Plugin Version       : " + std::to_string(pluginVersion.Major) + "."
                                             + std::to_string(pluginVersion.Minor) + "."
                                             + std::to_string(pluginVersion.Path) + "."
                                             + pluginVersion.Label << std::endl;
    std::cout << "| Plugin Host Version  : " + std::to_string(pluginHostVersion.Major) + "."
                                             + std::to_string(pluginHostVersion.Minor) + "."
                                             + std::to_string(pluginHostVersion.Path) + "."
                                             + pluginHostVersion.Label << std::endl;
    std::cout << "|------------------------------------------------------------" << std::endl;
    std::cout << "| Plugin Name           : " + pluginInfo.Name << std::endl;
    std::cout << "| Plugin Author         : " + pluginInfo.Author << std::endl;
    std::cout << "| Plugin License        : " + pluginInfo.License << std::endl;
    std::cout << "| Plugin Description    : " + pluginInfo.Description << std::endl;
    std::cout << "|------------------------------------------------------------" << std::endl;
    std::cout << "|"; plugin->DisplayHelloWorldFromMyPlugin();
    std::cout << "|------------------------------------------------------------" << std::endl;


    std::cout << std::endl;
    XCORE_STOP_PLUGIN(dll_handler);
    std::cout << std::endl;
}