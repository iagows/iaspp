#ifndef SPRITE_H
#define SPRITE_H

#include "display/displayablecontainer.h"
#include "display/graphic.h"
#include "media/soundproperties.h"

class IASPP_PUBLIC Sprite : public DisplayableContainer
{
public:
    Sprite();
    virtual ~Sprite() override;

    bool buttonMode;
    //drop target
    Graphic *getGraphic();
    Sprite *hitArea;
    SoundProperties* soundProp;
    bool useHandCursor;
    void startDrag(bool lockCenter=false, Rectangle* bounds=nullptr);
    void stopDrag();
    virtual void createChildren() override;

private:
    Graphic *graphic;
};

#endif // SPRITE_H
