#ifndef TEXTFIELDAUTOSIZE_H
#define TEXTFIELDAUTOSIZE_H

#include "object.h"
class IASPP_PUBLIC TextFieldAutoSize : public Object
{
public:
    enum Size
    {
        CENTER,
        LEFT,
        NONE,
        RIGHT
    };
};

#endif // TEXTFIELDAUTOSIZE_H
