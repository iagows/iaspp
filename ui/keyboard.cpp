#include "keyboard.h"

bool Keyboard::capsLock()
{
    return (SDL_GetModState() & KMOD_CAPS) == KMOD_CAPS;
}

bool Keyboard::numLock()
{
    return (SDL_GetModState() & KMOD_NUM) == KMOD_NUM;
}

const std::string Keyboard::getNameFromKey(size_t key)
{
    return SDL_GetKeyName(key);
}

const size_t Keyboard::getKeyFromName(std::string name)
{
    return SDL_GetKeyFromName(name.c_str());
}

Keyboard::Keyboard()
{
}

const size_t Keyboard::A=SDLK_a;
const size_t Keyboard::B=SDLK_b;
const size_t Keyboard::BACKQUOTE=SDLK_BACKQUOTE;
const size_t Keyboard::BACKSLASH=SDLK_BACKSLASH;
const size_t Keyboard::BACKSPACE=SDLK_BACKSPACE;
const size_t Keyboard::C = SDLK_c;
const size_t Keyboard::CAPS_LOCK = SDLK_CAPSLOCK;
const size_t Keyboard::COMMA = SDLK_COMMA;
const size_t Keyboard::D = SDLK_d;
const size_t Keyboard::DELETE_K = SDLK_DELETE;
const size_t Keyboard::DOWN = SDLK_DOWN;
const size_t Keyboard::E = SDLK_e;
const size_t Keyboard::END = SDLK_END;
const size_t Keyboard::ENTER= SDLK_RETURN;
const size_t Keyboard::EQUAL = SDLK_EQUALS;
const size_t Keyboard::ESCAPE = SDLK_ESCAPE;
const size_t Keyboard::F = SDLK_f;
const size_t Keyboard::F1 = SDLK_F1;
const size_t Keyboard::F10 = SDLK_F10;
const size_t Keyboard::F11 = SDLK_F11;
const size_t Keyboard::F12 = SDLK_F12;
const size_t Keyboard::F13 = SDLK_F13;
const size_t Keyboard::F14 = SDLK_F14;
const size_t Keyboard::F15 = SDLK_F15;
const size_t Keyboard::F16 = SDLK_F16;
const size_t Keyboard::F17 = SDLK_F17;
const size_t Keyboard::F18 = SDLK_F18;
const size_t Keyboard::F19 = SDLK_F19;
const size_t Keyboard::F2 = SDLK_F2;
const size_t Keyboard::F20 = SDLK_F20;
const size_t Keyboard::F21 = SDLK_F21;
const size_t Keyboard::F22 = SDLK_F22;
const size_t Keyboard::F23 = SDLK_F23;
const size_t Keyboard::F24 = SDLK_F24;
const size_t Keyboard::F3 = SDLK_F3;
const size_t Keyboard::F4 = SDLK_F4;
const size_t Keyboard::F5 = SDLK_F5;
const size_t Keyboard::F6 = SDLK_F6;
const size_t Keyboard::F7 = SDLK_F7;
const size_t Keyboard::F8 = SDLK_F8;
const size_t Keyboard::F9 = SDLK_F9;
const size_t Keyboard::G = SDLK_g;
const size_t Keyboard::H = SDLK_h;
const size_t Keyboard::HOME = SDLK_HOME;
const size_t Keyboard::I = SDLK_i;
const size_t Keyboard::INSERT = SDLK_INSERT;
const size_t Keyboard::J = SDLK_j;
const size_t Keyboard::K = SDLK_k;
const size_t Keyboard::L = SDLK_l;
const size_t Keyboard::LEFT = SDLK_LEFT;
const size_t Keyboard::LEFT_BRACKET = SDLK_LEFTBRACKET;
const size_t Keyboard::M = SDLK_m;
const size_t Keyboard::MINUS = SDLK_MINUS;
const size_t Keyboard::N = SDLK_n;
const size_t Keyboard::NUMBER_0 = SDLK_0;
const size_t Keyboard::NUMBER_1 = SDLK_1;
const size_t Keyboard::NUMBER_2 = SDLK_2;
const size_t Keyboard::NUMBER_3 = SDLK_3;
const size_t Keyboard::NUMBER_4 = SDLK_4;
const size_t Keyboard::NUMBER_5 = SDLK_5;
const size_t Keyboard::NUMBER_6 = SDLK_6;
const size_t Keyboard::NUMBER_7 = SDLK_7;
const size_t Keyboard::NUMBER_8 = SDLK_8;
const size_t Keyboard::NUMBER_9 = SDLK_9;
const size_t Keyboard::NUMPAD_0 = SDLK_KP_0;
const size_t Keyboard::NUMPAD_1 = SDLK_KP_1;
const size_t Keyboard::NUMPAD_2 = SDLK_KP_2;
const size_t Keyboard::NUMPAD_3 = SDLK_KP_3;
const size_t Keyboard::NUMPAD_4 = SDLK_KP_4;
const size_t Keyboard::NUMPAD_5 = SDLK_KP_5;
const size_t Keyboard::NUMPAD_6 = SDLK_KP_6;
const size_t Keyboard::NUMPAD_7 = SDLK_KP_7;
const size_t Keyboard::NUMPAD_8 = SDLK_KP_8;
const size_t Keyboard::NUMPAD_9 = SDLK_KP_9;
const size_t Keyboard::NUMPAD_ADD = SDLK_KP_PLUS;
const size_t Keyboard::NUMPAD_DECIMAL = SDLK_KP_DECIMAL;
const size_t Keyboard::NUMPAD_DIVIDE = SDLK_KP_DIVIDE;
const size_t Keyboard::NUMPAD_ENTER = SDLK_RETURN2;
const size_t Keyboard::NUMPAD_MULTIPLY = SDLK_KP_MULTIPLY;
const size_t Keyboard::NUMPAD_SUBTRACT = SDLK_KP_MINUS;
const size_t Keyboard::O = SDLK_o;
const size_t Keyboard::P = SDLK_p;
const size_t Keyboard::PAGE_DOWN = SDLK_PAGEDOWN;
const size_t Keyboard::PAGE_UP = SDLK_PAGEUP;
const size_t Keyboard::PERIOD = SDLK_PERIOD;
const size_t Keyboard::Q = SDLK_q;
const size_t Keyboard::QUOTE = SDLK_QUOTE;
const size_t Keyboard::R = SDLK_r;
const size_t Keyboard::RIGHT = SDLK_RIGHT;
const size_t Keyboard::RIGHT_BRACKET = SDLK_RIGHTBRACKET;
const size_t Keyboard::S = SDLK_s;
const size_t Keyboard::SEMICOLON = SDLK_SEMICOLON;
const size_t Keyboard::LSHIFT = SDLK_LSHIFT;
const size_t Keyboard::RSHIFT = SDLK_RSHIFT;
const size_t Keyboard::SLASH = SDLK_SLASH;
const size_t Keyboard::SPACE = SDLK_SPACE;
const size_t Keyboard::T = SDLK_t;
const size_t Keyboard::TAB = SDLK_TAB;
const size_t Keyboard::U = SDLK_u;
const size_t Keyboard::UP = SDLK_UP;
const size_t Keyboard::V = SDLK_v;
const size_t Keyboard::W = SDLK_w;
const size_t Keyboard::X = SDLK_x;
const size_t Keyboard::Y = SDLK_y;
const size_t Keyboard::Z = SDLK_z;
