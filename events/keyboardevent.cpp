#include "keyboardevent.h"

KeyboardEvent::KeyboardEvent(std::string type, bool bubbles, bool cancelable, char charCodeValue,
                             size_t keyCodeValue, /*size_t keyLocationValue,*/ bool ctrlKeyValue,
                             bool altKeyValue, bool shiftKeyValue)
    :Event(type, bubbles, cancelable)
{
    this->charCode = charCodeValue;
    this->keyCode = keyCodeValue;
    this->ctrlKey = ctrlKeyValue;
    this->altKey = altKeyValue;
    this->shiftKey = shiftKeyValue;
}

KeyboardEvent::~KeyboardEvent()
{
    //do nothing
}

Event *KeyboardEvent::clone()
{
    KeyboardEvent* ke = new KeyboardEvent(_type, _bubbles, _cancelable, charCode, keyCode, ctrlKey, altKey, shiftKey);
    return static_cast<Event*>(ke);
}

std::string KeyboardEvent::toString()
{
    std::string out = "[KeyboardEvent type=";
    out += _type;
    out += " bubbles=";
    out += aspp::to_string(_bubbles);
    out += " cancelable=";
    out += aspp::to_string(_cancelable);
    out += " charCodeValue=";
    out += std::to_string(charCode);
    out += "]";
    return out;
}

const std::string KeyboardEvent::KEY_DOWN = "keyDown";
const std::string KeyboardEvent::KEY_UP = "keyUp";
