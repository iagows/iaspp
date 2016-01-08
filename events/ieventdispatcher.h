#ifndef IEVENTDISPATCHER_H
#define IEVENTDISPATCHER_H

#include "iaspp_global.h"
#include "event.h"
#include "util/callback.h"
#include <map>
#include <vector>
#include <tuple>

//'functionPointer' para funções do tipo: void nome(Event*);
using functionPointer = void(*)(Event*, Object*);
//'objectFunctionTuple' para tuplas de objetos e as funções
using objectFunctionTuple = std::tuple<Object*, functionPointer>;
//'tuplesVector' para vetores de tuplas
using tuplesVector = std::vector<objectFunctionTuple*>;
//'priorityMap' para mapas de inteiros <> vetores tuplas
using priorityMap = std::map<int, tuplesVector*>;
//'nameMap' para mapas de strings <> (mapas de inteiros <> vetores de tuplas)
using nameMap = std::map<std::string, priorityMap*>;

class IASPP_PUBLIC IEventDispatcher
{
public:
    IEventDispatcher() {}
    virtual ~IEventDispatcher() {}

    virtual void addEventListener(const std::string &type, Object* obj, functionPointer l, int priority = 0) = 0;
    virtual bool dispatchEvent(Event* event) = 0;
    virtual bool hasEventListener(const std::string &s) = 0;
    virtual void removeEventListener(const std::string &type, Object* obj, functionPointer l, bool removeAll=false) = 0;
};

#endif // IEVENTDISPATCHER_H
