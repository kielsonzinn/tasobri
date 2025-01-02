#include "topiccontrol.h"

#include <QDate>
#include <QSqlQuery>
#include <QVariant>

#include "../config/databasesetup.h"
#include "../dto/topicdto.h"

//TODO SEPARAR ESSE CONTROL EM LIST E CREATE
TopicControl::TopicControl( QObject* parent ) :
    QObject{ parent },
    _topics( getTopicsByDatabase() ) {}

TopicControl::~TopicControl() {
    qDeleteAll( _topics );
}

QList<TopicDTO*> TopicControl::topics() const {
    return _topics;
}

void TopicControl::refresh() {
    _topics = getTopicsByDatabase();
    emit topicsChanged();
}

void TopicControl::doSave( const QString& name, const QString& date ) const {

    QDate startDate = QDate::fromString( date, "dd/MM/yyyy" );

    QSqlQuery query( DatabaseSetup::getDatabase() );

    int currentStreak = startDate.daysTo( QDate::currentDate() );
    int longestStreak = 0;

    query.prepare( "INSERT INTO topics (name, start_date, current_streak, longest_streak) "
                   "VALUES (?, ?, ?, ?)" );
    query.addBindValue( name );
    query.addBindValue( startDate.toString( "yyyy-MM-dd" ) );
    query.addBindValue( currentStreak );
    query.addBindValue( longestStreak );

    query.exec();

}

QList<TopicDTO*> TopicControl::getTopicsByDatabase() const {

    QSqlQuery query( DatabaseSetup::getDatabase() );
    query.exec( "SELECT name, current_streak FROM topics" );

    QList<TopicDTO*> dtos = {};

    while ( query.next() ) {
        dtos.append( new TopicDTO( query.value( "name" ).toString(), query.value( "current_streak" ).toInt() ) );
    }

    return dtos;

}
