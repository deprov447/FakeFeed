#include "module.h"

bool
Module::findOriginalCam ()
{
    return true;
};

bool
Module::manageDevice ( QString deviceName, bool toRemove )
{
  QString program = "modprobe"; //permission

  QStringList arguments;
  if( toRemove )
  {
    arguments << "-r";
    qDebug() << "toRemove is set to" << toRemove;
  }
  arguments << deviceName;
  qDebug() << "deviceName is set to" << deviceName << deviceName.length();

  QProcess *callManageDevice = new QProcess(  );
  callManageDevice->start( program, arguments );
  qDebug() << "callManageDevice process done";

  return true; //toDo
};
