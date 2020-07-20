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
 *
 */

#pragma once

#include "sink.h"
#include "level.h"

#include "../common/disposable.h"
#include "../common/common.h"

#include <memory>
#include <string>

namespace xcore
{
    namespace log
    {
        /**
         * @class Loggable loggable.h <xcore/log/loggable.h>
         *
         * @brief An interface for loggable types.
         */
        class Loggable : public xcore::Disposable
        {
        public:
            XCORE_DISABLE_COPY_AND_MOVE(Loggable);

        public:
            /**
             * @brief Default destructor.
             * 
             */
            Loggable() = default;

            /**
             * @brief Default virtual destructor.
             */
            virtual ~Loggable() = default;

            virtual void SetLevel(xcore::log::Level level) = 0;
            virtual void AddSink(const std::string& name, std::unique_ptr<xcore::log::Sink> sink) = 0;
            virtual void RemoveSink(const std::string& name) = 0;
            virtual void Log(xcore::log::Level level, const std::string& msg) = 0;
        };
    }
}