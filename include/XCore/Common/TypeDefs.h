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
 * @brief Contains common type definitions.
 *
 * @details This file contains a common set of type definitions.
 */

#if defined(XCORE_COMPILER_MSVC) || defined(DOXYGEN)
    #include <windows.h>

    /**
     * @brief A handle to manage a dynamic shared library.
     *
     * @details On MSVC this macro expands to #HMODULE and
     *          on GCC expands to `void*`.
     */
    typedef HMODULE XCORE_DLL_HANDLER;

    /**
     * @brief A pointer to a symbol inside a shared library.
     *
     * @details On MSVC this macro expands to #FARPROC and
     *          on GCC expands to `void*`.
     */
    typedef FARPROC XCORE_DLL_SYMBOL_POINTER;
#else
    typedef void* XCORE_DLL_HANDLER;
    typedef void* XCORE_DLL_SYMBOL_POINTER;
#endif
