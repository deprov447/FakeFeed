#include "ffmpeg.h"

void
FFMPEG::stream ( QString textfile, QString device )
{
  QString program = "ffmpeg";
  
  qDebug() << "Reading from" << textfile;

  QStringList arguments;
  arguments << "-re" << "-f" << "concat" << "i" << textfile;
  arguments << "-f" << "v4l2" << device;

  qDebug() << "Writing to" << device;

  QProcess *callStream = new QProcess( );
  callStream->start( program, arguments );
  
  qDebug() << "callStream process started";
}

void
FFMPEG::hello ()
{
  std::cout << "hello";
}
