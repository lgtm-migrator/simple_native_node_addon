#include "logger.h"

#include <iostream>

Logger::Logger()
{

}

Logger::~Logger()
{

}

void Logger::PrintString(std::string text)
{
  std::cout<<text<<std::endl;
}
