#ifndef MOUSE_H
#define MOUSE_H

#include "object.h"
#include "ui/mousecursordata.h"

class IASPP_PUBLIC Mouse : public Object
{
public:
    enum CursorType
    {
        ARROW,
        AUTO,
        BUTTON,
        HAND,
        IBEAM,
    };

    static Mouse *Instance();
    virtual ~Mouse();

    static bool setCursor(CursorType ct);
    static bool supportsCursor();
    static bool supportsNativeCursor();
    static void hide();
    static void registerCursor(std::string name, MouseCursorData* cursor);
    static void show();
    static void unregisterCursor(std::string name);

private:
    Mouse();
    //escondendo coisas que não devem ser usadas \o/
    Mouse(Mouse const&){}
    Mouse operator=(Mouse const&){}
    static Mouse* instance;

    static bool supports;
    static bool supportsNative;
    static CursorType cursor;
};

#endif // MOUSE_H
