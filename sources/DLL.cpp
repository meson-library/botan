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

#include "XCore/DLL.h"

XCORE_DLL_HANDLER XCore::DLL::Load(const core::stl::string& path)
{
    XCORE_DLL_HANDLER handler = core::platform::load_dll(path);
    return handler;
}

bool XCore::DLL::Unload(XCORE_DLL_HANDLER& handler)
{
    bool status = core::platform::unload_dll(handler);
    return status;
}

XCORE_DLL_SYMBOL_POINTER XCore::DLL::GetSymbolPointer(XCORE_DLL_HANDLER        handler,
                                                      const core::stl::string& symbolName)
{
    XCORE_DLL_SYMBOL_POINTER symbolPointer = core::platform::get_symbol_pointer_from_dll(handler,
                                                                                         symbolName);
    return symbolPointer;
}
