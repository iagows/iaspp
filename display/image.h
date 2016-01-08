#ifndef IMAGE_H
#define IMAGE_H

#include "display/displayable.h"
#include "display/imagedata.h"

class IASPP_PUBLIC Image : public Displayable
{
public:
    Image();
    virtual ~Image();
    virtual bool draw() override;

    bool setSource(std::string source, SDL_Renderer* ren);
    virtual void createChildren() override;
private:
    ImageData *imgData;
};

#endif // IMAGE_H
