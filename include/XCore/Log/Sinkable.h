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
 * @brief Contains an interface for sinkable types.
 */

#pragma once

#include "../Common/Macros.h"
#include "Level.h"

#include <memory>
#include <string>


namespace XCore { namespace Log
{
    /**
     * @class Sinkable Sinkable.h <XCore/Log/Sinkable.h>
     *
     * @brief An interface for sinkable types.
     */
    class Sinkable
    {
    public:
        XCORE_DISABLE_COPY_AND_MOVE(Sinkable);

    public:
        Sinkable() = default;
        virtual ~Sinkable() = default;

    public:
        /**
         * @brief Get the name of this sinkable object.
         * 
         * @return const std::string& 
         */
        virtual const std::string& GetName() = 0;

        /**
         * @brief Get the severity level of this sinkable object.
         * 
         * @return XCore::Log::Level 
         */
        virtual XCore::Log::Level GetLevel() = 0;

        /**
         * @brief Set the maximum severity level that this sink can 
         *     respond to.
         * 
         * @param[in] level The Level to be set.
         */
        virtual void SetLevel(XCore::Log::Level level) = 0;

        /**
         * @brief Get custom data of this object.
         * 
         * @return std::shared_ptr<void> 
         */
        virtual std::shared_ptr<void> GetData() = 0;

        /**
         * @brief Flush the buffered log records to the target. 
         */
        virtual void Flush() = 0;
    };
}}
