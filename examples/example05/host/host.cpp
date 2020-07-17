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

#include <xcore/xcore.h>

#include <memory>

int main()
{
    xcore::log::Level loggerLevel      = xcore::log::Level::Warning;
    xcore::log::Level consoleSinkLevel = xcore::log::Level::Error;
    xcore::log::Level fileSinkLevel    = xcore::log::Level::Warning;

    auto logger = std::make_unique<xcore::log::Logger>("logger-01");
    logger->SetLevel(loggerLevel);

    auto consoleSink = std::make_unique<xcore::log::ConsoleSink>();
    consoleSink->SetLevel(consoleSinkLevel);
    logger->AddSink(std::move(consoleSink));

    auto fileSink = std::make_unique<xcore::log::FileSink>("teste.txt");
    fileSink->SetLevel(fileSinkLevel);
    logger->AddSink(std::move(fileSink));

    logger->Log(xcore::log::Level::None,    "Log message 1.");
    logger->Log(xcore::log::Level::Fatal,   "Log message 2.");
    logger->Log(xcore::log::Level::Error,   "Log message 3.");
    logger->Log(xcore::log::Level::Warning, "Log message 4.");
    logger->Log(xcore::log::Level::Info,    "Log message 5.");
    logger->Log(xcore::log::Level::Debug,   "Log message 6.");
    logger->Log(xcore::log::Level::Trace,   "Log message 7.");

    return 0;
}