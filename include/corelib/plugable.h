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

#pragma once

#include "dll.h"
#include "disposable.h"
#include "asset_info.h"
#include "semver.h"

#include <string>

namespace corelib 
{
    class Plugable: public corelib::Disposable
    {
    public:
        Plugable() {};
        virtual ~Plugable() {};

        virtual const std::string        GetPluginUID() = 0;
        virtual const std::string        GetPluginGroupUID() = 0;
        virtual const corelib::AssetInfo GetPluginInfo() = 0;
        virtual const corelib::Semver    GetPluginVersion() = 0;
        virtual const corelib::Semver    GetPluginHostVersion() = 0;
    };
}

#define CORELIB_EXPORT_PLUGIN(PluginClassName) \
PluginClassName* pluginInstance = NULL; \
\
extern "C" CORELIB_API corelib::Plugable * corelib_start_plugin() \
{ \
    if(pluginInstance == NULL) \
    { \
        pluginInstance = new PluginClassName(); \
    } \
    return pluginInstance; \
}; \
\
extern "C" CORELIB_API void corelib_stop_plugin(void) \
{ \
    if(pluginInstance != NULL) \
    { \
        pluginInstance->Dispose(); \
        delete pluginInstance; \
        pluginInstance = NULL; \
    } \
}

typedef corelib::Plugable* (*corelib_start_plugin_function_pointer) (void);
typedef void (*corelib_stop_plugin_function_pointer) (void);

#define CORELIB_START_PLUGIN(handler) ((corelib_start_plugin_function_pointer) corelib::dll::get_symbol_pointer(handler, "corelib_start_plugin"))()
#define CORELIB_STOP_PLUGIN(handler) ((corelib_stop_plugin_function_pointer) corelib::dll::get_symbol_pointer(handler, "corelib_stop_plugin"))()