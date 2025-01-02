#include "topicdomain.h"

TopicDomain::TopicDomain( int id,
                          int currentStreak,
                          int longestStreak,
                          const QString& name,
                          const QDate& startDate,
                          const QDate& lastResetDate ) :
    _id( id ),
    _currentStreak( currentStreak ),
    _longestStreak( longestStreak ),
    _name( name ),
    _startDate( startDate ),
    _lastResetDate( lastResetDate )
{}

int TopicDomain::id() const {
    return _id;
}

int TopicDomain::currentStreak() const {
    return _currentStreak;
}

int TopicDomain::longestStreak() const {
    return _longestStreak;
}

QString TopicDomain::name() const {
    return _name;
}

QDate TopicDomain::startDate() const {
    return _startDate;
}

QDate TopicDomain::lastResetDate() const {
    return _lastResetDate;
}
