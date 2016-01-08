#include "event.h"

Event::Event(std::string type, bool bubbles, bool cancelable):Object()
{
    this->_type = type;
    this->_bubbles = bubbles;
    this->_cancelable = cancelable;
}

Event::~Event()
{

}

bool Event::bubbles()
{
    return this->bubbles();
}

bool Event::cancelable()
{
    return this->_cancelable;
}

Object *Event::currentTarget()
{
    return this->_currentTarget;
}

size_t Event::eventPhase()
{
    return this->_eventPhase;
}

void Event::setTarget(Object *target)
{
    this->_target = target;
}

Object *Event::getTarget()
{
    return this->_target;
}

std::string Event::type()
{
    return this->_type;
}

Event *Event::clone()
{
    return new Event(this->_type, this->_bubbles, this->_cancelable);;
}

bool Event::isDefaultPrevented()
{

}

void Event::preventDefault()
{

}

void Event::stopImmediatePropagation()
{

}

void Event::stopPropagation()
{

}

std::string Event::toString()
{
    std::string out = "[Event type=";
    out += _type;
    out += " bubbles=";
    out += aspp::to_string(_bubbles);
    out += " cancelable=";
    out += aspp::to_string(_cancelable);
    out += "]";
    return out;
}

const std::string Event::ACTIVATE = "activate";
const std::string Event::ADDED = "added";
const std::string Event::ADDED_TO_STAGE = "addedToStage";
const std::string Event::CANCEL = "cancel";
const std::string Event::CHANGE = "change";
const std::string Event::CLEAR = "clear";
const std::string Event::CLOSE = "close";
const std::string Event::CLOSING = "closing";
const std::string Event::COPY = "copy";
const std::string Event::CUT = "cut";
const std::string Event::DEACTIVATE = "deactivate";
const std::string Event::ENTER_FRAME = "enterFrame";
const std::string Event::EXIT_FRAME = "exitFrame";
const std::string Event::FRAME_CONSTRUCTED = "frameConstructed";
const std::string Event::FULLSCREEN = "fullScreen";
const std::string Event::INIT = "init";
const std::string Event::MOUSE_LEAVE = "mouseLeave";
const std::string Event::OPEN = "open";
const std::string Event::PASTE = "paste";
const std::string Event::REMOVED = "removed";
const std::string Event::REMOVED_FROM_STAGE = "removedFromStage";
const std::string Event::RENDER = "render";
const std::string Event::RESIZE = "resize";
const std::string Event::SUSPEND = "suspend";
const std::string Event::TAB_CHILDREN_CHANGE = "tabChildrenChange";
const std::string Event::TAB_ENABLED_CHANGE = "tabEnabledChange";
const std::string Event::TAB_INDEX_CHANGE = "tabIndexChange";
const std::string Event::USER_IDLE = "userIdle";
const std::string Event::USER_PRESENT = "userPresent";
