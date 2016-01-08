#ifndef EVENTPROCESSER_H
#define EVENTPROCESSER_H

#include "object.h"
#include "events/windowevent.h"
#include "events/maindispatcher.h"
#include "events/mouseevent.h"
#include "events/keyboardevent.h"

class IASPP_PUBLIC EventProcesser : public Object
{
public:
    static EventProcesser *Instance();
    virtual ~EventProcesser();

    bool processEvents();
private:
    EventProcesser();
    //escondendo coisas que não devem ser usadas \o/
    EventProcesser(EventProcesser const&){}
    EventProcesser operator=(EventProcesser const&){}

    static EventProcesser* instance;

    SDL_Event event;

    void processWindowEvents(const SDL_Event* evt);

    void dispatchKeyEvent(const SDL_Event *e);
    void dispatchMouseMoveEvent(const SDL_Event *e);
    void dispatchMouseButtonEvent(const SDL_Event *e);
    void dispatchMouseWheelEvent(const SDL_Event *e);

    Uint32 lastMouseDown;
    Uint32 lastMouseMiddleDown;
    Uint32 lastMouseRightDown;
    int clickCount = 0;

    const Uint32 diff = 400;
};

#endif // EVENTPROCESSER_H
