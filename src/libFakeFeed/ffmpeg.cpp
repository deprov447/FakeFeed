#include "ffmpeg.h"
#include "globalStorage.h"

void
FFMPEG::stream ( )
{
  QString program = "ffmpeg";
  
  qDebug() << "Reading from" << m_vFileLocation;

  QStringList arguments;
  arguments << "-re" << "-i" << m_vFileLocation;
  arguments << "-f" << "v4l2" << "/dev/video" + GlobalStorage::vDeviceID ;

  qDebug() << "Writing to device number" << GlobalStorage::vDeviceID;

  QProcess *callStream = new QProcess( );
  callStream->start( program, arguments );
}

void
FFMPEG::textFileGenerator ( QString tfileAddress, int loopMax )
{
    m_tFileLocation = tfileAddress;
    qDebug() << "textfileGenerator address set to" << tfileAddress;
    qDebug() << "textfileGenerator loopCount set to"<< loopMax;

    QFile textFile ( tfileAddress );
    if (!textFile.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream out( &textFile );
    while ( loopMax-- )
    {
        out << "file '" << m_vFileLocation << "'\n";
    }
}
