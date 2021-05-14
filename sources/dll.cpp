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

#include "xcore/dll.h"

XCORE_DLL_HANDLER xcore::dll::load(const xcore::stl::string& path)
{
    XCORE_DLL_HANDLER handler = xcore::common::platform::load_dll(xcore::stl::to_std_string(path));
    return handler;
}

bool xcore::dll::unload(XCORE_DLL_HANDLER& handler)
{
    bool status = xcore::common::platform::unload_dll(handler);
    return status;
}

XCORE_DLL_SYMBOL_POINTER xcore::dll::get_symbol_pointer(XCORE_DLL_HANDLER         handler,
                                                        const xcore::stl::string& symbolName)
{
    XCORE_DLL_SYMBOL_POINTER symbolPointer = xcore::common::platform::get_symbol_pointer_from_dll(
        handler, xcore::stl::to_std_string(symbolName));
    return symbolPointer;
}
