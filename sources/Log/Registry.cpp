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

#include "XCore/log/Registry.h"

#include <shared_mutex>
#include <unordered_map>


namespace {
    core::stl::unordered_map<core::stl::string, core::stl::unique_ptr<XCore::Log::Loggable>> loggers;
    std::shared_mutex                                                                        mutex;
}


bool XCore::Log::Registry::Contains(const core::stl::string& loggerName)
{
    std::shared_lock<std::shared_mutex> lock(mutex);

    return loggers.count(loggerName) > 0;
}

XCore::Log::Loggable& XCore::Log::Registry::Get(const core::stl::string& loggerName)
{
    std::shared_lock<std::shared_mutex> lock(mutex);

    if (Contains(loggerName))
    {
        auto& item = loggers.at(loggerName);
        return *item;
    }
    else
    {
        throw;
    }
}

void XCore::Log::Registry::Remove(const core::stl::string& loggerName)
{
    std::unique_lock<std::shared_mutex> lock(mutex);

    auto result = loggers.erase(loggerName);
    if (result == 0)
    {
        throw;
    }
}

void XCore::Log::Registry::Add(core::stl::unique_ptr<Loggable> logger)
{
    std::unique_lock<std::shared_mutex> lock(mutex);

    auto result = loggers.insert(core::stl::make_pair(logger->GetName(), core::stl::move(logger)));
    if (result.second == false)
    {
        throw;
    }
}
