#ifndef MOUSEEVENT_H
#define MOUSEEVENT_H

#include "events/event.h"
#include "display/interactive.h"
class IASPP_PUBLIC MouseEvent : public Event
{
public:
    MouseEvent(std::string type, bool bubbles = true, bool cancelable = false,
               int localX = -1, int localY = -1, int movementX = -1, int movementY= -1,
               Interactive* relatedObject = nullptr, bool ctrlKey = false,
               bool altKey = false, bool shiftKey = false, bool buttonDown = false,
               int delta = 0, int clickCount = 0);
    virtual ~MouseEvent();

    bool altKey;
    bool buttonDownPrimary;
    int getClickCount();
    bool ctrlKey;
    int delta; //linhas por giro da roda do mouse
    //lock false
    int localX;
    int localY;
    //lock true
    int movementX;
    int movementY;
    Interactive* relatedObject;
    bool shiftKey;
    int stageX;
    int stageY;

    virtual Event* clone() override;
    virtual std::string toString() override;

    const static std::string CLICK;
    const static std::string CONTEXT_MENU;
    const static std::string DOUBLE_CLICK_;
    const static std::string MIDDLE_CLICK;
    const static std::string MIDDLE_MOUSE_DOWN;
    const static std::string MIDDLE_MOUSE_UP;
    const static std::string MOUSE_DOWN;
    const static std::string MOUSE_MOVE;
    const static std::string MOUSE_OUT;
    const static std::string MOUSE_OVER;
    const static std::string MOUSE_UP;
    const static std::string MOUSE_WHEEL;
    const static std::string RIGHT_CLICK;
    const static std::string RIGHT_MOUSE_DOWN;
    const static std::string RIGHT_MOUSE_UP;
    const static std::string ROLL_OUT;
    const static std::string ROLL_OVER;
protected:
    int clickCount;
};

#endif // MOUSEEVENT_H
