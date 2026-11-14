QT += widgets

CONFIG += c++17

INCLUDEPATH += $$PWD/include \
               $$PWD/solver

SOURCES += \
    solver/astar.cpp \
    solver/astarsolver.cpp \
    src/Box.cpp \
    src/Depot.cpp \
    src/Load.cpp \
    src/display.cpp \
    src/entity.cpp \
    src/floor.cpp \
    src/game.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/map.cpp \
    src/mobileentity.cpp \
    src/player.cpp \
    src/staticentity.cpp \
    src/wall.cpp

HEADERS += \
    include/Box.h \
    include/Depot.h \
    include/Load.h \
    include/Map.h \
    include/coords.h \
    include/display.h \
    include/entity.h \
    include/floor.h \
    include/game.h \
    include/mainwindow.h \
    include/mobileentity.h \
    include/player.h \
    include/staticentity.h \
    include/wall.h \
    solver/AStarState.h \
    solver/astar.h \
    solver/astarsolver.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressources.qrc
