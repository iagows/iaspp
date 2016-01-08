#ifndef DISPLAYABLECONTAINER_H
#define DISPLAYABLECONTAINER_H

#include "display/interactive.h"

#ifdef LINUX
    #include <climits>
#endif

class IASPP_PUBLIC DisplayableContainer : public Interactive
{
public:
    DisplayableContainer();
    virtual ~DisplayableContainer();

    bool mouseChildren;
    size_t getNumChildren();
    bool tabChildren;

    void addChild(Displayable* child);
    void addChildAt(Displayable* child, size_t index);
    bool contains(Displayable* child);
    Displayable* getChildAt(size_t index);
    Displayable* getChildByName(std::string name_);
    int getChildIndex(Displayable* child);
    std::vector<Displayable*> *getObjectsUnderPoint(Point *p);
    void removeChild(Displayable* child);
    void removeChildAt(size_t index);
    void removeChildren(size_t beginIndex=0, size_t endIndex=INT_MAX);
    void setChildIndex(Displayable* child, size_t index);
    void stopAllAnimations();
    void swapChildren(Displayable* a, Displayable* b);
    void swapChildrenAt(int indexA, int indexB);

private:
    void removeFromParent(Displayable *d);
};

#endif // DISPLAYABLECONTAINER_H
