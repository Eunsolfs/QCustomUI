#pragma once

#include "qcustomui_global.h"

#include <QDialog>

#include <memory>

class QCtmTitleBar;

class QCUSTOMUI_EXPORT QCtmDialog : public QDialog
{
	Q_OBJECT

public:
	QCtmDialog(QWidget *parent = nullptr);
	~QCtmDialog();

	/**
	 * @brief       ���ÿͻ���������ͻ��������Ѵ��ڣ�ǰһ���ͻ������ڽ�������
	 * @param[in]   widget �ͻ�������	
	 */
	void setContent(QWidget* widget);

	/**
	 * @brief       ��ȡ�ͻ������ڵ�ַ�����û�����ÿͻ������ڣ�Ĭ�ϴ���һ��QWidget
	 * @Return:     �ͻ������ڵ�ַ	
	 */
	QWidget* content()const;

	/**
	 * @brief       �����ڸ���������λ����ʾ
	 * @param[in]   showInCenter true:������λ����ʾ��false:��������λ����ʾ
	 */
	void setShowInCenter(bool showInCenter);

	/**
	 * @brief       �Ƿ��ڸ���������λ����ʾ
	 */
	bool showInCenter() const;

    /**
     * @brief		��ȡ��������ַ
     */
    QCtmTitleBar* titleBar() const;

    /**
     * @brief		���ÿ��϶��Ŀؼ�
     * @param[in]	moveBars ���϶��Ŀؼ�
     */
    void setMoveBars(const QWidgetList& moveBars);

    /**
     * @brief		�Ƴ����϶��ؼ�
     * @param[in]	
     */
    void removeMoveBar(QWidget* moveBar);

#ifndef Q_OS_WIN
	/**
	 * @brief		���ô��ڱ߿��Ƿ�����Ӱ�����������Ҫ����OpenGL����Ӧ����Ϊtrue
	 * @param[in]	flag true:����Ӱ��flase:����Ӱ
	 */
	void setShadowless(bool flag);

	/**
	 * @brief		�����Ƿ�����Ӱ
	 */
	bool shadowless() const;
#endif
protected:
	void showEvent(QShowEvent *) override;
	void hideEvent(QHideEvent *event) override;
	bool eventFilter(QObject*, QEvent*) override;
	bool nativeEvent(const QByteArray& eventType, void* message, long* result) override;
private:
	void normalizes(QPoint& pos);

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};
