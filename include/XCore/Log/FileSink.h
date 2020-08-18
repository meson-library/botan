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
 *     file.
 */

#pragma once

#include "Level.h"
#include "Sinkable.h"

#include <string>

namespace XCore { namespace Log {
    /**
     * @class FileSink FileSink.h <XCore/Log/FileSink.h>
     *
     * @brief A sink implementation for general use wich the destination is a
     *     file.
     */
    class FileSink : public XCore::Log::Sinkable
    {
    public:
        /**
         * @brief Construct a new sink object which the destination is a file.
         *
         * @param[in] name A unique name for the sink that will be built.
         *
         * @param[in] path The file path to which this sink will write the logs.
         *
         * @param[in] truncate Indicates whether the log file will be truncated.
         */
        FileSink(const std::string& name, const std::string& path, bool truncate = false);

    public:
        virtual const std::string& GetName() override;
        virtual XCore::Log::Level GetLevel() override;
        virtual void SetLevel(XCore::Log::Level level) override;
        virtual std::shared_ptr<void> GetData() override;
        virtual void Flush() override;

    private:
        struct Impl;
        std::unique_ptr<Impl> m_Impl;
    };
}}
