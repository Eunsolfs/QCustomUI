#pragma once

#include "qcustomui_global.h"

#include <QScrollArea>

#include <memory>

class QCtmNavigationBar;

class QCUSTOMUI_EXPORT QCtmNavigationSidePanel : public QWidget
{
	Q_OBJECT

public:
	enum class DockArea
	{
		Left,
		Top,
		Right,
		Bottom
	};
	explicit QCtmNavigationSidePanel(QCtmNavigationBar *parent = nullptr);
	~QCtmNavigationSidePanel();

	/**
	 * @brief  		����ͣ������
	 * @param[in]  	area ͣ������	
	 */
	void setDockArea(DockArea area);

	/**
     * @brief  		��ȡͣ������
     * @Return:   	ͣ������
     */
	DockArea dockArea() const;

	/**
	 * @brief  		������ʾ���ڣ��ڵ���ǰ������������weiget�Ĳ��֣��ڵ��ú����õĲ��ֽ���Ч��
	 * @param[in]  	widget ��ʾ���ڵ�ַ
	 */
	void setWidget(QWidget* widget);

	/**
	 * @brief  		��ȡ��ʾ���ڵĵ�ַ
	 * @Return:   	��ʾ���ڵĵ�ַ		
	 */
	QWidget* widget()const;

	/**
	 * @brief  		��ͼ��������
	 * @Return:   	��ͼ����������ַ		
	 */
	QScrollArea* viewContainer()const;
	
	/**
	 * @brief  		���ñ������ɼ�
	 * @param[in]  	visbile �Ƿ�ɼ�	
	 */
	void setTitleVisible(bool visible);

	/**
	 * @brief  		��ȡ�������Ƿ�ɼ�
	 * @Return:   	true �ɼ���false ���ɼ�		
	 */
	bool titleVisible()const;

	/**
	 * @brief  		���ñ�������
	 * @param[in]  	text ��������		
	 */
	void setTitle(const QString& text);

	/**
	 * @brief  		��ȡ��������
	 * @Return:   	��������		
	 */
	QString title()const;

    /**
     * @brief		��Ϊ����ʽ����
     * @param[in]	popup �Ƿ�Ϊ����ʽ����
     */
    void setPopup(bool popup);

    /**
     * @brief		��ȡ�����Ƿ�Ϊ����ʽ����
     */
    bool popup() const;
signals:
	/**
	 * @brief  		���ر�ʱ���͸��ź�		
	 */
	void paneClosed();
protected:
	void paintEvent(QPaintEvent *event) override;
	void showEvent(QShowEvent *event) override;
	void closeEvent(QCloseEvent *event) override;
	QSize sizeHint()const override;
	bool eventFilter(QObject* o, QEvent* e) override;
    void mousePressEvent(QMouseEvent *event) override;

	virtual QPoint smartPosition(DockArea area)const;
	virtual QSize smartSize(DockArea area)const;

    void setNavigationBar(QCtmNavigationBar* bar);
    QCtmNavigationBar* navigationBar() const;
private:
	void bindAction(QAction* action);
	void paintShadow(int shadowWidth);
private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;

	friend class QCtmNavigationBar;
};
