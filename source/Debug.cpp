#include "Debug.hpp"
#include "Hardware/VBAPrint.hpp"

void Debug::Log(std::string message)
{
#ifndef NO_DEBUG
#ifndef NO_LOGGING
    message = "LOG: " + message;
    VBAPrint(message.c_str());
#endif
#endif
}
void Debug::Warning(std::string message)
{
#ifndef NO_DEBUG
#ifndef NO_WARNINGS
    message = "WARNING: " + message;
    VBAPrint(message.c_str());
#endif
#endif
}
void Debug::Error(std::string message)
{
#ifndef NO_DEBUG
#ifndef NO_ERRORS
    message = "ERROR: " + message;
    VBAPrint(message.c_str());
#endif
#endif
}