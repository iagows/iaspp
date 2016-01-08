#ifndef KEYBOARDEVENT_H
#define KEYBOARDEVENT_H

#include "events/event.h"
class IASPP_PUBLIC KeyboardEvent : public Event
{
public:
    KeyboardEvent(std::string type, bool bubbles=true, bool cancelable=false, char charCodeValue=0,
                  size_t keyCodeValue=0, bool ctrlKeyValue=false,
                  bool altKeyValue=false, bool shiftKeyValue=false);
    virtual ~KeyboardEvent();

    bool altKey;
    char charCode;
    bool ctrlKey;
    size_t keyCode;
    //size_t keyLocation();
    bool shiftKey;

    virtual Event* clone() override;
    virtual std::string toString() override;

    static const std::string KEY_DOWN;
    static const std::string KEY_UP;
};

#endif // KEYBOARDEVENT_H
