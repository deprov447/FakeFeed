#include "module.h"
#include "globalStorage.h"

bool
Module::getOriginalCam ( QString webCamName )
{
    qDebug() << "m_OriginalCam set to" << webCamName;
    m_OriginalCam = webCamName;
    manageDevice( webCamName , true );      // this shouldn't live here
    return true;                            // ToDo
};

bool
Module::manageDevice ( QString deviceName, bool toRemove )
{
  QString program = "modprobe";             //permission

  QStringList arguments;
  if( toRemove )
  {
    arguments << "-r";
  }
  arguments << deviceName;
  qDebug() << deviceName;

  if( deviceName=="v4l2loopback" && !toRemove )
  {
      qDebug() << "Loopback device number set to" << GlobalStorage::vDeviceID;
      qDebug() << "Loopback device name set to" << GlobalStorage::vDeviceName;
      arguments << "video_nr=" + GlobalStorage::vDeviceID << "card_label=" + GlobalStorage::vDeviceName;
  }

  QProcess *callManageDevice = new QProcess(  );
  callManageDevice->start( program, arguments );
  qDebug() << "Module" << deviceName << "Removed? :" << toRemove;

  return true; //toDo
};

void
Module::setvDeviceName ( QString deviceName )
{
    GlobalStorage::vDeviceName = deviceName;
    qDebug() << "vDeviceName set to" << deviceName;
}

void
Module::setvDeviceID ( QString deviceID )
{
    GlobalStorage::vDeviceID = deviceID;
    qDebug() << "vDeviceID set to" << deviceID;
}
