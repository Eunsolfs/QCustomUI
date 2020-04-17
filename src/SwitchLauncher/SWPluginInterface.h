#pragma once

#include <QIcon>
#include <QAction>

#include <memory>

class QCtmTabWidget;
class QCtmNavigationSideBar;
class QCtmNavigationBar;
class QCtmMainWindow;
class QCtmNavigationMainMenu;
class QCtmActivityInterface;
class QCtmAbstractMessage;
class QCtmNavigationSidePanel;
class SWContextInterface;
typedef std::shared_ptr<QCtmAbstractMessage> QCtmAbstractMessagePtr;

typedef int ActionPosition;

constexpr auto SWPluginKey = "QCustomUi.SwitchLauncher.PluginInterface";

struct ActionInfo
{
    ActionInfo(QAction* a, ActionPosition p, QCtmNavigationSidePanel* sp = nullptr, bool always = false)
        : action(a)
        , position(p)
        , panel(sp)
        , alwaysShow(always) {}
    QAction* action{ nullptr };		            //Action��ַ
	QCtmNavigationSidePanel* panel{ nullptr };  //��������ַ�����panel��Ϊ�գ���action������panel��
    ActionPosition position;		            //Action��ͣ��λ��
    bool alwaysShow{ false };		            //Action�Ƿ�������ʾ
};

struct TabPageInfo
{
    QString title;					            //Tabҳ�ı���
    QWidget* widget{ nullptr };		            //Tabҳ��������
    QList<QAction*> actions;		            //Tabҳ���Ͻǵ�Action
};

struct StatusBarInfo
{
    enum WidgetPosition
    {
        Left,
        Right
    };
    QWidget* widget{ nullptr };		            //Ҫ����״̬���ϵ�weiget
    int stretch{ 0 };				            //������ռ����
    WidgetPosition position{ Left };            //����ͣ������
};

struct MenuInfo
{
    QMenu* menu{ nullptr };			            //Ҫ���ڲ˵����ϵ��Ӳ˵�
    bool alwaysShow{ false };		            //�Ƿ�������ʾ
};

struct SWUserData
{
    QVariant data;					            //�����ֶ��л����ʱ���丽����Ϣ
};

enum SWMessageEventType
{
	Add,
	Delete,
	Clicked
};


enum SWPluginAttribute
{
	SWPA_None,
	SWPA_DontShowInPluginMenu = 0x01,                  //����ʾ�ڲ���˵���
	SWPA_DontShowPluginNameInTitle = 0x02              //����ʾ������Ƶ�������
};

Q_DECLARE_FLAGS(SWPluginAttributes, SWPluginAttribute)
Q_DECLARE_OPERATORS_FOR_FLAGS(SWPluginAttributes)

enum class SWContextAttribute
{
	SWCA_None,
	SWCA_DontShowTitle = 0x01,                           //����ʾ������
	SWCA_LogInsertDESC = 0x02,                           //��־�������
	SWCA_QuitAlert = 0x04								 //�������˳�ʱ��ʾ
};

Q_DECLARE_FLAGS(SWContextAttributes, SWContextAttribute)
Q_DECLARE_OPERATORS_FOR_FLAGS(SWContextAttributes)

//����ӿ�
class SWPluginInterface
{
public:
    SWPluginInterface() = default;
    virtual ~SWPluginInterface() = default;

	/**
	 * @brief		���id����ֵ�͵�Խ�ȱ����غ���ʾ
	 */
    virtual int id() const = 0;

	/**
	 * @brief		�����ͼ�꣬����ʾ��QCtmNavigationMainMenu��
	 */
    virtual QIcon icon() const = 0;

	/**
	 * @brief		��������ƣ�����ʾ��QCtmNavigationMainMenu�����ڲ���л�ʱ��ʾ��������
	 */
    virtual QString name() const = 0;

	/**
	 * @brief		�����ʼ������������غ���ȵ��ó�ʼ������
	 * @param[in]	context ��������ģ����ڿ������
	 */
    virtual bool initialize(SWContextInterface* context) = 0;

	/**
	 * @brief		�����ж��ǰ���øú���
	 */
    virtual void release() = 0;

	/**
	 * @brief		�������ʽ���ɴ˽ӿڷ��ظ����
	 * @param[in]	theme ��ʽ����
	 */
    virtual QString styleSheet(const QString& theme) const = 0;

    /**
     * @brief		�л����ʱ���øýӿ�
     * @param[in]	current true���뵱ǰ�����false�г���ǰ���
     * @Return:		true:��ǰ��������л���false:��ǰ����ܾ��л�
     */
	virtual bool currentPluginChangeEvent(bool current, const SWPluginInterface* old, const SWUserData& data = SWUserData()) { return true; }

	/**
	 * @brief		�������ݣ�û���򷵻ؿ�
	 */
    virtual QWidget* content() const = 0;

	/**
	 * @brief		���������û�в�����򷵻ؿ�
	 */
	virtual QCtmNavigationSideBar* sideBar() const { return nullptr; }

	/**
	 * @brief		�μ����������û���򷵻ؿ�
	 */
	virtual QWidget* subSideBar() const { return nullptr; }

	/**
	 * @brief		Ҫ��QCtmNavigationBar����ʾ��Action��û���򷵻ؿ�list
	 */
	virtual QList<ActionInfo> navigationBarActions() const { return QList<ActionInfo>(); }

	/**
	 * @brief		Ҫ����Ϣ������ʾ��Tabҳ��û���򷵻ؿ�list
	 */
	virtual QList<TabPageInfo> messageBarTabPages() const { return QList<TabPageInfo>(); }

	/**
	 * @brief		Ҫ��״̬������ʾ�Ĵ���
	 */
	virtual QList<StatusBarInfo> statusBarWidgets() const { return QList<StatusBarInfo>(); }

	/**
	 * @brief		Ҫ�ڱ������Ĳ˵�������ʾ�Ĳ˵���
	 */
	virtual QList<MenuInfo> subMenus() const { return QList<MenuInfo>(); }

	/**
	 * @brief		���еĲ��������ɺ���øú���
	 */
	virtual void allActivitiesInitialized() {};

    /**
     * @brief		�����������
     * @Return:		������Լ���
     */
    virtual SWPluginAttributes attributes() const { return SWPluginAttribute::SWPA_None; }
};

//�����Ϣ��
class SWPluginSlots
{
public:
	SWPluginSlots() = default;
	~SWPluginSlots() = default;
	/**
	 * @brief		�˵���action����¼�
	 * @param[in]	action �������action
	 */
	virtual void onMenuBarActionTriggered(QAction* action) {}

	/**
	 * @brief		��Ӧ��Ϣ��ʾ��
	 * @param[in]	msg ��Ϣ����
	 * @param[in]	type ��Ϣ��������/ɾ/���
	 * @Return:		
	 */
	virtual void onMessageTip(QCtmAbstractMessagePtr msg, SWMessageEventType type) {}

	/**
	 * @brief		��Ӧ�û���ť����¼�
	 * @Return:		
	 */
	virtual void onUserActionTriggered() {}
};

Q_DECLARE_INTERFACE(SWPluginInterface, SWPluginKey)

//���������
class SWContextInterface
{
public:
	SWContextInterface() = default;
	~SWContextInterface() = default;

	/**
	 * @brief		���ݲ�����ƻ�ȡ�����ַ
	 */
	virtual SWPluginInterface* plugin(const QString& name) const = 0;

	/**
	 * @brief		��ȡ�����ַ�б�
	 */
	virtual QList<SWPluginInterface*> plugins() const = 0;

	/**
	 * @brief		��ȡ��������б�
	 */
	virtual QStringList activitiesNames() const = 0;

	/**
	 * @brief		���õ�ǰ��ʾ���
	 * @param[in]	activity ��ǰ�����ַ
	 * @param[in]	data ��������
	 * @Return:		�Ƿ��л��ɹ�
	 */
	virtual bool setCurrentPlugin(SWPluginInterface* activity, const SWUserData& data = SWUserData()) = 0;

    /**
     * @brief		��ǰ��ʾ�Ĳ����ַ
     * @Return:		�����ַ
     */
    virtual SWPluginInterface* currentPlugin() const = 0;

	/**
	 * @brief		����Ϣ��ʾ�����һ����Ϣ
	 * @param[in]	msg ��Ϣ����
	 */
	virtual void addMessageTip(QCtmAbstractMessagePtr msg) = 0;

	/**
	 * @brief		���Logo
	 * @param[in]	icon logoͼ��
	 * @param[in]	pos logoͣ������
	 * @Return:		logo��ַ
	 */
	virtual QAction* addLogo(const QIcon& icon, ActionPosition pos = 0) = 0;

	/**
	 * @brief		�����û�����Ȩ��
	 * @param[in]	user �û���
	 * @param[in]	authority Ȩ��
	 */
	virtual void setUserInfo(const QString& user, const QString& authority) = 0;

    /**
     * @brief		������Ϣ���Ƿ�����
     * @param[in]	visible true:��ʾ��false:����
     */
    virtual void setMessageBarVisible(bool visible) = 0;

    /**
     * @brief		��ȡ��Ϣ���Ƿ�����
     */
    virtual bool messageBarVisible() const = 0;

    /**
     * @brief		�������ԣ�Ŀǰ֧��CN��EN���֣������ĺ�Ӣ�ģ�Ĭ��ΪӢ�ġ�
     *              Ŀǰδʵ�ֶ�̬�����л����������޸������ļ�Ϊ׼��
     * @param[in]	language ����
     */
    virtual void setLanguage(const QString& language) = 0;

    /**
     * @brief		��ȡ��ǰ����
     * @Return:		��ǰ����
     */
    virtual const QString& language() const = 0;

    /**
     * @brief		����Context����
     * @param[in]	features ���Լ���
     */
    virtual void setAttributes(SWContextAttributes features) = 0;

	/**
	 * @brief		����Context����
	 * @param[in]	attribute ����
	 * @param[in]	enable ����/����
	 */
	virtual void setAttribute(SWContextAttribute attribute, bool enable = true) = 0;

    /**
     * @brief		��ȡcontext������
     * @Return:		���Լ���
     */
    virtual SWContextAttributes attributes() const = 0;

	/**
	 * @brief		������Ϣ����ǰ��ʾҳ��
	 * @param[in]	index ҳ������
	 */
	virtual void setMessageBarCurrentIndex(int index) = 0;

	/**
	 * @brief		��ȡ��Ϣ����ǰ��ʾҳ��
	 * @param[in]	
	 * @param[in]	
	 * @Return:		
	 */
	virtual int messageBarCurrentIndex() const = 0;

    /**
     * @brief		��ȡĬ����ʽ
     * @param[in]	theme ��ʽ����
     * @Return:		��ʽԴ��
     */
    virtual QString defaultStyleSheet(const QString& theme) const = 0;

	/**
	 * @brief		��ȡ�����ڵ�ַ
	 */
	virtual QCtmMainWindow* mainWindow() const = 0;
};
