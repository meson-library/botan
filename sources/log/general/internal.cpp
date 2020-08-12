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

spdlog::level::level_enum xcore::log::general::convert_level(xcore::log::general::Level level)
{
	spdlog::level::level_enum nativeLevel = spdlog::level::level_enum::off;

	switch(level)
	{
	case xcore::log::general::Level::None:
		nativeLevel = spdlog::level::level_enum::off;
		break;

	case xcore::log::general::Level::Fatal:
		nativeLevel = spdlog::level::level_enum::critical;
		break;

	case xcore::log::general::Level::Error:
		nativeLevel = spdlog::level::level_enum::err;
		break;

	case xcore::log::general::Level::Warning:
		nativeLevel = spdlog::level::level_enum::warn;
		break;

	case xcore::log::general::Level::Info:
		nativeLevel = spdlog::level::level_enum::info;
		break;

	case xcore::log::general::Level::Debug:
		nativeLevel = spdlog::level::level_enum::debug;
		break;

	case xcore::log::general::Level::Trace:
		nativeLevel = spdlog::level::level_enum::trace;
		break;

	default:
		break;
	}

	return nativeLevel;
}

xcore::log::general::Level xcore::log::general::convert_level(spdlog::level::level_enum nativeLevel)
{
	xcore::log::general::Level level = xcore::log::general::Level::None;

	switch(nativeLevel)
	{
	case spdlog::level::level_enum::off:
		level = xcore::log::general::Level::None;
		break;

	case spdlog::level::level_enum::critical:
		level = xcore::log::general::Level::Fatal;
		break;

	case spdlog::level::level_enum::err:
		level = xcore::log::general::Level::Error;
		break;

	case spdlog::level::level_enum::warn:
		level = xcore::log::general::Level::Warning;
		break;

	case spdlog::level::level_enum::info:
		level = xcore::log::general::Level::Info;
		break;

	case spdlog::level::level_enum::debug:
		level = xcore::log::general::Level::Debug;
		break;

	case spdlog::level::level_enum::trace:
		level = xcore::log::general::Level::Trace;
		break;

	default:
		break;
	}

	return level;
}
