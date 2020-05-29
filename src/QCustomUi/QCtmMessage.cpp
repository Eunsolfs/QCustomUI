#include "QCtmMessage.h"

QCtmAbstractMessage::QCtmAbstractMessage()
{

}


struct QCtmMessage::Impl
{
	QString title;
	QString content;
	QDateTime time;
};

/**
 * @brief       ���캯��
 * @param[in]   title ��Ϣ����
 * @param[in] 	content ��Ϣ����
 * @param[in]	time ��Ϣʱ��
 */
QCtmMessage::QCtmMessage(const QString& title, const QString& content, const QDateTime& time)
	:m_impl(std::make_unique<Impl>())
{
	m_impl->title = title;
	m_impl->content = content;
	m_impl->time = time;
}

QCtmMessage::~QCtmMessage()
{
}

/**
 * @brief       ������Ϣ����
 * @param[in]   title ������Ϣ
 */
void QCtmMessage::setTitle(const QString& title)
{
	m_impl->title = title;
}

/**
 * @brief       ��ȡ������Ϣ
 * @Return:     ����
 */
const QString& QCtmMessage::title() const
{
	return m_impl->title;
}

/**
 * @brief       ������Ϣ����
 * @param[in]   content ��Ϣ����
 */
void QCtmMessage::setContent(const QString& content)
{
	m_impl->content = content;
}

/**
 * @brief       ��ȡ��Ϣ����
 * @Return:     ��Ϣ����
 */
const QString& QCtmMessage::content() const
{
	return m_impl->content;
}

/**
 * @brief       ������Ϣʱ��
 * @param[in]   time ��Ϣʱ��
 */
void QCtmMessage::setDateTime(const QDateTime& time)
{
	m_impl->time = time;
}

/**
 * @brief       ��ȡ��Ϣʱ��
 * @Return:     ʱ��
 */
const QDateTime& QCtmMessage::dateTime() const
{
	return m_impl->time;
}
