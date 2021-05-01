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

#include "XCore/Common/support/platform/linux.h"

#if defined(XCORE_OS_FAMILY_LINUX)

#    include <dlfcn.h>
#    include <uuid/uuid.h>

XCORE_DLL_HANDLER xcore::platform::load_dll(const xcore::stl::string& path)
{
    XCORE_DLL_HANDLER handler = dlopen(path.c_str(), RTLD_LAZY);
    return handler;
}

bool xcore::platform::unload_dll(XCORE_DLL_HANDLER handler)
{
    if (dlclose(handler) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

XCORE_DLL_SYMBOL_POINTER xcore::platform::get_symbol_pointer_from_dll(XCORE_DLL_HANDLER handler,
                                                                     const xcore::stl::string& symbolName)
{
    XCORE_DLL_SYMBOL_POINTER symbolPointer = dlsym(handler, symbolName.c_str());
    return symbolPointer;
}

xcore::stl::array<unsigned char, 16> xcore::platform::get_guid()
{
    uuid_t id;
    uuid_generate(id);
    return id;
}

#endif
