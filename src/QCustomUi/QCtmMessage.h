#pragma once

#include "qcustomui_global.h"

#include <QString>
#include <QDateTime>

#include <memory>

class QCUSTOMUI_EXPORT QCtmAbstractMessage
{
public:
	QCtmAbstractMessage();
	virtual ~QCtmAbstractMessage() {}

};

class QCUSTOMUI_EXPORT QCtmMessage :public QCtmAbstractMessage
{
public:
	enum Column
	{
		Title,
		Content,
		Time,
		ColumnCount
	};

	/**
	 * @brief       ���캯��
	 * @param[in]   title ��Ϣ����
	 * @param[in] 	content ��Ϣ����
	 * @param[in]	time ��Ϣʱ��
	 */
	QCtmMessage(const QString& title, const QString& content, const QDateTime& time);
	~QCtmMessage();

	/**
     * @brief       ������Ϣ����
     * @param[in]   title ������Ϣ
     */
	void setTitle(const QString& title);

	/**
     * @brief       ��ȡ������Ϣ
     * @Return:     ����
     */
	const QString& title()const;

	/**
     * @brief       ������Ϣ����
     * @param[in]   content ��Ϣ����
     */
	void setContent(const QString& content);

	/**
     * @brief       ��ȡ��Ϣ����
     * @Return:     ��Ϣ����
     */
	const QString& content()const;

	/**
     * @brief       ������Ϣʱ��
     * @param[in]   time ��Ϣʱ��
     */
	void setDateTime(const QDateTime& time);

	/**
     * @brief       ��ȡ��Ϣʱ��
     * @Return:     ʱ��
     */
	const QDateTime& dateTime()const;

private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

