#ifndef COLOR_H
#define COLOR_H

#include "geometry/colortransform.h"

//http://help.adobe.com/pt_BR/FlashPlatform/reference/actionscript/3/fl/motion/Color.html
class IASPP_PUBLIC Color : public ColorTransform
{
public:
    Color(double redMultiplier = 1, double greenMultiplier = 1, double blueMultiplier = 1, double alphaMultiplier = 1,
          double redOffset = 0, double greenOffset = 0, double blueOffset = 0, double alphaOffset = 0);
    virtual ~Color();

    double brightness;
    size_t tintColor;
    double tintMultiplier;

    SDL_Color toSDLColor();

    static SDL_Color toSDLColor(size_t c);
};

#endif // COLOR_H
