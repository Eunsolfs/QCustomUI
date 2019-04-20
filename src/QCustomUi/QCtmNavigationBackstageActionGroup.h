#pragma once

#include "qcustomui_global.h"

#include <QFrame>

#include <memory>

class QCtmNavigationBackstageMenu ;
class QWidgetAction;

class QCUSTOMUI_EXPORT QCtmNavigationBackstageActionGroup : public QFrame
{
	Q_OBJECT

public:
	/**
	 * @brief       ���캯��
	 * @param[in]   groupName �Ӳ˵�����
	 * @param[in] 	parent ���˵���ַ		
	 */
	QCtmNavigationBackstageActionGroup(const QString& groupName, QCtmNavigationBackstageMenu  *parent);
	~QCtmNavigationBackstageActionGroup();

	/**
	 * @brief       ��Ӳ˵���
	 * @param[in]   text �˵�������
	 * @Return:   	�˵����ַ	
	 */
	QAction* addAction(const QString& text);

	/**
	 * @brief       ��Ӳ˵���
	 * @param[in]   icon �˵���ͼ��
	 * @param[in] 	text �˵�������		
	 */
	QAction* addAction(const QIcon& icon, const QString& text);
	
	/**
	 * @brief       �޸��Ӳ˵�����
	 * @param[in]   groupName �µ��Ӳ˵�����
	 * @Return:   	
	 *	true        �ɹ�
	 *	false       ʧ�ܣ����˵��Ѵ��ڸ÷�������
	 */
	bool setGroupName(const QString& groupName);

	/**
	 * @brief       ��ȡ�Ӳ˵�����
	 * @Return:     �Ӳ˵�����
	 */
	QString groupName()const;

	/**
	 * @brief       ����˵���
	 * @param[in]   index �˵���λ��
	 * @param[in] 	icon �˵���ͼ��
	 * @param[in] 	text �˵�������
	 * @Return:   	�˵����ַ	
	 */
	QAction* insertAction(int index, const QIcon& icon, const QString& text);

	/**
	 * @brief       ����˵���
	 * @param[in]   index �˵���λ��
	 * @param[in] 	text �˵�������
	 * @Return:   	�˵����ַ
	 */
	QAction* insertAction(int index, const QString& text);

	/**
	 * @brief       ��ȡ�˵���λ��
	 * @param[in]   action �˵����ַ
	 * @Return:   	�˵���λ��	
	 */
	int indexOf(QAction* action)const;

	/**
	 * @brief       ��ȡ�˵�������
	 * @Return:   	�˵�������	
	 */
	int count()const;

	/**
	 * @brief       ��ȡָ��indexλ�õ�action,���index����λ�õ�action�����ڣ�����nullptr
	 * @param[in]   index λ��
	 * @Return:   	action��ַ
	 */
	QAction* actionAt(int index)const;

    /**
     * @brief		����action
     * @param[in]	index Ҫ�����λ��
     * @param[in]	action action��ַ
     */
    void insertAction(int index, QAction* action);

protected:
    void actionEvent(QActionEvent *event) override;

private:
	struct Impl;
	std::shared_ptr<Impl> m_impl;
};
