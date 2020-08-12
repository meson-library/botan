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

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include "internal.h"



struct xcore::log::general::ConsoleSink::Impl
{
	std::string Name;
	std::shared_ptr<void> Data;
};



xcore::log::general::ConsoleSink::ConsoleSink(const std::string& name) :
	m_Impl {std::make_unique<Impl>()}
{
	m_Impl->Name = name;
	m_Impl->Data = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
}

const std::string& xcore::log::general::ConsoleSink::GetName()
{
	return m_Impl->Name;
}

xcore::log::general::Level xcore::log::general::ConsoleSink::GetLevel()
{
	auto sink = std::static_pointer_cast<spdlog::sinks::stdout_color_sink_mt>(m_Impl->Data);
	return convert_level(sink->level());
}

void xcore::log::general::ConsoleSink::SetLevel(xcore::log::general::Level level)
{
	auto sink = std::static_pointer_cast<spdlog::sinks::stdout_color_sink_mt>(m_Impl->Data);
	sink->set_level(convert_level(level));
}

std::shared_ptr<void> xcore::log::general::ConsoleSink::GetData()
{
	return m_Impl->Data;
}

void xcore::log::general::ConsoleSink::Flush()
{
	auto sink = std::static_pointer_cast<spdlog::sinks::stdout_color_sink_mt>(m_Impl->Data);
	sink->flush();
}
