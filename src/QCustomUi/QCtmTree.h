#pragma once

#include "qcustomui_global.h"

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QAction>
#include <QList>
#include <QMouseEvent>
#include <QMap>
#include <QScrollArea>
#include <QSplitter>

#include <memory>

class QCtmTreeItem;

class QCUSTOMUI_EXPORT QCtmTree : public QWidget
{
	Q_OBJECT
        Q_PROPERTY(bool exclusive READ exclusive WRITE setExclusive)
public:
	QCtmTree(QWidget *parent = nullptr);
	~QCtmTree();

	/** 
	 * @brief	    ���һ���Ӵ���
	 * @param[in]	title ����
     * @param[in]	widget �Ӵ��ڵ�ַ
     * @return:     item��ַ
	 */
    QCtmTreeItem* addWidget(const QString& title, QWidget* widget);

    /**
     * @brief	    ����һ���Ӵ���
     * @param[in]	index Ҫ�����λ��
     * @param[in]	title ����
     * @param[in]	widget �Ӵ��ڵ�ַ
     * @return:     item��ַ
     */
    QCtmTreeItem* insertWidget(int index, const QString& title, QWidget* widget);

	/** 
	 * @brief	    �Ƴ�һ��
	 * @param[in]	item Ҫ�Ƴ�����	
	 */
	void removeItem(QCtmTreeItem* item);

	/** 
	 * @brief	    ��ȡ������λ��
	 * @param[in]	item Ҫ��ȡλ�õ���
	 * @return: 	λ��
	 */
	int indexOf(QCtmTreeItem* item) const;

	/** 
	 * @brief	    ��ȡָ��λ�õ���
	 * @param[in]	index ָ��λ��
	 * @return:	    ���ַ	
	 */
	QCtmTreeItem* item(int index) const;

	/** 
	 * @brief	    �����������չ��״̬
	 * @param[in]	expand true:չ����false:��£	
	 */
	void setAllExpand(bool expand) const;

	/** 
     * @brief	    ��ȡ������
     * @return: 	������
     */
	int count() const;

    /**
     * @brief		��������չ�����⣬��ֻ����һ��չ��
     * @param[in]	
     */
    void setExclusive(bool exclusive);

    /**
     * @brief		�����Ƿ�չ������
     */
    bool exclusive() const;

    /**
     * @brief		����ÿһ��item�ĸ߶�
     * @param[in]	sizes ÿ��item�ĸ߶�
     */
    void setSizes(const QList<int>& sizes);
signals:
    /**
     * @brief		����չ���仯
     * @param[in]   item չ��״̬�����仯����
     * @param[in]	expand true:չ����false:�ر�
     */
    void itemExpandChanged(QCtmTreeItem* item, bool expand);

    /**
     * @brief		����������¼�
     * @param[in]	item �����ַ
     * @param[in]	expand true:չ����false:�ر�
     */
    void itemTitleClicked(QCtmTreeItem* item, bool expand);
protected:
	bool allClosed()const;
	int total(const QList<int>& sizes) const;
    void showEvent(QShowEvent* event) override;
private slots:
	void childExpandChanged(QCtmTreeItem* item, bool expand, int size);
    void doResize();
    void onItemExpand(bool expand);
    void onItemClicked(bool expand);
private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;
};

/*!***************************************************************************
* @class QCtmTreeItem
* @brief QCtmTree���ӽڵ�ʵ��
*****************************************************************************/
class QCUSTOMUI_EXPORT QCtmTreeItem:public QWidget
{
	Q_OBJECT
public:

	/**
     * @brief  		������ʾ����
     * @param[in]  	widget ���ڵ�ַ
	 */
	void setWidget(QWidget* widget);

	/**
	 * @brief  		��ȡ��ʾ���ڵ�ַ
	 * @Return:   	���ڵ�ַ
	 */
	QWidget* widget() const;

	/**
     * @brief  		����Ҷ�ӽڵ����
     * @param[in]  	title ����
     */
	void setTitle(const QString& title);

	/**
     * @brief  		��ȡҶ�ӽڵ����
     * @Return:   	����
     */
	QString title() const;

	/**
     * @brief  		��ȡ��ǰҶ�ӽڵ��Ƿ�չ��
     * @Return:   	true:չ����false:�ر�
     */
	bool isExpand()const;

	/**
	 * @brief  		���õ�ǰҶ�ӽڵ��Ƿ�չ��
	 * @param[in]  	expend true:չ����false:�ر�
	 */
	void setExpand(bool expand);

    /**
     * @brief		�ڱ��������һ����ť
     * @param[in]	icon ��ťͼ��
     * @param[in]	text ��ť����
     * @Return:		
     */
    QAction* addAction(const QIcon& icon, const QString& text);

    /**
    * @brief		�ڱ��������һ����ť
    * @param[in]	text ��ť����
    * @Return:
    */
    QAction* addAction(const QString& text);

    /**
     * @brief		�ڱ���������һ����ť
     * @param[in]	index Ҫ�����λ��
     * @param[in]   icon ��ťͼ��
     * @param[in]	text ��ť����
     * @Return:		
     */
    QAction* insertAction(int index, const QIcon& icon, const QString& text);

    /**
     * @brief		�ڱ���������һ����ť
     * @param[in]	index Ҫ�����λ��
     * @param[in]	text ��ť����
     * @Return:
     */
    QAction* insertAction(int index, const QString& text);

    /**
     * @brief		�ӱ������Ƴ���ť
     * @param[in]	action Ҫ�Ƴ��İ�ť
     */
    void removeAction(QAction *action);

    /**
     * @brief		���ⰴť����
     * @Return:		����
     */
    int count() const;

    /**
     * @brief		��ȡaction��λ��
     * @param[in]	action Ҫ��ȡλ�õ�action
     * @Return:		λ��
     */
    int indexOf(QAction* action);

    /**
     * @brief		��ȡָ��λ�õ�action
     * @param[in]	index ָ��λ��
     * @Return:		action��ַ
     */
    QAction* actionAt(int index);

signals:
    /**
     * @brief		չ��״̬�ı�
     * @param[in]	expand true:չ����false:�ر�
     */
    void expandChanged(bool expand);

    /**
     * @brief		����������ź�
     * @param[in]	expand true:չ����false:�ر�
     */
    void titleClicked(bool expand);
protected:
    QCtmTreeItem(const QString& title, QCtmTree* parent);
    ~QCtmTreeItem();

	private slots:
	void onClicked();
	void resizeEvent(QResizeEvent *event);

private:
	int suggestSize()const;
    void setSuggestSize(int size);
    void insertAction(int index, QAction* action);
private:
	struct Impl;
	std::unique_ptr<Impl> m_impl;

	friend QCtmTree;
};
