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
 * @brief Contains an interface for loggable types.
 */

#pragma once

#include "sinkable.h"
#include "level.h"

#include "../../common/disposable.h"
#include "../../common/common.h"

#include <memory>
#include <string>

namespace xcore { namespace log { namespace general
{
    /**
     * @class Loggable loggable.h <xcore/log/general/loggable.h>
     *
     * @brief An interface for loggable types.
     */
    class Loggable : public xcore::common::Disposable
    {
    public:
        XCORE_DISABLE_COPY_AND_MOVE(Loggable);

    public:
        Loggable() = default;
        virtual ~Loggable() = default;

    public:
        /**
         * @brief Get the name of this loggable object.
         * 
         * @return const std::string& 
         */
        virtual const std::string& GetName() = 0;

        /**
         * @brief Get the severity level of this loggable object.
         * 
         * @return xcore::log::general::Level 
         */
        virtual xcore::log::general::Level GetLevel() = 0;

        /**
         * @brief Set the maximum severity level that this logger can 
         *     respond to.
         * 
         * @param[in] level The Level to be set.
         */
        virtual void SetLevel(xcore::log::general::Level level) = 0;

        /**
         * @brief Add a sink to this logabble object.
         * 
         * @param[in] sink The Sink to be added.
         */
        virtual void AddSink(std::shared_ptr<xcore::log::general::Sinkable> sink) = 0;

        /**
         * @brief Remove a sink from this logabble object.
         * 
         * @param[in] name The name of the Sink to be removed.
         */
        virtual void RemoveSink(const std::string& name) = 0;

        /**
         * @brief Log a message with a defined severity level with this loggable 
         *     object.
         * 
         * @param[in] level The severity level.
         * 
         * @param[in] msg The message to be logged.
         */
        virtual void Log(xcore::log::general::Level level, const std::string& msg) = 0;
    };
}}}
