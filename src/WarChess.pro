QT       += core gui
RC_ICONS=W.ico

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
# TARGET = WarChess
CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    archerchess.cpp \
    assassinchess.cpp \
    chess.cpp \
    gamecontroller.cpp \
    gamewindow.cpp \
    main.cpp \
    initwindow.cpp \
    tankchess.cpp \
    windowcontroller.cpp

HEADERS += \
    archerchess.h \
    assassinchess.h \
    chess.h \
    gamecontroller.h \
    gamewindow.h \
    globaldefination.h \
    includedLibs.h \
    initwindow.h \
    tankchess.h \
    windowcontroller.h

FORMS += \
    gamewindow.ui \
    initwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
