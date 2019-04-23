/*
 * Copyright 2018 Gabriel de Moura Peres
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include "Input.hpp"
#include "Math.hpp"
#include "Log.hpp"

using namespace Adven;

std::array<Input::EventSet, Input::KeyCount> Input::eventSets;

//TODO:Handle invalid keys
int Input::KeyToIndex(Key key)
{
    return Math::Log2(static_cast<int>(key));
}
Input::Key Input::IndexToKey(int index)
{
   return static_cast<Key>(Math::Power2(index)); 
}
void Input::Update()
{
    for (int i = 0; i < KeyCount; i++)
    {
        Key key = IndexToKey(i);
        if (Input::GetKeyDown(key))
        {
            eventSets[i].Pressed.Raise();
        }
        else if (Input::GetKeyUp(key))
        {
            eventSets[i].Released.Raise();
        }
    }
}
Input::EventSet& Input::GetEventSet(Input::Key key)
{
    int index = KeyToIndex(key);
    if (index >= 0 && index < KeyCount)
    {
        return eventSets[(int) index];
    }
    else
    {
        throw std::invalid_argument("Key must greater or equal to 0 and less than " + KeyCount);
    }
}