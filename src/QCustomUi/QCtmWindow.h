﻿/*********************************************************************************
**                                                                              **
**  Copyright (C) 2019-2020 LiLong                                              **
**  This file is part of QCustomUi.                                             **
**                                                                              **
**  QCustomUi is free software: you can redistribute it and/or modify           **
**  it under the terms of the GNU Lesser General Public License as published by **
**  the Free Software Foundation, either version 3 of the License, or           **
**  (at your option) any later version.                                         **
**                                                                              **
**  QCustomUi is distributed in the hope that it will be useful,                **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of              **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               **
**  GNU Lesser General Public License for more details.                         **
**                                                                              **
**  You should have received a copy of the GNU Lesser General Public License    **
**  along with QCustomUi.  If not, see <https://www.gnu.org/licenses/>.         **
**********************************************************************************/

#pragma once

#include "qcustomui_global.h"

#include <QMenuBar>
#include <QStatusBar>
#include <QWidget>

#include <memory>

namespace Ui
{
class QCtmWindow;
}
class QCtmNavigationBar;
class QCtmTitleBar;

class QCUSTOMUI_EXPORT QCtmWindow : public QWidget
{
    Q_OBJECT

public:
    QCtmWindow(QWidget* parent = nullptr);
    ~QCtmWindow();

    void setStatusBar(QStatusBar* statusBar);
    QStatusBar* statusBar() const;
    void removeStatusBar();
    void setMenuBar(QMenuBar* menuBar);
    QMenuBar* menuBar() const;
    void removeMenuBar();
    void setNavigationBar(QCtmNavigationBar* menuBar);
    QCtmNavigationBar* navigationBar() const;
    void removeNavigationBar();
    void setTitleBar(QCtmTitleBar* titleBar);
    QCtmTitleBar* titleBar() const;
    void removeTitleBar();
    void setCentralWidget(QWidget* widget);
    QWidget* centralWidget() const;
    void addMoveBar(QWidget* moveBar);
    void removeMoveBar(QWidget* moveBar);
#ifndef Q_OS_WIN
    void setShadowless(bool flag);
    bool shadowless() const;
#endif
protected:
    bool eventFilter(QObject* watched, QEvent* event) override;
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    bool nativeEvent(const QByteArray& eventType, void* message, long* result) override;
#else
    bool nativeEvent(const QByteArray& eventType, void* message, qintptr* result) override;
#endif
private:
    struct Impl;
    std::unique_ptr<Impl> m_impl;
    Ui::QCtmWindow* ui;
};
