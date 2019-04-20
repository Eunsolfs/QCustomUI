#pragma once

#include "qcustomui_global.h"
#include "QCtmNavigationSidePanel.h"

class QCtmAbstractMessageModel;
class QCtmNavigationBar;

class QCUSTOMUI_EXPORT QCtmAbstractMessageView : public QCtmNavigationSidePanel
{
	Q_OBJECT

public:
	QCtmAbstractMessageView(QCtmNavigationBar *parent);
	~QCtmAbstractMessageView();

	 /** 
	  * @brief  ����model
	  * @param  model ��Ϣmodel	
	  */
	virtual void setModel(QCtmAbstractMessageModel* model) = 0;

	 /** 
	  * @brief  ��ȡ��Ϣmodel
	  * @return ��Ϣmodel
	  */
	virtual QCtmAbstractMessageModel* model()const = 0;

};
