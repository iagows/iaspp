#include "rectangle.h"

Rectangle::Rectangle():Object()
{
    this->x = 0;
    this->y = 0;
    this->width = 0;
    this->height = 0;
}

Rectangle::Rectangle(SDL_Rect *rec):Object()
{
    this->x = rec->x;
    this->y = rec->y;
    this->width = rec->w;
    this->height = rec->h;
}

Rectangle::Rectangle(int x, int y, int width, int height):Object()
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

Rectangle::~Rectangle()
{
    //nothing to remove
}

int Rectangle::getBottom()
{
    return this->y + this->height;
}

void Rectangle::setBottom(int b)
{
    this->height = b - this->y;
}

Point *Rectangle::getBottomRight()
{
    return new Point(this->x + this->width, this->y + this->height);
}

void Rectangle::setBottomRight(Point *p)
{
    this->height = p->y - this->y;
    this->width = p->x - this->x;
}

int Rectangle::getLeft()
{
    return this->x;
}

void Rectangle::setLeft(int l)
{
    int currentW = this->x + this->width;
    this->x = l;
    this->width = currentW;
}

int Rectangle::getRight()
{
    return this->x + this->width;
}

void Rectangle::setRight(int r)
{
    this->width = r - this->x;
}

Point *Rectangle::getSize()
{
    return new Point(this->width, this->height);
}

void Rectangle::setSize(Point *p)
{
    this->width = p->x;
    this->height = p->y;
}

int Rectangle::getTop()
{
    return this->x;
}

void Rectangle::setTop(int t)
{
    int currentH = this->y + this->height;
    this->y = t;
    this->height = currentH;
}

Point *Rectangle::getTopLeft()
{
    return new Point(this->x, this->y);
}

void Rectangle::setTopLeft(Point *p)
{
    this->setLeft(p->x);
    this->setTop(p->y);
}

Rectangle *Rectangle::clone()
{
    return new Rectangle(this->x, this->y, this->width, this->height);
}

bool Rectangle::contains(int x, int y)
{
    Point *p = new Point(x,y);
    bool out = this->contains(p);
    delete p;
    return out;
}

bool Rectangle::contains(Point *p)
{
    std::vector<int> *x_ = this->xVectors();
    std::vector<int> *y_ = this->yVectors();

    bool inside = p->isInPolygon(*x_, *y_);

    delete x_;
    delete y_;

    return inside;
}

bool Rectangle::contains(Rectangle *r)
{
    return ((r->x <= this->x)
            && (r->getRight() <= this->getRight())
            && (r->y <= this->y)
            && (r->getBottom() <= this->getBottom()));
}

void Rectangle::copyFrom(Rectangle *r)
{
    this->x = r->x;
    this->y = r->y;
    this->width = r->width;
    this->height = r->height;
}

bool Rectangle::operator ==(const Rectangle &r)
{
    return ((this->x == r.x) && (this->y == r.y) && (this->width==r.width) && (this->height==r.height));
}

bool Rectangle::operator !=(const Rectangle &r)
{
    return ((this->x != r.x) || (this->y != r.y) || (this->width!=r.width) || (this->height!=r.height));
}

void Rectangle::inflate(int dx, int dy)
{
    this->x -= dx;
    this->width += 2*dx;

    this->y -= dy;
    this->height += 2*dy;
}

void Rectangle::inflate(Point *p)
{
    this->x -= p->x;
    this->width += 2*p->x;

    this->y -= p->y;
    this->height += 2*p->y;
}

Rectangle *Rectangle::intersection(Rectangle *r)
{
    Rectangle *out = new Rectangle();

    if(this->intersects(r))
    {
        out->x = std::max(this->getLeft(), r->getLeft());
        out->y = std::max(this->getTop(), r->getTop());
        out->setRight(std::min(this->getRight(), r->getRight()));
        out->setBottom(std::min(this->getBottom(), r->getBottom()));
    }

    return out;
}

bool Rectangle::intersects(Rectangle *r)
{
    return !((this->getRight() < r->getLeft()) || (r->getRight() < this->getLeft())
            || (this->getBottom() < r->getTop()) || (r->getBottom() < this->getTop()));
}

bool Rectangle::isEmpty()
{
    return ((this->width <= 0) || (this->height <=0));
}

void Rectangle::offset(int dx, int dy)
{
    this->x += dx;
    this->y += dy;
}

void Rectangle::offset(Point *p)
{
    this->x += p->x;
    this->y += p->y;
}

void Rectangle::setEmpty()
{
    this->x = 0;
    this->y = 0;
    this->height = 0;
    this->width = 0;
}

void Rectangle::setTo(int x, int y, int w, int h)
{
    this->x = x;
    this->y = y;
    this->width = w;
    this->height = h;
}

std::string Rectangle::toString()
{
    return "(x=" + std::to_string(this->x) +", y="+std::to_string(this->y)+"),(w="+
            std::to_string(this->width) + ",h="+std::to_string(this->height)+")";
}

Rectangle *Rectangle::unite(Rectangle *r)
{
    return new Rectangle(std::min(this->x, r->x),
                         std::min(this->y, r->y),
                         std::max(this->getRight(), r->getRight()),
                         std::max(this->getBottom(), r->getBottom()));
}

SDL_Rect* Rectangle::toSDL()
{
    SDL_Rect* r = new SDL_Rect();
    r->x = this->x;
    r->y = this->y;
    r->w = this->width;
    r->h = this->height;
    return r;
}

std::vector<int>* Rectangle::xVectors()
{
    std::vector<int>* v = new std::vector<int>();
    v->push_back(this->x);
    v->push_back(this->getRight());
    v->push_back(this->x);
    v->push_back(this->getRight());

    return v;
}

std::vector<int>* Rectangle::yVectors()
{
    std::vector<int>* v = new std::vector<int>();
    v->push_back(this->y);
    v->push_back(this->y);
    v->push_back(this->getBottom());
    v->push_back(this->getBottom());

    return v;
}
