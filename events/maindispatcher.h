#ifndef MAINDISPATCHER_H
#define MAINDISPATCHER_H

#include "events/eventdispatcher.h"

class IASPP_PUBLIC MainDispatcher: public EventDispatcher
{
public:
    static MainDispatcher *Instance();
    virtual ~MainDispatcher();
private:
    MainDispatcher();
    //hiding things that should not be seen \o/
    MainDispatcher(MainDispatcher const&){}
    MainDispatcher operator=(MainDispatcher const&){}

    static MainDispatcher* instance;
};

#endif // MAINDISPATCHER_H
