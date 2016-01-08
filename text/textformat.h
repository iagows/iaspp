#ifndef TEXTFORMAT_H
#define TEXTFORMAT_H

#include "object.h"
#include "text/textalignformat.h"
#include "system/file.h"

class IASPP_PUBLIC TextFormat : public Object
{
public:
    TextFormat();
    TextFormat(std::string font, size_t size=12, size_t color=0, bool bold=false, bool italic=false, bool underline=false,
               std::string url="", TextAlignFormat::Format align=TextAlignFormat::Format::LEFT, size_t leftMargin=0,
               size_t rightMargin=0, size_t indent=0, size_t leading=0);
    virtual ~TextFormat();

    TextAlignFormat::Format align;
    //uint blockIndent;//recuo para todas as linhas
    bool bold;
    bool bullet;
    size_t getColor();
    void setColor(size_t c);
    std::string getFont();
    void setFont(std::string font);
    std::string getFullFont();
    size_t indent;//recuo da primeira linha do parágrafo
    bool italic;
    bool kerning;
    size_t leading;//espaço vertical
    size_t leftMargin;//recuo - esquerda - para todos os parágrafos
    size_t letterSpacing;//espaço entre letras
    size_t rightMargin;//recuo - esquerda - para todos os parágrafos
    size_t getSize();
    void setSize(size_t s);
    size_t tabSpaces;//espaço, em pixels, pulados nos 'tabs'
    //std::string target;//janela alvo do url
    bool underline;
    std::string url;

    bool updated;

private:
    std::string path;
    std::string font;
    size_t size;
    size_t color;
};

#endif // TEXTFORMAT_H
