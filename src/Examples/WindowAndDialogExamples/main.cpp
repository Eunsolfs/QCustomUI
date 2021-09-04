﻿#include "WindowAndDialogExamples.h"

#include <QCustomUi/QCtmApplication.h>

#include <QAbstractNativeEventFilter>
#include <QDialog>
#include <QDebug>

#include <qt_windows.h>

int main(int argc, char* argv[])
{
    QCtmApplication a(argc, argv);
    WindowAndDialogExamples w;
    w.show();
    return a.exec();
}
