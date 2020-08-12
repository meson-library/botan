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
 * @brief Contains a sink implementation for general use wich de destination is a 
 *     console.
 */

#pragma once

#include "sinkable.h"
#include "level.h"

#include <string>

namespace xcore { namespace log { namespace general
{
    /**
     * @class ConsoleSink console_sink.h <xcore/log/general/console_sink.h>
     *
     * @brief A sink implementation for general use wich the destination is a 
     *     console.
     */
    class ConsoleSink : public xcore::log::general::Sinkable
    {
    public:
        /**
         * @brief Construct a new sink object wich the destination is a console.
         * 
         * @param[in] name A unique name for the sink that will be built.
         */
        ConsoleSink(const std::string& name);
    
    public:
        virtual const std::string& GetName() override;
        virtual xcore::log::general::Level GetLevel() override;
        virtual void SetLevel(xcore::log::general::Level level) override;
        virtual std::shared_ptr<void> GetData() override;
        virtual void Flush() override;
    
    private:
        struct Impl;
        std::unique_ptr<Impl> m_Impl;
    };
}}}
