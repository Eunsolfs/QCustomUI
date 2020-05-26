#pragma once

#include "qcustomui_global.h"

#include <QAbstractTableModel>

#include <memory>

using QCtmAbstractMessagePtr = std::shared_ptr<class QCtmAbstractMessage>;

class QCUSTOMUI_EXPORT QCtmAbstractMessageModel : public QAbstractTableModel
{
	Q_OBJECT

public:
	QCtmAbstractMessageModel(QObject *parent);
	~QCtmAbstractMessageModel();

	 /** 
	  * @brief  ���һ����Ϣ
	  * @param  msg ��Ϣ����	
	  */
	void addMessage(QCtmAbstractMessagePtr msg);

	 /** 
	  * @brief  ����һ����Ϣ
	  * @param  index Ҫ�����λ��
	  * @param  msg ��Ϣ����
	  */
	void insertMessage(int index, QCtmAbstractMessagePtr msg);

	 /** 
	  * @brief  �Ƴ�һ����Ϣ
	  * @param  msg ��Ϣ����
	  */
	void removeMessage(QCtmAbstractMessagePtr msg);

	 /** 
	  * @brief  ��ȡָ���ж�Ӧ����Ϣ����
	  * @param  row ָ����
      * @return ָ���ж�Ӧ����Ϣ����
	  */
	QCtmAbstractMessagePtr message(int row)const;
	
	 /** 
	  * @brief    ���������Ϣ
	  */
	void clear();

	/**
	 * @brief		������󱣴���Ϣ������Ĭ��1����
	 * @param[in]	count ��Ϣ����
	 */
	void setMaximumCount(int count);
	
	/**
	 * @brief		��󱣴���Ϣ����
	 */
	int maximumCount() const;

	int	rowCount(const QModelIndex &parent = QModelIndex()) const override;
	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override { return false; }
	bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;
	bool insertRows(int row, int count, const QModelIndex &parent  = QModelIndex()) override;
private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};
