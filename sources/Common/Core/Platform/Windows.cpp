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

#include "XCore/Common/Core/Platform/Windows.h"

#if defined(XCORE_OS_FAMILY_WINDOWS)

XCORE_DLL_HANDLER core::platform::load_dll(const core::stl::string& path)
{
    XCORE_DLL_HANDLER handler = LoadLibraryA(path.c_str());
    return handler;
}

bool core::platform::unload_dll(XCORE_DLL_HANDLER handler)
{
    if (FreeLibrary(handler) == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

XCORE_DLL_SYMBOL_POINTER core::platform::get_symbol_pointer_from_dll(XCORE_DLL_HANDLER handler,
                                                                     const core::stl::string& symbolName)
{
    XCORE_DLL_SYMBOL_POINTER symbolPointer = GetProcAddress(handler, symbolName.c_str());
    return symbolPointer;
}

#endif
