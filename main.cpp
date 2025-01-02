#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "config/databasesetup.h"
#include "control/topiccontrol.h"
#include "dto/topicdto.h"

int main( int argc, char* argv[] ) {

#if QT_VERSION < QT_VERSION_CHECK( 6, 0, 0 )
    QCoreApplication::setAttribute( Qt::AA_EnableHighDpiScaling );
#endif
    QGuiApplication app( argc, argv );

    QQmlApplicationEngine engine;

    qmlRegisterType<TopicControl>( "TopicControl", 1, 0, "TopicControl" );
    qRegisterMetaType<QList<TopicDTO*> >( "QList<TopicDTO*>" );

    DatabaseSetup::setup();

    const QUrl url( QStringLiteral( "qrc:/ui/main.qml" ) );
    QObject::connect( &engine, &QQmlApplicationEngine::objectCreated,
                      &app, [url]( QObject* obj, const QUrl& objUrl ) {
        if ( !obj && url == objUrl ) {
            QCoreApplication::exit( -1 );
        }
    }, Qt::QueuedConnection );
    engine.load( url );

    return app.exec();

}
