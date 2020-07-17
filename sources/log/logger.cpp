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

xcore::log::Logger::Logger(std::string name)
{
    m_LogSinkRoot = std::make_shared<spdlog::sinks::dist_sink_mt>();
    m_Logger        = std::make_shared<spdlog::logger>(name, m_LogSinkRoot);
}

xcore::log::Logger::Logger(std::string name, std::vector<std::unique_ptr<xcore::log::Sink>> sinks)
{
    m_LogSinkRoot = std::make_shared<spdlog::sinks::dist_sink_mt>();
    for (auto& sink : sinks)
    {
        m_LogSinkRoot->add_sink(std::static_pointer_cast<spdlog::sinks::sink>(sink->m_LogSink));
        m_LogSinks.push_back(std::move(sink));
    }

    m_Logger = std::make_shared<spdlog::logger>(name, m_LogSinkRoot);
}

inline void xcore::log::Logger::SetLevel(xcore::log::Level level)
{
    m_Logger->set_level(convert_level(level));
}

inline void xcore::log::Logger::AddSink(std::unique_ptr<xcore::log::Sink> sink)
{   
    m_LogSinkRoot->add_sink(std::static_pointer_cast<spdlog::sinks::sink>(sink->m_LogSink));
    m_LogSinks.push_back(std::move(sink));
}

inline void xcore::log::Logger::Log(xcore::log::Level level, std::string msg)
{
    m_Logger->log(convert_level(level), msg);
}

inline void xcore::log::Logger::Dispose()
{

}