#pragma once

#include "QString"
#include "QObject"
#include "QDebug"
#include "QProcess"
#include <iostream>

class FFMPEG : public QObject {

  Q_OBJECT
//  Q_PROPERTY( READ hello )

  public:
    explicit FFMPEG (QObject* parent = 0) : QObject(parent) {};
    void hello ();
    void stream ( QString textfile, QString device );
};
