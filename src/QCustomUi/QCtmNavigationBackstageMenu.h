#pragma once

#include "qcustomui_global.h"
#include "QCtmNavigationSidePanel.h"

#include <memory>

class QCtmNavigationBackstageActionGroup;
class QCtmNavigationMainMenu;

class QCUSTOMUI_EXPORT QCtmNavigationBackstageMenu  : public QCtmNavigationSidePanel
{
	Q_OBJECT
        Q_PROPERTY(QColor baseColor READ baseColor WRITE setBaseColor)
public:
	QCtmNavigationBackstageMenu(QCtmNavigationBar *parent = nullptr);
	~QCtmNavigationBackstageMenu();

	/**
	 * @brief       ����Ӳ˵�
	 * @param[in]   menu �Ӳ˵���ַ
	 * @Return:   	
	 *	true        �ɹ�
	 *	false       ʧ�ܣ�groupName�ظ�	
	 */
	bool addSubMenu(QCtmNavigationBackstageActionGroup* menu);

	/**
	 * @brief       ����Ӳ˵�������ò˵�����groupName�Ѵ���ֱ�ӷ��ش˲˵��������½�һ���Ӳ˵���
	 * @param[in]   groupName �Ӳ˵���������
	 * @Return:   	�Ӳ˵���ַ	
	 */
	QCtmNavigationBackstageActionGroup* addSubMenu(const QString& groupName);

	/**
	 * @brief       �Ƴ��Ӳ˵�
	 * @param[in]   groupName �Ӳ˵�����		
	 */
	void removeSubMenu(const QString& groupName);

	/**
	 * @brief       �Ƴ��Ӳ˵�
	 * @param[in]   menu �Ӳ˵���ַ	
	 */
	void removeSubMenu(QCtmNavigationBackstageActionGroup* menu);

	/**
	 * @brief       �����Ӳ˵�
	 * @param[in]   index �Ӳ˵�λ��
	 * @param[in] 	menu �Ӳ˵���ַ
	 * @Return:		
	 *	true        �ɹ�
	 *	false       ʧ�ܣ���������	
	 */
	bool insertSubMenu(int index, QCtmNavigationBackstageActionGroup* menu);

	/**
	 * @brief       �����Ӳ˵�������ò˵�����groupName�Ѵ���ֱ�ӷ��ش˲˵��������½�һ���Ӳ˵���
	 * @param[in]   index �Ӳ˵�λ��
	 * @param[in] 	groupName �Ӳ˵�����
	 * @Return:   	�Ӳ˵���ַ
	 */
	QCtmNavigationBackstageActionGroup* insertSubMenu(int index, const QString& groupName);

	/**
	 * @brief       ��ȡ�Ӳ˵���λ�ã�����Ӳ˵��������򷵻�-1
	 * @param[in]   groupName �Ӳ˵�����
	 * @Return:   	�Ӳ˵�λ��
	 */
	int indexOf(const QString& groupName);

	/**
	 * @brief       ��ȡ�Ӳ˵�����
	 * @Return:     �Ӳ˵�����	
	 */
	int count()const;

	/**
	 * @brief       �����˵�������ʾ
	 * @param[in]   mainMenu ���˵���ַ	
	 */
	void showByMainMenu(QCtmNavigationMainMenu* mainMenu);

	/**
	 * @brief       ��ȡindexλ�õĲ˵���ַ
	 * @param[in]   index λ��
	 * @Return:   	�˵���ַ
	 */
	QCtmNavigationBackstageActionGroup* subMenuAt(int index)const;

    /**
     * @brief		���ò˵��Ϸ��߿���ɫ�����������˵��ָ�
     * @param[in]	color ��ɫ
     */
    void setBaseColor(const QColor& color);

    /**
     * @brief		��ȡ�˵��Ϸ��߿���ɫ
     */
    const QColor& baseColor() const;
protected:
    void mousePressEvent(QMouseEvent *event) override;
	void closeEvent(QCloseEvent *event)override;
	QSize sizeHint() const override;
	QPoint smartPosition(DockArea align)const override;
	bool eventFilter(QObject* o, QEvent* e)override;
    void paintEvent(QPaintEvent *event) override;
private:
	struct Impl;
	std::shared_ptr<Impl> m_impl;
};
