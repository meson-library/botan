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

#pragma once

#include "internal.h"

spdlog::level::level_enum xcore::log::convert_level(xcore::log::Level level)
{
    spdlog::level::level_enum nativeLevel = spdlog::level::level_enum::off;

    switch (level)
    {
    case xcore::log::Level::None:
        nativeLevel = spdlog::level::level_enum::off;
        break;
    case xcore::log::Level::Fatal:
        nativeLevel = spdlog::level::level_enum::critical;
        break;
    case xcore::log::Level::Error:
        nativeLevel = spdlog::level::level_enum::err;
        break;
    case xcore::log::Level::Warning:
        nativeLevel = spdlog::level::level_enum::warn;
        break;
    case xcore::log::Level::Info:
        nativeLevel = spdlog::level::level_enum::info;
        break;
    case xcore::log::Level::Debug:
        nativeLevel = spdlog::level::level_enum::debug;
        break;
    case xcore::log::Level::Trace:
        nativeLevel = spdlog::level::level_enum::trace;
        break;
    default:
        break;
    }

    return nativeLevel;
}
