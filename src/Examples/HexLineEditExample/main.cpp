﻿#include "HexLineEditExample.h"

#include <QCustomUi/QCtmApplication.h>

int main(int argc, char* argv[])
{
    QCtmApplication a(argc, argv);
    HexLineEditExample w;
    w.show();
    return a.exec();
}
