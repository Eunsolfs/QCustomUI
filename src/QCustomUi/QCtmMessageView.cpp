#include "QCtmMessageView.h"
#include "QCtmAbstractMessageModel.h"
#include "Private/QCtmMessageViewDelegate_p.h"

#include <QListView>
#include <QHBoxLayout>
#include <QScrollBar>
#include <QHelpEvent>
#include <QEvent>
#include <QToolTip>

struct QCtmMessageView::Impl
{
	QListView *view{ nullptr };
	QCtmAbstractMessageModel* model{ nullptr };
	QCtmMessageViewDelegate* delegate{nullptr};

	QColor titleColor;
	QColor timeColor;
};

QCtmMessageView::QCtmMessageView(QCtmNavigationBar *parent)
	: QCtmAbstractMessageView(parent)
	, m_impl(std::make_shared<Impl>())
{
	this->setTitleVisible(true);
	setPopup(false);
	m_impl->view = new QListView(this);
	m_impl->view->setMouseTracking(true);

	m_impl->delegate = new QCtmMessageViewDelegate(m_impl->view);
	m_impl->view->setItemDelegate(m_impl->delegate);
	setWidget(m_impl->view);
	setFixedWidth(300);

	connect(m_impl->delegate, &QCtmMessageViewDelegate::closeButtonClicked, this, &QCtmMessageView::closeButtonClicked);
	connect(m_impl->delegate, &QCtmMessageViewDelegate::closeButtonClicked, this, &QCtmMessageView::onCloseButtonClicked);
	connect(m_impl->delegate, &QCtmMessageViewDelegate::titleClicked, this, &QCtmMessageView::onTitleClicked);
	m_impl->view->verticalScrollBar()->installEventFilter(this);

	qRegisterMetaType<QCtmAbstractMessagePtr>("QCtmAbstractMessagePtr");
}

QCtmMessageView::~QCtmMessageView()
{
}

void QCtmMessageView::setModel(QCtmAbstractMessageModel* model)
{
	m_impl->model = model;
	setTimeColor(m_impl->timeColor);
	setTitleColor(m_impl->titleColor);
	m_impl->view->setModel(model);
}

QCtmAbstractMessageModel* QCtmMessageView::model() const
{
	return m_impl->model;
}

void QCtmMessageView::setDecoration(const QColor& color)
{
	m_impl->delegate->setDecoration(color);
}

const QColor& QCtmMessageView::decoration() const
{
	return m_impl->delegate->decoration();
}

void QCtmMessageView::setTitleColor(const QColor& color)
{
	m_impl->titleColor = color;
	if (m_impl->model)
		m_impl->model->setProperty("titlecolor", color);
}

const QColor& QCtmMessageView::titleColor() const
{
	return m_impl->titleColor;
}

void QCtmMessageView::setTimeColor(const QColor& color)
{
	m_impl->timeColor = color;
	if (m_impl->model)
		m_impl->model->setProperty("timecolor", color);
}

const QColor& QCtmMessageView::timeColor() const
{
	return m_impl->timeColor;
}

void QCtmMessageView::setCloseButtonIcon(const QPixmap& icon)
{
	m_impl->delegate->setCloseButtonIcon(icon);
}

const QPixmap& QCtmMessageView::closeButtonIcon() const
{
	return m_impl->delegate->closeButtonIcon();
}

void QCtmMessageView::resizeEvent(QResizeEvent* e)
{
	QCtmAbstractMessageView::resizeEvent(e);
	m_impl->view->reset();
}

void QCtmMessageView::showEvent(QShowEvent* e)
{
	QCtmAbstractMessageView::showEvent(e);
}

bool QCtmMessageView::eventFilter(QObject* o, QEvent* e)
{
	if (o == m_impl->view->verticalScrollBar())
	{
		if (e->type() == QEvent::Show || e->type() == QEvent::Hide)
			m_impl->view->reset();
	}
	return QCtmNavigationSidePanel::eventFilter(o, e);
}

void QCtmMessageView::onCloseButtonClicked(const QModelIndex& index)
{
	if (m_impl->model)
	{
		m_impl->model->removeMessage(m_impl->model->message(index.row()));
		m_impl->view->viewport()->update();
	}
}

void QCtmMessageView::onTitleClicked(const QModelIndex& index)
{
	if (index.isValid())
	{
		auto msg = m_impl->model->message(index.row());
		emit messageClicked(msg);
	}
}
