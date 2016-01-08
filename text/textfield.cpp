#include "textfield.h"

TextField::TextField():Interactive()
{
    this->defaultTextFormat = new TextFormat();
    this->textColor = 0x000000;
    this->borderColor = 0x000000;
    this->tft = TextFieldType::Type::DYNAMIC;

    //this->gFont = nullptr;

    alwaysShowSelection = false;
    antiAliasType = AntiAliasType::Type::NORMAL;
    autoSize = TextFieldAutoSize::Size::NONE;
    background = false;

    backgroundColor = 0xFFFFFF;
    border = false;
    borderColor = 0x000000;

    //bool condenseWhite = false;

    //defaultTextFormat = nullptr;
    this->defaultTextFormat = new TextFormat();
    displayAsPassword = false;

    maxChars = 0;
    mouseWheelEnabled = true;
    multiline = false;

    selectable = true;

    textColor = 0x000000;

    useRichTextClipboard = false;

    wordWrap = false;

    this->caretIndex = 0;
    this->restrictor = nullptr;
    this->textTexture = nullptr;
    this->gFont = nullptr;
    this->bounds = nullptr;

    this->textUpdated = false;

    this->setEvents();
}

TextField::~TextField()
{
    delete this->defaultTextFormat;
    //SDL_DestroyTexture(this->textTexture);

    delete this->restrictor;
}

int TextField::getBottomScrollV()
{
    aspp_throw("TO DO");
    throw;
}

int TextField::getCaretIndex()
{
    return this->caretIndex;
}

void TextField::setDefaultTextFormat(TextFormat *dtf)
{
    if(this->defaultTextFormat != nullptr) delete this->defaultTextFormat;
    this->defaultTextFormat = dtf;
}

TextFormat *TextField::getDefaultTextFormat()
{
    return this->defaultTextFormat;
}

int TextField::getMaxScrollH()
{
    aspp_throw("TO DO");
    throw;
}

int TextField::getMaxScrollV()
{
    aspp_throw("TO DO");
    throw;
}

int TextField::getLength()
{
    return this->text.length();
}

int TextField::getNumLines()
{
    aspp_throw("TO DO");
    throw;
}

std::string *TextField::getRestrict()
{
    return this->restrictor;
}

void TextField::setRestrict(std::string *r)
{
    this->restrictor = r;
    //TODO: limpar string
    aspp_throw("TO DO");
    throw;
}

int TextField::getScrollH()
{
    aspp_throw("TO DO");
    throw;
}

void TextField::setScrollH(int v)
{
    aspp_throw("TO DO");
    throw;
}

int TextField::getScrollV()
{
    aspp_throw("TO DO");
    throw;
}

void TextField::setScrollV(int v)
{
    aspp_throw("TO DO");
    throw;
}

int TextField::getSelectionBeginIndex()
{
    aspp_throw("TO DO");
    throw;
}

int TextField::getSelectionEndIndex()
{
    aspp_throw("TO DO");
    throw;
}

double TextField::getSharpness()
{
    aspp_throw("TO DO");
}

void TextField::setSharpness(double s)
{
    aspp_throw("TO DO");
}

std::string TextField::getText()
{
    return this->text;
}

void TextField::setText(std::string t)
{
    this->text = t;
    this->textUpdated = true;
}

size_t TextField::getTextColor()
{
    return this->defaultTextFormat->getColor();
}

void TextField::setTextColor(size_t c)
{
    this->defaultTextFormat->setColor(c);
}

int TextField::getTextHeight()
{
    aspp_throw("TO DO");
    throw;
}

int TextField::getTextWidth()
{
    aspp_throw("TO DO");
    throw;
}

int TextField::getThickness()
{
    aspp_throw("TO DO");
    throw;
}

void TextField::setThickness(int t)
{
    (void)t;
    aspp_throw("TO DO");
    throw;
}

TextFieldType::Type TextField::getType()
{
    return this->tft;
}

void TextField::setType(TextFieldType::Type t)
{
    this->tft = t;
}

void TextField::appendText(std::string str)
{
    this->text.append(str);
}

Rectangle *TextField::getCharBoundaries(int charIndex)
{
    (void)charIndex;
    aspp_throw("TO DO");
    throw; //TODO everything
}

int TextField::getFirstCharInParagraph(int charIndex)
{
    aspp_throw("TO DO");
    throw; //TODO everything
}

Displayable *TextField::getImageReference(std::string)
{
    aspp_throw("TO DO");
    throw; //TODO everything
}

int TextField::getLineIndexAtPoint(int x, int y)
{
    aspp_throw("TO DO");
    throw; //TODO everything
}

int TextField::getLineIndexOfChar(int charIndex)
{
    aspp_throw("TO DO");
    throw; //TODO everything
}

int TextField::getLineLength(int lineIndex)
{
    aspp_throw("TO DO");
    throw; //TODO everything
}

int TextField::getHeight()
{
    return this->height;
}

void TextField::setHeight(int h)
{
    this->width;
}

int TextField::getWidth()
{
    return this->width;
}

void TextField::setWidth(int w)
{
    this->width = w;
}

void TextField::createChildren()
{
    //aspp_throw("TO DO");
    //throw; //TODO everything
}

bool TextField::update()
{
    bool output = true;
    if(this->defaultTextFormat->updated || this->textUpdated)
    {
        //abre a fonte
        TTF_Font *font = TTF_OpenFont(this->defaultTextFormat->getFullFont().c_str(), this->defaultTextFormat->getSize());
        if(font==nullptr)
        {
            aspp_throw("error: opening font");
            return EXIT_FAILURE;
        }

        SDL_Surface *surf = TTF_RenderText_Blended(font, this->text.c_str(), Color::toSDLColor(this->getTextColor()));
        if(surf==nullptr)
        {
            TTF_CloseFont(font);
            aspp_throw("error on opening font 2");
            return EXIT_FAILURE;
        }

        if(this->textTexture != nullptr)
            SDL_DestroyTexture(textTexture);
        this->textTexture = SDL_CreateTextureFromSurface(renderer, surf);
        if(this->textTexture== nullptr)
        {
            SDL_FreeSurface(surf);
            TTF_CloseFont(font);
            aspp_throw("error on opening font 3");
            return EXIT_FAILURE;
        }

        SDL_FreeSurface(surf);
        TTF_CloseFont(font);

        //if(this->autoSize == TextFieldAutoSize::Size::LEFT)
        {
            //updating this width and height
            SDL_QueryTexture(this->textTexture, NULL, NULL, &this->width, &this->height);
        }

        if(this->bounds != nullptr)
            delete this->bounds;

        Rectangle* rec = this->getRectangle();
        this->bounds = rec->toSDL();
        delete rec;
    }
    this->defaultTextFormat->updated = false;
    return output;
}

bool TextField::draw()
{
    bool output = Displayable::draw();

    /*SDL_Rect rec;
    rec.x = rec.y = 0;*/
    //if(SDL_RenderCopy(this->renderer, this->textTexture, &rec, this->bounds) != 0)
    if(SDL_RenderCopy(this->renderer, this->textTexture, nullptr, this->bounds) != 0)
        output = false;

    return output;
}

std::string TextField::toString()
{
    aspp_throw("TO DO"); throw;
    return "[TextField]";
}

void TextField::setEvents()
{
    MainDispatcher::Instance()->addEventListener(MouseEvent::MOUSE_MOVE, this, &over);
}

#include "ui/mouse.h"
//TODO check this
void over(Event *ev, Object *obj)
{
    MouseEvent* me = static_cast<MouseEvent*>(ev);
    Displayable* _displayable = static_cast<Displayable*>(obj);

    int _x = me->localX;
    int _y = me->localY;

    Rectangle* r = _displayable->getRectangle();

    if(r->contains(_x, _y))
    {
        Mouse::Instance()->setCursor(Mouse::CursorType::IBEAM);
    }
    else
    {
        Mouse::Instance()->setCursor(Mouse::CursorType::ARROW);
    }
    delete r;
}
