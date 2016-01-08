#include "labelbutton.h"

LabelButton::LabelButton():BaseButton()
{
}

LabelButton::~LabelButton()
{
    //delete this->tf;
}

std::string LabelButton::getLabel()
{
    return this->label;
}

void LabelButton::setLabel(std::string l)
{
    this->label = l;
    aspp_throw("TO DO");
    throw; //TODO
}

void LabelButton::setSelected(bool s)
{
    BaseButton::setSelected(s);
}

void LabelButton::setTextField(TextField *tf)
{
    (void)tf;
    aspp_throw("TO DO");
    throw; //TODO
}

TextField *LabelButton::getTextField()
{
    aspp_throw("TO DO");
    throw; //TODO
}
