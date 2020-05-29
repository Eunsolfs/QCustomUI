#include "QCtmToolBox.h"
#include "Private/QCtmToolBoxItem_p.h"

#include <QSplitter>
#include <QHBoxLayout>

struct QCtmToolBox::Impl
{
	QSplitter* vSplitter;
	bool firstShow{ true };
};

QCtmToolBox::QCtmToolBox(QWidget* parent)
	: QWidget(parent)
	, m_impl(std::make_unique<Impl>())
{
	m_impl->vSplitter = new QSplitter(this);
	m_impl->vSplitter->setOrientation(Qt::Vertical);
	m_impl->vSplitter->setChildrenCollapsible(false);
    m_impl->vSplitter->setObjectName("toolBoxSplitter");
	QHBoxLayout* layout = new QHBoxLayout(this);
	layout->setMargin(0);
	layout->addWidget(m_impl->vSplitter);
}

QCtmToolBox::~QCtmToolBox()
{

}

/**
 * @brief      ���һ���Ӵ���
 * @param[in]  title ����
 * @param[in] 	widget �Ӵ��ڵ�ַ
 */
void QCtmToolBox::addWidget(const QString& title, QWidget* widget)
{
	insertWidget(m_impl->vSplitter->count(), title, widget);
}

/**
 * @brief      ����һ���Ӵ���
 * @param[in]  index ����λ��
 * @param[in] 	title ����
 * @param[in] 	widget �Ӵ��ڵ�ַ
 */
void QCtmToolBox::insertWidget(int index, const QString& title, QWidget* widget)
{
	auto item = new QCtmToolBoxItem(this);
	item->setTitle(title);
	item->setContent(widget);
	m_impl->vSplitter->insertWidget(index, item);
}

/**
 * @brief  		�Ƴ��Ӵ���
 * @param[in]  	widget �Ӵ��ڵ�ַ
 */
void QCtmToolBox::removeWidget(QWidget* widget)
{
	for (int i = 0; i < m_impl->vSplitter->count(); i++)
	{
		auto item = qobject_cast<QCtmToolBoxItem*>(m_impl->vSplitter->widget(i));
		if (item->content() == widget)
		{
			delete item;
		}
	}
}

/**
 * @brief  		�Ƴ��Ӵ���
 * @param[in]  	index �Ӵ���λ��
 */
void QCtmToolBox::removeWidget(int index)
{
	auto w = m_impl->vSplitter->widget(index);
	if (w)
		delete w;
}

/**
 * @brief  		��ѯ�Ӵ���λ��
 * @param[in]  	widget �Ӵ��ڵ�ַ
 * @Return:   	�Ӵ���λ��
 */
int QCtmToolBox::indexOf(QWidget* widget) const
{
	for (int i = 0; i < m_impl->vSplitter->count(); i++)
	{
		auto item = qobject_cast<QCtmToolBoxItem*>(m_impl->vSplitter->widget(i));
		if (item->content() == widget)
		{
			return i;
		}
	}
	return -1;
}

/**
 * @brief  		��ѯָ��λ�õ��Ӵ���
 * @param[in]  	index ָ��λ��
 * @Return:   	�Ӵ��ڵ�ַ
 */
QWidget* QCtmToolBox::widget(int index) const
{
	auto item = qobject_cast<QCtmToolBoxItem*>(m_impl->vSplitter->widget(index));
	if (item)
	{
		return item->content();
	}
	return nullptr;
}

/**
 * @brief  		�����Ӵ��ڼ�Ĭ����ʾ����
 * @param[in]  	index �Ӵ���λ��
 * @param[in] 	stretch �Ӵ�����ʾ����
 */
void QCtmToolBox::setStretchFactor(int index, int stretch)
{
	m_impl->vSplitter->setStretchFactor(index, stretch);
}

/**
 * @brief  		���ø��Ӵ��ڵ���ʾ��С(�߶�)
 * @param[in]  	sizes ���ϵ��µĴ�С����
 */
void QCtmToolBox::setSizes(const QList<int>& sizes)
{
	m_impl->vSplitter->setSizes(sizes);
}

/**
 *  @brief      ���ô��ڵ�һ����ʾʱ�ı���
 *  @param[in]  index �������
 *  @param[in] 	stretch ����
 */
void QCtmToolBox::setDefaultStretch(int index, int stretch)
{
	auto item = qobject_cast<QCtmToolBoxItem*>(m_impl->vSplitter->widget(index));
	if (item)
	{
		item->setStretch(stretch);
	}
}

void QCtmToolBox::showEvent([[maybe_unused]] QShowEvent *event)
{
	if (m_impl->firstShow)
	{
		m_impl->firstShow = false;
		QList<int> sizes;
		float total = 0;
		for (int i = 0;i<m_impl->vSplitter->count();i++)
		{
			auto item = qobject_cast<QCtmToolBoxItem*>(m_impl->vSplitter->widget(i));
			if (item)
			{
				total += item->stretch();
			}
		}
		if (total != 0)
		{
			for (int i = 0; i < m_impl->vSplitter->count(); i++)
			{
				auto item = qobject_cast<QCtmToolBoxItem*>(m_impl->vSplitter->widget(i));
				if (item)
				{
                    auto size = item->stretch() / total* this->height();
					sizes.push_back(size > item->minimumSizeHint().height() ? size : item->minimumHeight());
				}
			}
            m_impl->vSplitter->setSizes(sizes);
		}
	}
}

