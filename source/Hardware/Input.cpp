#include "Input.hpp"
volatile Input::KeyInput * const Input::KeyInputRegister = (volatile Input::KeyInput *) 0x4000130; 
Input::KeyInput Input::KeyInputCurrent = 0;
Input::KeyInput Input::KeyInputPrevious = 0;

void Input::KeyUpdate()
{
    KeyInputPrevious = KeyInputCurrent;
    //Do not forget the bitwise not or the key states will be flipped
    KeyInputCurrent = ~((unsigned int) *Input::KeyInputRegister);
}
bool Input::GetKeyState(Key key, KeyInput keyInput)
{
    //The values of the Key enum are bit masks for a KeyInput value
    return KeyInputCurrent & (int) key;
}
bool Input::GetKeyHeld(Key key)
{
    return GetKeyState(key, KeyInputPrevious) && GetKeyState(key, KeyInputCurrent);
}
bool Input::GetKeyDown(Key key)
{
    return !GetKeyState(key, KeyInputPrevious) && GetKeyState(key, KeyInputCurrent);
}
bool Input::GetKeyUp(Key key)
{
    return GetKeyState(key, KeyInputPrevious) && !GetKeyState(key, KeyInputCurrent);
}
Input::Tribool Input::GetTribool(Direction direction)
{
    Tribool tri = 0;
    if (GetKeyState((Key) direction, KeyInputCurrent))
        tri = 1;
    else if (GetKeyState((Key) ((int) direction << 1), KeyInputCurrent))
        tri = -1;
    return tri;
}