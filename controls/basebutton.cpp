#include "basebutton.h"

BaseButton::BaseButton():UIComponent()
{
    this->enabled = true;

    this->autoRepeat = false;
    this->selected = false;
}

BaseButton::~BaseButton()
{

}

void BaseButton::setEnabled(bool e)
{
    UIComponent::setEnabled(e);
}

bool BaseButton::isSelected()
{
    return this->selected;
}

void BaseButton::setSelected(bool s)
{
    this->selected = s;
}

void BaseButton::setMouseState(std::string state)
{
    aspp_throw("TO DO");
    throw; //TODO : up, down, over
}

Object *BaseButton::getStyleDefinition()
{
    aspp_throw("TO DO");
    throw; //TODO
}
