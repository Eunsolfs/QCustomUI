#pragma once

#include "qcustomui_global.h"

#include <QWidget>
#include <QAction>

#include <memory>

class QCtmTabWidget;
class QCtmTabCornerLayout;

class QCUSTOMUI_EXPORT QCtmTabPage :public QWidget
{
	Q_OBJECT
public:
	/**
	 * @brief  		���Ͻ����һ��action
	 * @param[in]  	icon ͼ��
	 * @param[in] 	text ����
	 * @Return:   	action ��ַ
	 */
	QAction* addAction(const QIcon& icon, const QString& text);

	/**
     * @brief  		���Ͻ����һ��action
     * @param[in]  	text ����
     * @Return:   	action ��ַ
     */
	QAction* addAction(const QString& text);

	/**
     * @brief  		���Ͻǲ���һ��action
     * @param[in]  	index ����λ��
     * @param[in] 	icon ͼ��
     * @param[in] 	text ����
     * @Return:   	action ��ַ
     */
	QAction* insertAction(int index, const QIcon& icon, const QString& text);

	/**
	 * @brief  		���Ͻǲ���һ��action
	 * @param[in]  	index ����λ��
	 * @param[in] 	text ����
	 * @Return:   	action ��ַ
	 */
	QAction* insertAction(int index, const QString& text);

	/**
     * @brief      ��ȡaction����
     * @Return:    action����
     */
	int count() const;

    /**
     * @brief		����action
     * @param[in]	index Ҫ�����λ��
     * @param[in]	action Ҫ�����action	
     */
    void insertAction(int index, QAction* action);

    /**
     * @brief		��ȡָ��λ�õ�action
     * @param[in]	index ָ��λ��
     * @Return:		action��ַ
     */
    QAction* actionAt(int index) const;

	/**
	 * @brief		�ͷŵ�ǰ���봰��
	 * @Return:		��ǰ���봰�ڵ�ַ
	 */
	QWidget* takeCentralWidget() const;

	/**
	 * @brief		���봰�ڵ�ַ
	 */
	QWidget* centralWidget() const;

    using QWidget::addAction;
protected:
	void paintEvent(QPaintEvent *event) override;
    void actionEvent(QActionEvent* event) override;
	void setCentralWidget(QWidget* widget);

	QWidget* cornerWidget()const;
	QCtmTabPage(QCtmTabWidget* parent);
	~QCtmTabPage();
	friend QCtmTabWidget;
	friend QCtmTabCornerLayout;

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};
