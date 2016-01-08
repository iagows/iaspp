#include "imagedata.h"

ImageData::ImageData()
{
    this->width = 0;
    this->height = 0;
    this->transparent = true;
    this->fillColor = 0xFFFFFFFF;
    this->texture = nullptr;
}

ImageData::ImageData(int w, int h, bool transp, size_t fill)
{
    this->width = w;
    this->height = h;
    this->transparent = transp;
    this->fillColor = fill;
    this->texture = nullptr;
}

ImageData::~ImageData()
{
    this->clearTexture();
}

int ImageData::getHeight()
{
    return this->height;
}

Point *ImageData::getSize()
{
    return new Point(this->width, this->height);
}

Rectangle *ImageData::getDimension()
{
    return new Rectangle(0,0,this->width, this->height);
}

bool ImageData::isTransparent()
{
    return this->transparent;
}

int ImageData::getWidth()
{
    return this->width;
}

bool ImageData::setSource(std::string source, SDL_Renderer *renderer)
{
    bool out = false;
    this->source = source;
    this->renderer = renderer;

    this->clearTexture();

    this->texture = IMG_LoadTexture(this->renderer, this->source.c_str());

    if(texture!= nullptr)
    {
        out = true;
        SDL_QueryTexture(this->texture, NULL, NULL, &this->width, &this->height);
    }
#ifdef DEBUG
    else
        std::cout << "Erro: "<<SDL_GetError() << std::endl;
#endif

    return out;
}

SDL_Texture *ImageData::getTexture()
{
    return this->texture;
}

void ImageData::clearTexture()
{
    if(this->texture!=nullptr)
        SDL_DestroyTexture(this->texture);
}
