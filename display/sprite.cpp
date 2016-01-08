#include "sprite.h"

Sprite::Sprite():DisplayableContainer()
{
    this->graphic = new Graphic();
    this->hitArea = nullptr;
    this->soundProp = new SoundProperties();
}

Sprite::~Sprite()
{
    delete this->graphic;
    delete this->soundProp;
}

Graphic *Sprite::getGraphic()
{
    return this->graphic;
}

void Sprite::startDrag(bool lockCenter, Rectangle *bounds)
{
    aspp_throw("TO DO");
    throw; //TODO
}

void Sprite::stopDrag()
{
    aspp_throw("TO DO");
    throw; //TODO
}

void Sprite::createChildren()
{
    aspp_throw("TO DO");
    throw; //TODO
}
