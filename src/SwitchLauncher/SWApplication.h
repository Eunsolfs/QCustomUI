#pragma once

#include "switchlauncher_global.h"

#include <QApplication>

#include <memory>

class QCtmMainWindow;
class QCtmDialog;

class SWITCHLAUNCHER_EXPORT SWApplication : public QApplication
{
    Q_OBJECT

public:
    /**
     * @brief	themeĿǰ��ѡ��Light��Blue
     */
    SWApplication(int &argc, char **argv, const QString& theme = "Light");
    ~SWApplication();

    /**
     * @brief		�ڵ��ù��캯��֮ǰ���øú������г�ʼ��
     */
    static void initBeforeStructure();

    /**
     * @brief       ��ȡmainWindow��ַ
     */
    QCtmMainWindow* mainWindow() const;

	/**
	 * @brief		���ù��ڴ��ڵ�ַ	
	 */
	void setAboutDialog(QCtmDialog* about);

	/**
	 * @brief		��ȡ���ڴ��ڵ�ַ
	 */
	QCtmDialog* aboutDialog() const;

	/**
	 * @brief		�Ƿ��ʼ���ɹ�
	 */
	static bool isSuccessful();

	static int exec();

	/**
	 * @brief		�Ƿ��Ե���ģʽ��������ȷ���ú�����SWApplication����֮ǰ������
	 * @param[in]	flag��Ĭ��Ϊ��
	 */
	static void setSingleton(bool flag);

	/**
	 * @brief		���õ���ģʽ�Ĺؼ��֣����ú���һ�����иùؼ��ֵĳ����޷�������ȷ���ú�����
		SWApplication����֮ǰ������
	 * @param[in]	key���ؼ���
	 */
	static void setSingletonKey(const QString& key);
private:
    void init(const QString& theme);
	
private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};
