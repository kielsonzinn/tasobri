#ifndef TOPICCONTROL_H
#define TOPICCONTROL_H

#include <QObject>

class TopicDTO;

class TopicControl : public QObject {
    Q_OBJECT
    Q_PROPERTY( QList<TopicDTO*> topics READ topics NOTIFY topicsChanged )
public:
    explicit TopicControl( QObject* parent = nullptr );
    ~TopicControl();

    QList<TopicDTO*> topics() const;

signals:
    void topicsChanged();

public slots:
    void refresh();
    void doSave( const QString& name, const QString& date ) const;

private:
    QList<TopicDTO*> _topics;

    QList<TopicDTO*> getTopicsByDatabase() const;

};

#endif // TOPICCONTROL_H
