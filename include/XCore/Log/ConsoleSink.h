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
 * @brief Contains a sink implementation for general use wich the destination is a
 *     console.
 */

#pragma once

#include "../Common.h"
#include "Sinkable.h"

namespace XCore { namespace Log {
    /**
     * @class ConsoleSink ConsoleSink.h <XCore/Log/ConsoleSink.h>
     *
     * @brief A sink implementation for general use wich the destination is a
     *     console.
     */
    class ConsoleSink : public XCore::Log::Sinkable
    {
    public:
        /**
         * @brief Construct a new sink object wich the destination is a console.
         *
         * @param[in] name A unique name for the sink that will be built.
         */
        ConsoleSink(const core::stl::string& name);

    public:
        virtual core::stl::string GetName() override;
        virtual XCore::Log::Level GetLevel() override;
        virtual void              SetLevel(XCore::Log::Level level) override;
        virtual void              Flush() override;
        virtual void*             GetData() override;

    private:
        struct Impl;
        core::stl::unique_ptr<Impl> m_impl;
    };
}}
