#ifndef LOGGERIMPL_H
#define LOGGERIMPL_H

// LoggerImpl.h - Реализация
#include <string>
#include <iostream>

class LoggerImpl
{
  public:
    virtual ~LoggerImpl( ) {}
    virtual void console_log(const std::string & str ) = 0;
    virtual void file_log(
                    const std::string & file, const std::string & str ) = 0;

};

class ST_LoggerImpl : public LoggerImpl
{
  public:
    void console_log(const std::string & str );
    void file_log   (const std::string & file,const std::string & str );

};

#endif // LOGGERIMPL_H
