#ifndef TOPICDTO_H
#define TOPICDTO_H

#include <QObject>

class TopicDTO : public QObject {
    Q_OBJECT
    Q_PROPERTY( int currentStreak READ currentStreak CONSTANT FINAL )
    Q_PROPERTY( QString name READ name CONSTANT FINAL )
public:
    TopicDTO( const QString& name, const int currentStreak, QObject* parent = nullptr );

    int currentStreak() const;
    QString name() const;

private:
    int _currentStreak;
    QString _name;

};

#endif // TOPICDTO_H
