#pragma once

#include "qcustomui_global.h"

#include <QTabWidget>
#include <QMap>
#include <QAction>

#include <memory>

class QCtmTabPage;

class QCUSTOMUI_EXPORT QCtmTabWidget :public QTabWidget
{
	Q_OBJECT
public:
	QCtmTabWidget(QWidget *parent = nullptr);
	~QCtmTabWidget();

public:
	/**
     * @brief       ���Tabҳ
     * @param[in]   widget	ҳ����
     * @param[in]   label	ҳ��ǩ�ı�
     * @Return:     ���ҳ������
     */
	QCtmTabPage* addTab(QWidget *widget, const QString &label);

	/**
	 * @brief		���Tabҳ
	 * @param[in]	widget	ҳ����
	 * @param[in]	icon	ҳ��ǩͼ��
	 * @param[in]	label	ҳ��ǩ�ı�
	 * @Return:		���ҳ������
	 */
	QCtmTabPage* addTab(QWidget *widget, const QIcon &icon, const QString &label);

	/**
	 * @brief       ����Tabҳ
	 * @param[in]   index ����ҳ��index
	 * @param[in]   widget ҳ����
	 * @param[in]   label ҳ��ǩ�ı�
	 * @Return:     ����ҳ����
	 */
	QCtmTabPage* insertTab(int index, QWidget *widget, const QString &label);

	/**
     *  @brief		����Tabҳ
     *  @param[in]	index ����ҳ��index
     *  @param[in]	widget ҳ����
     *  @param[in]	icon ҳ��ǩͼ��
     *  @param[in]	label ҳ��ǩ�ı�
     *  @Return:	����ҳ����
     */
	QCtmTabPage* insertTab(int index, QWidget *widget, const QIcon &icon, const QString &label);

signals:
    /**
     * @brief		���ذ�ť�����
     */
	void closeButtonClicked();
    /**
     * @brief		λ�õ�����ť�����
     */
	void areaButtonClicked();
protected:
	void paintEvent(QPaintEvent *e);

	private slots:
	void onCurrentChanged(int index);

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

