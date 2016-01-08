#include "componentevent.h"

ComponentEvent::ComponentEvent(std::string type, bool bubbles, bool cancelable)
    :Event(type, bubbles, cancelable)
{

}

ComponentEvent::~ComponentEvent()
{

}

Event *ComponentEvent::clone()
{
    ComponentEvent* ce = new ComponentEvent(this->_type, this->_bubbles, this->_cancelable);

    return static_cast<Event*>(ce);
}

std::string ComponentEvent::toString()
{
    std::string out = "[ComponentEvent type=";
    out += _type;
    out += " bubbles=";
    out += aspp::to_string(_bubbles);
    out += " cancelable=";
    out += aspp::to_string(_cancelable);
    out += "]";
}

const std::string ComponentEvent::BUTTON_DOWN = "buttonDown";
const std::string ComponentEvent::ENTER = "enter";
const std::string ComponentEvent::HIDE = "hide";
const std::string ComponentEvent::LABEL_CHANGE = "labelChange";
const std::string ComponentEvent::MOVE = "move";
const std::string ComponentEvent::RESIZE = "resize";
const std::string ComponentEvent::SHOW = "show";
