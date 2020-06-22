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

#include "Util_p.h"
#include "QCtmWidgetItem_p.h"

QCtmWidgetItemPtr Util::find(QAction* action, const QList<QCtmWidgetItemPtr>& items)
{
    for (auto& item : items)
    {
        if (item->action() == action)
            return item;
    }
    return nullptr;
}

QCtmWidgetItemPtr Util::find(QWidget* widget, const QList<QCtmWidgetItemPtr>& items)
{
    for (auto& item : items)
    {
        if (item->widget() == widget)
            return item;
    }
    return nullptr;
}
