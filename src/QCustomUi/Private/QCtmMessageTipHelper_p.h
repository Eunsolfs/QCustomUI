﻿/*********************************************************************************
**                                                                              **
**  Copyright (C) 2019-2022 LiLong                                              **
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

#include <QWidget>

#include <memory>

class QCtmMessageTipButton;
class QCtmMessageTipHelper : public QObject
{
    Q_OBJECT

public:
    QCtmMessageTipHelper(QCtmMessageTipButton* parent);
    ~QCtmMessageTipHelper();

    void drawMessageTip(int msgCount, QPainter& p, QWidget* w);

    void setTipColor(const QColor& color);
    const QColor& tipColor() const;

protected:
    QRect tipsRect(const QRect& rect);
    bool eventFilter(QObject* watched, QEvent* event) override;

private:
    struct Impl;
    std::unique_ptr<Impl> m_impl;
};
