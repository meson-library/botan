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

#include "xcore/log/general/logger.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/dist_sink.h>

#include <algorithm>

#include "internal.h"



struct xcore::log::general::Logger::Impl
{
	std::vector<std::shared_ptr<xcore::log::general::Sinkable>> Sinks;
	std::shared_ptr<spdlog::sinks::dist_sink_mt> SinkRoot;

	std::shared_ptr<spdlog::logger> Logger;
};



xcore::log::general::Logger::Logger(const std::string& name) :
	xcore::log::general::Logger::Logger(name, xcore::log::general::Level::Trace)
{
	/* Do Nothing! */
}

xcore::log::general::Logger::Logger(const std::string& name, xcore::log::general::Level level) :
	xcore::log::general::Logger::Logger(name, level, {})
{
	/* Do Nothing! */
}

xcore::log::general::Logger::Logger(const std::string& name, std::vector<std::shared_ptr<xcore::log::general::Sinkable>> sinks) :
	xcore::log::general::Logger::Logger(name, xcore::log::general::Level::Trace, std::move(sinks))
{
	/* Do Nothing! */
}

xcore::log::general::Logger::Logger(const std::string& name, xcore::log::general::Level level, std::vector<std::shared_ptr<xcore::log::general::Sinkable>> sinks) :
	m_Impl { std::make_unique<Impl>() }
{
	m_Impl->SinkRoot = std::make_shared<spdlog::sinks::dist_sink_mt>();

	m_Impl->Sinks = sinks;
	for(auto& sink : m_Impl->Sinks)
	{
		m_Impl->SinkRoot->add_sink(std::static_pointer_cast<spdlog::sinks::sink>(sink->GetData()));
	}

	m_Impl->Logger = std::make_shared<spdlog::logger>(name, m_Impl->SinkRoot);
	SetLevel(level);
}

const std::string& xcore::log::general::Logger::GetName()
{
	return m_Impl->Logger->name();
}

xcore::log::general::Level xcore::log::general::Logger::GetLevel()
{
	return convert_level(m_Impl->Logger->level());
}

void xcore::log::general::Logger::SetLevel(xcore::log::general::Level level)
{
	m_Impl->Logger->set_level(convert_level(level));
}

void xcore::log::general::Logger::AddSink(std::shared_ptr<xcore::log::general::Sinkable> sink)
{
	auto iterator = std::find_if(m_Impl->Sinks.begin(), m_Impl->Sinks.end(), [&] (const auto& item) { return item->GetName() == sink->GetName(); });
	if(iterator == m_Impl->Sinks.end())
	{
		m_Impl->SinkRoot->add_sink(std::static_pointer_cast<spdlog::sinks::sink>(sink->GetData()));
		m_Impl->Sinks.push_back(sink);
	}
}

void xcore::log::general::Logger::RemoveSink(const std::string& name)
{
	auto iterator = std::find_if(m_Impl->Sinks.begin(), m_Impl->Sinks.end(), [&] (const auto& item) { return item->GetName() == name; });
	if(iterator != m_Impl->Sinks.end())
	{
		m_Impl->SinkRoot->remove_sink(std::static_pointer_cast<spdlog::sinks::sink>((*iterator)->GetData()));
		m_Impl->Sinks.erase(iterator);
	}
}

void xcore::log::general::Logger::Log(xcore::log::general::Level level, const std::string& msg)
{
	m_Impl->Logger->log(convert_level(level), msg);
}

void xcore::log::general::Logger::Dispose()
{
	/* Do Nothing! */
}
