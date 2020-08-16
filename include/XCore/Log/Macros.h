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
 * @brief Contains a set of macros to support logging.
 */

#pragma once

#include "Level.h"

#define XCORE_LOG_GENERAL1_CRITICAL(logger, ...) \
    logger->Log(XCore::Log::Level::Critical, __VA_ARGS__)

#define XCORE_LOG_GENERAL1_ERROR(logger, ...) \
    logger->Log(XCore::Log::Level::Error, __VA_ARGS__)

#define XCORE_LOG_GENERAL1_WARNING(logger, ...) \
    logger->Log(XCore::Log::Level::Warning, __VA_ARGS__)

#define XCORE_LOG_GENERAL1_INFO(logger, ...) \
    logger->Log(XCore::Log::Level::Info, __VA_ARGS__)

#define XCORE_LOG_GENERAL1_DEBUG(logger, ...) \
    logger->Log(XCore::Log::Level::Debug, __VA_ARGS__)

#define XCORE_LOG_GENERAL1_TRACE(logger, ...) \
    logger->Log(XCore::Log::Level::Trace, __VA_ARGS__)



#define XCORE_LOG_GENERAL_CRITICAL(...) \
    XCORE_LOG_GENERAL1_CRITICAL(default_logger, __VA_ARGS__)

#define XCORE_LOG_GENERAL_ERROR(...) \
    XCORE_LOG_GENERAL1_ERROR(default_logger, __VA_ARGS__)

#define XCORE_LOG_GENERAL_WARNING(...) \
    XCORE_LOG_GENERAL1_WARNING(default_logger, __VA_ARGS__)

#define XCORE_LOG_GENERAL_INFO(...) \
    XCORE_LOG_GENERAL1_INFO(default_logger, __VA_ARGS__)

#define XCORE_LOG_GENERAL_DEBUG(...) \
    XCORE_LOG_GENERAL1__DEBUG(default_logger, __VA_ARGS__)

#define XCORE_LOG_GENERAL_TRACE(...) \
    XCORE_LOG_GENERAL1_TRACE(default_logger, __VA_ARGS__)
