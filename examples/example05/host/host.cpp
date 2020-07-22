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
    xcore::log::general::Level loggerLevel      = xcore::log::general::Level::Trace;
    xcore::log::general::Level consoleSinkLevel = xcore::log::general::Level::Trace;
    xcore::log::general::Level fileSinkLevel    = xcore::log::general::Level::Trace;

    auto consoleSink = std::make_unique<xcore::log::general::ConsoleSink>();
    consoleSink->SetLevel(consoleSinkLevel);

    auto fileSink = std::make_unique<xcore::log::general::FileSink>("teste.txt");
    fileSink->SetLevel(fileSinkLevel);

    std::vector<std::unique_ptr<xcore::log::general::Sink>> sinks;
    sinks.push_back(std::move(consoleSink));
    sinks.push_back(std::move(fileSink));

    auto logger = std::make_shared<xcore::log::general::Logger>("logger-01", std::move(sinks));
    logger->SetLevel(loggerLevel);

    /*auto consoleSink2 = std::make_unique<xcore::log::general::ConsoleSink>();
    consoleSink2->SetLevel(consoleSinkLevel);
    logger->AddSink(std::move(consoleSink2));*/

    logger->Log(xcore::log::general::Level::None,    "Log message 1.");
    logger->Log(xcore::log::general::Level::Fatal,   "Log message 2.");
    logger->Log(xcore::log::general::Level::Error,   "Log message 3.");
    logger->Log(xcore::log::general::Level::Warning, "Log message 4.");
    logger->Log(xcore::log::general::Level::Info,    "Log message 5.");
    logger->Log(xcore::log::general::Level::Debug,   "Log message 6.");
    logger->Log(xcore::log::general::Level::Trace,   "Log message 7.");

    return 0;
}