#pragma once

#include "QString"
#include "QObject"
#include "QDebug"
#include "QProcess"
#include "QFile"

class FFMPEG : public QObject {

    Q_OBJECT

  public:
    explicit FFMPEG (QObject* parent = 0) : QObject(parent) {}

    Q_INVOKABLE void textFileGenerator ( QString tfileAddress, int loopMax );
    Q_INVOKABLE void stream ( );
    Q_INVOKABLE void fileInput ( QString fileAddress ) { m_vFileLocation = fileAddress.remove(0,7); };

  private:
    QString m_vFileLocation ;
    QString m_tFileLocation = "vtextfile.txt";
    QString m_loopbackDevice = "/dev/video0";

};
