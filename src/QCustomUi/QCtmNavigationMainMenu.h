#pragma once

#include "qcustomui_global.h"

#include "QCtmNavigationSidePanel.h"

#include <memory>

class QCtmNavigationBackstageMenu ;
class QWidgetAction;

class QCUSTOMUI_EXPORT QCtmNavigationMainMenu : public QCtmNavigationSidePanel
{
	Q_OBJECT
        Q_PROPERTY(QSize itemSize READ itemSize WRITE setItemSize)
		Q_PROPERTY(int horizontalSpacing READ horizontalSpacing WRITE setHorizontalSpacing)
		Q_PROPERTY(int verticalSpacing READ verticalSpacing WRITE setVerticalSpacing)
        Q_PROPERTY(bool colorAlternate READ colorAlternate WRITE setColorAlternate)
public:
	QCtmNavigationMainMenu(QCtmNavigationBar *parent = nullptr);
	~QCtmNavigationMainMenu();

	/**
	 * @brief       ��Ӳ˵���
	 * @param[in]   text �˵�������
	 * @Return:     �˵����ַ		
	 */
	QAction* addAction(const QString& text);

	/**
	 * @brief  		��Ӳ˵���
	 * @param[in]  	icon �˵���ͼ��
	 * @param[in] 	text �˵�������
	 * @Return:   	�˵����ַ		
	 */
	QAction* addAction(const QIcon& icon, const QString& text);

	/**
	 * @brief  	    ��ӷ���˵�
	 * @param[in]   icon �˵�ͼ��
	 * @param[in]   text �˵�����
	 * @param[in]   menu ����˵���ַ
	 * @Return:     �˵����ַ		
	 */
	QAction* addGroupingMenu(const QIcon& icon, const QString& text, QCtmNavigationBackstageMenu * menu);

	/**
	 * @brief       ��ӷ���˵�
	 * @param[in] 	text �˵�����
	 * @param[in] 	menu ����˵���ַ
	 * @Return:   	�˵����ַ
	 */
	QAction* addGroupingMenu(const QString& text, QCtmNavigationBackstageMenu * menu);

	/**
	 * @brief  		�������˵�
	 * @param[in]  	index ����λ��
	 * @param[in]  	icon �˵�ͼ��
	 * @param[in] 	text �˵�����
	 * @param[in] 	menu ����˵���ַ
	 * @Return:   	�˵����ַ
	 */
	QAction* insertGroupingMenu(int index, const QIcon& icon, const QString& text, QCtmNavigationBackstageMenu * menu);

	/**
     * @brief       �������˵�
     * @param[in]   index ����λ��
     * @param[in] 	text �˵�����
     * @param[in] 	menu ����˵���ַ
     * @Return:   	�˵����ַ
     */
	QAction* insertGroupingMenu(int index, const QString& text, QCtmNavigationBackstageMenu * menu);

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
	 * @brief       ��ѯ�˵���λ��
	 * @param[in]   action �˵����ַ
	 * @Return:   	�˵���λ��	
	 */
	int indexOf(QAction* action) const;

	/**
	 * @brief  		��ȡ�˵�������
	 * @Return:   	�˵�������		
	 */
	int count()const;

	/**
     * @brief  		��ȡָ��λ�õ�action,�����λ��û��action�򷵻�nullptr
     * @param[in]  	index �˵�λ��
     * @Return:   	�˵���ַ	
     */
	QAction* actionAt(int index)const;

    /**
     * @brief		���ò˵����С
     * @param[in]	size ��С
     */
    void setItemSize(const QSize& size);

    /**
     * @brief		��ȡ�˵����С
     */
    QSize itemSize() const;

	/**
	 * @brief		���ò˵���֮���ˮƽ���
	 * @param[in]	spacing �������
	 */
	void setHorizontalSpacing(int spacing);

	/**
	 * @brief		��ȡ�˵���֮���ˮƽ���
	 */
	int horizontalSpacing() const;

	/**
	 * @brief		���ò˵���֮��Ĵ�ֱ���
	 * @param[in]	spacing �������
	 */
	void setVerticalSpacing(int spacing);

	/**
	 * @brief		��ȡ�˵���֮��Ĵ�ֱ���
	 */
	int verticalSpacing() const;

    /**
     * @brief		�����Ƿ�ʹ����ɫ����
     * @param[in]	enable true:���ã�false:����
     */
    void setColorAlternate(bool enabled);

    /**
     * @brief	    �Ƿ�ʹ����ɫ����	
     */
    bool colorAlternate() const;
protected:
	bool event(QEvent* e) override;
    void actionEvent(QActionEvent *event) override;
	QSize sizeHint()const override;
	void insertAction(int index, QAction* action);
	void bindMenu(QAction* action, QCtmNavigationBackstageMenu * menu);

private slots:
	void relayout();
    void calcItemColor();

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};
