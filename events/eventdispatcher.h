#ifndef EVENTDISPATCHER_H
#define EVENTDISPATCHER_H

#include <vector>
#include <map>

#include "iaspp_global.h"
#include "object.h"
#include "ieventdispatcher.h"

class IASPP_PUBLIC EventDispatcher : public Object, IEventDispatcher
{
public:
    EventDispatcher(IEventDispatcher *target = nullptr);
    virtual ~EventDispatcher();
    virtual void addEventListener(const std::string &type, Object* obj, functionPointer l, int priority = 0) override final;
    virtual bool dispatchEvent(Event* event) override final;
    virtual bool hasEventListener(const std::string &type) override final;
    virtual void removeEventListener(const std::string &type, Object* obj, functionPointer l, bool removeAll=false) override final;

private:
    IEventDispatcher* target = nullptr;
    nameMap* internalMap;
};

#endif // EVENTDISPATCHER_H
