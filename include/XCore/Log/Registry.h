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
 * @brief Contains a global registry for working with loggers.
 */

#include "../Common.h"
#include "Loggable.h"

namespace XCore { namespace Log { namespace Registry {
    /**
     * @brief Checks whether this registry contains a logger with the given name.
     *
     * @param loggerName The logger name (case insensitive).
     *
     * @return true
     * @return false
     */
    bool Contains(const xcore::stl::string& loggerName);

    /**
     * @brief Get from this registry a logger with the given name.
     *
     * @param loggerName The logger name (case insensitive).
     *
     * @return XCore::Log::Loggable&
     */
    XCore::Log::Loggable& Get(const xcore::stl::string& loggerName);

    /**
     * @brief Remove from this registry a logger with the given name.
     *
     * @param loggerName The logger name (case insensitive).
     */
    void Remove(const xcore::stl::string& loggerName);

    /**
     * @brief Add the supplied logger to this registry.
     *
     * @param logger The logger to be added.
     */
    void Add(xcore::stl::unique_ptr<XCore::Log::Loggable> logger);
}}}
