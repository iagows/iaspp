#ifndef LABEL_H
#define LABEL_H

#include "core/uicomponent.h"
#include "text/textfieldautosize.h"
#include "text/textfield.h"
#include "events/componentevent.h"

class IASPP_PUBLIC Label : public UIComponent
{
public:
    Label();
    virtual ~Label();

   TextFieldAutoSize::Size autoSize;
   bool condensedWhite;
   virtual int getHeight() override;
   virtual void setHeight(int h) override;
   bool selectable;
   std::string getText();
   void setText(std::string t);
   TextField* getTextField();
   void setTextField(TextField* tf);
   virtual int getWidth() override;
   virtual void setWidth(int w) override;
   bool wordWrap;

   virtual Object* getStyleDefinition() override;
   virtual std::string toString() override;
   virtual void createChildren();

protected:
   std::string _text;
   TextField* textField;
};

#endif // LABEL_H
