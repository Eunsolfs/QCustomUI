#pragma once

#include "qcustomui_global.h"

#include <QWidget>

#include <memory>

class QCUSTOMUI_EXPORT QCtmToolBox :public QWidget
{
	Q_OBJECT

public:
	QCtmToolBox(QWidget* parent);
	~QCtmToolBox();

	/**
	 * @brief      ���һ���Ӵ���
	 * @param[in]  title ����
	 * @param[in] 	widget �Ӵ��ڵ�ַ
	 */
	void addWidget(const QString& title, QWidget* widget);

	/**
	 * @brief      ����һ���Ӵ���
	 * @param[in]  index ����λ��
	 * @param[in] 	title ����
	 * @param[in] 	widget �Ӵ��ڵ�ַ
	 */
	void insertWidget(int index, const QString& title, QWidget* widget);

	/**
	 * @brief  		�Ƴ��Ӵ���
	 * @param[in]  	widget �Ӵ��ڵ�ַ
	 */
	void removeWidget(QWidget* widget);

	/**
     * @brief  		�Ƴ��Ӵ���
     * @param[in]  	index �Ӵ���λ��
     */
	void removeWidget(int index);

	/**
     * @brief  		��ѯ�Ӵ���λ��
     * @param[in]  	widget �Ӵ��ڵ�ַ
     * @Return:   	�Ӵ���λ��
     */
	int indexOf(QWidget* widget) const;

	/**
	 * @brief  		��ѯָ��λ�õ��Ӵ���
	 * @param[in]  	index ָ��λ��
	 * @Return:   	�Ӵ��ڵ�ַ
	 */
	QWidget* widget(int index) const;

	/**
     * @brief  		�����Ӵ��ڼ�Ĭ����ʾ����
     * @param[in]  	index �Ӵ���λ��
     * @param[in] 	stretch �Ӵ�����ʾ����
     */
	void setStretchFactor(int index, int stretch);

	/**
     * @brief  		���ø��Ӵ��ڵ���ʾ��С(�߶�)
     * @param[in]  	sizes ���ϵ��µĴ�С����
     */
	void setSizes(const QList<int>& sizes);

	/**
	 *  @brief      ���ô��ڵ�һ����ʾʱ�ı���
	 *  @param[in]  index �������
	 *  @param[in] 	stretch ����
	 */
	void setDefaultStretch(int index, int stretch);
protected:
	void showEvent(QShowEvent *event) override;

private:
	struct Impl;
	std::shared_ptr<Impl> m_impl;
};