#ifndef TEXTFIELDTYPE_H
#define TEXTFIELDTYPE_H

#include "object.h"

class IASPP_PUBLIC TextFieldType : public Object
{
public:
    enum Type
    {
        DYNAMIC,
        INPUT
    };
};

#endif // TEXTFIELDTYPE_H
