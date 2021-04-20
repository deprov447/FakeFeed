#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QUrl>
#include <KLocalizedContext>
#include <KLocalizedString>

#include "ffmpeg.h"

int main(int argc, char *argv[])
{
  QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  QGuiApplication app(argc, argv);
  KLocalizedString::setApplicationDomain("helloworld");
  QCoreApplication::setOrganizationName("deprov447");
  QCoreApplication::setOrganizationDomain("deprov447.netlify.app");
  QCoreApplication::setApplicationName("Hello World");

  QQmlApplicationEngine engine;

  ffmpeg demo;
  qmlRegisterSingletonInstance<ffmpeg>("org.deprov447.example",1,0,"FFMPEG",&demo);

  auto temp = new KLocalizedContext( &engine );
  engine.rootContext()->setContextObject( temp );
  engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

  if(engine.rootObjects().isEmpty())
  {
    return -1;
  }

  return app.exec();
}
