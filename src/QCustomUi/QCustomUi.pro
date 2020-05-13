# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

CONFIG += c++17

TEMPLATE = lib
TARGET = QCustomUi
DESTDIR = ../../build/bin/x64/Debug
QT += core network gui widgets
win32: QT += winextras
CONFIG += debug
DEFINES += QCUSTOMUI_LIB
win32: DEFINES += WIN32 WIN64
INCLUDEPATH += ./GeneratedFiles \
    . \
    ./GeneratedFiles/$(ConfigurationName) \
    ./Private
DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/$(ConfigurationName)
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
include(QCustomUi.pri)
TRANSLATIONS += qcustomui_zh.ts
win32: LIBS += -luser32
