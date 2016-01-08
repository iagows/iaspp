#include "uicomponent.h"

UIComponent::UIComponent():Sprite()
{

}

UIComponent::~UIComponent()
{

}

bool UIComponent::isEnabled()
{
    return this->enabled;
}

void UIComponent::setEnabled(bool e)
{
    this->enabled = e;
}

void UIComponent::clearStyle(std::string style)
{
    aspp_throw("TO DO");
    throw;
}

void UIComponent::drawFocus(bool focused)
{
    aspp_throw("TO DO");
    throw;
}

Interactive *UIComponent::getFocus()
{
    aspp_throw("TO DO");
    throw;
}

Object *UIComponent::getStyle()
{
    aspp_throw("TO DO");
    throw;
}

Object *UIComponent::getStyleDefinition()
{
    aspp_throw("TO DO");
    throw;
}

void UIComponent::invalidate(std::string property, bool callLater)
{
    aspp_throw("TO DO");
    throw;
}

void UIComponent::move(int x, int y)
{
    this->x +=x;
    this->y +=y;
}

void UIComponent::setFocus()
{
    aspp_throw("TO DO");
    throw;
}

void UIComponent::setSize(int w, int h)
{
    this->setWidth(w);
    this->setHeight(h);
}

void UIComponent::setStyle(Object *value)
{
    (void)value;
    aspp_throw("TO DO");
    throw;
}

Object *UIComponent::getStyleValue(std::string name)
{
    aspp_throw("TO DO");
    throw;
}
