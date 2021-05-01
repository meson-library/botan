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

#include "XCore/Log/FileSink.h"

#include "internal.h"

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>


struct XCore::Log::FileSink::Impl
{
    xcore::stl::string           Name;
    xcore::stl::shared_ptr<void> Data;
};


XCore::Log::FileSink::FileSink(const xcore::stl::string& name,
                               const xcore::stl::string& path,
                               bool                     truncate)
    : m_impl {xcore::stl::make_unique<Impl>()}
{
    m_impl->Name = name;
    m_impl->Data = xcore::stl::make_shared<spdlog::sinks::basic_file_sink_mt>(path.c_str(), truncate);
}

xcore::stl::string XCore::Log::FileSink::GetName()
{
    return m_impl->Name;
}

XCore::Log::Level XCore::Log::FileSink::GetLevel()
{
    auto sink = xcore::stl::static_pointer_cast<spdlog::sinks::basic_file_sink_mt>(m_impl->Data);
    return ConvertLevel(sink->level());
}

void XCore::Log::FileSink::SetLevel(XCore::Log::Level level)
{
    auto sink = xcore::stl::static_pointer_cast<spdlog::sinks::basic_file_sink_mt>(m_impl->Data);
    sink->set_level(ConvertLevel(level));
}

void* XCore::Log::FileSink::GetData()
{
    return m_impl->Data.get();
}

void XCore::Log::FileSink::Flush()
{
    auto sink = xcore::stl::static_pointer_cast<spdlog::sinks::basic_file_sink_mt>(m_impl->Data);
    sink->flush();
}
