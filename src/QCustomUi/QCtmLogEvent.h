#pragma once

#include "qcustomui_global.h"

#include <QEvent>
#include <QString>
#include <QDateTime>

#include <memory>

struct QCUSTOMUI_EXPORT QCtmLogData
{
    QCtmLogData(QtMsgType type, const QMessageLogContext& context, const QString& msg)
        : m_type(type)
        , m_msg(msg)
        , m_dateTime(QDateTime::currentDateTime())
    {
        m_context.category = context.category;
        m_context.file = context.file;
        m_context.line = context.line;
        m_context.function = context.function;
    }
    ~QCtmLogData(){}

    /**
     * @brief		��ȡ��־�ȼ�
     */
    QtMsgType type() const { return m_type; }
    
    /**
     * @brief		��ȡ��־������
     */
    const QMessageLogContext& context() const { return m_context; }

    /**
     * @brief		��ȡ��־����
     */
    const QString& msg() const { return m_msg; }

    /**
     * @brief		��ȡ��־����ʱ��
     */
    const QDateTime& dateTime() const { return m_dateTime; }
private:
    QtMsgType m_type;
    QMessageLogContext m_context;
    QString m_msg;
    QDateTime m_dateTime;
};
typedef std::shared_ptr<QCtmLogData> QCtmLogDataPtr;

 /*!***************************************************************************
 * @class QCtmLogEvent
 * @brief ��־�¼�����
 *****************************************************************************/
class QCUSTOMUI_EXPORT QCtmLogEvent : public QEvent
{
public:
    enum { QCtmLog = QEvent::User + 0xFE };
    QCtmLogEvent(QCtmLogDataPtr log);
    ~QCtmLogEvent();

    QCtmLogDataPtr log()const;
private:
    struct Impl;
    std::unique_ptr<Impl> m_impl;
};

enum LogInsertMode  //��־����˳��
{
    ASC,            //����
    DESC            //����
};