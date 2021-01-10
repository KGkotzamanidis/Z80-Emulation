TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    bus.cpp \
    cpu.cpp \
    init.cpp \
    mem.cpp

HEADERS += \
    bus.h \
    cpu.h \
    mem.h
