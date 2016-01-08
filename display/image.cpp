#include "image.h"

Image::Image():Displayable()
{
    this->imgData = new ImageData();
}

Image::~Image()
{
    if(this->imgData != nullptr)
        delete this->imgData;
}

bool Image::draw()
{
    bool out = false;
    if(this->renderer!=nullptr)
    {
        Rectangle *imgR = this->imgData->getDimension();
        Rectangle *r = this->getRectangle();

        SDL_Rect *_imgR = imgR->toSDL();
        SDL_Rect *_r = r->toSDL();
        out = SDL_RenderCopyEx(this->renderer,
                               this->imgData->getTexture(),
                               _imgR,
                               _r,
                               this->rotation,
                               NULL,
                               SDL_FLIP_NONE) == 0;
        delete _imgR;
        delete _r;
        delete imgR;
        delete r;
    }
    return out;
}

bool Image::setSource(std::string source, SDL_Renderer *ren)
{
    this->renderer = ren;
    bool out = this->imgData->setSource(source, ren);
    if(out)
    {
        this->width = this->imgData->getWidth();
        this->height = this->imgData->getHeight();
    }
    return out;
}

void Image::createChildren()
{
    //não precisa de nada aqui :D
}
