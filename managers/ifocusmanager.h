#ifndef IFOCUSMANAGER_H
#define IFOCUSMANAGER_H

#include "iaspp_global.h"
#include "display/displayablecontainer.h"
#include "display/interactive.h"
#include "controls/ibutton.h"

//http://help.adobe.com/en_US/FlashPlatform/reference/actionscript/3/fl/managers/IFocusManager.html
class IASPP_PUBLIC IFocusManager
{
public:
    IFocusManager() { }
    virtual ~IFocusManager() {}

    IButton* defaultButton;
    DisplayableContainer* form;
    virtual int getNextTabIndex() = 0;
    bool showFocusIndicator;

    virtual void activate() = 0;
    virtual void deactivate() = 0;

    virtual Interactive* findFocusManagerComponent(Interactive* component) = 0;
    virtual Interactive* getFocus() = 0;
    virtual Interactive* getNextFocusManagerComponent(bool backward=false) = 0;
    virtual void hideFocus() = 0;
    virtual void setFocus(Interactive* o) = 0;
    virtual void showFocus() = 0;
};

#endif // IFOCUSMANAGER_H
