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
  KLocalizedString::setApplicationDomain("fakefeed");
  QCoreApplication::setOrganizationName("deprov447");
  QCoreApplication::setOrganizationDomain("deprov447.netlify.app");
  QCoreApplication::setApplicationName("Fake Feed");

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

  qmlRegisterType<FFMPEG>("com.fakefeed.ffmpeg", 1, 0, "FFMPEG");
  qmlRegisterType<Module>("com.fakefeed.module", 1, 0, "MODULE");

  QQmlEngine engine;
  auto temp = new KLocalizedContext( &engine );
  engine.rootContext()->setContextObject( temp );

  QQmlComponent component(&engine,
          QUrl("qrc:/main.qml"));
  component.create();

  return app.exec();
}
