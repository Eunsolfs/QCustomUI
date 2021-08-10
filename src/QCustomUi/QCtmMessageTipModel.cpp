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

#include "QCtmMessageTipModel.h"
#include "QCtmMessageTipData.h"

#include <QColor>

struct QCtmMessageTipModel::Impl
{
    QColor titleColor;
    QColor timeColor;
};

/*!
    \class      QCtmMessageTipModel
    \brief      ��Ϣ��ʾmodel��һ��ʵ��.
    \inherits   QCtmAbstractMessageTipModel
    \ingroup    QCustomUi
    \inmodule   QCustomUi
    \sa         QCtmMessageTipData
*/

/*!
    \property   QCtmMessageTipModel::titleColor
    \brief      ��Ϣ������ı���ɫ.
    \sa         setTitleColor, titleColor
*/

/*!
    \property   QCtmMessageTipModel::timeColor
    \brief      ��Ϣʱ����ı���ɫ.
    \sa         setTimeColor, timeColor
*/

/*!
    \brief      ����һ��������Ϊ \a parent ����Ϣmodel.
*/
QCtmMessageTipModel::QCtmMessageTipModel(QObject* parent)
    : QCtmAbstractMessageTipModel(parent)
    , m_impl(std::make_unique<Impl>())
{
}

/*!
    \brief      ���ٵ�ǰ��Ϣmodel����.
*/
QCtmMessageTipModel::~QCtmMessageTipModel()
{
}

/*!
    \reimp
*/
QVariant QCtmMessageTipModel::data(const QModelIndex& index, int role) const
{
    QVariant d;
    if (index.row() == -1)
        return d;
    auto msg = std::dynamic_pointer_cast<QCtmMessageTipData>(message(index.row()));
    if (msg)
    {
        if (role == Qt::DisplayRole)
        {
            switch (index.column())
            {
            case QCtmMessageTipData::Title:
                d = msg->title();
                break;
            case QCtmMessageTipData::Content:
                d = msg->content();
                break;
            case QCtmMessageTipData::Time:
                d = msg->dateTime().toString("yyyy-MM-dd hh:mm:ss");
                break;
            }
        }
        else if (role == Qt::ForegroundRole)
        {
            switch (index.column())
            {
            case QCtmMessageTipData::Title:
                d = QColor(m_impl->titleColor);
                break;
            case QCtmMessageTipData::Content:
                break;
            case QCtmMessageTipData::Time:
                d = QColor(m_impl->timeColor);
                break;
            }
        }
        else if (role == Qt::ToolTipRole)
        {
            d = QString("<html><head/><body><p><span style=\" font-weight:600;\">%1</span></p><p>%2</p><p>%3</p></body></html>")
                .arg(msg->title())
                .arg(msg->content())
                .arg(msg->dateTime().toString("yyyy-MM-dd hh:mm:ss"));
        }
    }
    return d;
}

/*!
    \reimp
*/
int QCtmMessageTipModel::columnCount([[maybe_unused]] const QModelIndex& parent /* = QModelIndex() */) const
{
    return QCtmMessageTipData::ColumnCount;
}

/*!
    \brief      ������Ϣ������ı���ɫ \a color.
    \sa         titleColor()
*/
void QCtmMessageTipModel::setTitleColor(const QColor& color)
{
    m_impl->titleColor = color;
}

/*!
    \brief      ������Ϣ������ı���ɫ.
    \sa         setTitleColor
*/
const QColor& QCtmMessageTipModel::titleColor() const
{
    return m_impl->titleColor;
}

/*!
    \brief      ������Ϣʱ����ı���ɫ \a color.
    \sa         timeColor()
*/
void QCtmMessageTipModel::setTimeColor(const QColor& color)
{
    m_impl->timeColor = color;
}

/*!
    \brief      ������Ϣʱ����ı���ɫ.
    \sa         setTimeColor
*/
const QColor& QCtmMessageTipModel::timeColor() const
{
    return m_impl->timeColor;
}
