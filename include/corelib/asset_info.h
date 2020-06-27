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

#pragma once

#include <string>

namespace corelib
{
    /**
     * @ingroup    corelib
     *
     * @brief      Struct to hold basic asset info.
     */
    typedef struct AssetInfo
    {
        AssetInfo
        (
            std::string name, std::string author="", std::string license="", std::string description=""
        ): 
        Name(name), Author(author), License(license), Description(description) { };

        std::string Name;
        std::string Author;
        std::string License;
        std::string Description;
    } 
    AssetInfo;
}