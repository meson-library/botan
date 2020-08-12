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
    /*
        Create a console sink with name: "console-sink-01". 
    */
    xcore::log::general::Level console_sink_01_level = xcore::log::general::Level::Trace;
    auto console_sink_01 = std::make_shared<xcore::log::general::ConsoleSink>("console-sink-01");
    console_sink_01->SetLevel(console_sink_01_level);

    /*
        Create a console sink with name: "console-sink-02". 
    */
    xcore::log::general::Level console_sink_02_level = xcore::log::general::Level::Trace;
    auto console_sink_02 = std::make_shared<xcore::log::general::ConsoleSink>("console-sink-02");
    console_sink_02->SetLevel(console_sink_02_level);

    /*
        Create a file sink with name: "file-sink-01". 
    */
    xcore::log::general::Level file_sink_01_level = xcore::log::general::Level::Trace;
    auto file_sink_01 = std::make_shared<xcore::log::general::FileSink>("file-sink-01", "file-sink-01.log");
    file_sink_01->SetLevel(file_sink_01_level);

    /*
        Create a file sink with name: "file-sink-02". 
    */
    xcore::log::general::Level file_sink_02_level = xcore::log::general::Level::Trace;
    auto file_sink_02 = std::make_shared<xcore::log::general::FileSink>("file-sink-02", "file-sink-02.log");
    file_sink_02->SetLevel(file_sink_02_level);

    /*
        Create a compound sink.
    */
    xcore::log::general::Level compound_console_sink_01_level = xcore::log::general::Level::Trace;
    auto compound_console_sink_01 = std::make_shared<xcore::log::general::ConsoleSink>("compound-console-sink-01");
    compound_console_sink_01->SetLevel(compound_console_sink_01_level);

    xcore::log::general::Level compound_file_sink_01_level = xcore::log::general::Level::Trace;
    auto compound_file_sink_01 = std::make_shared<xcore::log::general::FileSink>("compound-file-sink-01", "compound-file-sink-01.log");
    compound_file_sink_01->SetLevel(compound_file_sink_01_level);

    std::vector<std::shared_ptr<xcore::log::general::Sinkable>> compound_sinks;
    compound_sinks.push_back(compound_console_sink_01);
    compound_sinks.push_back(compound_file_sink_01);

    /*
        Create a logger with name: "logger-01".
        This log has a console sink with name: "console-sink-01".
    */
    xcore::log::general::Level logger_01_level = xcore::log::general::Level::Trace;
    auto logger_01 = std::make_shared<xcore::log::general::Logger>("logger-01", std::vector<std::shared_ptr<xcore::log::general::Sinkable>>{console_sink_01});
    logger_01->SetLevel(logger_01_level);

    /*
        Create a logger with name: "logger-02".
        This log has a console sink with name: "console-sink-02".
    */
    xcore::log::general::Level logger_02_level = xcore::log::general::Level::Trace;
    auto logger_02 = std::make_shared<xcore::log::general::Logger>("logger-02", std::vector<std::shared_ptr<xcore::log::general::Sinkable>>{console_sink_02});
    logger_02->SetLevel(logger_02_level);

    /*
        Create a logger with name: "logger-03".
        This log has a file sink with name: "file-sink-01".
    */
    xcore::log::general::Level logger_03_level = xcore::log::general::Level::Trace;
    auto logger_03 = std::make_shared<xcore::log::general::Logger>("logger-03", std::vector<std::shared_ptr<xcore::log::general::Sinkable>>{file_sink_01});
    logger_03->SetLevel(logger_03_level);

    /*
        Create a logger with name: "logger-04".
        This log has a file sink with name: "file-sink-02".
    */
    xcore::log::general::Level logger_04_level = xcore::log::general::Level::Trace;
    auto logger_04 = std::make_shared<xcore::log::general::Logger>("logger-04", std::vector<std::shared_ptr<xcore::log::general::Sinkable>>{file_sink_02});
    logger_04->SetLevel(logger_04_level);

    /*
        Create a logger with name: "logger-05".
        This log is composed with the following sinks: "compound-console-sink-01", 
        "compound-file-sink-01".  
    */
    xcore::log::general::Level logger_05_level = xcore::log::general::Level::Trace;
    auto logger_05 = std::make_shared<xcore::log::general::Logger>("logger-05", compound_sinks);
    logger_05->SetLevel(logger_05_level);

    /*
        'logger-01' should display all 7 log messages with the sink 'console-sink-01' on console.
    */
    logger_01->Log(xcore::log::general::Level::None,    "Log message 1.");
    logger_01->Log(xcore::log::general::Level::Fatal,   "Log message 2.");
    logger_01->Log(xcore::log::general::Level::Error,   "Log message 3.");
    logger_01->Log(xcore::log::general::Level::Warning, "Log message 4.");
    logger_01->Log(xcore::log::general::Level::Info,    "Log message 5.");
    logger_01->Log(xcore::log::general::Level::Debug,   "Log message 6.");
    logger_01->Log(xcore::log::general::Level::Trace,   "Log message 7.");

    /*
       'logger_02' should display all 7 log messages with the sink 'console-sink-02' on console.
    */
    logger_02->Log(xcore::log::general::Level::None,    "Log message 1.");
    logger_02->Log(xcore::log::general::Level::Fatal,   "Log message 2.");
    logger_02->Log(xcore::log::general::Level::Error,   "Log message 3.");
    logger_02->Log(xcore::log::general::Level::Warning, "Log message 4.");
    logger_02->Log(xcore::log::general::Level::Info,    "Log message 5.");
    logger_02->Log(xcore::log::general::Level::Debug,   "Log message 6.");
    logger_02->Log(xcore::log::general::Level::Trace,   "Log message 7.");

    /*
       'logger-03' should write all 7 log messages with the sink 'file-sink-01' on file-sink-01.log.
    */
    logger_03->Log(xcore::log::general::Level::None,    "Log message 1.");
    logger_03->Log(xcore::log::general::Level::Fatal,   "Log message 2.");
    logger_03->Log(xcore::log::general::Level::Error,   "Log message 3.");
    logger_03->Log(xcore::log::general::Level::Warning, "Log message 4.");
    logger_03->Log(xcore::log::general::Level::Info,    "Log message 5.");
    logger_03->Log(xcore::log::general::Level::Debug,   "Log message 6.");
    logger_03->Log(xcore::log::general::Level::Trace,   "Log message 7.");

    /*
       'logger-04' should write all 7 log messages with the sink 'file-sink-02' on file-sink-02.log.
    */
    logger_04->Log(xcore::log::general::Level::None,    "Log message 1.");
    logger_04->Log(xcore::log::general::Level::Fatal,   "Log message 2.");
    logger_04->Log(xcore::log::general::Level::Error,   "Log message 3.");
    logger_04->Log(xcore::log::general::Level::Warning, "Log message 4.");
    logger_04->Log(xcore::log::general::Level::Info,    "Log message 5.");
    logger_04->Log(xcore::log::general::Level::Debug,   "Log message 6.");
    logger_04->Log(xcore::log::general::Level::Trace,   "Log message 7.");

    /*
        'logger-05' should display 7 log messages with the sink 'compound-console-sink-01' on console
         and should write 7 log messages with the sink 'compound-file-sink-01' on compound-file-sink-01.log.
    */
    logger_05->Log(xcore::log::general::Level::None,    "Log message 1.");
    logger_05->Log(xcore::log::general::Level::Fatal,   "Log message 2.");
    logger_05->Log(xcore::log::general::Level::Error,   "Log message 3.");
    logger_05->Log(xcore::log::general::Level::Warning, "Log message 4.");
    logger_05->Log(xcore::log::general::Level::Info,    "Log message 5.");
    logger_05->Log(xcore::log::general::Level::Debug,   "Log message 6.");
    logger_05->Log(xcore::log::general::Level::Trace,   "Log message 7.");

    return 0;
}