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

/**
 * @file
 *
 * @brief Contains an interface for plugable libraries.
 */

#pragma once

#include "../Common.h"
#include "../DLL.h"

namespace XCore { namespace Plugin {
    /**
     * @class Plugable Plugable.h <XCore/Plugin/Plugable.h>
     *
     * @brief An interface to plugable libraries, so we can have a native plugin system.
     */
    class Plugable : public XCore::Common::Types::Disposable
    {
    public:
        Plugable() {};
        virtual ~Plugable() {};

        virtual const XCore::Common::Types::Guid      GetPluginUID()         = 0;
        virtual const XCore::Common::Types::Guid      GetPluginGroupUID()    = 0;
        virtual const XCore::Common::Types::AssetInfo GetPluginInfo()        = 0;
        virtual const XCore::Common::Types::SemVer    GetPluginVersion()     = 0;
        virtual const XCore::Common::Types::SemVer    GetPluginHostVersion() = 0;
    };
}}


/**
 * @brief We must pass a class name (From a class that inherits from `XCore::Plugin::Plugable`) to
 * this macro and it will generate a boilerplate code for the plugin export, startup, stop and
 * verification actions.
 *
 * @param[in] pluginClassName The plugin class name.
 */
#define XCORE_EXPORT_PLUGIN(pluginClassName)                                                       \
    pluginClassName* pluginInstance = nullptr;                                                     \
                                                                                                   \
    XCORE_EXTERN_C_BEGIN                                                                           \
    XCORE_API XCore::Plugin::Plugable* xcore_start_plugin()                                        \
    {                                                                                              \
        if (pluginInstance == nullptr)                                                             \
        {                                                                                          \
            pluginInstance = new pluginClassName();                                                \
        }                                                                                          \
        return pluginInstance;                                                                     \
    };                                                                                             \
                                                                                                   \
    XCORE_API void xcore_stop_plugin(void)                                                         \
    {                                                                                              \
        if (pluginInstance != nullptr)                                                             \
        {                                                                                          \
            pluginInstance->Dispose();                                                             \
            delete pluginInstance;                                                                 \
            pluginInstance = nullptr;                                                              \
        }                                                                                          \
    };                                                                                             \
                                                                                                   \
    XCORE_API bool xcore_is_plugin_stopped(void)                                                   \
    {                                                                                              \
        return pluginInstance == nullptr;                                                          \
    };                                                                                             \
                                                                                                   \
    XCORE_API bool xcore_is_plugin_started(void)                                                   \
    {                                                                                              \
        return !xcore_is_plugin_stopped();                                                         \
    };                                                                                             \
    XCORE_EXTERN_C_END


typedef XCore::Plugin::Plugable* (*xcore_start_plugin_function_pointer)(void);
typedef void (*xcore_stop_plugin_function_pointer)(void);
typedef bool (*xcore_is_plugin_started_function_pointer)(void);
typedef bool (*xcore_is_plugin_stopped_function_pointer)(void);


/**
 * @brief We can pass a plugin handler (Obteined by `XCore::DLL::Load(...)`) to this macro and it
 * will startup and return a pointer to the plugin.
 *
 * @param[in] handler A dll handler to the plugin.
 *
 * @return A pointer to the plugin.
 *
 * @exception std::runtime_error The provided handler is not a plugin.
 *
 * @todo `xcore_start_plugin` (inside this macro) should not be throwable?
 */
#define XCORE_START_PLUGIN(handler)                                                                \
    ([&](void) {                                                                                   \
        auto xcore_symbol_pointer = XCore::DLL::GetSymbolPointer(handler, "xcore_start_plugin");   \
        if (xcore_symbol_pointer != nullptr)                                                       \
        {                                                                                          \
            return ((xcore_start_plugin_function_pointer)(xcore_symbol_pointer))();                \
        }                                                                                          \
        else                                                                                       \
        {                                                                                          \
            throw std::runtime_error(                                                              \
                "The plugin can not be started. Provided handler is not from a plugin.");          \
        }                                                                                          \
    })()

/**
 * @brief We can pass a plugin handler (Obteined by `XCore::DLL::Load(...)`) to this macro and it
 * will stop the plugin.
 *
 * @param[in] handler A dll handler to the plugin.
 *
 * @exception std::runtime_error The provided handler is not a plugin.
 *
 * @todo `xcore_stop_plugin` (inside this macro) should not be throwable?
 */
#define XCORE_STOP_PLUGIN(handler)                                                                 \
    ([&](void) {                                                                                   \
        auto xcore_symbol_pointer = XCore::DLL::GetSymbolPointer(handler, "xcore_stop_plugin");    \
        if (xcore_symbol_pointer != nullptr)                                                       \
        {                                                                                          \
            ((xcore_stop_plugin_function_pointer)(xcore_symbol_pointer))();                        \
        }                                                                                          \
        else                                                                                       \
        {                                                                                          \
            throw std::runtime_error(                                                              \
                "The plugin can not be stopped. Provided handler is not from a plugin.");          \
        }                                                                                          \
    })()

/**
 * @brief We can pass a plugin handler (Obteined by `XCore::DLL::Load(...)`) to this macro and it
 * will check if the plugin is started or not.
 *
 * @param[in] handler A dll handler to the plugin.
 *
 * @return true if the plugin is started, otherwise false.
 *
 * @todo `xcore_is_plugin_started` (inside this macro) should not be throwable?
 */
#define XCORE_IS_PLUGIN_STARTED(handler)                                                           \
    ([&](void) {                                                                                   \
        auto xcore_symbol_pointer = XCore::DLL::GetSymbolPointer(handler,                          \
                                                                 "xcore_is_plugin_started");       \
        if (xcore_symbol_pointer != nullptr)                                                       \
        {                                                                                          \
            return ((xcore_is_plugin_started_function_pointer)(xcore_symbol_pointer))();           \
        }                                                                                          \
        else                                                                                       \
        {                                                                                          \
            throw std::runtime_error(                                                              \
                "Can not check if the plugin is started. Provided handler is not from a plugin."); \
        }                                                                                          \
    })()

/**
 * @brief We can pass a plugin handler (Obteined by `XCore::DLL::Load(...)`) to this macro and it
 * will check if the plugin is stopped or not.
 *
 * @param[in] handler A dll handler to the plugin.
 *
 * @return true if the plugin is stopped, otherwise false.
 *
 * @exception std::runtime_error The provided handler is not a plugin.
 *
 * @todo `xcore_is_plugin_stopped` (inside this macro) should not be throwable?
 */
#define XCORE_IS_PLUGIN_STOPPED(handler)                                                           \
    ([&](void) {                                                                                   \
        auto xcore_symbol_pointer = XCore::DLL::GetSymbolPointer(handler,                          \
                                                                 "xcore_is_plugin_stopped");       \
        if (xcore_symbol_pointer != nullptr)                                                       \
        {                                                                                          \
            return ((xcore_is_plugin_stopped_function_pointer)(xcore_symbol_pointer))();           \
        }                                                                                          \
        else                                                                                       \
        {                                                                                          \
            throw std::runtime_error("Can not check if the plugin is stopped. Provided "           \
                                     "handler is not from a plugin.");                             \
        }                                                                                          \
    })()
