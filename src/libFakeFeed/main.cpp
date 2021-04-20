#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QUrl>
#include <KLocalizedContext>
#include <KLocalizedString>
#include <QDebug>
#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QString>
#include <QStringList>

#include "module.h"
#include "ffmpeg.h"
#include "test.h"

int main(int argc, char *argv[])
{
  QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QGuiApplication app(argc, argv);
  KLocalizedString::setApplicationDomain("helloworld");
  QCoreApplication::setOrganizationName("deprov447");
  QCoreApplication::setOrganizationDomain("deprov447.netlify.app");
  QCoreApplication::setApplicationName("Hello World");

  QCommandLineParser parser;
  QCommandLineOption testOption ( QStringList() << QStringLiteral( "t" ) << QStringLiteral( "test" )
                                , QCoreApplication::translate( "main", "Raw tests without GUI" ) );
  parser.addOption( testOption );
  parser.process( app );
  bool isTestMode = parser.isSet( testOption );
  if ( isTestMode )
  {
      qDebug() << "Test Mode";
      Test t;
      t.initiateTest();
      return 0;
  }

  QQmlApplicationEngine engine;
  qDebug() << "QML engine instantiated";

  auto temp = new KLocalizedContext( &engine );
  engine.rootContext()->setContextObject( temp );
  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

  if(engine.rootObjects().isEmpty())
  {
    return -1;
  }

  return app.exec();
}
