#include "colortransform.h"

ColorTransform::ColorTransform(double redMult, double greenMult, double blueMult, double alphaMult,
                               double redOffset, double greenOffset, double blueOffset, double alphaOffset):Object()
{
    this->redMult = redMult;
    this->greenMult = greenMult;
    this->blueMult = blueMult;
    this->alphaMult = alphaMult;

    this->redOffset = redOffset;
    this->greenOffset = greenOffset;
    this->blueOffset = blueOffset;
    this->alphaOffset = alphaOffset;
}

ColorTransform::~ColorTransform()
{

}

size_t ColorTransform::getColor()
{
    this->redMult = 0;
    this->greenMult = 0;
    this->blueMult = 0;

    std::string r = std::to_string(redOffset);
    std::string g = std::to_string(greenOffset);
    std::string b = std::to_string(blueOffset);
    return std::stoi(r+g+b);
}

void ColorTransform::setColor(size_t c)
{
    char buff[6];
    sprintf(buff, "%x", c);
    std::string all = buff;

    std::string complement(6 - all.size(), '0');//quero 6 dígitos
    all = complement + all;

    std::string red = all.substr(0, 2);
    std::string green = all.substr(2, 2);
    std::string blue = all.substr(4, 2);

    this->redOffset = std::stoi(red);
    this->greenOffset = std::stoi(green);
    this->blueOffset = std::stoi(blue);

    this->redMult = 0;
    this->greenMult = 0;
    this->blueMult = 0;
}

void ColorTransform::concat(ColorTransform *second)
{
    this->redMult += second->redMult;
    this->redOffset += second->redOffset;

    this->greenMult += second->greenMult;
    this->greenOffset += second->greenOffset;

    this->blueMult += second->blueMult;
    this->blueOffset += second->blueOffset;
}

std::string ColorTransform::toString()
{
    return "[ColorTransform redMult=" +std::to_string(redMult) +
            " greenMult=" + std::to_string(greenMult) +
            " blueMult=" + std::to_string(blueMult) +
            " redOffset=" + std::to_string(redOffset) +
            " greenOffset=" + std::to_string(greenOffset) +
            " blueOffset=" + std::to_string(blueOffset) + "]";
}
