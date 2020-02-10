#ifndef LOGGER_H
#define LOGGER_H

// Logger.h - Абстракция
#include <string>
#include <iostream>

// Опережающее объявление
class LoggerImpl;

class Logger
{
  public:
    Logger( LoggerImpl* p );
    virtual ~Logger( );
    virtual void log( const std::string & str ) = 0;
  protected:
    LoggerImpl * pimpl;
};

class ConsoleLogger : public Logger
{
  public:
    ConsoleLogger();
    void log(const std::string & str );
};

class FileLogger : public Logger
{
  public:
    FileLogger(const std::string & file_name );
    void log(const std::string & str );
  private:
    std::string file;
};



#endif // LOGGER_H
