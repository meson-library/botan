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

spdlog::level::level_enum XCore::Log::ConvertLevel(XCore::Log::Level level)
{
    spdlog::level::level_enum nativeLevel = spdlog::level::level_enum::off;

    switch (level)
    {
    case XCore::Log::Level::None:
        nativeLevel = spdlog::level::level_enum::off;
        break;

    case XCore::Log::Level::Critical:
        nativeLevel = spdlog::level::level_enum::critical;
        break;

    case XCore::Log::Level::Error:
        nativeLevel = spdlog::level::level_enum::err;
        break;

    case XCore::Log::Level::Warning:
        nativeLevel = spdlog::level::level_enum::warn;
        break;

    case XCore::Log::Level::Info:
        nativeLevel = spdlog::level::level_enum::info;
        break;

    case XCore::Log::Level::Debug:
        nativeLevel = spdlog::level::level_enum::debug;
        break;

    case XCore::Log::Level::Trace:
        nativeLevel = spdlog::level::level_enum::trace;
        break;

    default:
        break;
    }

    return nativeLevel;
}

XCore::Log::Level XCore::Log::ConvertLevel(spdlog::level::level_enum nativeLevel)
{
    XCore::Log::Level level = XCore::Log::Level::None;

    switch (nativeLevel)
    {
    case spdlog::level::level_enum::off:
        level = XCore::Log::Level::None;
        break;

    case spdlog::level::level_enum::critical:
        level = XCore::Log::Level::Critical;
        break;

    case spdlog::level::level_enum::err:
        level = XCore::Log::Level::Error;
        break;

    case spdlog::level::level_enum::warn:
        level = XCore::Log::Level::Warning;
        break;

    case spdlog::level::level_enum::info:
        level = XCore::Log::Level::Info;
        break;

    case spdlog::level::level_enum::debug:
        level = XCore::Log::Level::Debug;
        break;

    case spdlog::level::level_enum::trace:
        level = XCore::Log::Level::Trace;
        break;

    default:
        break;
    }

    return level;
}
