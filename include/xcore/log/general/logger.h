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
 * @brief The default logger implementation.
 */

#pragma once

#include "loggable.h"
#include "sink.h"
#include "level.h"

#include "../../common/common.h"

#include <vector>
#include <memory>

namespace xcore { namespace log { namespace general
{
    class Logger : public xcore::log::general::Loggable
    {
        public:
            Logger(const std::string& name);
            Logger(const std::string& name, xcore::log::general::Level level);
            Logger(const std::string& name, std::vector<std::unique_ptr<xcore::log::general::Sink>> sinks);
            Logger(const std::string& name, xcore::log::general::Level level, std::vector<std::unique_ptr<xcore::log::general::Sink>> sinks);

        public:
            virtual const std::string& GetName() override;
            virtual xcore::log::general::Level GetLevel() override;
            virtual void SetLevel(xcore::log::general::Level level) override;
            virtual void AddSink(std::unique_ptr<xcore::log::general::Sink> sink) override;
            virtual void RemoveSink(const std::string& name) override;
            virtual void Log(xcore::log::general::Level level, const std::string& msg) override;
                    
            virtual void Dispose() override;

        private:
            struct Impl;
            std::unique_ptr<Impl> m_Impl;
    };
}}}
