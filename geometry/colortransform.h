#ifndef COLORTRANSFORM_H
#define COLORTRANSFORM_H

#include "object.h"


class IASPP_PUBLIC ColorTransform : public Object
{
public:
    ColorTransform(double redMult=1., double greenMult=1., double blueMult=1., double alphaMult=1.,
                   double redOffset=0, double greenOffset=0, double blueOffset=0, double alphaOffset=0);
    virtual ~ColorTransform();

    double alphaMult;
    double alphaOffset;
    double blueMult;
    double blueOffset;
    size_t getColor();
    void setColor(size_t c);
    double greenMult;
    double greenOffset;
    double redMult;
    double redOffset;

    void concat(ColorTransform* second);

    virtual std::string toString() override;

private:
    size_t color;
};

#endif // COLORTRANSFORM_H
