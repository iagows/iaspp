#include "textevent.h"

TextEvent::TextEvent(std::string type, bool bubbles, bool cancelable, std::string text)
    :Event(type, bubbles, cancelable)
{
    this->text = text;
}

TextEvent::~TextEvent()
{

}

Event *TextEvent::clone()
{
    TextEvent* evt = new TextEvent(this->_type, this->_bubbles, this->_bubbles, this->text);
    return dynamic_cast<Event*>(evt);
}

std::string TextEvent::toString()
{
    std::string out = "[TextEvent type=";
    out += _type;
    out += " bubbles=";
    out += aspp::to_string(_bubbles);
    out += " cancelable=";
    out += aspp::to_string(_cancelable);
    out += " text=";
    out += this->text;
    out += "]";

    return out;
}

const std::string TextEvent::LINK = "link";
const std::string TextEvent::TEXT_INPUT = "textInput";
