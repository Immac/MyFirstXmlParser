TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
    stringcycler.cpp \
    lexicalanalyzer.cpp \
    token.cpp

HEADERS += \
    stringcycler.h \
    lexicalanalyzer.h \
    token.h

