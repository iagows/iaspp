#ifndef IMAGEDATA_H
#define IMAGEDATA_H

#include "object.h"
#include "geometry/rectangle.h"

class IASPP_PUBLIC ImageData : public Object
{
public:
    //sem construtor que receba 'source' para evitar que se crie com imagem vazia
    ImageData();
    ImageData(int w, int h, bool transp=true, size_t fill=0xFFFFFFFF);
    virtual ~ImageData();

    int getHeight();
    Point* getSize();
    Rectangle* getDimension();
    bool isTransparent();
    int getWidth();

    bool setSource(std::string source, SDL_Renderer* renderer);
    SDL_Texture* getTexture();

private:
    int height;
    int width;
    bool transparent;
    size_t fillColor;
    std::string source;

    SDL_Renderer *renderer;
    SDL_Texture *texture;

    void clearTexture();
};

#endif // IMAGEDATA_H
