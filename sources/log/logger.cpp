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

#include "xcore/log/logger.h"

#include "internal.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/dist_sink.h>

class xcore::log::Logger::Impl
{
private:
    std::shared_ptr<spdlog::logger>              m_Logger;
    std::shared_ptr<spdlog::sinks::dist_sink_mt> m_SinkRoot;

    friend class Logger;
};

xcore::log::Logger::Logger(const std::string& name) : m_Impl{ std::make_unique<Impl>() }
{
    m_Impl->m_SinkRoot = std::make_shared<spdlog::sinks::dist_sink_mt>();
    m_Impl->m_Logger   = std::make_shared<spdlog::logger>(name, m_Impl->m_SinkRoot);
}

xcore::log::Logger::Logger(const std::string& name, std::vector<std::unique_ptr<xcore::log::Sink>> sinks) : m_Impl{ std::make_unique<Impl>() }
{
    m_Impl->m_SinkRoot = std::make_shared<spdlog::sinks::dist_sink_mt>();
    for (auto& sink : sinks)
    {
        m_Impl->m_SinkRoot->add_sink(std::static_pointer_cast<spdlog::sinks::sink>(sink->m_Sink));
        m_Sinks.push_back(std::move(sink)); // É necessário?
    }

    m_Impl->m_Logger = std::make_shared<spdlog::logger>(name, m_Impl->m_SinkRoot);
}

void xcore::log::Logger::SetLevel(xcore::log::Level level)
{
    m_Impl->m_Logger->set_level(convert_level(level));
}

void xcore::log::Logger::AddSink(const std::string& name, std::unique_ptr<xcore::log::Sink> sink)
{   
    m_Impl->m_SinkRoot->add_sink(std::static_pointer_cast<spdlog::sinks::sink>(sink->m_Sink));
    m_Sinks.push_back(std::move(sink));  // É necessário?
}

void xcore::log::Logger::RemoveSink(const std::string& name)
{

}

void xcore::log::Logger::Log(xcore::log::Level level, const std::string& msg)
{
    m_Impl->m_Logger->log(convert_level(level), msg); // Verificar come melhorar o seguinte método 'convert_level'.
}

void xcore::log::Logger::Dispose()
{
    // Verificar forma de fazer o 'Dispose'.
}

