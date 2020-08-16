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

#include "XCore/Log/Logger.h"
#include "Internal.h"

#include <spdlog/sinks/dist_sink.h>
#include <spdlog/spdlog.h>

#include <algorithm>
#include <shared_mutex>



struct XCore::Log::Logger::Impl
{
	std::unordered_map<std::string, std::shared_ptr<XCore::Log::Sinkable>> Sinks;
	std::shared_ptr<spdlog::sinks::dist_sink_mt> SinkRoot;
	std::shared_ptr<spdlog::logger> Logger;
	std::shared_mutex Mutex;
};



XCore::Log::Logger::Logger(const std::string& name) :
	XCore::Log::Logger::Logger(name, XCore::Log::Level::Trace)
{
	/* Do Nothing! */
}

XCore::Log::Logger::Logger(const std::string& name, XCore::Log::Level level) :
	XCore::Log::Logger::Logger(name, level, std::vector<std::shared_ptr<XCore::Log::Sinkable>>{})
{
	/* Do Nothing! */
}

XCore::Log::Logger::Logger(const std::string& name, std::shared_ptr<XCore::Log::Sinkable> sink) :
	XCore::Log::Logger::Logger(name, XCore::Log::Level::Trace, std::vector<std::shared_ptr<XCore::Log::Sinkable>>{sink})
{
	/* Do Nothing! */
}

XCore::Log::Logger::Logger(const std::string& name, std::vector<std::shared_ptr<XCore::Log::Sinkable>> sinks) :
	XCore::Log::Logger::Logger(name, XCore::Log::Level::Trace, sinks)
{
	/* Do Nothing! */
}

XCore::Log::Logger::Logger(const std::string& name, XCore::Log::Level level, std::vector<std::shared_ptr<XCore::Log::Sinkable>> sinks) :
	m_Impl { std::make_unique<Impl>() }
{
	m_Impl->SinkRoot = std::make_shared<spdlog::sinks::dist_sink_mt>();

	std::for_each(sinks.begin(), sinks.end(), [&] (const auto& sink) 
	{ 
		m_Impl->Sinks.emplace(sink->GetName(), sink); 
	});

	for (auto& sink : m_Impl->Sinks)
	{
		m_Impl->SinkRoot->add_sink(std::static_pointer_cast<spdlog::sinks::sink>(sink.second->GetData()));
	}

	m_Impl->Logger = std::make_shared<spdlog::logger>(name, m_Impl->SinkRoot);
	SetLevel(level);
}

const std::string& XCore::Log::Logger::GetName()
{
	return m_Impl->Logger->name();
}

XCore::Log::Level XCore::Log::Logger::GetLevel()
{
	std::shared_lock<std::shared_mutex> lock(m_Impl->Mutex);

	return ConvertLevel(m_Impl->Logger->level());
}

void XCore::Log::Logger::SetLevel(XCore::Log::Level level)
{
	std::unique_lock<std::shared_mutex> lock(m_Impl->Mutex);

	m_Impl->Logger->set_level(ConvertLevel(level));
}

bool XCore::Log::Logger::ContainsSink(const std::string& name)
{
    std::shared_lock<std::shared_mutex> lock(m_Impl->Mutex);

    return m_Impl->Sinks.count(name) > 0;    
}

XCore::Log::Sinkable& XCore::Log::Logger::GetSink(const std::string& name)
{
    std::shared_lock<std::shared_mutex> lock(m_Impl->Mutex);

    if (ContainsSink(name))
    {
        auto& item = m_Impl->Sinks.at(name);
        return *item;
    }
    else
    {
        throw;
    }
}

void XCore::Log::Logger::AddSink(std::shared_ptr<XCore::Log::Sinkable> sink)
{
	std::unique_lock<std::shared_mutex> lock(m_Impl->Mutex);

	auto result = m_Impl->Sinks.emplace(sink->GetName(), sink);
    if(result.second == true)
    {
        m_Impl->SinkRoot->add_sink(std::static_pointer_cast<spdlog::sinks::sink>(sink->GetData()));
    }
	else
    {
        throw;
    }
}

void XCore::Log::Logger::RemoveSink(const std::string& name)
{
	std::unique_lock<std::shared_mutex> lock(m_Impl->Mutex);

	if(m_Impl->Sinks.count(name) > 0)
	{
		auto& sink = m_Impl->Sinks.at(name);
		m_Impl->SinkRoot->remove_sink(std::static_pointer_cast<spdlog::sinks::sink>(sink->GetData()));

		m_Impl->Sinks.erase(name);
	}
	else
    {
        throw;
    }
}

void XCore::Log::Logger::Log(XCore::Log::Level level, const std::string& msg)
{
	std::shared_lock<std::shared_mutex> lock(m_Impl->Mutex);
	
	m_Impl->Logger->log(ConvertLevel(level), msg);
}

void XCore::Log::Logger::Dispose()
{
	/* Do Nothing! */
}
