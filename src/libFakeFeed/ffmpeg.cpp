#include "ffmpeg.h"
#include <iostream>

#include "QProcess"
#include "QStringList"
#include "QString"
#include "QObject"

void
ffmpeg::stream ( QString textfile, QString device )
{
  QObject *parent;
  QString program="ffmpeg";
  
  QStringList arguments;
  arguments<<"-re"<<"-f"<<"concat"<<"i"<<textfile;
  arguments<<"-f"<<"v4l2"<<device;

  QProcess *callStream = new QProcess( parent );
  callStream->start( program, arguments );
}

void
ffmpeg::hello ()
{
  std::cout<<"hello";
}
