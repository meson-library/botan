// +---------------------------------------------------------------------------
// |
// |   XCore GPL Source Code
// |   Copyright (c) 2021 XNerv Ltda (http://xnerv.com). All rights reserved.
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

#include <memory>
#include <shared_mutex>
#include <spdlog/sinks/dist_sink.h>
#include <spdlog/spdlog.h>


struct XCore::Log::Logger::Impl
{
    xcore::stl::unordered_map<xcore::stl::string, xcore::stl::shared_ptr<XCore::Log::Sinkable>> Sinks;
    xcore::stl::shared_ptr<spdlog::sinks::dist_sink_mt> SinkRoot;
    xcore::stl::shared_ptr<spdlog::logger>              Logger;
    std::shared_mutex                                  Mutex;
};


XCore::Log::Logger::Logger(const xcore::stl::string& name)
    : XCore::Log::Logger::Logger(name, XCore::Log::Level::Trace)
{
    /* Do Nothing! */
}

XCore::Log::Logger::Logger(const xcore::stl::string& name, XCore::Log::Level level)
    : XCore::Log::Logger::Logger(
        name, level, xcore::stl::vector<xcore::stl::shared_ptr<XCore::Log::Sinkable>> {})
{
    /* Do Nothing! */
}

XCore::Log::Logger::Logger(const xcore::stl::string&                    name,
                           xcore::stl::shared_ptr<XCore::Log::Sinkable> sink)
    : XCore::Log::Logger::Logger(name,
                                 XCore::Log::Level::Trace,
                                 xcore::stl::vector<xcore::stl::shared_ptr<XCore::Log::Sinkable>> {sink})
{
    /* Do Nothing! */
}

XCore::Log::Logger::Logger(const xcore::stl::string&                                       name,
                           xcore::stl::vector<xcore::stl::shared_ptr<XCore::Log::Sinkable>> sinks)
    : XCore::Log::Logger::Logger(name, XCore::Log::Level::Trace, sinks)
{
    /* Do Nothing! */
}

XCore::Log::Logger::Logger(const xcore::stl::string&                                       name,
                           XCore::Log::Level                                              level,
                           xcore::stl::vector<xcore::stl::shared_ptr<XCore::Log::Sinkable>> sinks)
    : m_impl {xcore::stl::make_unique<Impl>()}
{
    m_impl->SinkRoot = xcore::stl::make_shared<spdlog::sinks::dist_sink_mt>();

    xcore::stl::for_each(sinks.begin(), sinks.end(), [&](const auto& sink) {
        m_impl->Sinks.emplace(sink->GetName(), sink);
    });

    for (auto& sink: m_impl->Sinks)
    {
        auto sink_ptr = static_cast<spdlog::sinks::sink*>(sink.second->GetData());
        m_impl->SinkRoot->add_sink(
            std::shared_ptr<spdlog::sinks::sink>(std::shared_ptr<void>(), sink_ptr));
    }

    m_impl->Logger = xcore::stl::make_shared<spdlog::logger>(
        name.c_str(), xcore::utils::stl::to_std_ptr(m_impl->SinkRoot));
    SetLevel(level);
}

xcore::stl::string XCore::Log::Logger::GetName()
{
    return m_impl->Logger->name().c_str();
}

XCore::Log::Level XCore::Log::Logger::GetLevel()
{
    std::shared_lock<std::shared_mutex> lock(m_impl->Mutex);

    return ConvertLevel(m_impl->Logger->level());
}

void XCore::Log::Logger::SetLevel(XCore::Log::Level level)
{
    std::unique_lock<std::shared_mutex> lock(m_impl->Mutex);

    m_impl->Logger->set_level(ConvertLevel(level));
}

bool XCore::Log::Logger::ContainsSink(const xcore::stl::string& name)
{
    std::shared_lock<std::shared_mutex> lock(m_impl->Mutex);

    return m_impl->Sinks.count(name) > 0;
}

XCore::Log::Sinkable& XCore::Log::Logger::GetSink(const xcore::stl::string& name)
{
    std::shared_lock<std::shared_mutex> lock(m_impl->Mutex);

    if (ContainsSink(name))
    {
        auto& item = m_impl->Sinks.at(name);
        return *item;
    }
    else
    {
        throw;
    }
}

void XCore::Log::Logger::AddSink(xcore::stl::shared_ptr<XCore::Log::Sinkable> sink)
{
    std::unique_lock<std::shared_mutex> lock(m_impl->Mutex);

    auto result = m_impl->Sinks.emplace(sink->GetName(), sink);
    if (result.second == true)
    {
        auto sink_ptr = static_cast<spdlog::sinks::sink*>(sink->GetData());
        m_impl->SinkRoot->add_sink(
            std::shared_ptr<spdlog::sinks::sink>(std::shared_ptr<void>(), sink_ptr));
    }
    else
    {
        throw;
    }
}

void XCore::Log::Logger::RemoveSink(const xcore::stl::string& name)
{
    std::unique_lock<std::shared_mutex> lock(m_impl->Mutex);

    if (m_impl->Sinks.count(name) > 0)
    {
        auto& sink     = m_impl->Sinks.at(name);
        auto  sink_ptr = static_cast<spdlog::sinks::sink*>(sink->GetData());
        m_impl->SinkRoot->remove_sink(
            std::shared_ptr<spdlog::sinks::sink>(std::shared_ptr<void>(), sink_ptr));

        m_impl->Sinks.erase(name);
    }
    else
    {
        throw;
    }
}

void XCore::Log::Logger::Log(XCore::Log::Level level, const xcore::stl::string& msg)
{
    std::shared_lock<std::shared_mutex> lock(m_impl->Mutex);

    m_impl->Logger->log(ConvertLevel(level), msg.c_str());
}

void XCore::Log::Logger::Dispose()
{
    /* Do Nothing! */
}
