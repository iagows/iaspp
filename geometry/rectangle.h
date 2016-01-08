#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <algorithm>

#include "object.h"
#include "geometry/point.h"

//I hate "windows.h" for having a "Rectangle" definition ¬¬
class IASPP_PUBLIC Rectangle : public Object
{
public:
    Rectangle();
    Rectangle(SDL_Rect *rec);
    Rectangle(int x, int y, int width, int height);
    virtual ~Rectangle();
    int getBottom();
    void setBottom(int b);
    Point* getBottomRight();
    void setBottomRight(Point *p);
    int height;
    int getLeft();
    void setLeft(int l);

    int getRight();
    void setRight(int r);

    Point *getSize();
    void setSize(Point *p);
    int getTop();
    void setTop(int t);
    Point *getTopLeft();
    void setTopLeft(Point *p);
    int width;
    int x;
    int y;

    Rectangle *clone();
    bool contains(int x, int y);
    bool contains(Point *p);
    bool contains(Rectangle *r);
    void copyFrom(Rectangle *r);
    bool operator ==(const Rectangle &r);
    bool operator !=(const Rectangle &r);
    void inflate(int dx, int dy);
    void inflate(Point *p);
    Rectangle *intersection(Rectangle *r);
    bool intersects(Rectangle *r);
    bool isEmpty();
    void offset(int dx, int dy);
    void offset(Point *p);
    void setEmpty();
    void setTo(int x, int y, int w, int h);
    virtual std::string toString();
    Rectangle* unite(Rectangle *r);

    SDL_Rect *toSDL();

//private:
    std::vector<int> *xVectors();
    std::vector<int> *yVectors();
};

#endif // RECTANGLE_H
