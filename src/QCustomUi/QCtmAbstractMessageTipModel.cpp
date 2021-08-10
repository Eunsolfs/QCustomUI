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

#include "QCtmAbstractMessageTipModel.h"

struct QCtmAbstractMessageTipModel::Impl
{
    QVector<QCtmAbstractMessageTipDataPtr> messages;
    int maxCount{ 10000 };
    bool reversedOrder{ true };
};

/*!
    \class      QCtmAbstractMessageTipModel
    \brief      ��Ϣmodel�ӿ��࣬������Ϣmodel�Ļ����ӿڣ�Ҫ�����Լ�����Ϣmodel���Լ̳��Ը���.
    \inherits   QAbstractTableModel
    \ingroup    QCustomUi
    \inmodule   QCustomUi
*/

/*!
    \property   QCtmAbstractMessageTipModel::reversedOrder
    \brief      ��Ϣ�Ƿ�������ʾ��������һ����Ϣ��ʾ�ڵ�һ����Ĭ��Ϊ��.
    \sa         setReversedOrder, reversedOrder
*/

/*!
    \brief      ����һ��������Ϊ \a parent ����Ϣ����.
*/
QCtmAbstractMessageTipModel::QCtmAbstractMessageTipModel(QObject* parent)
    : QAbstractTableModel(parent)
    , m_impl(std::make_unique<Impl>())
{
}

/*!
    \brief      ���ٵ�ǰ��Ϣmodel����.
*/
QCtmAbstractMessageTipModel::~QCtmAbstractMessageTipModel()
{
}

/*!
    \brief      ���һ����Ϣ \a msg.
    \sa         insertMessage, removeMessage
*/
void QCtmAbstractMessageTipModel::addMessage(QCtmAbstractMessageTipDataPtr msg)
{
    insertMessage(m_impl->messages.size(), msg);
}

/*!
    \brief      �� \a index ��λ�ò���һ����Ϣ���� \a msg.
    \sa         addMessage, removeMessage
*/
void QCtmAbstractMessageTipModel::insertMessage(int index, QCtmAbstractMessageTipDataPtr msg)
{
    if (m_impl->maxCount <= 0)
        return;
    m_impl->messages.insert(index, msg);
    insertRow(m_impl->reversedOrder ? m_impl->messages.size() - index : index);
    while (m_impl->messages.size() >= m_impl->maxCount && !m_impl->messages.isEmpty())
    {
        removeMessage(m_impl->messages.front());
    }
}

/*!
    \brief      ����Ϣmodel���Ƴ���Ϣ���� \a msg.
    \sa         addMessage, insertMessage
*/
void QCtmAbstractMessageTipModel::removeMessage(QCtmAbstractMessageTipDataPtr msg)
{
    const auto& index = m_impl->messages.indexOf(msg);
    removeRow(m_impl->reversedOrder ? m_impl->messages.size() - 1 - index : index);
    m_impl->messages.removeOne(msg);
}

/*!
    \brief      ���ص� \a row �е���Ϣ����.
*/
QCtmAbstractMessageTipDataPtr QCtmAbstractMessageTipModel::message(int row) const
{
        return m_impl->messages.at(m_impl->reversedOrder ? m_impl->messages.size() - 1 - row : row);
}

/*!
    \brief      ���������Ϣ����.
*/
void QCtmAbstractMessageTipModel::clear()
{
    beginResetModel();
    m_impl->messages.clear();
    endResetModel();
}

/*!
    \brief      ������Ϣ��󱣴����� \a count.
    \sa         maximumCount()
*/
void QCtmAbstractMessageTipModel::setMaximumCount(int count)
{
    m_impl->maxCount = count;
}

/*!
    \brief      ������Ϣ��󱣴����.
    \sa         setMaximumCount
*/
int QCtmAbstractMessageTipModel::maximumCount() const
{
    return m_impl->maxCount;
}

/*!
    \brief      ������Ϣ�Ƿ�������ʾ��������һ����ʾ�ڵ�һ����Ĭ��Ϊ��.
    \sa         reversedOrder
*/
void QCtmAbstractMessageTipModel::setReversedOrder(bool re)
{
    beginResetModel();
    m_impl->reversedOrder = re;
    endResetModel();
}

/*!
    \brief      ��Ϣ�Ƿ�������ʾ��������һ����ʾ�ڵ�һ����Ĭ��Ϊ��.
    \sa         setReversedOrder
*/
bool QCtmAbstractMessageTipModel::reversedOrder() const
{
    return m_impl->reversedOrder;
}

/*!
    \reimp
*/
int QCtmAbstractMessageTipModel::rowCount([[maybe_unused]] const QModelIndex& parent /*= QModelIndex()*/) const
{
    return m_impl->messages.size();
}

/*!
    \reimp
*/
bool QCtmAbstractMessageTipModel::removeRows(int row, int count, const QModelIndex& parent /*= QModelIndex()*/)
{
    beginRemoveRows(parent, row, row + count - 1);
    endRemoveRows();
    return true;
}

/*!
    \reimp
*/
bool QCtmAbstractMessageTipModel::insertRows(int row, int count, const QModelIndex& parent /*= QModelIndex()*/)
{
    beginInsertRows(parent, row, row + count - 1);
    endInsertRows();
    return true;
}
