#include "eventdispatcher.h"

EventDispatcher::EventDispatcher(IEventDispatcher *target):Object()
{
    this->target = target;
    this->internalMap = new nameMap();
}

EventDispatcher::~EventDispatcher()
{
    for(auto& iter : *(this->internalMap))
    {
        priorityMap* p = iter.second;
        std::cout << "for 1"<<std::endl;
        for(auto& iter2 : *p)
        {
            std::cout << "for 2"<<std::endl;
            tuplesVector* v = iter2.second;
            v->clear();
            delete v;
            std::cout << "delete 1"<<std::endl;
        }
        p->clear();
        delete p;
        std::cout << "delete 2"<<std::endl;
    }
    this->internalMap->clear();
    delete this->internalMap;
}

void EventDispatcher::addEventListener(const std::string &type, Object *obj, functionPointer l, int priority)
{
    if(type.size() <1 || obj == nullptr || l == nullptr)
        throw;

    priorityMap *pMap;

    nameMap::iterator it = this->internalMap->find(type);
    if(it == this->internalMap->end())
    {
        pMap = new priorityMap();
        this->internalMap->insert({type, pMap});
    }
    else
    {
        pMap = it->second;
    }

    tuplesVector *vect;
    priorityMap::iterator it2 = pMap->find(priority);
    if(it2 == pMap->end())
    {
        //achou PN
        vect = new tuplesVector();
        pMap->insert({priority, vect});
    }
    else
    {
        vect = it2->second;
    }

    objectFunctionTuple* myPair = new objectFunctionTuple();
    std::get<0>(*myPair) = obj;
    std::get<1>(*myPair) = l;

    vect->push_back(myPair);
}

bool EventDispatcher::dispatchEvent(Event *event)
{
    event->setTarget(this);

    //pega lista de funções baseada no tipo de evento
    auto it = this->internalMap->find(event->type());
    //std::cout<< "disp" <<std::endl;
    //vejo se está no fim (vazio)
    if(it != this->internalMap->end())
    {
        //achou algo
        priorityMap *map0 = it->second;
        //verificando todas as entradas
        for(auto& iter : *map0)
        {
            //verificando o array
            tuplesVector* v = iter.second;
            //chamar cada função
            for(auto& it : *v)
            {
                objectFunctionTuple* fTuple = it;

                Object* o = std::get<0>(*fTuple);
                functionPointer func = std::get<1>(*fTuple);
                if(func != nullptr && o != nullptr)
                    (*func)(event, o);
            }
        }
    }
    delete event;
    return true;
}

bool EventDispatcher::hasEventListener(const std::string &type)
{
    bool output = false;
    auto it = this->internalMap->find(type);
    //vejo se está no fim (vazio)
    if(it != this->internalMap->end())
    {
        //achou algo
        priorityMap *map0 = it->second;
        //verificando todas as entradas
        for(auto& iter : *map0)
        {
            //verificando o array
            tuplesVector* v = iter.second;
            //se existe, pelo menos, uma entrada
            if(v->size()>0)
            {
                //então tem algum listener
                output = true;
                break;
            }
        }
    }
    return output;
}

void EventDispatcher::removeEventListener(const std::string &type, Object *obj, functionPointer l, bool removeAll)
{
    auto it = this->internalMap->find(type);
    //vejo se está no fim (vazio)
    if(it != this->internalMap->end())
    {
        //achou algo
        priorityMap *map0 = it->second;
        //verificando todas as entradas
        for(auto& iter : *map0)
        {
            //verificando o array
            tuplesVector* v = iter.second;
            //verificando todas as entradas
            for(size_t i = 0; i<v->size(); ++i)
            {
                objectFunctionTuple* oft = v->at(i);

                functionPointer f = std::get<1>(*oft);
                Object *tempObj = std::get<0>(*oft);
                if(f == l && tempObj == obj)
                {
                    v->erase(v->begin() + i);
                    if(!removeAll)
                    {
                        return;//acabou //só remove uma vez
                    }
                }
            }
        }
    }
}
