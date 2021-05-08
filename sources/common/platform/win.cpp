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

#include "xcore/common/platform/win.h"

#if defined(XCORE_OS_FAMILY_WINDOWS)

#    include <objbase.h>

XCORE_DLL_HANDLER xcore::common::platform::load_dll(const std::string& path)
{
    XCORE_DLL_HANDLER handler = LoadLibraryA(path.c_str());
    return handler;
}

bool xcore::common::platform::unload_dll(XCORE_DLL_HANDLER& handler)
{
    BOOL retval = FreeLibrary(handler);
    if (retval == 0)
    {
        return false;
    }
    else
    {
        handler = nullptr;
        return true;
    }
}

XCORE_DLL_SYMBOL_POINTER xcore::common::platform::get_symbol_pointer_from_dll(
    XCORE_DLL_HANDLER handler, const std::string& symbolName)
{
    XCORE_DLL_SYMBOL_POINTER symbolPointer = GetProcAddress(handler, symbolName.c_str());
    return symbolPointer;
}

std::array<unsigned char, 16> xcore::common::platform::get_guid()
{
    GUID newId;
    CoCreateGuid(&newId);

    std::array<unsigned char, 16> bytes = {(unsigned char)((newId.Data1 >> 24) & 0xFF),
                                           (unsigned char)((newId.Data1 >> 16) & 0xFF),
                                           (unsigned char)((newId.Data1 >> 8) & 0xFF),
                                           (unsigned char)((newId.Data1) & 0xff),

                                           (unsigned char)((newId.Data2 >> 8) & 0xFF),
                                           (unsigned char)((newId.Data2) & 0xff),

                                           (unsigned char)((newId.Data3 >> 8) & 0xFF),
                                           (unsigned char)((newId.Data3) & 0xFF),

                                           (unsigned char)newId.Data4[0],
                                           (unsigned char)newId.Data4[1],
                                           (unsigned char)newId.Data4[2],
                                           (unsigned char)newId.Data4[3],
                                           (unsigned char)newId.Data4[4],
                                           (unsigned char)newId.Data4[5],
                                           (unsigned char)newId.Data4[6],
                                           (unsigned char)newId.Data4[7]};

    return bytes;
}
#endif
