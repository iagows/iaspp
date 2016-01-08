#include "focusevent.h"

FocusEvent::FocusEvent(std::string type, bool bubbles, bool cancelable,
                       Interactive *relatedObject, bool shiftKey, size_t keyCode,
                       std::string direction):Event(type, bubbles, cancelable)
{
    this->relatedObject = relatedObject;
    this->shiftKey = shiftKey;
    this->keyCode = keyCode;
    this->direction = direction;

    //no sandbox, baby
    this->isRelatedObjectInaccessible = false;
}

FocusEvent::~FocusEvent()
{
    //don't delete relatedObject, you animal!
}

Event *FocusEvent::clone()
{
    FocusEvent* fe = new FocusEvent(_type, _bubbles, _cancelable, relatedObject, shiftKey, keyCode, direction);

    return static_cast<Event*>(fe);
}

std::string FocusEvent::toString()
{
    std::string out = "[FocusEvent type=";
    out += this->_type;
    out += " bubbles=";
    out += aspp::to_string(this->_bubbles);
    out += " cancelable=";
    out += aspp::to_string(this->_cancelable);
    out += " relatedObject=";
    out += this->relatedObject->toString();
    out += " keyCode=";
    out += std::to_string(this->keyCode);
    out += "]";
    return out;
}

const std::string FocusEvent::FOCUS_IN = "focusIn";
const std::string FocusEvent::FOCUS_OUT = "focusOut";
const std::string FocusEvent::KEY_FOCUS_CHANGE = "keyFocusChange";
const std::string FocusEvent::MOUSE_FOCUS_CHANGE = "mouseFocusChange";
