#ifndef COMPONENTEVENT_H
#define COMPONENTEVENT_H

#include "events/event.h"

class IASPP_PUBLIC ComponentEvent : public Event
{
public:
    ComponentEvent(std::string type, bool bubbles = false, bool cancelable = false);
    virtual ~ComponentEvent();

    virtual Event* clone() override;
    virtual std::string toString() override;

    const static std::string BUTTON_DOWN;
    const static std::string ENTER;
    const static std::string HIDE;
    const static std::string LABEL_CHANGE;
    const static std::string MOVE;
    const static std::string RESIZE;
    const static std::string SHOW;
};

#endif // COMPONENTEVENT_H
