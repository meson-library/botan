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

/**
 * @file
 *
 * @brief Contains specific code for Windows platform.
 */

#pragma once

#include "../STL.h"

#include <windows.h>

/**
 * @brief A handle to a shared library.
 *
 * @details On MSVC this macro expands to `HMODULE`.
 */
typedef HMODULE XCORE_DLL_HANDLER;

/**
 * @brief A pointer to a symbol inside a shared library.
 *
 * @details On MSVC this macro expands to `FARPROC`.
 */
typedef FARPROC XCORE_DLL_SYMBOL_POINTER;


namespace core { namespace platform {
    /**
     * @brief Load a shared library at runtime.
     *
     * @param[in] path A path to the shared library to be loaded.
     *
     * @return A shared library handler as `XCORE_DLL_HANDLER`.
     *
     * @note This function return a `XCORE_DLL_HANDLER` that in Windows is of type
     * [HMODULE](https://msdn.microsoft.com/en-us/library/windows/desktop/aa383751(v=vs.85).aspx).
     */
    XCORE_DLL_HANDLER load_dll(const core::stl::string& path);

    /**
     * @brief Unload a shared library at runtime.
     *
     * @param[in] handler A shared library handler.
     *
     * @return true if success, otherwise false.
     */
    bool unload_dll(XCORE_DLL_HANDLER& handler);

    /**
     * @brief Get a symbol pointer from the loaded shared library.
     *
     * @param[in] handler A shared library handler.
     *
     * @param[in] symbolName A symbol name exported from the shared library (variable or function).
     *
     * @return A symbol pointer from the shared library as `XCORE_DLL_SYMBOL_POINTER`. If the call
     * fails, the return value is `NULL`.
     *
     * @note This function return a `XCORE_DLL_SYMBOL_POINTER` that in Windows is of type
     * [FARPROC](https://msdn.microsoft.com/en-us/library/windows/desktop/ms633571(v=vs.85).aspx).
     */
    XCORE_DLL_SYMBOL_POINTER get_symbol_pointer_from_dll(XCORE_DLL_HANDLER        handler,
                                                         const core::stl::string& symbolName);

    /**
     * @brief Get a new guid as byte array. The returned guid is variant 1 of Version 4 (random).
     *
     * @return core::stl::array<unsigned char, 16>
     */
    core::stl::array<unsigned char, 16> get_guid();
}}
