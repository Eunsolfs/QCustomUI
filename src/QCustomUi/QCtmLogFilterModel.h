#pragma once

#include <QSortFilterProxyModel>

#include <memory>

class QCtmLogFilterModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    QCtmLogFilterModel(QObject *parent);
    ~QCtmLogFilterModel();

    /**
     * @brief		������־�к��йؼ��ֵ���Ϣ
     * @param[in]	keywords �ؼ���
     */
    void search(const QString& keywords);
    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;

    public slots:
    /**
     * @brief		������Ϣ�����Ƿ���ʾ
     * @param[in]	type ��Ϣ����
     * @param[in]	show �Ƿ���ʾ
     */
    void showLog(QtMsgType type, bool show);

private:
    struct Impl;
    std::shared_ptr<Impl> m_impl;
};
