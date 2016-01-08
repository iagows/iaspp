#ifndef BUTTON_H
#define BUTTON_H

#include "controls/labelbutton.h"
#include "controls/ibutton.h"

class IASPP_PUBLIC Button : public LabelButton, IButton
{
public:
    Button();
    virtual ~Button();
};

#endif // BUTTON_H
