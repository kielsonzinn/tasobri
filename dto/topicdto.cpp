#include "topicdto.h"

TopicDTO::TopicDTO( const QString& name, const int currentStreak, QObject* parent ) :
    QObject( parent ),
    _currentStreak( currentStreak ),
    _name( name ) {}

int TopicDTO::currentStreak() const {
    return _currentStreak;
}

QString TopicDTO::name() const {
    return _name;
}
