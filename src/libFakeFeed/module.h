#pragma once

#include "QString"
#include "QDebug"
#include "QStringList"
#include "QObject"
#include "QProcess"

class Module : public QObject {

    Q_OBJECT

  public :
    explicit Module (QObject* parent = 0) : QObject(parent) {}

    Q_INVOKABLE bool getOriginalCam ( QString webCamName );
    Q_INVOKABLE bool manageDevice ( QString deviceName, bool toRemove );

  private :
    QString m_OriginalCam = "uvcvideo" ;

};
