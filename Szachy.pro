TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        cbishop.cpp \
        cboard.cpp \
        cclock.cpp \
        cking.cpp \
        cknight.cpp \
        cpawn.cpp \
        cpiece.cpp \
        cqueen.cpp \
        crook.cpp \
        main.cpp

HEADERS += \
    cbishop.h \
    cboard.h \
    cclock.h \
    cking.h \
    cknight.h \
    cpawn.h \
    cpiece.h \
    cqueen.h \
    crook.h
