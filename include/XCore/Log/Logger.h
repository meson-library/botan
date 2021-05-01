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

/**
 * @file
 *
 * @brief Contains a logger implementation for general use.
 */

#pragma once

#include "Level.h"
#include "Loggable.h"
#include "Sinkable.h"

namespace XCore { namespace Log {
    /**
     * @class Logger Logger.h <XCore/Log/logger.h>
     *
     * @brief A logger implementation for general use.
     */
    class Logger : public XCore::Log::Loggable
    {
    public:
        /**
         * @brief Construct a new Logger object.
         *
         * @param[in] name A unique name for the logger that will be built.
         *
         * @note The default severity level will be `XCore::Log::Level::Trace`.
         *
         * @see XCore::Log::Level
         */
        Logger(const xcore::stl::string& name);

        /**
         * @brief Construct a new Logger object.
         *
         * @param[in] name A unique name for the logger that will be built.
         *
         * @param[in] level The maximum severity level that this logger can
         *     respond to.
         */
        Logger(const xcore::stl::string& name, XCore::Log::Level level);

        /**
         * @brief Construct a new Logger object.
         *
         * @param[in] name A unique name for the logger that will be built.
         *
         * @param[in] sink A sink that will receive log messages from this
         *     logger and will redirect to an appropriate destination, such
         *     as file or console.
         *
         * @note The default severity level will be `XCore::Log::Level::Trace`.
         *
         * @see XCore::Log::Level
         */
        Logger(const xcore::stl::string& name, xcore::stl::shared_ptr<XCore::Log::Sinkable> sink);

        /**
         * @brief Construct a new Logger object.
         *
         * @param[in] name A unique name for the logger that will be built.
         *
         * @param[in] level The maximum severity level that this logger can
         *     respond to.
         *
         * @param[in] sink A sink that will receive log messages from this
         *     logger and will redirect to an appropriate destination, such
         *     as file or console.
         *
         * @note The default severity level will be `XCore::Log::Level::Trace`.
         *
         * @see XCore::Log::Level
         */
        Logger(const xcore::stl::string&                    name,
               XCore::Log::Level                           level,
               xcore::stl::shared_ptr<XCore::Log::Sinkable> sink);

        /**
         * @brief Construct a new Logger object.
         *
         * @param[in] name A unique name for the logger that will be built.
         *
         * @param[in] sinks A list of sinks that will receive log messages from
         *     this logger and will redirect to an appropriate destination,
         *     such as file or console.
         *
         * @note The default severity level will be `XCore::Log::Level::Trace`.
         *
         * @see XCore::Log::Level
         */
        Logger(const xcore::stl::string&                                       name,
               xcore::stl::vector<xcore::stl::shared_ptr<XCore::Log::Sinkable>> sinks);

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
        Logger(const xcore::stl::string&                                       name,
               XCore::Log::Level                                              level,
               xcore::stl::vector<xcore::stl::shared_ptr<XCore::Log::Sinkable>> sinks);

    public:
        virtual xcore::stl::string     GetName() override;
        virtual XCore::Log::Level     GetLevel() override;
        virtual void                  SetLevel(XCore::Log::Level level) override;
        virtual bool                  ContainsSink(const xcore::stl::string& name) override;
        virtual XCore::Log::Sinkable& GetSink(const xcore::stl::string& name) override;
        virtual void AddSink(xcore::stl::shared_ptr<XCore::Log::Sinkable> sink) override;
        virtual void RemoveSink(const xcore::stl::string& name) override;
        virtual void Log(XCore::Log::Level level, const xcore::stl::string& msg) override;
        virtual void Dispose() override;

    private:
        struct Impl;
        xcore::stl::unique_ptr<Impl> m_impl;
    };
}}
