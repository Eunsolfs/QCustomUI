#pragma once

#include "qcustomui_global.h"

#include <QWidget>
#include <QMenu>

#include <memory>

namespace Ui
{
	class QCtmTitleBar;
}

class QCUSTOMUI_EXPORT QCtmTitleBar : public QWidget
{
	Q_OBJECT
		Q_PROPERTY(bool showicon READ showIcon WRITE setShowIcon)
public:
	QCtmTitleBar(QWidget *parent = Q_NULLPTR);
	~QCtmTitleBar();

	/**
	 * @brief       ���ô�ͳ�˵���
	 * @param[in]   menu ��ͳ�˵���
	 * @note        ����Ѵ��ڲ˵�������ɵĲ˵�����������
	 */
	void setMenuBar(QMenuBar* menu);

	/**
	 * @brief  		��ȡ��ͳ�˵�����ַ�����û�����ò˵������򷵻ؿ�
	 * @Return:   	��ͳ�˵�����ַ
	 */
	QMenuBar* menuBar()const;

	/**
	 * @brief  		�Ƴ���ͳ�˵���������˵��������ڲ�������κ�Ч����
	 */
	void removeMenuBar();

	/**
     * @brief  		�����Ƿ���ʾ������ͼ��
     * @param[in]  	show true:��ʾ��false:����ʾ
     */
	void setShowIcon(bool show);

	/**
	 * @brief  		��ȡ�Ƿ���ʾ������ͼ��
	 * @Return:   	true:��ʾ��false:����ʾ
	 */
	bool showIcon()const;

	private slots:
	void onCloseBtn();
	void onMaximumSizeBtn();
	void onMinimumSizeBtn();

protected:
	void paintEvent(QPaintEvent *event) override;
	void showEvent(QShowEvent* event) override;
	bool eventFilter(QObject *watched, QEvent *event)override;
	void actionEvent(QActionEvent *event) override;
private:
	Ui::QCtmTitleBar* ui;

	struct Impl;
	std::unique_ptr<Impl> m_impl;
};
