// Logger.cpp - Абстракция
#include "logger.h"
#include "LoggerImpl.h"

Logger::Logger(LoggerImpl* p ) : pimpl(p)
{

}

Logger::~Logger( )
{
    delete pimpl;
}

ConsoleLogger::ConsoleLogger() : Logger(
        new ST_LoggerImpl()
    )
{ }

void ConsoleLogger::log(const std::string & str )
{
    pimpl->console_log( str);
}

FileLogger::FileLogger(const std::string & file_name ) :
    Logger(new ST_LoggerImpl()), file(file_name)
{ }

void FileLogger::log(const std::string & str )
{
    pimpl->file_log( file, str);
}

