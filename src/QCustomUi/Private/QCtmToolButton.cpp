/*********************************************************************************
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

#include "QCtmToolButton_p.h"

#include <QAction>
#include <QStyle>
#include <QEvent>

struct QCtmToolButton::Impl
{
    bool showToolTip{ true };
};

QCtmToolButton::QCtmToolButton(QWidget* parent)
    : QToolButton(parent)
    , m_impl(std::make_unique<Impl>())
{
    connect(this, &QAbstractButton::toggled, this, [=](bool) {style()->unpolish(this); style()->polish(this); });
}

QCtmToolButton::~QCtmToolButton()
{
}

void QCtmToolButton::setIcon(const QIcon& icon)
{
    if (defaultAction())
    {
        defaultAction()->setIcon(icon);
    }
    else
        QToolButton::setIcon(icon);
}

void QCtmToolButton::setShowToolTips(bool show)
{
    m_impl->showToolTip = show;
}

bool QCtmToolButton::showToolTips() const
{
    return m_impl->showToolTip;
}

bool QCtmToolButton::event(QEvent* e)
{
    if (e->type() == QEvent::ToolTip)
    {
        return m_impl->showToolTip ? QToolButton::event(e) : true;
    }
    return QToolButton::event(e);
}
