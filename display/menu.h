#ifndef MENU_H
#define MENU_H

#include "events/eventdispatcher.h"
//http://help.adobe.com/pt_BR/FlashPlatform/reference/actionscript/3/flash/display/NativeMenu.html
class IASPP_PUBLIC Menu : public EventDispatcher
{
public:
    Menu();
    virtual ~Menu();
};

#endif // MENU_H
