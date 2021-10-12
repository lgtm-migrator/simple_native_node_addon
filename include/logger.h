#ifndef __LOGGER_EXAMPLE_H__
#define __LOGGER_EXAMPLE_H__

#include <string>

class Logger
{
public:
    Logger();
    virtual ~Logger();

    virtual void PrintString(std::string text);
};

#endif //__LOGGER_EXAMPLE_H__
