#ifndef TEXTALIGNFORMAT_H
#define TEXTALIGNFORMAT_H

#include "object.h"

class IASPP_PUBLIC TextAlignFormat : public Object
{
public:
    enum Format
    {
        CENTER,
        JUSTIFY,
        LEFT,
        RIGHT
    };
};

#endif // TEXTALIGNFORMAT_H
