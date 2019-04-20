#pragma once

#include "qcustomui_global.h"

#include <QString>

#include <memory>

class QCtmAbstractLogModel;
struct QCtmLogData;
typedef std::shared_ptr<QCtmLogData> QCtmLogDataPtr;

class QCUSTOMUI_EXPORT QCtmLogManager
{
public:
    enum LogSaveType
    {
        Date,
        Size
    };

    /**
     * @brief		
     * @param[in]	
     * @param[in]	
     * @Return:		
     */
    static void initBeforeApp();

    /**
     * @brief		��ȡ��־������ʵ������Ҫ��qAppʵ����֮ǰ���øú���
     */
    static QCtmLogManager& instance();

    /**
     * @brief		������־·��
     * @param[in]	path ��־·��
     */
    void setLogFilePath(const QString& path);

    /**
     * @brief		��ȡ��־·��
     */
    const QString& logFilePath() const;

    /**
     * @brief		������־��������
     * @param[in]	��־��������
     */
    void setLogSaveType(LogSaveType type);

    /**
     * @brief		��ȡ��־��������
     */
    LogSaveType logSaveType() const;
    
    /**
     * @brief		������Щ��־��Ҫ����
     * @param[in]	type ��־�Ǽ�
     * @param[in]	save true:���棬false:������
     */
    void setLogTypeEnable(QtMsgType type, bool save);

    /**
     * @brief		��ȡĳ��־�����Ƿ񱣴�
     * @param[in]	type ��־����
     */
    bool logTypeEnable(QtMsgType type) const;

    /**
     * @brief		�����ļ���С���ƣ�ֻ����LogSaveType::Sizeģʽ����Ч
     * @param[in]	size ��־�ļ������ô�С���½�һ����־�ļ�
     */
    void setLogSizeLimit(qint64 size);

    /**
     * @brief		��ȡ��־�ļ���С����
     */
    qint64 logSizeLimit() const;
protected:
    QCtmLogManager();
    ~QCtmLogManager();

    /**
     * @brief		���log�ļ���������һ��������log�ļ�
     */
    virtual bool checkFile();
    
    /**
     * @brief		����־д����־�ļ�
     * @param[in]	data ��־��Ϣ
     */
    virtual void writeLog(QCtmLogDataPtr data);

    void registerModel(QCtmAbstractLogModel* model);
    void unRegisterModel(QCtmAbstractLogModel* model);

    static QList<QString> parseObjectNames(QString& msg);
private:
    struct Impl;
    std::shared_ptr<Impl> m_impl;

    friend QCtmAbstractLogModel;
    friend void qtMessageHandle(QtMsgType, const QMessageLogContext&, const QString&);
};

