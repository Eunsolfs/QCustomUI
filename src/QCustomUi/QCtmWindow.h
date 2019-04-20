#pragma once

#include "qcustomui_global.h"

#include <QWidget>
#include <QMenuBar>
#include <QStatusBar>

#include <memory>

namespace Ui
{
	class QCtmWindow;
}

class QCtmNavigationBar;
class QCtmTitleBar;

class QCUSTOMUI_EXPORT QCtmWindow : public QWidget
{
	Q_OBJECT

public:
	QCtmWindow(QWidget *parent = nullptr);
	~QCtmWindow();

	/**
	 * @brief  		����״̬��������Ѵ���statusbar���ɵ�statusbar��������
	 * @param[in]  	statusBar ״̬������
	 */
	void setStatusBar(QStatusBar* statusBar);
	
	/**
	 * @brief  		��ȡ״̬����ַ�����û������statusbar�򷵻ؿ�
	 * @Return:   	״̬����ַ	
	 */
	QStatusBar* statusBar() const;

	/**
	 * @brief  		�Ƴ�״̬�������û������statusbar�򲻻�����κ�Ч����
	 */
	void removeStatusBar();

	/**
	 * @brief  		���ô�ͳ�˵���
	 * @param[in]  	menuBar �˵�����ַ
	 */
	void setMenuBar(QMenuBar* menuBar);

	/**
	 * @brief  		��ȡ��ͳ�˵�����ַ
	 * @Return:   	�˵�����ַ		
	 */
	QMenuBar* menuBar() const;

	/**
	 * @brief  		�Ƴ���ͳ�˵���
	 * @note			
	 */
	void removeMenuBar();

	/**
	 * @brief  		���õ����˵���
	 * @param[in]  	menuBar �˵�����ַ
	 */
	void setNavigationBar(QCtmNavigationBar* menuBar);

	/**
	 * @brief  		��ȡ�����˵�����ַ
	 * @Return:   	�˵�����ַ		
	 */
	QCtmNavigationBar* navigationBar()const;

	/**
	 * @brief  		�Ƴ������˵���		
	 */
	void removeNavigationBar();

	/**
     * @brief  		���ñ�����
     * @param[in]  	titleBar ��������ַ
     */
	void setTitleBar(QCtmTitleBar* titleBar);

	/**
	 * @brief  		���ر�������ַ
	 * @Return:   	��������ַ		
	 */
	QCtmTitleBar* titleWidget()const;

	/**
     * @brief  		�Ƴ�������
     */
	void removeTitleBar();

	/**
	 * @brief  		�������Ĵ���
	 * @param[in]  	widget ���Ĵ���ָ��	
	 */
	void setCentralWidget(QWidget *widget);

	/**
	 * @brief  		��ȡ���Ĵ���ָ��
	 * @Return:   	���Ĵ���ָ��	
	 */
	QWidget* centralWidget()const;

	/**
	 * @brief		���ô��ڱ߿��Ƿ�����Ӱ�����������Ҫ����OpenGL����Ӧ����Ϊtrue
	 * @param[in]	flag true:����Ӱ��flase:����Ӱ
	 */
	void setShadowless(bool flag);

	/**
	 * @brief		�����Ƿ�����Ӱ
	 */
	bool shadowless() const;
protected:
    bool eventFilter(QObject *watched, QEvent *event) override;

private:
	struct Impl;
	std::shared_ptr<Impl> m_impl;
	Ui::QCtmWindow* ui;
};
