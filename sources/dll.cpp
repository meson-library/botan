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

#include "corelib/dll.h"

#if defined(CORELIB_OS_FAMILY_UNIX)
    #include <dlfcn.h>
#endif

CORELIB_DLL_HANDLER corelib::dll::load(const std::string& path)
{
#if defined(CORELIB_COMPILER_MSVC)
    CORELIB_DLL_HANDLER handler = LoadLibraryA(path.c_str());
#else
    CORELIB_DLL_HANDLER handler = dlopen(path.c_str(), RTLD_LAZY);
#endif

    return handler;
}

bool corelib::dll::unload(CORELIB_DLL_HANDLER handler)
{
#if defined(CORELIB_COMPILER_MSVC)
    if (FreeLibrary(handler) == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
#else
    if (dlclose(handler) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
#endif
}

CORELIB_DLL_SYMBOL_POINTER corelib::dll::get_symbol_pointer(CORELIB_DLL_HANDLER handler, const std::string& symbolName)
{
#if defined(CORELIB_COMPILER_MSVC)
    CORELIB_DLL_SYMBOL_POINTER symbolPointer = GetProcAddress(handler, symbolName.c_str());
#else
    CORELIB_DLL_SYMBOL_POINTER symbolPointer = dlsym(handler, symbolName.c_str());
#endif 

    return symbolPointer;
}