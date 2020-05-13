# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

TEMPLATE = lib
TARGET = SwitchLauncher
DESTDIR = ../../build/bin/x64/Debug
QT += core network gui widgets
CONFIG += debug
DEFINES += SWITCHLAUNCHER_LIB
INCLUDEPATH += ./GeneratedFiles \
    . \
    ./GeneratedFiles/$(ConfigurationName) \
    ../

DEPENDPATH += .
MOC_DIR += ./GeneratedFiles/$(ConfigurationName)
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
include(SwitchLauncher.pri)
TRANSLATIONS += switchlauncher_zh.ts
win32:RC_FILE = SwitchLauncher.rc
win32: LIBS += -L$$DESTDIR -lQCustomUi
