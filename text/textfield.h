#ifndef TEXTFIELD_H
#define TEXTFIELD_H

#include "display/interactive.h"
#include "text/textformat.h"
#include "motion/color.h"
#include "text/textfieldtype.h"
#include "text/textfieldautosize.h"
#include "text/antialiastype.h"
#include "geometry/rectangle.h"
#include "events/maindispatcher.h"
#include "events/mouseevent.h"

//http://help.adobe.com/pt_BR/FlashPlatform/reference/actionscript/3/flash/text/TextField.html#useRichTextClipboard
//https://wiki.libsdl.org/SDL_StartTextInput
//http://lazyfoo.net/tutorials/SDL/32_text_input_and_clipboard_handling/index.php
//TODO make editable / finish class
class IASPP_PUBLIC TextField : public Interactive
{
public:
    TextField();
    virtual ~TextField();

    bool alwaysShowSelection;
    AntiAliasType::Type antiAliasType;
    TextFieldAutoSize::Size autoSize;
    bool background;
    size_t backgroundColor;
    bool border;
    size_t borderColor;
    int getBottomScrollV();
    int getCaretIndex();
    //bool condenseWhite;html

    void setDefaultTextFormat(TextFormat* dTF);
    TextFormat* getDefaultTextFormat();
    bool displayAsPassword;

    //gridFitType : String
    int getLength();
    int maxChars;
    int getMaxScrollH();
    int getMaxScrollV();
    bool mouseWheelEnabled;
    bool multiline;
    int getNumLines();
    std::string *getRestrict();
    void setRestrict(std::string *r);

    int getScrollH();
    void setScrollH(int v);
    int getScrollV();
    void setScrollV(int v);

    bool selectable;
    int getSelectionBeginIndex();
    int getSelectionEndIndex();

    double getSharpness();
    void setSharpness(double s);

    //styleSheet : StyleSheet

    std::string getText();
    void setText(std::string t);
    size_t getTextColor();
    void setTextColor(size_t c);
    int getTextHeight();
    int getTextWidth();
    int getThickness();
    void setThickness(int t);

    TextFieldType::Type getType();
    void setType(TextFieldType::Type t);

    bool useRichTextClipboard;
    bool wordWrap;

    void appendText(std::string str);
    Rectangle *getCharBoundaries(int charIndex);
    int getCharIndexAtPoint(int x, int y);
    int getFirstCharInParagraph(int charIndex);
    Displayable *getImageReference(std::string);
    int getLineIndexAtPoint(int x, int y);
    int getLineIndexOfChar(int charIndex);
    int getLineLength(int lineIndex);

    virtual int getHeight() override;
    virtual void setHeight(int h) override;
    virtual int getWidth() override;
    virtual void setWidth(int w) override;

    virtual void createChildren();

    virtual bool update() override;
    virtual bool draw() override;

    virtual std::string toString() override;

private:
    int caretIndex;
    std::string text;
    bool textUpdated;
    size_t textColor;
    std::string *restrictor;

    SDL_Texture* textTexture;

    TTF_Font* gFont;

    TextFormat* defaultTextFormat;

    TextFieldType::Type tft;

    SDL_Rect* bounds;

    void setEvents();
};

void over(Event* ev, Object* obj);

#endif // TEXTFIELD_H
