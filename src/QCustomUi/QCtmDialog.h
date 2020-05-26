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

	void setCentralWidget(QWidget* widget);
	QWidget* centralWidget()const;
    QCtmTitleBar* titleBar() const;
    void setMoveBars(const QWidgetList& moveBars);
    void removeMoveBar(QWidget* moveBar);
#ifndef Q_OS_WIN
	void setShadowless(bool flag);
	bool shadowless() const;
#endif
protected:
	void hideEvent(QHideEvent *) override;
	bool eventFilter(QObject*, QEvent*) override;
	bool nativeEvent(const QByteArray& eventType, void* message, long* result) override;
private:
	void normalizes(QPoint& pos);

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};
