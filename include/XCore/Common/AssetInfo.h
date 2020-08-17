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

#include "../STL.h"

namespace XCore { namespace Common {
    /**
     * @struct AssetInfo AssetInfo.h <XCore/Common/AssetInfo.h>
     *
     * @brief Struct to hold basic asset info.
     */
    struct AssetInfo
    {
        AssetInfo(XCore::STL::string name, XCore::STL::string author = "",
                  XCore::STL::string license = "", XCore::STL::string description = "")
            : Name(name), Author(author), License(license), Description(description) {};

        XCore::STL::string Name;
        XCore::STL::string Author;
        XCore::STL::string License;
        XCore::STL::string Description;
    };

    typedef struct AssetInfo AssetInfo;
}}  // namespace XCore::Common
