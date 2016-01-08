#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "object.h"

//https://wiki.libsdl.org/SDL_Keycode

class IASPP_PUBLIC Keyboard : public Object
{
public:
    static bool capsLock();
    static bool numLock();
    static const std::string getNameFromKey(size_t key);
    static const size_t getKeyFromName(std::string name);
    static const size_t A;
    static const size_t B;
    static const size_t BACKQUOTE;
    static const size_t BACKSLASH;
    static const size_t BACKSPACE;
    static const size_t C;
    static const size_t CAPS_LOCK;
    static const size_t COMMA;
    static const size_t D;
    static const size_t DELETE_K;
    static const size_t DOWN;
    static const size_t E;
    static const size_t END;
    static const size_t ENTER;
    static const size_t EQUAL;
    static const size_t ESCAPE;
    static const size_t F;
    static const size_t F1;
    static const size_t F10;
    static const size_t F11;
    static const size_t F12;
    static const size_t F13;
    static const size_t F14;
    static const size_t F15;
    static const size_t F16;
    static const size_t F17;
    static const size_t F18;
    static const size_t F19;
    static const size_t F2;
    static const size_t F20;
    static const size_t F21;
    static const size_t F22;
    static const size_t F23;
    static const size_t F24;
    static const size_t F3;
    static const size_t F4;
    static const size_t F5;
    static const size_t F6;
    static const size_t F7;
    static const size_t F8;
    static const size_t F9;
    static const size_t G;
    static const size_t H;
    static const size_t HOME;
    static const size_t I;
    static const size_t INSERT;
    static const size_t J;
    static const size_t K;
    static const size_t L;
    static const size_t LEFT;
    static const size_t LEFT_BRACKET;
    static const size_t M;
    static const size_t MINUS;
    static const size_t N;
    static const size_t NUMBER_0;
    static const size_t NUMBER_1;
    static const size_t NUMBER_2;
    static const size_t NUMBER_3;
    static const size_t NUMBER_4;
    static const size_t NUMBER_5;
    static const size_t NUMBER_6;
    static const size_t NUMBER_7;
    static const size_t NUMBER_8;
    static const size_t NUMBER_9;
    static const size_t NUMPAD_0;
    static const size_t NUMPAD_1;
    static const size_t NUMPAD_2;
    static const size_t NUMPAD_3;
    static const size_t NUMPAD_4;
    static const size_t NUMPAD_5;
    static const size_t NUMPAD_6;
    static const size_t NUMPAD_7;
    static const size_t NUMPAD_8;
    static const size_t NUMPAD_9;
    static const size_t NUMPAD_ADD;
    static const size_t NUMPAD_DECIMAL;
    static const size_t NUMPAD_DIVIDE;
    static const size_t NUMPAD_ENTER;
    static const size_t NUMPAD_MULTIPLY;
    static const size_t NUMPAD_SUBTRACT;
    static const size_t O;
    static const size_t P;
    static const size_t PAGE_DOWN;
    static const size_t PAGE_UP;
    static const size_t PERIOD;
    static const size_t Q;
    static const size_t QUOTE;
    static const size_t R;
    static const size_t RIGHT;
    static const size_t RIGHT_BRACKET;
    static const size_t S;
    static const size_t SEMICOLON;
    static const size_t LSHIFT;
    static const size_t RSHIFT;
    static const size_t SLASH;
    static const size_t SPACE;
    static const size_t T;
    static const size_t TAB;
    static const size_t U;
    static const size_t UP;
    static const size_t V;
    static const size_t W;
    static const size_t X;
    static const size_t Y;
    static const size_t Z;
private:
    Keyboard();

};

#endif // KEYBOARD_H
