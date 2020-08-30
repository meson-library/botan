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

#include "XCore/Log/ConsoleSink.h"

#include "internal.h"

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>


struct XCore::Log::ConsoleSink::Impl
{
    core::stl::string           Name;
    core::stl::shared_ptr<void> Data;
};


XCore::Log::ConsoleSink::ConsoleSink(const core::stl::string& name)
    : m_impl {core::stl::make_unique<Impl>()}
{
    m_impl->Name = name;
    m_impl->Data = core::stl::make_shared<spdlog::sinks::stdout_color_sink_mt>();
}

core::stl::string XCore::Log::ConsoleSink::GetName()
{
    return m_impl->Name;
}

XCore::Log::Level XCore::Log::ConsoleSink::GetLevel()
{
    auto sink = core::stl::static_pointer_cast<spdlog::sinks::stdout_color_sink_mt>(m_impl->Data);
    return ConvertLevel(sink->level());
}

void XCore::Log::ConsoleSink::SetLevel(XCore::Log::Level level)
{
    auto sink = core::stl::static_pointer_cast<spdlog::sinks::stdout_color_sink_mt>(m_impl->Data);
    sink->set_level(ConvertLevel(level));
}

void* XCore::Log::ConsoleSink::GetData()
{
    return m_impl->Data.get();
}

void XCore::Log::ConsoleSink::Flush()
{
    auto sink = core::stl::static_pointer_cast<spdlog::sinks::stdout_color_sink_mt>(m_impl->Data);
    sink->flush();
}
