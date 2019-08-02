#pragma once

#include "switchlauncher_global.h"

#include <QApplication>

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
private:
    void init(const QString& theme);
};
