#ifndef INTERACTIVE_H
#define INTERACTIVE_H

#include "display/displayable.h"
#include "display/menu.h"

class IASPP_PUBLIC Interactive : public Displayable
{
public:
    Interactive();
    virtual ~Interactive();

    Menu* contextMenu;
    bool doubleClickEnabled;
    bool focusRect;
    bool mouseEnabled;
    bool tabEnabled;
    int tabIndex;
};

#endif // INTERACTIVE_H
