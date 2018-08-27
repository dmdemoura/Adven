#pragma once

#include <string>

class Debug
{
public:
    static void Log(std::string message);
    static void Warning(std::string message);
    static void Error(std::string message);
};