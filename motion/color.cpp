#include "color.h"

Color::Color(double redMultiplier, double greenMultiplier, double blueMultiplier,
             double alphaMultiplier, double redOffset, double greenOffset, double blueOffset,
             double alphaOffset) : ColorTransform(redMultiplier, greenMultiplier, blueMultiplier,
                                                  alphaMultiplier, redOffset, greenOffset, blueOffset,
                                                  alphaOffset)
{

}

Color::~Color()
{

}

SDL_Color Color::toSDLColor()
{
    SDL_Color outputColor;
    /*outputColor.a = this->alphaOffset;
    outputColor.r = this->redOffset;
    outputColor.g = this->greenOffset;
    outputColor.b = this->blueOffset;*/
    return outputColor;
}

SDL_Color Color::toSDLColor(size_t c)
{
    SDL_Color sdlColor;
    sdlColor.r = ((c>>24) & 0xff);
    sdlColor.g = ((c>>16) & 0xff);
    sdlColor.b = ((c>>8) & 0xff);
    sdlColor.a = (c & 0xff);

    return sdlColor;

}
