#pragma once

#include "QCtmWindow.h"

#include <memory>
#include <QStackedWidget>

class QCtmTabWidget;
class QCtmNavigationSideBar;

namespace Ui
{
    class QCtmMainWindow;
}

class QCUSTOMUI_EXPORT QCtmMainWindow : public QCtmWindow
{
    Q_OBJECT

public:
    enum class SideBarArea
    {
        Left,
        Right
    };

    enum class MessageBarArea
    {
        Bottom,
        Right
    };

    QCtmMainWindow(QWidget *parent = nullptr);
    ~QCtmMainWindow();

    /**
     * @brief       ����������������Ѵ�������������ɵĽ�������
     * @param[in]   mainSideBar ���������ַ
     */
    void setNavigationSideBar(QCtmNavigationSideBar* mainSideBar);

    /**
     * @brief       ��ȡ���������ַ�����û�������������򷵻ؿ�
     * @Return:     ���������ַ
     */
    QCtmNavigationSideBar* navigationSideBar()const;

    /**
     * @brief		�Ƴ����������������Ȩ
     */
    QCtmNavigationSideBar* takeNavigationSideBar();

    /**
     * @brief       �Ƴ��������
     */
    void removeNavigationSideBar();

    /**
     * @brief       ��Ӵμ������������μ�������Ѵ��ڣ��ɵĽ�������
     * @param[in]   subSideBar �μ��������ַ
     */
    void setSubSideBar(QWidget* subSideBar);

    /**
     * @brief       ���ض����������ַ
     * @Return:     �����������ַ
     */
    QWidget* subSideBar()const;

    /**
     * @brief		�Ƴ��������������������Ȩ
     */
    QWidget* takeSubSideBar();

    /**
     * @brief       �Ƴ��μ������
     */
    void removeSubSideBar();

    /**
     * @brief       ����������ʾ����
     * @param[in]   widget ���ڵ�ַ
     */
    void setContentWidget(QWidget* widget);

    /**
     * @brief       ��ȡcontent���ڵ�ַ
     * @Return:     content���ڵ�ַ
     */
    QWidget* contentWidget()const;

    /**
     * @brief		�Ƴ�content���ڲ���������Ȩ
     */
    QWidget* takeContentWidget();

    /**
     * @brief       ������Ϣ�������Ѵ�����Ϣ�����ɵ���Ϣ����������
     * @param[in]   messageBar ��Ϣ����ַ
     */
    void setMessageBar(QCtmTabWidget* messageBar);

    /**
     * @brief       ��ȡ��Ϣ����ַ
     * @Return:     ��Ϣ����ַ
     */
    QCtmTabWidget* messageBar()const;

    /**
     * @brief		�Ƴ���Ϣ������������Ȩ
     */
    QCtmTabWidget* takeMessageBar();

    /**
     * @brief       �Ƴ���Ϣ��
     */
    void removeMessageBar();

    /**
     * @brief       ����������������Ѵ������������ɵ���������������
     * @param[in]   propertyBar ��������ַ
     */
    void setPropertyBar(QWidget* propertyBar);

    /**
     * @brief       ��ȡ��������ַ
     * @Return:     ��������ַ
     */
    QWidget* propertyBar()const;

    /**
     * @brief		�Ƴ�����������������Ȩ
     */
    QWidget* takePropertyBar();

    /**
     * @brief       �Ƴ�������
     */
    void removePropertyBar();
    /**
     * @brief       ���ò����ͣ��λ��
     * @param[in]   area �������ʾ����
     */
    void setSideBarArea(SideBarArea area);

    /**
     * @brief       ��ȡ�����ͣ��λ��
     * @Return:     �����ͣ��λ��
     */
    SideBarArea sideBarArea()const;

    /**
     * @brief		������Ϣ����ʾ����
     * @param[in]	area ����
     */
    void setMessageBarArea(MessageBarArea area);

    /**
     * @brief		��ȡ��Ϣ����ʾ����
     * @Return:		����
     */
    MessageBarArea messageBarArea()const;

    /**
     * @brief       ���ò�����Ŀ��
     * @param[in]   width ���
     */
    void setSubSideBarWidth(int width);

    /**
     * @brief       ��ȡ������Ŀ��
     * @Return:     ���
     */
    int subSideBarWidth()const;

    /**
     * @brief       �������������
     * @param[in]   width ���������
     */
    void setPropertyBarWidth(int width);

    /**
     * @brief       ��ȡ���������
     * @Return:     ���
     */
    int propertyBarWidth()const;

    /**
     * @brief       ������Ϣ���߶�
     * @param[in]   height �߶�
     */
    void setMessageBarHeight(int height);

    /**
     * @brief       ��ȡ��Ϣ���߶�
     * @Return:     �߶�
     */
    int messageBarHeight()const;
protected:
    bool eventFilter(QObject *watched, QEvent *event) override;
    void showEvent(QShowEvent*)override;
    void doSize();

    private slots:
    void onTabWidgetAreaButtonClicked();
private:
    QList<int>& swap(QList<int>& sizes);

private:
    struct Impl;
    std::shared_ptr<Impl> m_impl;

    Ui::QCtmMainWindow* ui;
};
