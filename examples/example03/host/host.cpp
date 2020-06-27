// +---------------------------------------------------------------------------
// |
// |   CoreLib GPL Source Code
// |   Copyright (c) 2020 XNerv Ltda (http://xnerv.com). All rights reserved.
// |
// |   This file is part of the CoreLib GPL Source Code.
// |
// |   CoreLib Source Code is free software: you can redistribute it and/or
// |   modify it under the terms of the GNU General Public License
// |   as published by the Free Software Foundation, either version 3
// |   of the License, or (at your option) any later version.
// |
// |   CoreLib Source Code is distributed in the hope that it will be useful,
// |   but WITHOUT ANY WARRANTY; without even the implied warranty of
// |   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// |   GNU General Public License for more details.
// |
// |   You should have received a copy of the GNU General Public License
// |   along with CoreLib Source Code. If not, see <http://www.gnu.org/licenses/>.
// |
// +---------------------------------------------------------------------------

#include <corelib/corelib.h>
#include <iostream>

int main() 
{
	std::string pluginPath = "example03_plugin.dll";
	CORELIB_DLL_HANDLER dll_handler = corelib::dll::load(pluginPath);
	corelib::Plugable* plugin = CORELIB_START_PLUGIN(dll_handler);

	std::string pluginUID = plugin->GetPluginUID();
	std::string pluginGroupUID = plugin->GetPluginGroupUID();
	corelib::Semver pluginVersion = plugin->GetPluginVersion();
	corelib::Semver pluginHostVersion = plugin->GetPluginHostVersion();
	corelib::AssetInfo pluginInfo = plugin->GetPluginInfo();

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

	std::cout << std::endl;
	CORELIB_STOP_PLUGIN(dll_handler);
	std::cout << std::endl;
}