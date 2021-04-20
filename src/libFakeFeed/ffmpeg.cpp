#include "ffmpeg.h"
#include <iostream>

#include "QDebug"
#include "QProcess"
#include "QStringList"
#include "QString"
#include "QObject"

void
ffmpeg::stream ( QString textfile, QString device )
{
  QObject *parent;
  QString program = "ffmpeg";
  
  QDebug() << "Reading from" << textfile;

  QStringList arguments;
  arguments << "-re" << "-f" << "concat" << "i" << textfile;
  arguments << "-f" << "v4l2" << device;

  QDebug() << "Writing to" << device;

  QProcess *callStream = new QProcess( parent );
  callStream->start( program, arguments );
  
  QDebug() << "callStream process started";
}

void
ffmpeg::hello ()
{
  std::cout << "hello";
}
