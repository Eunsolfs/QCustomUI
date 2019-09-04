#pragma once

#include "qcustomui_global.h"

#include <QAbstractButton>

#include <memory>

class QCtmAbstractMessageModel;
class QCtmAbstractMessageView;
class QStyleOptionButton;

class QCUSTOMUI_EXPORT QCtmMessageTip : public QAbstractButton
{
	Q_OBJECT
		Q_PROPERTY(QColor tipcolor READ tipColor WRITE setTipColor)
public:
	QCtmMessageTip(QWidget *parent);
	~QCtmMessageTip();

	/**
     * @brief       ����������Դ
     * @param[in]   model ����Դ
	 */
	void setModel(QCtmAbstractMessageModel* model);

	/**
	 * @brief       ��ȡ����Դ
	 * @Return:     ����Դ
	 */
	QCtmAbstractMessageModel* model()const;

	/**
	 * @brief       ������Ϣ��ʾ��ͼ
	 * @param[in] 	view ��ͼ��ַ
	 */
	void setView(QCtmAbstractMessageView* view);

	/**
     * @brief       ��ȡ��Ϣ��ʾ��ͼ
     * @Return:   	��ͼ��ַ
     *
     * @note
     */
	QCtmAbstractMessageView* view()const;

	/**
     * @brief       ������ʾ����ɫ
     * @param[in]   color ����ɫ
     */
	void setTipColor(QColor color);

	/**
     * @brief       ��ȡ��ʾ����ɫ
     * @Return:   	����ɫ
     */
	QColor tipColor()const;
private:
	void paintEvent(QPaintEvent *event) override;
	QSize sizeHint()const override;
	void connectView();
	void initStyleOption(QStyleOptionButton* opt);

	private slots:
	void onClicked(bool);
	void onModelDataChanged();
private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};
