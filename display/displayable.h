#ifndef DISPLAYABLE_H
#define DISPLAYABLE_H

#include "display/iimagedrawable.h"
#include "events/eventdispatcher.h"
#include "filters/imagefilter.h"
#include "display/BlendMode.h"
#include "geometry/rectangle.h"
#include "geometry/point.h"

//displayobject
class IASPP_PUBLIC Displayable : public EventDispatcher, IImageDrawable
{
public:
    Displayable();
    virtual ~Displayable();

    double alpha;
    int blendMode;
    bool cacheAsBitmap;
    std::vector<ImageFilter*> *filters;
    virtual int getHeight();
    virtual void setHeight(int h);
    //loaderinfo
    Displayable *mask;
    int getMouseX();
    int getMouseY();
    std::string name;
    Object *getOpaqueBackground();
    Displayable *getParent();
    void setParent(Displayable* parent);
    double rotation;
    double scaleX;
    double scaleY;
    //scrollREctangle (limites)
    //transform
    bool visible;
    virtual int getWidth();
    virtual void setWidth(int w);
    int getX();
    void setX(int v);
    int getY();
    void setY(int v);

    Rectangle* getRectangle();
    bool hitTest(Displayable *object);
    bool hitTest(int x_, int y_, bool shape=false);
    void removeFromChildren(Displayable* child);
    void setRenderer(SDL_Renderer* ren);

    virtual void createChildren()=0;

    virtual bool draw();
protected:
    int height;
    int width;
    int mouseX;
    int mouseY;
    Object *opaqueBg;
    Displayable *parent;

    SDL_Renderer* renderer;

    int x;
    int y;

    void cleanFilters();
    virtual bool update();
    std::vector<Displayable*> *children;
};

#endif // DISPLAYABLE_H
