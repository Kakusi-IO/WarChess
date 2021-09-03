QT       += core gui
RC_ICONS=W.ico
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
# TARGET = WarChess
CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    archerchess.cpp \
    assassinchess.cpp \
    bosschess.cpp \
    chess.cpp \
    finallywindialog.cpp \
    firstlywindialog.cpp \
    gamecontroller.cpp \
    gamewindow.cpp \
    losedialog.cpp \
    main.cpp \
    initwindow.cpp \
    pausedialog.cpp \
    tankchess.cpp \
    windowcontroller.cpp

HEADERS += \
    archerchess.h \
    assassinchess.h \
    bosschess.h \
    chess.h \
    finallywindialog.h \
    firstlywindialog.h \
    gamecontroller.h \
    gamewindow.h \
    includedLibs.h \
    index.h \
    initwindow.h \
    losedialog.h \
    pausedialog.h \
    tankchess.h \
    windowcontroller.h

FORMS += \
    finallywindialog.ui \
    firstlywindialog.ui \
    gamewindow.ui \
    initwindow.ui \
    losedialog.ui \
    pausedialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
