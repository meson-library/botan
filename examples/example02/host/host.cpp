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

#include <corelib/corelib.h>

int main() 
{
    typedef void (*display_helloworld_from_shared_library) (void);

    CORELIB_DLL_HANDLER dll_handler = corelib::dll::load("example02_library.dll");
    CORELIB_DLL_SYMBOL_POINTER symbol_pointer = corelib::dll::get_symbol_pointer(dll_handler, "display_helloworld_from_shared_library");

    auto function_pointer = ((display_helloworld_from_shared_library)symbol_pointer);

    function_pointer();

    corelib::dll::unload(dll_handler);
}