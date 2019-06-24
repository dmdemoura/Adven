/*
 * Copyright 2018 Amanda de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef DM_ADVEN_INPUT_HPP
#define DM_ADVEN_INPUT_HPP

#include <array>
#include <advenCore/Input.hpp>
#include "Event.hpp"

namespace Adven
{
    class Input : public AdvenCore::Input
    {
    public:
        static constexpr int KeyCount = 10;
        struct EventSet
        {
            Event<void()> Pressed;
            Event<void()> Released;
        };
    private:
        static std::array<EventSet, KeyCount> eventSets;
    public:
        static int KeyToIndex(Key key);
        static Key IndexToKey(int index);
        static EventSet& GetEventSet(Key key);
        static void Update();
    };
}

#endif