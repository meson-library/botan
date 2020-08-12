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
 * @brief Contains a logger implementation for general use.
 */

#pragma once

#include "loggable.h"
#include "sinkable.h"
#include "level.h"

#include <vector>
#include <memory>

namespace xcore { namespace log { namespace general
{
    /**
     * @class Logger logger.h <xcore/log/general/logger.h>
     *
     * @brief A logger implementation for general use.
     */
    class Logger : public xcore::log::general::Loggable
    {
        public:
            /**
             * @brief Construct a new Logger object. 
             * 
             * @param[in] name A unique name for the logger that will be built.
             * 
             * @note The default severity level will be `xcore::log::general::Level::Trace`.
             * 
             * @see xcore::log::general::Level
             */
            Logger(const std::string& name);

            /**
             * @brief Construct a new Logger object.
             * 
             * @param[in] name A unique name for the logger that will be built.
             * 
             * @param[in] level The maximum severity level that this logger can 
             *     respond to.
             */
            Logger(const std::string& name, xcore::log::general::Level level);

            /**
             * @brief Construct a new Logger object.
             * 
             * @param[in] name A unique name for the logger that will be built.
             * 
             * @param[in] sinks A list of sinks that will receive log messages from 
             *     this logger and will redirect to an appropriate destination, 
             *     such as file or console.
             * 
             * @note The default severity level will be `xcore::log::general::Level::Trace`.
             * 
             * @see xcore::log::general::Level
             */
            Logger(const std::string& name, std::vector<std::shared_ptr<xcore::log::general::Sinkable>> sinks);

            /**
             * @brief Construct a new Logger object.
             * 
             * @param[in] name A unique name for the logger that will be built.
             * 
             * @param[in] level The maximum severity level that this logger can 
             *     respond to.
             * 
             * @param[in] sinks A list of sinks that will receive log messages from 
             *     this logger and will redirect to an appropriate destination, 
             *     such as file or console.
             */
            Logger(const std::string& name, xcore::log::general::Level level, std::vector<std::shared_ptr<xcore::log::general::Sinkable>> sinks);

        public:
            virtual const std::string& GetName() override;
            virtual xcore::log::general::Level GetLevel() override;
            virtual void SetLevel(xcore::log::general::Level level) override;
            virtual void AddSink(std::shared_ptr<xcore::log::general::Sinkable> sink) override;
            virtual void RemoveSink(const std::string& name) override;
            virtual void Log(xcore::log::general::Level level, const std::string& msg) override;
            virtual void Dispose() override;

        private:
            struct Impl;
            std::unique_ptr<Impl> m_Impl;
    };
}}}
