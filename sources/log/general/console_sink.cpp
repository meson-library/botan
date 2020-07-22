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

#include "xcore/log/general/console_sink.h"

#include "internal.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

xcore::log::general::ConsoleSink::ConsoleSink()
{
	m_Sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
}

inline void xcore::log::general::ConsoleSink::SetLevel(xcore::log::general::Level level)
{
	auto logSink = std::static_pointer_cast<spdlog::sinks::sink>(m_Sink);
	logSink->set_level(convert_level(level));
}

inline void xcore::log::general::ConsoleSink::Flush()
{
	auto logSink = std::static_pointer_cast<spdlog::sinks::sink>(m_Sink);
	logSink->flush();
}
