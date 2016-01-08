#ifndef IBUTTON_H
#define IBUTTON_H

#include "object.h"

class IASPP_PUBLIC IButton : public Object
{
public:
    IButton() { }

    bool emphasized;
};

#endif // IBUTTON_H
