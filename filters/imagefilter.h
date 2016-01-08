#ifndef IMAGEFILTER_H
#define IMAGEFILTER_H

#include "iaspp_global.h"
#include "object.h"

//http://help.adobe.com/pt_BR/FlashPlatform/reference/actionscript/3/flash/filters/package-detail.html

//IBitmapDrawable
class IASPP_PUBLIC ImageFilter : public Object
{
public:
    ImageFilter() {}
    virtual ~ImageFilter() = 0;
    virtual ImageFilter* clone() = 0;
};

#endif // IMAGEFILTER_H
