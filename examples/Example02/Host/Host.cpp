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

#include <xcore/xcore.h>

int main()
{
    typedef void (*display_helloworld_from_shared_library)(void);

    XCORE_DLL_HANDLER        dllHandler    = xcore::dll::load("example02_library.dll");
    XCORE_DLL_SYMBOL_POINTER symbolPointer = xcore::dll::get_symbol_pointer(
        dllHandler, "display_helloworld_from_shared_library");

    auto function_pointer = ((display_helloworld_from_shared_library)symbolPointer);

    function_pointer();

    xcore::dll::unload(dllHandler);
}
