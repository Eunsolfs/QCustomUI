# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

TEMPLATE = app
QT += core gui widgets

CONFIG(debug, debug|release){
TARGET = DisplayWidgetExamplesd
LIBS += -L../../../build/bin -lQCustomUid
}
else{
TARGET = DisplayWidgetExamples
LIBS += -L../../../build/bin -lQCustomUi
}

DESTDIR = ../../../build/bin
INCLUDEPATH += ../../
include(DisplayWidgetExamples.pri)

