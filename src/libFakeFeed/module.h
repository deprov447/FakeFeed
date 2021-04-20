#pragma once

#include "QString"
#include "QDebug"
#include "QStringList"
#include "QObject"
#include "QProcess"

class Module {
  public :
    bool findOriginalCam ();
    bool manageDevice ( QString deviceName, bool toRemove );
  private :
    QString m_OriginalCam;
};
