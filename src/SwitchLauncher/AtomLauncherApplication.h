#pragma once

#include <QApplication>

class AtomMainWindow;

class AtomLauncherApplication : public QApplication
{
    Q_OBJECT

public:
    /**
     * @brief	themeĿǰ��ѡ��Light��Blue
     */
    AtomLauncherApplication(int &argc, char **argv, const QString& theme = "Light");
    ~AtomLauncherApplication();

    /**
     * @brief		�ڵ��ù��캯��֮ǰ���øú������г�ʼ��
     */
    static void initBeforeStructure();

    /**
     * @brief       ��ȡmainWindow��ַ
     */
    AtomMainWindow* mainWindow() const;
private:
    void init(const QString& theme);
};
