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
 * @brief Contains some general purpose utilities.
 */

#pragma once

#include "STL.h"

#include <memory>

namespace core { namespace utils { namespace stl {
    template<typename T>
    core::stl::shared_ptr<T> to_core_ptr(std::shared_ptr<T>& input)
    {
        return core::stl::shared_ptr<T>(input.get(), [input](T*) mutable {
            input.reset();
        });
    }

    template<typename T>
    std::shared_ptr<T> to_std_ptr(core::stl::shared_ptr<T>& input)
    {
        return std::shared_ptr<T>(input.get(), [input](T*) mutable {
            input.reset();
        });
    }

    core::stl::string to_core_string(const std::string& input);
    std::string to_std_string(const core::stl::string& input);
}}}
