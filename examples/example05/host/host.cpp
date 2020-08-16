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

#include <XCore/XCore.h>

#include <memory>

int main()
{
    /*
        Create a console sink with name: "console-sink-01". 
    */
    XCore::Log::Level consoleSink01Level = XCore::Log::Level::Trace;
    auto consoleSink01 = std::make_shared<XCore::Log::ConsoleSink>("console-sink-01");
    consoleSink01->SetLevel(consoleSink01Level);

    /*
        Create a console sink with name: "console-sink-02". 
    */
    XCore::Log::Level consoleSink02Level = XCore::Log::Level::Trace;
    auto consoleSink02 = std::make_shared<XCore::Log::ConsoleSink>("console-sink-02");
    consoleSink02->SetLevel(consoleSink02Level);

    /*
        Create a file sink with name: "file-sink-01". 
    */
    XCore::Log::Level fileSink01Level = XCore::Log::Level::Trace;
    auto fileSink01 = std::make_shared<XCore::Log::FileSink>("file-sink-01", "file-sink-01.log");
    fileSink01->SetLevel(fileSink01Level);

    /*
        Create a file sink with name: "file-sink-02". 
    */
    XCore::Log::Level fileSink02Level = XCore::Log::Level::Trace;
    auto fileSink02 = std::make_shared<XCore::Log::FileSink>("file-sink-02", "file-sink-02.log");
    fileSink02->SetLevel(fileSink02Level);

    /*
        Create a compound sink.
    */
    XCore::Log::Level compoundConsoleSink01Level = XCore::Log::Level::Trace;
    auto compoundConsoleSink01 = std::make_shared<XCore::Log::ConsoleSink>("compound-console-sink-01");
    compoundConsoleSink01->SetLevel(compoundConsoleSink01Level);

    XCore::Log::Level compoundFileSink01Level = XCore::Log::Level::Trace;
    auto compoundFileSink01 = std::make_shared<XCore::Log::FileSink>("compound-file-sink-01", "compound-file-sink-01.log");
    compoundFileSink01->SetLevel(compoundFileSink01Level);

    std::vector<std::shared_ptr<XCore::Log::Sinkable>> compoundSinks;
    compoundSinks.push_back(compoundConsoleSink01);
    compoundSinks.push_back(compoundFileSink01);

    /*
        Create a logger with name: "logger-01".
        This log has a console sink with name: "console-sink-01".
    */
    XCore::Log::Level logger01Level = XCore::Log::Level::Trace;
    auto logger01 = std::make_shared<XCore::Log::Logger>("logger-01", consoleSink01);
    logger01->SetLevel(logger01Level);

    /*
        Create a logger with name: "logger-02".
        This log has a console sink with name: "console-sink-02".
    */
    XCore::Log::Level logger02Level = XCore::Log::Level::Trace;
    auto logger02 = std::make_shared<XCore::Log::Logger>("logger-02", consoleSink02);
    logger02->SetLevel(logger02Level);

    /*
        Create a logger with name: "logger-03".
        This log has a file sink with name: "file-sink-01".
    */
    XCore::Log::Level logger03Level = XCore::Log::Level::Trace;
    auto logger03 = std::make_shared<XCore::Log::Logger>("logger-03", fileSink01);
    logger03->SetLevel(logger03Level);

    /*
        Create a logger with name: "logger-04".
        This log has a file sink with name: "file-sink-02".
    */
    XCore::Log::Level logger04Level = XCore::Log::Level::Trace;
    auto logger04 = std::make_shared<XCore::Log::Logger>("logger-04", fileSink02);
    logger04->SetLevel(logger04Level);

    /*
        Create a logger with name: "logger-05".
        This log is composed with the following sinks: "compound-console-sink-01", 
        "compound-file-sink-01".  
    */
    XCore::Log::Level logger05Level = XCore::Log::Level::Trace;
    auto logger05 = std::make_shared<XCore::Log::Logger>("logger-05", compoundSinks);
    logger05->SetLevel(logger05Level);

    /*
        'logger-01' should display all 7 log messages with the sink 'console-sink-01' on console.
    */
    logger01->Log(XCore::Log::Level::None, "Log message 1.");
    logger01->Log(XCore::Log::Level::Critical, "Log message 2.");
    logger01->Log(XCore::Log::Level::Error, "Log message 3.");
    logger01->Log(XCore::Log::Level::Warning, "Log message 4.");
    logger01->Log(XCore::Log::Level::Info, "Log message 5.");
    logger01->Log(XCore::Log::Level::Debug, "Log message 6.");
    logger01->Log(XCore::Log::Level::Trace, "Log message 7.");

    /*
       'logger02' should display all 7 log messages with the sink 'console-sink-02' on console.
    */
    logger02->Log(XCore::Log::Level::None, "Log message 1.");
    logger02->Log(XCore::Log::Level::Critical,"Log message 2.");
    logger02->Log(XCore::Log::Level::Error, "Log message 3.");
    logger02->Log(XCore::Log::Level::Warning, "Log message 4.");
    logger02->Log(XCore::Log::Level::Info, "Log message 5.");
    logger02->Log(XCore::Log::Level::Debug, "Log message 6.");
    logger02->Log(XCore::Log::Level::Trace, "Log message 7.");

    /*
       'logger-03' should write all 7 log messages with the sink 'file-sink-01' on file-sink-01.log.
    */
    logger03->Log(XCore::Log::Level::None, "Log message 1.");
    logger03->Log(XCore::Log::Level::Critical, "Log message 2.");
    logger03->Log(XCore::Log::Level::Error, "Log message 3.");
    logger03->Log(XCore::Log::Level::Warning, "Log message 4.");
    logger03->Log(XCore::Log::Level::Info, "Log message 5.");
    logger03->Log(XCore::Log::Level::Debug, "Log message 6.");
    logger03->Log(XCore::Log::Level::Trace, "Log message 7.");

    /*
       'logger-04' should write all 7 log messages with the sink 'file-sink-02' on file-sink-02.log.
    */
    logger04->Log(XCore::Log::Level::None, "Log message 1.");
    logger04->Log(XCore::Log::Level::Critical, "Log message 2.");
    logger04->Log(XCore::Log::Level::Error, "Log message 3.");
    logger04->Log(XCore::Log::Level::Warning, "Log message 4.");
    logger04->Log(XCore::Log::Level::Info, "Log message 5.");
    logger04->Log(XCore::Log::Level::Debug, "Log message 6.");
    logger04->Log(XCore::Log::Level::Trace, "Log message 7.");

    /*
        'logger-05' should display 7 log messages with the sink 'compound-console-sink-01' on 
         console and should write 7 log messages with the sink 'compound-file-sink-01' on 
         compound-file-sink-01.log.
    */
    logger05->Log(XCore::Log::Level::None, "Log message 1.");
    logger05->Log(XCore::Log::Level::Critical, "Log message 2.");
    logger05->Log(XCore::Log::Level::Error, "Log message 3.");
    logger05->Log(XCore::Log::Level::Warning, "Log message 4.");
    logger05->Log(XCore::Log::Level::Info, "Log message 5.");
    logger05->Log(XCore::Log::Level::Debug, "Log message 6.");
    logger05->Log(XCore::Log::Level::Trace, "Log message 7.");

    return 0;
}