#include "focusmanager.h"

FocusManager::FocusManager(DisplayableContainer* container)
{
    this->form = nullptr;
    this->showFocusIndicator = false;
}

FocusManager::~FocusManager()
{
    throw; //TODO
}

int FocusManager::getNextTabIndex()
{
    throw; //TODO
}

void FocusManager::activate()
{
    throw; //TODO
}

void FocusManager::deactivate()
{
    throw; //TODO
}

Interactive *FocusManager::findFocusManagerComponent(Interactive *component)
{
    throw; //TODO
}

Interactive *FocusManager::getFocus()
{
    throw; //TODO
}

Interactive *FocusManager::getNextFocusManagerComponent(bool backward)
{
    throw; //TODO
}

void FocusManager::hideFocus()
{
    throw; //TODO
}

void FocusManager::setFocus(Interactive *o)
{
    throw; //TODO
}

void FocusManager::showFocus()
{
    throw; //TODO
}
