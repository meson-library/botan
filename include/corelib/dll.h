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

#include "common.h"

#include <string>

/**  
 * @defgroup 	corelib_dll dll
 * 
 * @ingroup  	corelib_dll
 */ 
namespace corelib { namespace dll
{
    /**
     * @ingroup    corelib_dll
     *
     * @brief      Load a shared library at runtime.
     *
     * @details    Load a shared library at runtime in a cross platform manner.
     *
     * @param[in]  path  A path to the shared library to be loaded.
     *
     * @return     An handle to the loaded shared library. If the function
     *             fails, the return value is NULL.
     *
     * @note       This function return a DLL_HANDLER that in Windows is of type
     *             [HMODULE](https://msdn.microsoft.com/en-us/library/windows/desktop/aa383751(v=vs.85).aspx)
     *             and in *nix is of type <b>void *</b>
     */
    CORELIB_DLL_HANDLER load(const std::string& path);

    /**
     * @ingroup    corelib_dll
     *
     * @brief      Unload a shared library at runtime.
     *
     * @param[in]  handler  A shared library handler.
     *
     * @return     true if success, otherwise false.
     */
    bool unload(CORELIB_DLL_HANDLER handler);

    /**
     * @ingroup    corelib_dll
     *
     * @brief      Get a symbol pointer from the loaded shared library.
     *
     * @param[in]  handler     A shared library handler.
     * @param[in]  symbolName  A symbol name (Exported variable or function).
     *
     * @return     A symbol pointer from a shared library. If the function fails, the return value is NULL.
     *
     * @note       This function return a DLL_SYMBOL_POINTER that in Windows
     *             is of type
     *             [FARPROC](https://msdn.microsoft.com/en-us/library/windows/desktop/ms633571(v=vs.85).aspx)
     *             and in *nix is of type <b>void *</b>
     */
    CORELIB_DLL_SYMBOL_POINTER get_symbol_pointer(CORELIB_DLL_HANDLER handler, const std::string& symbolName);
}}