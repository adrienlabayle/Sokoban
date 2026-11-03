QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Box.cpp \
    Depot.cpp \
    Load.cpp \
    display.cpp \
    entity.cpp \
    floor.cpp \
    game.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    mobileentity.cpp \
    player.cpp \
    staticentity.cpp \
    wall.cpp

HEADERS += \
    Box.h \
    Depot.h \
    Load.h \
    Map.h \
    coords.h \
    display.h \
    entity.h \
    floor.h \
    game.h \
    mainwindow.h \
    mobileentity.h \
    player.h \
    staticentity.h \
    wall.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
