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
 * @brief Contains a set of resources for work with shared library.
 */

#pragma once

#include "common.h"
#include "stl.h"

namespace xcore { namespace dll {
    /**
     * @brief Load a shared library at runtime.
     *
     * @details Load a shared library at runtime in a cross platform manner.
     *
     * @param[in] path A path to the shared library to be loaded.
     *
     * @return An handle to the loaded shared library. If the function fails, the return value is `NULL`.
     */
    XCORE_API XCORE_DLL_HANDLER load(const xcore::stl::string& path);

    /**
     * @brief Unload a shared library at runtime.
     *
     * @param[in] handler A shared library handler.
     *
     * @return true if success, otherwise false.
     */
    XCORE_API bool unload(XCORE_DLL_HANDLER& handler);

    /**
     * @brief Get a symbol pointer from the loaded shared library.
     *
     * @param[in] handler A shared library handler.
     * @param[in] symbolName A symbol name exported from the shared library (variable or function).
     *
     * @return A symbol pointer from the shared library. If the function fails, the return value is `NULL`.
     */
    XCORE_API XCORE_DLL_SYMBOL_POINTER get_symbol_pointer(XCORE_DLL_HANDLER         handler,
                                                          const xcore::stl::string& symbolName);
}}
