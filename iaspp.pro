#problems with permissions?
#http://forums.linuxmint.com/viewtopic.php?f=90&t=103867
#visibility
#http://gcc.gnu.org/wiki/Visibility

#mkdir
#http://www.linuxquestions.org/questions/programming-9/mkdir-in-c-setting-wrong-permissions-613250/

QT       -= core gui

CONFIG += c++14
CONFIG -= qt
TARGET = iaspp
TEMPLATE = lib

DEFINES += IASPP_LIBRARY

# Just one "debug_and_release" into CONFIG
debug_and_release {
    CONFIG -= debug_and_release
    CONFIG += debug_and_release
}
# Just one "debug" XOR "release" into CONFIG
CONFIG(debug, debug|release) {
    CONFIG -= debug release
    CONFIG += debug
    DEFINES += DEBUG
}
CONFIG(release, debug|release) {
    CONFIG -= debug release
    CONFIG += release
    DEFINES += RELEASE
}

win32 {
    DEFINES += WINDOWS
}
unix {
    DEFINES += LINUX
    target.path = /usr/lib
    INSTALLS += target
}

SOURCES += \
    object.cpp \
    geometry/point.cpp \
    events/eventdispatcher.cpp \
    events/event.cpp \
    display/displayable.cpp \
    display/interactive.cpp \
    display/menu.cpp \
    display/menuitem.cpp \
    display/displayablecontainer.cpp \
    display/sprite.cpp \
    display/graphic.cpp \
    media/soundproperties.cpp \
    text/textformat.cpp \
    window/window.cpp \
    display/image.cpp \
    display/imagedata.cpp \
    system/file.cpp \
    date.cpp \
    util/stringutil.cpp \
    geometry/vector2d.cpp \
    display/stage.cpp \
    events/maindispatcher.cpp \
    events/keyboardevent.cpp \
    ui/keyboard.cpp \
    display/movieclip.cpp \
    core/uicomponent.cpp \
    managers/focusmanager.cpp \
    controls/basebutton.cpp \
    events/componentevent.cpp \
    controls/labelbutton.cpp \
    events/mouseevent.cpp \
    events/eventprocesser.cpp \
    events/windowevent.cpp \
    controls/button.cpp \
    geometry/colortransform.cpp \
    motion/color.cpp \
    events/textevent.cpp \
    error.cpp \
    error_stacktrace/stacktrace.cpp \
    controls/label.cpp \
    text/textfield.cpp \
    geometry/rectangle.cpp \
    events/focusevent.cpp \
    ui/mouse.cpp \
    ui/mousecursordata.cpp \
    iaspp.cpp

HEADERS +=\
    object.h\
    geometry/point.h \
    events/eventdispatcher.h \
    events/event.h \
    events/ieventdispatcher.h \
    display/IBitmapDrawable.h \
    display/iimagedrawable.h \
    display/displayable.h \
    display/interactive.h \
    display/BlendMode.h \
    display/menu.h \
    display/menuitem.h \
    display/displayablecontainer.h \
    display/sprite.h \
    display/graphic.h \
    media/soundproperties.h \
    text/textformat.h \
    text/textalignformat.h \
    window/window.h \
    window/windowenums.h \
    display/image.h \
    display/imagedata.h \
    system/file.h \
    date.h \
    util/stringutil.h \
    geometry/vector2d.h \
    display/stage.h \
    events/maindispatcher.h \
    util/callback.h \
    events/keyboardevent.h \
    ui/keyboard.h \
    display/movieclip.h \
    core/uicomponent.h \
    managers/ifocusmanager.h \
    managers/focusmanager.h \
    controls/basebutton.h \
    events/componentevent.h \
    controls/labelbutton.h \
    events/mouseevent.h \
    events/eventprocesser.h \
    events/windowevent.h \
    controls/button.h \
    controls/ibutton.h \    
    text/textfieldautosize.h \
    geometry/colortransform.h \
    motion/color.h \
    events/textevent.h \
    error.h \
    error_stacktrace/stacktrace.h \
    text/textfieldtype.h \
    filters/imagefilter.h \
    controls/label.h \
    text/textfield.h \
    controls/buttonlabelplacement.h \
    geometry/rectangle.h \
    text/antialiastype.h \
    events/focusevent.h \
    ui/mouse.h \
    ui/mousecursordata.h \
    iaspp_global.h \
    iaspp.h

msvc{
    error("Will break with this msvc compiler!")
    #unix:!macx|win32: LIBS += -L$$PWD/../SDL2-2.0.3/lib/x86/ -lSDL2

    #INCLUDEPATH += $$PWD/../SDL2-2.0.3/include
    #DEPENDPATH += $$PWD/../SDL2-2.0.3/include
}

win32{
    #sdl2.0.3
    unix:!macx|win32: LIBS += -L$$PWD/../../sdl2_mingw/lib/x86/ -lSDL2
    INCLUDEPATH += $$PWD/../../sdl2_mingw/include
    DEPENDPATH += $$PWD/../../sdl2_mingw/include

    #----------------image----------------#
    #sdl2_image 2.0 vs pega com compilador mingw
    unix:!macx|win32: LIBS += -L$$PWD/../../sdl2_image_vs/lib/x86/ -lSDL2_image
    INCLUDEPATH += $$PWD/../../sdl2_image_vs/include
    DEPENDPATH += $$PWD/../../sdl2_image_vs/include

    #sdl2_ttf 2.0.12 vs pega com compilador mingw
    unix:!macx|win32: LIBS += -L$$PWD/../../sdl2_ttf_vs/lib/x86/ -lSDL2_ttf
    INCLUDEPATH += $$PWD/../../sdl2_ttf_vs/include
    DEPENDPATH += $$PWD/../../sdl2_ttf_vs/include

    #specific windows sdk lib
    win32:LIBS += "C:/Program Files (x86)/Microsoft SDKs/Windows/v7.1A/Lib/ImageHlp.lib"
}
