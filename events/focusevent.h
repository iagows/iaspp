#ifndef FOCUSEVENT_H
#define FOCUSEVENT_H

#include "events/event.h"
#include "display/interactive.h"

class IASPP_PUBLIC FocusEvent : public Event
{
public:
    FocusEvent(std::string type, bool bubbles = true,
               bool cancelable = false, Interactive* relatedObject = nullptr,
               bool shiftKey = false, size_t keyCode = 0, std::string direction = "none");
    ~FocusEvent();

    std::string direction;
    bool isRelatedObjectInaccessible;
    size_t keyCode;
    Interactive* relatedObject;
    bool shiftKey;

    virtual Event* clone() override;
    virtual std::string toString() override;

    const static std::string FOCUS_IN;
    const static std::string FOCUS_OUT;
    const static std::string KEY_FOCUS_CHANGE;
    const static std::string MOUSE_FOCUS_CHANGE;
};

#endif // FOCUSEVENT_H
