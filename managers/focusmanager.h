#ifndef FOCUSMANAGER_H
#define FOCUSMANAGER_H

#include "object.h"
#include "managers/ifocusmanager.h"

//http://help.adobe.com/en_US/FlashPlatform/reference/actionscript/3/fl/managers/FocusManager.html
class IASPP_PUBLIC FocusManager : public Object, IFocusManager
{
public:
    FocusManager(DisplayableContainer *container);
    virtual ~FocusManager();

    virtual int getNextTabIndex();

    void activate();
    void deactivate();

    Interactive* findFocusManagerComponent(Interactive* component);
    Interactive* getFocus();
    Interactive* getNextFocusManagerComponent(bool backward=false);
    void hideFocus();
    void setFocus(Interactive* o);
    void showFocus();
};

#endif // FOCUSMANAGER_H
