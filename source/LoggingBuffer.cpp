/*
 * Copyright 2018 Gabriel de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "LoggingBuffer.hpp"
#include <advenCore/VBAPrint.hpp>
#include <advenCore/SRAM.hpp>
#include <cstring>
#include <tonc.h>

using namespace AdvenCore;
using namespace Adven;

LoggingBuffer::LoggingBuffer(std::size_t buffer_size) : buffer(buffer_size + 1), SRAMCurrent((char*) SRAM::start)
{
    char* base = &buffer.front();
    setp(base, base + buffer.size());
}
LoggingBuffer::int_type LoggingBuffer::overflow(int_type c)
{
    if (c != traits_type::eof())
    {
        // assert(std::less_equal<char *>()(pptr(), epptr()));
        *pptr() = c;
        pbump(1);

        flush();
        return c;
    }

    return traits_type::eof();
}
int LoggingBuffer::sync()
{
    flush();
    return 1;
}
void LoggingBuffer::writeToNoCashDebugger()
{
    nocash_puts((const char*) buffer.data());
}
void LoggingBuffer::writeToVBAPrint()
{
    //VBAPrint(buffer.data());
}
void LoggingBuffer::writeToSRAM()
{
    strcpy(SRAMCurrent, buffer.data());
    SRAMCurrent += strlen(buffer.data());
}
void LoggingBuffer::flush()
{
    writeToNoCashDebugger();
    writeToVBAPrint();
    writeToSRAM();

    char* base = &buffer.front();
    setp(base, base + buffer.size());
}