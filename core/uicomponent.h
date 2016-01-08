#ifndef UICOMPONENT_H
#define UICOMPONENT_H

#include "display/sprite.h"
#include "managers/ifocusmanager.h"
#include "events/event.h"

class IASPP_PUBLIC UIComponent : public Sprite
{
public:
    UIComponent();
    virtual ~UIComponent();
    bool isEnabled();
    virtual void setEnabled(bool e);
    bool focusEnabled;
    IFocusManager* focusManager;
    bool mouseFocusEnabled;

    void clearStyle(std::string style);
    void drawFocus(bool focused);
    Interactive* getFocus();
    Object* getStyle();
    virtual Object* getStyleDefinition();
    void invalidate(std::string property, bool callLater = true);
    //mergeStyles(... list):Object
    void move(int x, int y);
    void setFocus();
    void setSize(int w, int h);
    void setStyle(Object* value);
    //void validateNow(); TODO

protected:
    Object *getStyleValue(std::string name);
    bool enabled;

};

#endif // UICOMPONENT_H
