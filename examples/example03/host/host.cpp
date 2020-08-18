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

#include <XCore/XCore.h>
#include <iostream>

int main()
{
    XCore::STL::string pluginPath = "Example03Plugin.dll";
    XCORE_DLL_HANDLER dllHandler = XCore::DLL::Load(pluginPath);
    XCore::Plugin::Plugable* plugin = XCORE_START_PLUGIN(dllHandler);

    XCore::STL::string pluginUID = plugin->GetPluginUID();
    XCore::STL::string pluginGroupUID = plugin->GetPluginGroupUID();
    XCore::Common::SemVer pluginVersion = plugin->GetPluginVersion();
    XCore::Common::SemVer pluginHostVersion = plugin->GetPluginHostVersion();
    XCore::Common::AssetInfo pluginInfo = plugin->GetPluginInfo();

    std::cout << std::endl;
    std::cout << " ------------------------------------------------------------" << std::endl;
    std::cout << "| Loaded plugin : " + std::string(pluginPath.c_str()) << std::endl;
    std::cout << "|------------------------------------------------------------" << std::endl;
    std::cout << "| Plugin UID           : " + std::string(pluginUID.c_str()) << std::endl;
    std::cout << "| Plugin Group UID     : " + std::string(pluginGroupUID.c_str()) << std::endl;
    std::cout << "| Plugin Version       : " + std::to_string(pluginVersion.Major) + "."
                     + std::to_string(pluginVersion.Minor) + "." + std::to_string(pluginVersion.Path)
                     + "." + std::string(pluginVersion.Label.c_str())
              << std::endl;
    std::cout << "| Plugin Host Version  : " + std::to_string(pluginHostVersion.Major) + "."
                     + std::to_string(pluginHostVersion.Minor) + "."
                     + std::to_string(pluginHostVersion.Path) + "."
                     + std::string(pluginHostVersion.Label.c_str())
              << std::endl;
    std::cout << "|------------------------------------------------------------" << std::endl;
    std::cout << "| Plugin Name           : " + std::string(pluginInfo.Name.c_str()) << std::endl;
    std::cout << "| Plugin Author         : " + std::string(pluginInfo.Author.c_str()) << std::endl;
    std::cout << "| Plugin License        : " + std::string(pluginInfo.License.c_str()) << std::endl;
    std::cout << "| Plugin Description    : " + std::string(pluginInfo.Description.c_str())
              << std::endl;
    std::cout << "|------------------------------------------------------------" << std::endl;

    std::cout << std::endl;
    XCORE_STOP_PLUGIN(dllHandler);
    std::cout << std::endl;
}
