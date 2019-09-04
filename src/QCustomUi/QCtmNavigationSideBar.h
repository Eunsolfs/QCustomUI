#pragma once

#include "qcustomui_global.h"

#include <QWidget>
#include <QWidgetAction>

#include <memory>

class QCUSTOMUI_EXPORT QCtmNavigationSideBar : public QWidget
{
	Q_OBJECT
        Q_PROPERTY(QSize iconSize READ iconSize WRITE setIconSize NOTIFY iconSizeChanged)
public:
	enum ActionPosition
	{
		Top,
		Bottom
	};
	QCtmNavigationSideBar(QWidget *parent);
	~QCtmNavigationSideBar();

	/**
	 * @brief       ���һ���������ť
	 * @param[in]   icon ��ťͼ��
	 * @param[in]   text ��ť���֣�������ʾtooltip
	 * @param[in]   pos ͣ������
	 * @Return:     �������ť��ַ
	 */
	QAction* addAction(const QIcon& icon, const QString& text, ActionPosition pos);

    /**
     * @brief		���һ��action
     * @param[in]	action Ҫ��ӵ�action
     * @param[in]	pos actionͣ������
     */
    void addAction(QAction* action, ActionPosition pos);

	/**
     * @brief       ����һ���������ť
     * @param[in]   index �������ťλ��
     * @param[in]   icon ��ťͼ��
     * @param[in]   text ��ť���֣�������ʾtooltip
     * @param[in]   pos ͣ������
	 */
	QAction* insertAction(int index, const QIcon& icon, const QString& text, ActionPosition pos);

    /**
     * @brief		����һ��action
     * @param[in]	index ����λ��
     * @param[in]	action Ҫ�����action
     * @param[in]   pos actionͣ������
     */
    void insertAction(int index, QAction* action, ActionPosition pos);

	/**
	 * @brief       ��ȡ�������ťλ�ã����action�������򷵻�-1
	 * @param[in]   action �������ť
	 * @Return:     �������ťλ��	
	 */
	int indexOf(QAction* action)const;

	/**
	 * @brief       ��ȡ��ť����
	 * @param[in]   pos ͣ������
	 * @Return:     ��ť����	
	 */
	int count(ActionPosition pos)const;

	/**
	 * @brief       ����ͼ����ʾ��С
	 * @param[in]   size ͼ��Ĵ�С	
	 */
	void setIconSize(const QSize& size);

	/**
     * @brief       ��ȡͼ����ʾ��С
     * @Return:     ͼ����ʾ��С
	 */
	const QSize& iconSize()const;

    /**
     * @brief		����ָ��λ�õ�action
     * @param[in]	index ָ��λ��
     * @param[in]	pos actionͣ������
     * @Return:		action action��ַ
     */
    QAction* actionAt(int index, ActionPosition pos) const;

signals:
    /**
     * @brief		ͼ���С�ı�
     * @param[in]	size ͼ���С
     */
    void iconSizeChanged(const QSize& size);
protected:
	void paintEvent(QPaintEvent *) override;
    void actionEvent(QActionEvent *event) override;
private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};
