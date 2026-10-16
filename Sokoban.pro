QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Load.cpp \
    bloc.cpp \
    coords.cpp \
    display.cpp \
    entity.cpp \
    floor.cpp \
    game.cpp \
    location.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    mobileentity.cpp \
    player.cpp \
    staticentity.cpp \
    wall.cpp

HEADERS += \
    Load.h \
    Map.h \
    bloc.h \
    coords.h \
    display.h \
    entity.h \
    floor.h \
    game.h \
    location.h \
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
