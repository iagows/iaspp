#include "textformat.h"

TextFormat::TextFormat():Object()
{
    this->align = TextAlignFormat::Format::LEFT;
    this->bold = false;
    this->bullet = false;
    this->color = 0;
    this->setFont("Arial");
    this->indent = 0;
    this->italic = false;
    this->kerning = false;
    this->leading = 0;
    this->leftMargin = 0;
    this->letterSpacing = 0;
    this->rightMargin = 0;
    this->size = 12;
    this->tabSpaces = 4;
    this->underline = false;
    this->url = "";
}

TextFormat::TextFormat(std::string font, size_t size, size_t color, bool bold, bool italic, bool underline,
                       std::string url, TextAlignFormat::Format align, size_t leftMargin, size_t rightMargin,
                       size_t indent, size_t leading):Object()
{
    this->setFont(font);
    this->size = size;
    this->color = color;
    this->bold = bold;
    this->italic = italic;
    this->underline = underline;
    this->url = url;
    this->align = align;
    this->leftMargin = leftMargin;
    this->rightMargin = rightMargin;
    this->indent = indent;
    this->leading = leading;

    this->bullet = false;
    this->kerning = false;
    this->letterSpacing = 0;
    this->tabSpaces = 4;
}

TextFormat::~TextFormat()
{
    //nada para limpar
}

size_t TextFormat::getColor()
{
    return this->color;
}

void TextFormat::setColor(size_t c)
{
    this->color = c;
    this->updated = true;
}

std::string TextFormat::getFont()
{
    return this->font;
}

void TextFormat::setFont(std::string font)
{
    std::string extension = ".ttf";
    //https://stackoverflow.com/questions/3954223/platform-independent-way-to-get-font-directory
    this->font = font;
    this->path = File::getResourcePath("fonts") + font + extension;
    if(!File::exists(path))
    {
#ifdef WINDOWS
        this->path = getenv("windir") + File::SEPARATOR + "fonts" + File::SEPARATOR + font + extension;
#else
        this->path = "/usr/share/fonts/" + font + extension;
#endif
    }
    this->updated = true;
}

std::string TextFormat::getFullFont()
{
    return this->path;
}

size_t TextFormat::getSize()
{
    return this->size;
}

void TextFormat::setSize(size_t s)
{
    this->size = s;
    this->updated = true;
}
