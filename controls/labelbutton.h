#ifndef LABELBUTTON_H
#define LABELBUTTON_H

#include "controls/basebutton.h"
#include "controls/buttonlabelplacement.h"
#include "text/textfield.h"

class IASPP_PUBLIC LabelButton : public BaseButton
{
public:
    LabelButton();
    virtual ~LabelButton();

    std::string getLabel();
    void setLabel(std::string l);
    ButtonLabelPlacement::Placement labelPlacement;
    virtual void setSelected(bool s);
    void setTextField(TextField* tf);
    TextField* getTextField();
    bool toggle;
protected:
    TextField* tf;
    std::string label;
};

#endif // LABELBUTTON_H
