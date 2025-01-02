#ifndef TOPICDOMAIN_H
#define TOPICDOMAIN_H

#include <QDate>
#include <QString>

class TopicDomain {

public:
    TopicDomain( int id,
                 int currentStreak,
                 int longestStreak,
                 const QString& name,
                 const QDate& startDate,
                 const QDate& lastResetDate );

    int id() const;
    int currentStreak() const;
    int longestStreak() const;
    QString name() const;
    QDate startDate() const;
    QDate lastResetDate() const;

private:
    int _id;
    int _currentStreak;
    int _longestStreak;
    QString _name;
    QDate _startDate;
    QDate _lastResetDate;

};

#endif // TOPICDOMAIN_H
