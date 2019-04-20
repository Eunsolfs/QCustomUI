#pragma once

#include "qcustomui_global.h"

#include "QCtmAbstractMessageView.h"

#include <memory>

class QCtmNavigationBar;
class QCtmAbstractMessage;

typedef std::shared_ptr<QCtmAbstractMessage> QCtmAbstractMessagePtr;

class QCUSTOMUI_EXPORT QCtmMessageView : public QCtmAbstractMessageView
{
	Q_OBJECT
		Q_PROPERTY(QColor decoration READ decoration WRITE setDecoration)
		Q_PROPERTY(QColor titlecolor READ titleColor WRITE setTitleColor)
		Q_PROPERTY(QColor timecolor READ timeColor WRITE setTimeColor)
		Q_PROPERTY(QPixmap closebuttonicon READ closeButtonIcon WRITE setCloseButtonIcon)
public:
	QCtmMessageView(QCtmNavigationBar *parent);
	~QCtmMessageView();

	virtual void setModel(QCtmAbstractMessageModel* model);
	virtual QCtmAbstractMessageModel* model()const;

	/**
	 * @brief       ����װ������ɫ
	 * @param[in] 	color ��ɫ
	 */
	void setDecoration(const QColor& color);

	/**
     * @brief       ��ȡװ������ɫ
     * @Return:   	��ɫ
     */
	const QColor& decoration()const;

	/**
     * @brief       ���ñ���������ɫ
     * @param[in]   color ��ɫ
     */
	void setTitleColor(const QColor& color);

	/**
     * @brief       ��ȡ����������ɫ
     * @Return:   	��ɫ
     */
	const QColor& titleColor()const;

	/**
     *  @brief      ����ʱ��������ɫ
     *  @param[in]  color ��ɫ
     */
	void setTimeColor(const QColor& color);

	/**
     * @brief       ��ȡʱ��������ɫ
     * @Return:   	��ɫ
     */
	const QColor& timeColor()const;

	/**
     * @brief       ������Ϣ�رհ�ťͼ��
     * @param[in]   icon ͼ��
     */
	void setCloseButtonIcon(const QPixmap& icon);

	/**
     * @brief       ��ȡ�رհ�ťͼ��
     * @Return:   	ͼ��
     */
	const QPixmap& closeButtonIcon()const;
signals:
	void closeButtonClicked(const QModelIndex& index);
	void messageClicked(QCtmAbstractMessagePtr message);
protected:
	void resizeEvent(QResizeEvent*) override;
	void showEvent(QShowEvent*) override;
	bool eventFilter(QObject* o, QEvent* e) override;

	private slots:
	void onCloseButtonClicked(const QModelIndex& index);
	void onTitleClicked(const QModelIndex& index);
private:
	struct Impl;
	std::shared_ptr<Impl> m_impl;
};
