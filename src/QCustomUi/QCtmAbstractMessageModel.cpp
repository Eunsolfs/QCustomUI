#include "QCtmAbstractMessageModel.h"

struct QCtmAbstractMessageModel::Impl
{
	QList<QCtmAbstractMessagePtr> messages;
	int maxCount{ 10000 };
};

QCtmAbstractMessageModel::QCtmAbstractMessageModel(QObject *parent)
	: QAbstractTableModel(parent)
	, m_impl(std::make_unique<Impl>())
{
}

QCtmAbstractMessageModel::~QCtmAbstractMessageModel()
{
}

/**
 * @brief  ���һ����Ϣ
 * @param  msg ��Ϣ����
 */
void QCtmAbstractMessageModel::addMessage(QCtmAbstractMessagePtr msg)
{
	while (m_impl->messages.size() >= m_impl->maxCount && !m_impl->messages.isEmpty())
	{
		removeMessage(m_impl->messages.front());
	}

	if (m_impl->maxCount <= 0)
		return;

	m_impl->messages.push_back(msg);
	insertRow(rowCount());
}

/**
 * @brief  ����һ����Ϣ
 * @param  index Ҫ�����λ��
 * @param  msg ��Ϣ����
 */
void QCtmAbstractMessageModel::insertMessage(int index, QCtmAbstractMessagePtr msg)
{
	m_impl->messages.insert(index, msg);
	insertRow(index);
}

/**
 * @brief  �Ƴ�һ����Ϣ
 * @param  msg ��Ϣ����
 */
void QCtmAbstractMessageModel::removeMessage(QCtmAbstractMessagePtr msg)
{
	const auto& index = m_impl->messages.indexOf(msg);
	removeRow(index);
	m_impl->messages.removeOne(msg);
}

/**
 * @brief  ��ȡָ���ж�Ӧ����Ϣ����
 * @param  row ָ����
 * @return ָ���ж�Ӧ����Ϣ����
 */
QCtmAbstractMessagePtr QCtmAbstractMessageModel::message(int row) const
{
	return m_impl->messages.at(row);
}

/**
 * @brief    ���������Ϣ
 */
void QCtmAbstractMessageModel::clear()
{
	beginResetModel();
	m_impl->messages.clear();
	endResetModel();
}

/**
 * @brief		������󱣴���Ϣ������Ĭ��1����
 * @param[in]	count ��Ϣ����
 */
void QCtmAbstractMessageModel::setMaximumCount(int count)
{
	m_impl->maxCount = count;
}

/**
 * @brief		��󱣴���Ϣ����
 */
int QCtmAbstractMessageModel::maximumCount() const
{
	return m_impl->maxCount;
}

int QCtmAbstractMessageModel::rowCount(const QModelIndex &parent /*= QModelIndex()*/) const
{
	return m_impl->messages.size();
}

bool QCtmAbstractMessageModel::removeRows(int row, int count, const QModelIndex &parent /*= QModelIndex()*/)
{
	beginRemoveRows(parent, row, row + count - 1);
	endRemoveRows();
	return true;
}

bool QCtmAbstractMessageModel::insertRows(int row, int count, const QModelIndex &parent /*= QModelIndex()*/)
{
	beginInsertRows(parent, row, row + count - 1);
	endInsertRows();
	return true;
}
