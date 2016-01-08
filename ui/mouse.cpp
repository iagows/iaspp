#include "mouse.h"

Mouse *Mouse::Instance()
{
    if(instance== nullptr)
        instance = new Mouse();

    return instance;
}

Mouse::~Mouse()
{
    delete instance;
}

bool Mouse::setCursor(Mouse::CursorType ct)
{
    cursor = ct;
    SDL_Cursor* cur;
    switch (cursor)
    {
    case CursorType::ARROW:
    case CursorType::AUTO:
    default:
        cur = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_ARROW);
        break;
    case CursorType::BUTTON:
        //TODO fix this
        //cur = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
        break;
    case CursorType::HAND:
        cur = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_HAND);
        break;
    case CursorType::IBEAM:
        cur = SDL_CreateSystemCursor(SDL_SYSTEM_CURSOR_IBEAM);
        break;
    }
    SDL_SetCursor(cur);
}

bool Mouse::supportsCursor()
{
    return supports;
}

bool Mouse::supportsNativeCursor()
{
    return supportsNative;
}

void Mouse::hide()
{
    SDL_ShowCursor(SDL_DISABLE);
}

void Mouse::registerCursor(std::string name, MouseCursorData *cursor)
{
    aspp_throw("TO DO");
    throw; //TODO everything
}

void Mouse::show()
{
    SDL_ShowCursor(SDL_ENABLE);
}

void Mouse::unregisterCursor(std::string name)
{
    aspp_throw("TO DO");
    throw; //TODO everything
}

Mouse::Mouse()
{
    supports = true;
}

Mouse::CursorType Mouse::cursor = Mouse::CursorType::AUTO;
Mouse* Mouse::instance = nullptr;
bool Mouse::supports = true;
bool Mouse::supportsNative = true;
