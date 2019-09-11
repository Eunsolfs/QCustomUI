#pragma once

#include "qcustomui_global.h"

#include <QWidget>
#include <QAction>

#include <memory>

class QCtmMessageTip;
class QCtmNavigationSidePanel;

class QCUSTOMUI_EXPORT QCtmNavigationBar : public QWidget
{
	Q_OBJECT

public:
	enum ActionPosition
	{
		Left,
		Right
	};
	QCtmNavigationBar(QWidget *parent);
	~QCtmNavigationBar();
	
	/**
	 * @brief       ���һ���˵���
	 * @param[in]   text ����
	 * @param[in]   pos ͣ������
	 * @return:     �˵����ַ		
	 */
	QAction* addAction(const QString& text, ActionPosition pos);

	/**
	 * @brief  	    ���һ���˵���
	 * @param[in]   icon �˵���ͼ��
	 * @param[in] 	text �˵�����
	 * @param[in]   pos ͣ������
	 * @Return:   	�˵����ַ	
	 */
	QAction* addAction(const QIcon& icon, const QString& text, ActionPosition pos);

	/**
	 * @brief       ��Ӳ˵��ָ���
	 * @param[in]   index Ҫ�����λ��
	 * @Return:   	�ָ���ĵ�ַ	
	 */
	QAction* addSeparator(ActionPosition pos);

	/**
     * @brief  	    ��Ӳ˵��ָ���
     * @param[in]   index Ҫ�����λ��
     * @param[in] 	pos ͣ������
     * @Return:
	 */
	QAction* insertSeparator(int index, ActionPosition pos);

	/**
	 * @brief  	    ����Զ��嵯�����
	 * @param[in]   icon �˵�ͼ��
	 * @param[in] 	text �˵�����
	 * @param[in] 	pos ͣ������
	 * @param[in] 	pane �Զ������
	 * @Return:   	�˵����ַ	
	 */
	QAction* addPane(const QIcon& icon, const QString& text, ActionPosition pos, QCtmNavigationSidePanel* pane);

	/**
	 * @brief  	    ����Զ��嵯�����
	 * @param[in] 	text �˵�����
	 * @param[in] 	pos ͣ������
	 * @param[in] 	pane �Զ������
	 * @Return:   	�˵����ַ
	 */
	QAction* addPane(const QString& text, ActionPosition pos, QCtmNavigationSidePanel* pane);

    /**
     * @brief		����Զ��嵯�����
     * @param[in]	action �������󶨵İ�ť
     * @param[in]	pos ͣ������
     * @Return:		
     */
    void addPane(QAction* action, ActionPosition pos, QCtmNavigationSidePanel* pane);

	/**
	 * @brief  	    ����˵���
	 * @param[in]   index �˵���λ��
	 * @param[in] 	icon �˵���ͼ��
	 * @param[in] 	text �˵�������
	 * @param[in] 	pos ͣ������
	 * @Return:   		
	 */
	QAction* insertAction(int index, const QIcon& icon, const QString& text, ActionPosition pos);

	/**
	 * @brief  	    ����˵���
	 * @param[in]   index �˵���λ��
	 * @param[in] 	text �˵�������
	 * @param[in] 	pos ͣ������
	 * @Return:
	 */
	QAction* insertAction(int index, const QString& text, ActionPosition pos);

	/**
	 * @brief  	    �����Զ��嵯�����
	 * @param[in]   index �˵���λ��
	 * @param[in] 	icon �˵���ͼ��
	 * @param[in] 	text �˵�������
	 * @param[in] 	pos ͣ������
	 * @param[in] 	pane ��������ַ
	 * @Return:
	 */
	QAction* insertPane(int index, const QIcon& icon, const QString& text, ActionPosition pos, QCtmNavigationSidePanel* pane);

	/**
	 * @brief  	    �����Զ��嵯�����
	 * @param[in]   index �˵���λ��
	 * @param[in] 	text �˵�������
	 * @param[in] 	pos ͣ������
	 * @param[in] 	pane ��������ַ
	 * @Return:
	 */
	QAction* insertPane(int index, const QString& text, ActionPosition pos,  QCtmNavigationSidePanel* pane);

    /**
     * @brief  	    �����Զ��嵯�����
     * @param[in]   index �˵���λ��
     * @param[in] 	action �뵯�����󶨵İ�ť
     * @param[in] 	pos ͣ������
     * @param[in] 	pane ��������ַ
     */
    void insertPane(int index, QAction* action, ActionPosition pos, QCtmNavigationSidePanel* pane);

	/**
	 * @brief  	    ��ȡ�˵���λ��
	 * @param[in]   action �˵����ַ
	 * @Return:   	�˵���λ��	
	 */
	int indexOf(QAction* action)const;

	/**
     * @brief  	    ��ȡ�˵�������
     * @param[in]   pos ͣ������
     * @Return:   	�˵�������
	 */
	int count(ActionPosition pos)const;

	/**
	 * @brief  	    ��ȡaction��rect
	 * @param[in]   action action��ַ
	 * @Return:   	action��rect		
	 */
	QRect actionRect(QAction* action);

	/**
	 * @brief  	    ��Ӱ����ĵ�
	 * @param[in]   filePath �ļ�·��
     * @param[in]   icon ������ťͼ��
     * @param[in]   pos ������ťλ��
	 */
	QAction* addHelp(const QUrl& filePath, const QIcon& icon, ActionPosition pos = Right);

	/**
	 * @brief  	    ��Ӱ����ĵ�
	 * @param[in]   index ����λ��
	 * @param[in]   filePath �ļ�·��
	 * @param[in]   icon ������ťͼ��
	 * @param[in]   pos ������ťλ��
	 */
	QAction* insertHelp(int index, const QUrl& filePath, const QIcon& icon, ActionPosition pos = Right);

	/** 
	 * @brief		���һ��Logo��ť
	 * @param[in]	icon logoͼ��
	 * @param[in]	pos ͼ��ͣ������
	 * @return	
	 */
	QAction* addLogo(const QIcon& icon, ActionPosition pos = Left);


	/**
	 * @brief		����һ��Logo��ť
	 * @param[in]	index ����λ��
	 * @param[in]	icon logoͼ��
	 * @param[in]	pos ͼ��ͣ������
	 * @return
	 */
	QAction* insertLogo(int index, const QIcon& icon, ActionPosition pos = Left);

	QAction* addUser(const QIcon& icon, const QString& text, ActionPosition pos = Right);

	QAction* insertUser(int index, const QIcon& icon, const QString& text, ActionPosition pos = Right);

    /**
     * @brief		��ȡָ��λ�õ�action
     * @param[in]	index action�����
     * @param[in]	pos action��ͣ������
     * @Return:		action��ַ
     */
    QAction* actionAt(int index, ActionPosition pos) const;

    /**
     * @brief		��ָ��λ�ò���һ��action
     * @param[in]	index Ҫ�����λ��
     * @param[in]	action Ҫ�����action��ַ
     * @param[in]   pos actionͣ������
     */
    void insertAction(int index, QAction* action, ActionPosition pos);

    /**
     * @brief		���һ��action
     * @param[in]	action Ҫ��ӵ�action
     * @param[in]	pos actionͣ������
     */
    void addAction(QAction* action, ActionPosition pos);
protected:
	void paintEvent(QPaintEvent* event)override;
    void actionEvent(QActionEvent *event) override;
	virtual void drawBackground(QPainter* p);

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};
