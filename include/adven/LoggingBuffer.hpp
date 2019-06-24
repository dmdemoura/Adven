/*
 * Copyright 2018 Amanda de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef DM_ADVEN_LOGGING_BUFFER_HPP
#define DM_ADVEN_LOGGING_BUFFER_HPP

#include <streambuf>
#include <vector>

namespace Adven
{
    class LoggingBuffer : public std::streambuf
    {
    private:
        std::vector<char> buffer;
        char* SRAMCurrent;
    private:
        int_type overflow(int_type c) override;
        int sync() override;
        void writeToNoCashDebugger();
        void writeToVBAPrint();
        void writeToSRAM();
        void flush();
    public:
        LoggingBuffer(std::size_t buffer_size);
    };
}
#endif