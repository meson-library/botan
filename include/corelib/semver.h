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
     * @brief      Struct to hold version info in the <a href="http://semver.org/spec/v2.0.0.html" 
     *             target="_blank">Semantic version standard</a>.
     *
     * @todo Validate the construction of instances of this struct with the
     * standard found at <a href="http://semver.org/spec/v2.0.0.html"
     * target="_blank">http://semver.org/spec/v2.0.0.html</a>. Right now, the
     * version info is stored without any validation.
     */
    typedef struct Semver
    {
        Semver
        (
            int major, int minor=0, int path=0, std::string label=""
        ):
        Major(major), Minor(minor), Path(path), Label(label) { };

        int	        Major;
        int	        Minor;
        int	        Path;
        std::string Label;
    }
    Semver;
}