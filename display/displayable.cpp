#include "displayable.h"

Displayable::Displayable()
{
    this->alpha = 1;
    this->blendMode = BlendMode::NORMAL;
    this->cacheAsBitmap = false;
    this->filters = new std::vector<ImageFilter*>();
    this->height = 0;
    //loaderinfo
    this->mask = nullptr;
    this->mouseX = -1;
    this->mouseY = -1;
    this->name ="";
    this->opaqueBg = nullptr;
    this->parent = nullptr;
    this->rotation = 0;
    this->scaleX = 1;
    this->scaleY = 1;
    //scrollRectangle
    //transform
    this->visible = true;
    this->width = 0;
    this->x = 0;
    this->y = 0;

    this->children = new std::vector<Displayable*>();

    this->renderer = nullptr;
}

Displayable::~Displayable()
{
    //apaga todos
    this->cleanFilters();
    //limpa o ponteiro
    delete this->filters;

    //loaderinfo
    delete this->mask;
    delete this->opaqueBg;
    this->parent = nullptr;
    //scrollRectangle
    //transform

    /*for(size_t i=0; i<this->children->size(); i++)
    {
        Displayable *child = this->children->at(i);
        delete child;
    }*/
    for(Displayable *d : *(this->children))
    {
        delete d;
    }
    delete this->children;
}

int Displayable::getHeight()
{
    return this->height * this->scaleY;
}

void Displayable::setHeight(int h)
{
    this->scaleY = h/this->height;
}

int Displayable::getMouseX()
{
    return this->mouseX;
}

int Displayable::getMouseY()
{
    return this->mouseY;
}

Object *Displayable::getOpaqueBackground()
{
    return this->opaqueBg;
}

Displayable *Displayable::getParent()
{
    return this->parent;
}

void Displayable::setParent(Displayable *parent)
{
    this->parent = parent;
}

int Displayable::getWidth()
{
    return this->width * this->scaleX;
}

void Displayable::setWidth(int w)
{
    this->scaleX = w/this->width;
}

int Displayable::getX()
{
    int out = this->x;
    if(this->parent != nullptr)
        out += this->parent->getX();
    return out;
}

void Displayable::setX(int v)
{
    this->x = v;
}

int Displayable::getY()
{
    int out = this->y;
    if(this->parent != nullptr)
        out += this->parent->getY();
    return out;
}

void Displayable::setY(int v)
{
    this->y = v;
}

Rectangle *Displayable::getRectangle()
{
    return new Rectangle(this->getX(), this->getY(), this->width, this->height);
}

bool Displayable::hitTest(Displayable* object)
{

}

bool Displayable::hitTest(int x_, int y_, bool shape)
{
    bool output = false;
    Rectangle* r = this->getRectangle();

    Point* p = new Point(x_, y_);
    if(shape)
    {
//TODO here
    }
    else
    {
        std::vector<int>* xV = r->xVectors();
        std::vector<int>* yV = r->yVectors();
        p->isInPolygon(*xV, *yV);

        delete xV;
        delete yV;
    }

    delete p;
    delete r;
    return output;
}

void Displayable::cleanFilters()
{
    for(size_t i=0; i<this->filters->size(); ++i)
    {
        ImageFilter* imgF = this->filters->at(i);
        delete imgF;
    }
}

bool Displayable::update()
{
    return true;
}

void Displayable::removeFromChildren(Displayable *child)
{
    for(size_t i = 0; i<this->children->size(); ++i)
    {
        if(this->children->at(i)==child)
        {
            this->children->erase(this->children->begin()+i);
        }
    }
}

void Displayable::setRenderer(SDL_Renderer *ren)
{
    this->renderer = ren;
    this->createChildren();
}

bool Displayable::draw()
{
    bool out = this->update();
    for(Displayable *d : *(this->children))
    {
        out = out && d->draw();
    }
    return out;
}
