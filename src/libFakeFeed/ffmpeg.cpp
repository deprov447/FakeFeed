#include "ffmpeg.h"

void
FFMPEG::stream ( )
{
  QString program = "ffmpeg";
  
  qDebug() << "Reading from" << m_vFileLocation;

  QStringList arguments;
  arguments << "-re" << "-i" << m_vFileLocation;
  arguments << "-f" << "v4l2" << m_loopbackDevice;

  qDebug() << "Writing to" << m_loopbackDevice;

  QProcess *callStream = new QProcess( );
  callStream->start( program, arguments );
  
  qDebug() << "callStream process started";
}

void
FFMPEG::textFileGenerator ( QString tfileAddress, int loopMax )
{
    m_tFileLocation = tfileAddress;
    qDebug() << "textfileGenerator called with arguments" << tfileAddress << loopMax;

    QFile textFile ( tfileAddress );
    if (!textFile.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream out( &textFile );
    while ( loopMax-- )
    {
        out << "file '" << m_vFileLocation << "'\n";
    }
}
