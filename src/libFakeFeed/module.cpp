#include "module.h"
#include "globalStorage.h"

bool
Module::getOriginalCam ( QString webCamName )
{
    qDebug() << "getOriginal Cam called with argument" << webCamName;
    m_OriginalCam = webCamName;
    manageDevice( webCamName , true );      // this shouldn't live here
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
  qDebug() << "deviceName is set to" << deviceName;

  if( deviceName=="v4l2loopback" && !toRemove )
  {
      arguments << "video_nr=" + GlobalStorage::vDeviceID << "card_label=" + GlobalStorage::vDeviceName;
  }

  QProcess *callManageDevice = new QProcess(  );
  callManageDevice->start( program, arguments );
  qDebug() << "callManageDevice process done";

  return true; //toDo
};

void
Module::setvDeviceName ( QString deviceName )
{
    GlobalStorage::vDeviceName = deviceName;
}

void
Module::setvDeviceID ( QString deviceID )
{
    GlobalStorage::vDeviceID = deviceID;
}
