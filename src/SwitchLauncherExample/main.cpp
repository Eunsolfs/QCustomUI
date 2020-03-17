#include <QtWidgets/QApplication>

#include <SwitchLauncher/SWApplication.h>
#include <QCustomUi/QCustomUi.h>
#include <QDebug>

int main(int argc, char *argv[])
{
	SWApplication::initBeforeStructure();
	SWApplication a(argc, argv);
	if (a.checkOtherProcess("sw_example"))
		return 0;
	if (a.isSuccessful())
	{
		a.mainWindow()->resize(1000, 600);
		a.mainWindow()->showMaximized();
	}
	qInfo() <<"#SW" << "1231111111111111111116346846Q4ERW\nERWEOIRWEIORIOWEUIORUWIORUIOWRIOWERFHWEFHSDHFSHIOFHIOFH11111111111111111111111111214423432423432423478236784238764782364782378462374678224278347823647862378482";
	qWarning() << "#SW" << "1231111111111111111116346846Q4ERW\nERWEOIRWEIORIOWEUIORUWIORUIOWRIOWERFHWEFHSDHFSHIOFHIOFH11111111111111111111111111214423432423432423478236784238764782364782378462374678224278347823647862378482";
	qCritical() << "#SW" << "1231111111111111111116346846Q4ERW\nERWEOIRWEIORIOWEUIORUWIORUIOWRIOWERFHWEFHSDHFSHIOFHIOFH11111111111111111111111111214423432423432423478236784238764782364782378462374678224278347823647862378482";

	return a.exec();
}
