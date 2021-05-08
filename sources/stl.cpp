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

#include "xcore/stl.h"

xcore::stl::string xcore::stl::to_xcore_string(const std::string& input)
{
    return xcore::stl::string(input.c_str());
}

std::string xcore::stl::to_std_string(const xcore::stl::string& input)
{
    return std::string(input.c_str());
}


/**
 *
 * EASTL requires some overloads for the operator new[].
 * Our implementation just forwards to the global new[].
 *
 * Important! This is only needed when build as static
 * library.
 *
 * More information can be found in the following url
 * https://github.com/electronicarts/EASTL/issues/258
 *
 */
#if defined(XCORE_BUILD_STATIC_LIBRARY)
void* XCORE_CDECL operator new[](
    size_t size, const char* name, int flags, unsigned debugFlags, const char* file, int line)
{
    return new uint8_t[size];
}

void* XCORE_CDECL operator new[](size_t      size,
                                 size_t      alignment,
                                 size_t      alignmentOffset,
                                 const char* name,
                                 int         flags,
                                 unsigned    debugFlags,
                                 const char* file,
                                 int         line)
{
    return new uint8_t[size];
}
#endif
