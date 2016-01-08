#ifndef BLENDMODE_H
#define BLENDMODE_H

#include "object.h"

class IASPP_PUBLIC BlendMode : public Object
{
public:
    enum
    {
        ADD,
        ALPHA,
        DARKEN,
        DIFFERENCE,
        ERASE,
        HARDLIGHT,
        INVERT,
        LAYER,
        LIGHTEN,
        MULTIPLY,
        NORMAL,
        OVERLAY,
        SCREEN,
        SHADER,
        SUBTRACT
    };
};

#endif // BLENDMODE_H
