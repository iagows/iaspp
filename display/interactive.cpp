#include "interactive.h"

Interactive::Interactive():Displayable()
{
    this->contextMenu = nullptr;
    this->doubleClickEnabled = false;
    this->focusRect = false;
    this->mouseEnabled = true;
    this->tabEnabled = true;
    this->tabIndex = -1;
}

Interactive::~Interactive()
{
    delete this->contextMenu;
}
