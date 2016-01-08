#ifndef TEXTEVENT_H
#define TEXTEVENT_H

#include "events/event.h"

class IASPP_PUBLIC TextEvent : public Event
{
public:
    TextEvent(std::string type, bool bubbles = false, bool cancelable = false, std::string text = "");
    virtual ~TextEvent();

    virtual Event* clone() override;
    virtual std::string toString() override;

    std::string text;

    static const std::string LINK;
    static const std::string TEXT_INPUT;
};

#endif // TEXTEVENT_H
