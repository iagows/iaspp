#ifndef BASEBUTTON_H
#define BASEBUTTON_H

#include "core/uicomponent.h"
#include "text/textformat.h"

class IASPP_PUBLIC BaseButton : public UIComponent
{
public:
    BaseButton();
    virtual ~BaseButton();

    bool autoRepeat;
    virtual void setEnabled(bool e) override;

    bool isSelected();
    void setSelected(bool s);

    void setMouseState(std::string state);

    virtual Object* getStyleDefinition() override;

protected:
    int repeatDelay;
    int repeatInterval;

    bool selected;
};

#endif // BASEBUTTON_H
