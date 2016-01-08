#include "mouseevent.h"

MouseEvent::MouseEvent(std::string type, bool bubbles, bool cancelable, int localX, int localY, int movementX, int movementY,
                       Interactive *relatedObject, bool ctrlKey, bool altKey, bool shiftKey,
                       bool buttonDown, int delta, int clickCount)
    :Event(type, bubbles, cancelable)
{
    this->localX = localX;
    this->localY = localY;
    this->relatedObject = relatedObject;
    this->ctrlKey = ctrlKey;
    this->altKey = altKey;
    this->shiftKey = shiftKey;
    this->buttonDownPrimary = buttonDown;
    this->delta = delta;
    this->clickCount = clickCount;
    this->movementX = movementX;
    this->movementY = movementY;
}

MouseEvent::~MouseEvent()
{

}

int MouseEvent::getClickCount()
{
    return this->clickCount;
}

Event *MouseEvent::clone()
{
    MouseEvent* me = new MouseEvent(_type, _bubbles, _cancelable, localX, localY, movementX,
                                    movementY, relatedObject, ctrlKey, altKey, shiftKey,
                                    buttonDownPrimary, delta, clickCount);

    return static_cast<Event*>(me);
}

std::string MouseEvent::toString()
{
    std::string out = "[MouseEvent type=";
    out += _type;
    out += " bubbles=";
    out += aspp::to_string(_bubbles);
    out += " cancelable=";
    out += aspp::to_string(_cancelable);
    out += " localX=";
    out += std::to_string(localX);
    out += " localY=";
    out += std::to_string(localY);
    out += " movementX=";
    out += std::to_string(movementX);
    out += " movementY=";
    out += std::to_string(movementY);
    out += " relatedObject=";
    out += relatedObject->toString();
    out += " ctrlKey=";
    out += aspp::to_string(ctrlKey);
    out += " altKey=";
    out += aspp::to_string(altKey);
    out += " shiftKey=";
    out += aspp::to_string(shiftKey);
    out += " buttonDownPrimary=";
    out += aspp::to_string(buttonDownPrimary);
    out += " delta=";
    out += std::to_string(delta);
    out += "clickCount=";
    out += std::to_string(clickCount);
    out += "]";

    return out;
}

const std::string MouseEvent::CLICK = "click";
const std::string MouseEvent::CONTEXT_MENU = "contextMenu";
const std::string MouseEvent::DOUBLE_CLICK_ = "doubleClick";
const std::string MouseEvent::MIDDLE_CLICK = "middleClick";
const std::string MouseEvent::MIDDLE_MOUSE_DOWN = "middleMousedown";
const std::string MouseEvent::MIDDLE_MOUSE_UP = "middleMouseUp";
const std::string MouseEvent::MOUSE_DOWN = "mouseDown";
const std::string MouseEvent::MOUSE_MOVE = "mouseMove";
const std::string MouseEvent::MOUSE_OUT = "mouseOut";
const std::string MouseEvent::MOUSE_OVER = "mouseOver";
const std::string MouseEvent::MOUSE_UP = "mouseUp";
const std::string MouseEvent::MOUSE_WHEEL = "mouseWheel";
const std::string MouseEvent::RIGHT_CLICK = "rightClick";
const std::string MouseEvent::RIGHT_MOUSE_DOWN = "rightMouseDown";
const std::string MouseEvent::RIGHT_MOUSE_UP = "rightMouseUp";
const std::string MouseEvent::ROLL_OUT = "rollOut";
const std::string MouseEvent::ROLL_OVER = "rollOver";
