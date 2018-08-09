class Input {
private:
    typedef unsigned int KeyInput;
public:
    typedef int Tribool;
    enum class Key
    {
        A      = 0b1,
        B      = 0b10,
        Select = 0b100,
        Start  = 0b1000,
        Right  = 0b10000,
        Left   = 0b100000,
        Up     = 0b1000000,
        Down   = 0b10000000,
        R      = 0b100000000,
        L      = 0b1000000000
    };
    enum class Direction
    {
        Vertical = (int) Key::Up,
        Horizontal = (int) Key::Right
    };
private:
    volatile static KeyInput * const KeyInputRegister;
private:
    static KeyInput KeyInputCurrent;
    static KeyInput KeyInputPrevious;
private:
    static bool GetKeyState(Key key, KeyInput keyInput);
public:
    static void KeyUpdate();
    static bool GetKeyDown(Key key);
    static bool GetKeyUp(Key key);
    static bool GetKeyHeld(Key key);
    static Tribool GetTribool(Direction direction);
};