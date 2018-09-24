#ifndef DM_ADVEN_DEBUG_HPP
#define DM_ADVEN_DEBUG_HPP

#include <string>

namespace Adven
{
    class Debug
    {
    public:
        static void Log(std::string message);
        static void Warning(std::string message);
        static void Error(std::string message);
    };
}

#endif