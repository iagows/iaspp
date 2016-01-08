#ifndef MENUITEM_H
#define MENUITEM_H

#include "events/eventdispatcher.h"
//http://help.adobe.com/pt_BR/FlashPlatform/reference/actionscript/3/flash/display/NativeMenuItem.html
class IASPP_PUBLIC MenuItem : public EventDispatcher
{
public:
    MenuItem();
    virtual ~MenuItem();
};

#endif // MENUITEM_H
