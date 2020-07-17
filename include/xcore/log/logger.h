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

/**
 * @file
 *
 * @brief 
 *
 */

#pragma once

#include "loggable.h"
#include "sink.h"
#include "level.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/dist_sink.h>

#include <vector>
#include <memory>

namespace xcore
{
    namespace log
    {
        class Logger : public xcore::log::Loggable
        {
        public:
                         Logger(std::string name);
                         Logger(std::string name, std::vector<std::unique_ptr<xcore::log::Sink>> sinks);

            virtual void Log(xcore::log::Level level, std::string msg) override;
            virtual void SetLevel(xcore::log::Level level) override;
            virtual void AddSink(std::unique_ptr<xcore::log::Sink> sink) override;
            virtual void Dispose() override;

        private:
            std::shared_ptr<spdlog::logger>              m_Logger;
            std::shared_ptr<spdlog::sinks::dist_sink_mt> m_LogSinkRoot;

            std::vector<std::unique_ptr<xcore::log::Sink>> m_LogSinks;
        };
    }
}