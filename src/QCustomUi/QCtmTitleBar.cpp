#include "QCtmTitleBar.h"
#include "ui_QCtmTitleBar.h"
#include "Private/Util_p.h"
#include "Private/QCtmWidgetItem_p.h"

#include <QStyleOption>
#include <QPainter>
#include <QResizeEvent>
#include <QMenuBar>

Q_CONSTEXPR int leftMargin = 5;
Q_CONSTEXPR int titleSpacing = 5;

struct QCtmTitleBar::Impl
{
	QPixmap windowIcon;
	QMenuBar *menuBar{ nullptr };
	bool showIcon{ true };
	QList<QCtmWidgetItemPtr> items;
};

QCtmTitleBar::QCtmTitleBar(QWidget *parent)
	: QWidget(parent)
	, m_impl(std::make_unique<Impl>())
	, ui(new Ui::QCtmTitleBar)
{
	ui->setupUi(this);
	setFocusPolicy(Qt::StrongFocus);
	connect(ui->closeBtn, &QPushButton::clicked, this, &QCtmTitleBar::onCloseBtn);
	connect(ui->minimumSizeBtn, &QPushButton::clicked, this, &QCtmTitleBar::onMinimumSizeBtn);
	connect(ui->maximumSizeBtn, &QPushButton::clicked, this, &QCtmTitleBar::onMaximumSizeBtn);

	parent->installEventFilter(this);
}

QCtmTitleBar::~QCtmTitleBar()
{
	delete ui;
}

/**
 * @brief       设置传统菜单栏
 * @param[in]   menu 传统菜单栏
 * @note        如果已存在菜单栏，则旧的菜单栏将被销毁
 */
void QCtmTitleBar::setMenuBar(QMenuBar* menu)
{
	removeMenuBar();
	menu->setAutoFillBackground(false);
	menu->setSizePolicy(QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed));;
	m_impl->menuBar = menu;
	ui->horizontalLayout->insertWidget(0, menu);
	update();
}

/**
 * @brief  		获取传统菜单栏地址，如果没有设置菜单栏，则返回空
 * @Return:   	传统菜单栏地址
 */
QMenuBar* QCtmTitleBar::menuBar() const
{
	return m_impl->menuBar;
}

/**
 * @brief  		移除传统菜单栏，如果菜单栏不存在不会产生任何效果。
 */
void QCtmTitleBar::removeMenuBar()
{
	if (m_impl->menuBar)
	{
		delete m_impl->menuBar;
		m_impl->menuBar = nullptr;
		update();
	}
}

/**
 * @brief  		设置是否显示标题栏图标
 * @param[in]  	show true:显示，false:不显示
 */
void QCtmTitleBar::setShowIcon(bool show)
{
	m_impl->showIcon = show;
    if(show)
        ui->horizontalLayout->setContentsMargins(leftMargin + titleSpacing + m_impl->windowIcon.width(), 0, 0, 0);
    else
        ui->horizontalLayout->setContentsMargins(0, 0, 0, 0);
}

/**
 * @brief  		获取是否显示标题栏图标
 * @Return:   	true:显示，false:不显示
 */
bool QCtmTitleBar::showIcon() const
{
	return m_impl->showIcon;
}

void QCtmTitleBar::onCloseBtn()
{
	this->window()->close();
}

void QCtmTitleBar::onMaximumSizeBtn()
{
	if (this->window()->isMaximized())
		this->window()->showNormal();
	else
		this->window()->showMaximized();
}

void QCtmTitleBar::onMinimumSizeBtn()
{
	this->window()->showMinimized();
}

void QCtmTitleBar::paintEvent(QPaintEvent *event)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
	if (!m_impl->windowIcon.isNull() && m_impl->showIcon)
	{
		p.drawPixmap(doIconRect(), m_impl->windowIcon);
	}

	if (parentWidget())
	{
		auto text = parentWidget()->windowTitle();
		auto rect = opt.fontMetrics.boundingRect(text);
		if (m_impl->menuBar)
		{
			if (m_impl->menuBar->geometry().right() >= (this->width() - rect.width()) / 2)
			{
				rect.moveTo((this->width() - m_impl->menuBar->geometry().right() - rect.width()) / 2, 0);
			}
			else
				rect.moveTo((width() - rect.width()) / 2, 0);
		}
		else
			rect.moveTo(leftMargin + m_impl->windowIcon.width() + titleSpacing, 0);
		rect.setHeight(this->height());
		QTextOption to;
        to.setWrapMode(QTextOption::NoWrap);
		to.setAlignment(Qt::AlignCenter);
		p.save();
		p.setFont(this->font());
		p.setPen(this->palette().windowText().color());
		p.drawText(rect, text, to);
		p.restore();
	}
}

void QCtmTitleBar::showEvent(QShowEvent* event)
{
	auto w = qobject_cast<QWidget*>(this->parent());
	if (w)
	{
		if (!w->windowFlags().testFlag(Qt::WindowType::WindowCloseButtonHint))
			ui->closeBtn->hide();
		if (!w->windowFlags().testFlag(Qt::WindowType::WindowMinimizeButtonHint))
			ui->minimumSizeBtn->hide();
		if (!w->windowFlags().testFlag(Qt::WindowType::WindowMaximizeButtonHint))
			ui->maximumSizeBtn->hide();
		if (w->windowState().testFlag(Qt::WindowState::WindowMaximized))
			ui->maximumSizeBtn->setMaximumSized(true);
		else
			ui->maximumSizeBtn->setMaximumSized(false);
	}
}

bool QCtmTitleBar::eventFilter(QObject *watched, QEvent *event)
{
	if (watched == parent())
	{
		auto w = qobject_cast<QWidget*>(this->parent());
		if (!w)
			return false;
		if (event->type() == QEvent::WindowStateChange)
		{
			auto w = qobject_cast<QWidget*>(this->parent());
			if (w)
			{
				if (w->windowState().testFlag(Qt::WindowState::WindowMaximized))
					ui->maximumSizeBtn->setMaximumSized(true);
				else
					ui->maximumSizeBtn->setMaximumSized(false);
			}
		}
		else if (event->type() == QEvent::WindowIconChange)
		{
			auto sizes = w->windowIcon().availableSizes();
			if (!sizes.isEmpty())
			{
				m_impl->windowIcon = w->windowIcon().pixmap(sizes.front());
#if QT_VERSION <= QT_VERSION_CHECK(5, 8, 0)
				int size = 16;
#else
                int size = this->style()->pixelMetric(QStyle::PM_TitleBarButtonIconSize);
#endif
                if (m_impl->windowIcon.height() > size)
                {
                    m_impl->windowIcon = m_impl->windowIcon.scaledToHeight(size, Qt::SmoothTransformation);
                }
                if(m_impl->showIcon)
				    ui->horizontalLayout->setContentsMargins(leftMargin + titleSpacing + m_impl->windowIcon.width(), 0, 0, 0);
			}
		}
		else if (event->type() == QEvent::WindowTitleChange)
		{
			update();
		}
		else if (event->type() == QEvent::Resize)
		{
			if (w->windowFlags().testFlag(Qt::WindowMaximizeButtonHint))
			{
				if (w->maximumSize() == w->minimumSize())
					ui->maximumSizeBtn->hide();
				else
					ui->maximumSizeBtn->show();
			}
		}
	}
	return false;
}

void QCtmTitleBar::actionEvent(QActionEvent *event)
{
	if (event->type() == QEvent::ActionAdded)
	{
		auto item = std::make_shared<QCtmWidgetItem>(event->action(), Qt::Horizontal, this);
		Util::addItem(item, m_impl->items, event->before(), ui->actionLayout);
	}
	else
	{
		Util::removeItem(event->action(), m_impl->items, ui->actionLayout);
	}
}

QRect QCtmTitleBar::doIconRect() const
{
	return { leftMargin, (this->height() - m_impl->windowIcon.height()) / 2, m_impl->windowIcon.width(), m_impl->windowIcon.height() };
}
