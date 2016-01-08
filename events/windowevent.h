#ifndef WINDOWEVENT_H
#define WINDOWEVENT_H

#include "events/event.h"
#include "geometry/vector2d.h"
class WindowEvent : public Event
{
public:
    WindowEvent(std::string type, bool bubbles = false, bool cancelable = false,
                int windowId = -1, Vector2D* to = nullptr);
    virtual ~WindowEvent();

    int windowId;
    Vector2D* to;

    virtual Event* clone();
    virtual std::string toString();

    const static std::string SHOWN;
    const static std::string HIDDEN;
    const static std::string EXPOSED;
    const static std::string MOVED;
    const static std::string RESIZED;
    const static std::string MINIMIZED;
    const static std::string MAXIMIZED;
    const static std::string RESTORED;
    const static std::string ENTER;
    const static std::string LEAVE;
    const static std::string FOCUS_GAINED;
    const static std::string FOCUS_LOST;
    const static std::string CLOSE;

};

#endif // WINDOWEVENT_H
