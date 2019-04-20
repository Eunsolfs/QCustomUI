#pragma once

#include "qcustomui_global.h"

#include "QCtmAbstractMessageModel.h"

#include <QColor>

class QCUSTOMUI_EXPORT QCtmMessageModel : public QCtmAbstractMessageModel
{
	Q_OBJECT
		Q_PROPERTY(QColor titlecolor READ titleColor WRITE setTitleColor)
		Q_PROPERTY(QColor timecolor READ timeColor WRITE setTimeColor)
public:
	QCtmMessageModel(QObject *parent);
	~QCtmMessageModel();

	QVariant data(const QModelIndex& index, int role)const override;
	int columnCount(const QModelIndex &parent /* = QModelIndex() */)const override;

	/** 
	 * @brief   ���ñ�����ʾ��ɫ
	 * @param   color ��ɫ
	 */
	void setTitleColor(const QColor& color);

	/** 
     * @brief	��ȡ������ʾ��ɫ
     * @return	��ɫ
     */
	const QColor& titleColor()const;

	/** 
	 * @brief	����ʱ����ʾ��ɫ
	 * @param	color ��ɫ
	 */
	void setTimeColor(const QColor& color);

	/** 
	 * @brief	��ȡʱ����ʾ��ɫ
	 * @return	��ɫ
	 */
	const QColor& timeColor()const;
private:
	struct Impl;
	std::shared_ptr<Impl> m_impl;
};
