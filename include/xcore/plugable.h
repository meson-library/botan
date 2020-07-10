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

#include "dll.h"
#include "disposable.h"
#include "asset_info.h"
#include "semver.h"
#include "stl.h"

namespace xcore
{
    class Plugable: public xcore::Disposable
    {
    public:
        Plugable() {};
        virtual ~Plugable() {};

        virtual const xcore::stl::string GetPluginUID() = 0;
        virtual const xcore::stl::string GetPluginGroupUID() = 0;
        virtual const xcore::AssetInfo   GetPluginInfo() = 0;
        virtual const xcore::Semver      GetPluginVersion() = 0;
        virtual const xcore::Semver      GetPluginHostVersion() = 0;
    };
}

#define XCORE_EXPORT_PLUGIN(PluginClassName) \
    PluginClassName* pluginInstance = NULL; \
    \
    XCORE_EXTERN_C_BEGIN \
        XCORE_API xcore::Plugable * xcore_start_plugin() \
        { \
            if(pluginInstance == NULL) \
            { \
                pluginInstance = new PluginClassName(); \
            } \
            return pluginInstance; \
        }; \
        \
        XCORE_API void xcore_stop_plugin(void) \
        { \
            if(pluginInstance != NULL) \
            { \
                pluginInstance->Dispose(); \
                delete pluginInstance; \
                pluginInstance = NULL; \
            } \
        } \
    XCORE_EXTERN_C_END

typedef xcore::Plugable* (*xcore_start_plugin_function_pointer) (void);
typedef void (*xcore_stop_plugin_function_pointer) (void);

#define XCORE_START_PLUGIN(handler) ((xcore_start_plugin_function_pointer) xcore::dll::get_symbol_pointer(handler, "xcore_start_plugin"))()
#define XCORE_STOP_PLUGIN(handler) ((xcore_stop_plugin_function_pointer) xcore::dll::get_symbol_pointer(handler, "xcore_stop_plugin"))()