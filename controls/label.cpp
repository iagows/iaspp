#include "label.h"

Label::Label():UIComponent()
{

}

Label::~Label()
{
    delete this->textField;
}

int Label::getHeight()
{
    return UIComponent::getHeight();//TODO check this
}

void Label::setHeight(int h)
{
    //lançar evento RESIZE
    UIComponent::setHeight(h);
    Event *e = new Event(Event::RESIZE);
    dispatchEvent(e);
}

std::string Label::getText()
{
    return this->textField->getText();
}

void Label::setText(std::string t)
{
    this->textField->setText(t);
}

TextField *Label::getTextField()
{
    return this->textField;
}

void Label::setTextField(TextField *tf)
{
    delete this->textField;

    this->textField = tf;
}

int Label::getWidth()
{
    return UIComponent::getWidth();//TODO check this
}

void Label::setWidth(int w)
{
    UIComponent::setWidth(w);
    Event *e = new Event(Event::RESIZE);
    dispatchEvent(e);
}

Object *Label::getStyleDefinition()
{
    aspp_throw("TO DO");
    throw; //TODO everything
}

std::string Label::toString()
{
    std::string str = "[Label]";
    return str;
}

void Label::createChildren()
{
    this->textField = new TextField();
    this->textField->setRenderer(this->renderer);
    this->addChild(this->textField);
}
