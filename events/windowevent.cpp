#include "windowevent.h"

WindowEvent::WindowEvent(std::string type, bool bubbles, bool cancelable, int windowId, Vector2D *to)
    :Event(type, bubbles, cancelable)
{
    this->windowId = windowId;
    this->to = to;
}

WindowEvent::~WindowEvent()
{
    delete this->to;
}

Event *WindowEvent::clone()
{
    WindowEvent* we = new WindowEvent(_type, _bubbles, _cancelable, windowId, to->clone());
    return dynamic_cast<Event*>(we);
}

std::string WindowEvent::toString()
{
    std::string out = "[Event type=";
    out += _type;
    out += " bubbles=";
    out += aspp::to_string(_bubbles);
    out += " cancelable=";
    out += aspp::to_string(_cancelable);
    out += " windowId=";
    out += std::to_string(this->windowId);
    out += " to=";
    out += this->to->toString();
    out += "]";

    return out;
}

const std::string WindowEvent::SHOWN = "windowShown";
const std::string WindowEvent::HIDDEN = "windowHidden";
const std::string WindowEvent::EXPOSED = "windowExposed";
const std::string WindowEvent::MOVED = "windowMoved";
const std::string WindowEvent::RESIZED = "windowResized";
const std::string WindowEvent::MINIMIZED = "windowMinimized";
const std::string WindowEvent::MAXIMIZED = "windowMaximized";
const std::string WindowEvent::RESTORED = "windowRestored";
const std::string WindowEvent::ENTER = "windowEnter";
const std::string WindowEvent::LEAVE = "windowLeave";
const std::string WindowEvent::FOCUS_GAINED = "windowFocusGained";
const std::string WindowEvent::FOCUS_LOST = "windowFocusLost";
const std::string WindowEvent::CLOSE = "windowClose";
