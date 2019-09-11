/*!***************************************************************************
*  Copyright (C) 2019 lilong(DLC)
*  This file is part of the QCustomUi
*  Contact: 634916105@qq.com
*  License: LGPL
*****************************************************************************/
#pragma once

#include <QWidget>
#include <memory>

class QPlatformSurfaceEvent;
class QCtmFramelessDelegate : public QObject
{
	Q_OBJECT

public:
	/**
	  *  @brief  		Constructs a widget helper with the given parent and move bars
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
	std::unique_ptr<Impl> m_impl;
};
