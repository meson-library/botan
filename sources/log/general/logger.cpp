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

#include "internal.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/dist_sink.h>

#include <unordered_map>



struct xcore::log::general::Logger::Impl
{
	std::string Name;
	xcore::log::general::Level Level;
	/*std::unordered_map<std::string, std::shared_ptr<xcore::log::general::Sink>> Sinks;*/

	std::shared_ptr<spdlog::logger> Logger;
	std::shared_ptr<spdlog::sinks::dist_sink_mt> SinkRoot;
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

xcore::log::general::Logger::Logger(const std::string& name, std::vector<std::unique_ptr<xcore::log::general::Sink>> sinks) :
	xcore::log::general::Logger::Logger(name, xcore::log::general::Level::Trace, std::move(sinks))
{
	/* Do Nothing! */
}

xcore::log::general::Logger::Logger(const std::string& name, xcore::log::general::Level level, std::vector<std::unique_ptr<xcore::log::general::Sink>> sinks) :
	m_Impl {std::make_unique<Impl>()}
{
	m_Impl->Name = name;

	m_Impl->SinkRoot = std::make_shared<spdlog::sinks::dist_sink_mt>();
	for(auto& sink : sinks)
	{
		m_Impl->SinkRoot->add_sink(std::static_pointer_cast<spdlog::sinks::sink>(sink->m_Sink));
		/*m_Impl->Sinks.insert({sink->m_Name, std::move(sink)});*/
	}

	m_Impl->Logger = std::make_shared<spdlog::logger>(m_Impl->Name, m_Impl->SinkRoot);
}

const std::string& xcore::log::general::Logger::GetName()
{
	return m_Impl->Name;
}

xcore::log::general::Level xcore::log::general::Logger::GetLevel()
{
	return m_Impl->Level;
}

void xcore::log::general::Logger::SetLevel(xcore::log::general::Level level)
{
	m_Impl->Level = level;
	m_Impl->Logger->set_level(convert_level(level));
}

void xcore::log::general::Logger::AddSink(std::unique_ptr<xcore::log::general::Sink> sink)
{
	/*m_Impl->Sinks.push_back(std::move(sink));*/
	m_Impl->SinkRoot->add_sink(std::static_pointer_cast<spdlog::sinks::sink>(sink->m_Sink));
}

void xcore::log::general::Logger::RemoveSink(const std::string& name)
{

}

void xcore::log::general::Logger::Log(xcore::log::general::Level level, const std::string& msg)
{
	m_Impl->Logger->log(convert_level(level), msg);
}

void xcore::log::general::Logger::Dispose()
{

}
