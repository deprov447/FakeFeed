#include "QDebug"
#include "QString"
#include "QStringList"
#include "QObject"
#include "QProcess"

bool
Module::findOriginalCam ()
{

};

bool
Module::manageDevice ( QString deviceName, bool toRemove )
{
  QObject *parentl;
  QString program = "modprobe"; //permission

  QStringList arguments;
  if( toRemove )
  {
    arguments << "-r";
    QDebug() << "toRemove is set to" << toRemove;
  }
  arguments << deviceName;
  QDebug() << "deviceName is set to" << deviceName;

  QProcess *callManageDevice = new QProcess( parent );
  callManageDevice->start( program, arguments );
  QDebug() << "callManageDevice process called";

  return true; //toDo
};
