TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    bitutils.cpp \
    cpu.cpp \
    registers.cpp

HEADERS += \
    bitutils.h \
    cpu.h \
    registers.h
