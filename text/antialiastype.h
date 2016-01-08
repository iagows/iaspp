#ifndef ANTIALIASTYPE_H
#define ANTIALIASTYPE_H

#include "object.h"

class AntiAliasType : public Object
{
public:
    enum Type
    {
        ADVANCED,
        NORMAL
    };
};

#endif // ANTIALIASTYPE_H
