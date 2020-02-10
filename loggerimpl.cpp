// LoggerImpl.cpp - Реализация
#include "loggerimpl.h"
#include <QFile> // Подключаем класс QFile
#include <QTextStream> // Подключаем класс QTextStream
#include <fstream>


void ST_LoggerImpl::console_log(const std::string & str )
{
  std::cout << "Single-threaded console logger" << std::endl;
  std::cout << str << std::endl;
}

void ST_LoggerImpl::file_log(const std::string & file, const std::string & str )
{
  std::cout << "Single-threaded file logger" << std::endl;

  /*QFile fileOut(file); // Связываем объект с файлом file
      if(fileOut.open(QIODevice::WriteOnly | QIODevice::Text))
      { // Если файл успешно открыт для записи в текстовом режиме
          QTextStream writeStream(&fileOut); // Создаем объект класса QTextStream
  // и передаем ему адрес объекта fileOut
          writeStream << str; // Посылаем строку в поток для записи
          fileOut.close(); // Закрываем файл
      }*/
  std::ofstream out(file, std::ios::app);
  if (out.is_open())
  {
      out << str << std::endl;
  }
  out.close();
}

