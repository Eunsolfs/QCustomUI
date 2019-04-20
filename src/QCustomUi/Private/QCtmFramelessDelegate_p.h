/**
  * @file   QCtmFramelessDelegate.h
  * @brief	�ޱ߿򴰿ڵ�ί��ʵ��
  * @author LiLong
  * @date   2018.11.16
  * @note   
  * @version 1.0
  */ 
#pragma once

#include <QWidget>
#include <memory>

/*!
 * \class QCtmFramelessDelegate
 *
 * \brief 
 *
 * �ޱ߿򴰿ڵ�ί��ʵ��
 *
 * \note 
 *
 * \author LiLong
 *
 * \version 1.0
 *
 * \date 2018.11.16
 *
 */
class QPlatformSurfaceEvent;
class QCtmFramelessDelegate : public QObject
{
	Q_OBJECT

public:
	/**
	  *  @brief  		���캯��
	  *  @param[in]  	parent �����ڵ�ַ�������ڱ���Ϊ���㴰��
	  *  @param[in] 	moveBars ��������϶��Ĵ���
	  *  @Return:   	
	  *
	  *  @note			
	  */
	QCtmFramelessDelegate(QWidget *parent, const QWidgetList& moveBars);

	/**
	  *  @brief  		���캯������
	  *  @param[in]  	parent �����ڵ�ַ�������ڱ���Ϊ���㴰��
	  *  @param[in] 	title �����������������ק�ƶ�
	  *  @Return:   	
	  *
	  *  @note			
	  */
	QCtmFramelessDelegate(QWidget *parent, QWidget* title);
	~QCtmFramelessDelegate();

    void addMoveBar(QWidget* widget);

    void removeMoveBar(QWidget* widget);

	void setShadowless(bool flag);
	bool shadowless() const;
protected:
	bool eventFilter(QObject* obj, QEvent* e) override;
	void resizeEvent(QResizeEvent* e);
	void mousePressEvent(QMouseEvent* e);
	void mouseMoveEvent(QMouseEvent* e);
	void mouseReleaseEvent(QMouseEvent* e);
	void mouseDoubleClickEvent(QMouseEvent* e);
	void paintEvent(QPaintEvent* e);
	void paintShadow(QPainter& p, int shadowWidth);
    void styleChangeEvent(QEvent* e);
    void platformSurfaceEvent(QPlatformSurfaceEvent* e);
private:
	void region(const QPoint &cursorGlobalPoint);
    void updateLayout();
private:
	struct Impl;
	std::shared_ptr<Impl> m_impl;
};
