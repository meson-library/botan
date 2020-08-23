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

/**
 * @file
 *
 * @brief Contains code about a struct to hold asset info.
 */

#pragma once

#include "../Core.h"

namespace XCore { namespace Common { namespace Types {
    /**
     * @struct AssetInfo AssetInfo.h <XCore/Common/AssetInfo.h>
     *
     * @brief Struct to hold basic asset info.
     */
    struct AssetInfo
    {
        AssetInfo(core::stl::string name,
                  core::stl::string author      = "",
                  core::stl::string license     = "",
                  core::stl::string description = "")
            : Name(name), Author(author), License(license), Description(description) {};

        core::stl::string Name;
        core::stl::string Author;
        core::stl::string License;
        core::stl::string Description;
    };

    typedef struct AssetInfo AssetInfo;
}}}
