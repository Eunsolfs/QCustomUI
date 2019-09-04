#pragma once

#include "qcustomui_global.h"
#include "QCtmLogEvent.h"

#include <QWidget>
#include <QIcon >

#include <memory>

class QCUSTOMUI_EXPORT QCtmLogWidget : public QWidget
{
    Q_OBJECT
        Q_PROPERTY(QIcon infoIcon READ infoIcon WRITE setInfoIcon)
        Q_PROPERTY(QIcon warningIcon READ warningIcon WRITE setWarningIcon)
        Q_PROPERTY(QIcon errorIcon READ errorIcon WRITE setErrorIcon)
public:

    enum class QCtmLogColumn    //��־��ö��
    {
        Level,                  //��־�ȼ�
        Time,                   //��־ʱ��
        Description             //��־����
    };

    QCtmLogWidget(const QString& objectName, QWidget *parent = Q_NULLPTR);
    ~QCtmLogWidget();

    /**
     * @brief		������־����˳��
     * @param[in]	mode ��־����˳��
     */
    void setLogInsertMode(LogInsertMode mode);

    /**
     * @brief		��ȡ��־����˳��
     * @Return:		��־����˳��
     */
    LogInsertMode logInsertMode() const;

    /**
     * @brief		������־���Ƿ���ʾ
     * @param[in]	column ��
     * @param[in]	visible �Ƿ���ʾ
     */
    void setColumnVisible(QCtmLogColumn column, bool visible);

    /**
     * @brief		��ȡ��־���Ƿ���ʾ
     * @param[in]	column ��
     * @Return:		�Ƿ���ʾ
     */
    bool columnVisible(QCtmLogColumn column) const;

    void setInfoIcon(const QIcon& icon);
    const QIcon& infoIcon() const;

    void setWarningIcon(const QIcon& icon);
    const QIcon& warningIcon() const;

    void setErrorIcon(const QIcon& icon);
    const QIcon& errorIcon() const;

    void setMaximumCount(int count);
    int maximumCount() const;
private:
    void init();
    void changeEvent(QEvent* e) override;
private slots:
    void updateLogCount();
private:
    struct Impl;
    std::unique_ptr<Impl> m_impl;
};
