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
 * @brief Contains the STL implementation currently in use by the system.
 *
 */

#pragma once

#include "common.h"

#if !defined(XCORE_STL_IMPLEMENTATION)
    #error The XCORE_STL_IMPLEMENTATION was not defined.
#endif

#if defined(DOXYGEN)
    #include "stl_std.h"
    #include "stl_ea.h"
#elif XCORE_STL_IMPLEMENTATION == XCORE_STL
    #include "stl_std.h"
#elif XCORE_STL_IMPLEMENTATION == XCORE_EASTL
    #include "stl_ea.h"
#else
    #error The value of XCORE_STL_IMPLEMENTATION is inválid.
#endif