#include "databasesetup.h"

#include <QDebug>
#include <QSqlQuery>

QSqlDatabase DatabaseSetup::getDatabase() {

    static QSqlDatabase db = QSqlDatabase::addDatabase( "QSQLITE" );
    db.setDatabaseName( "tasobri.db" );

    if ( !db.open() ) {
        qDebug() << "Falha ao abrir o banco de dados!";

    }

    return db;

}

void DatabaseSetup::setup() {

    QSqlQuery query( getDatabase() );
    query.exec( R"(
        CREATE TABLE IF NOT EXISTS topics (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            name TEXT NOT NULL,
            start_date DATE NOT NULL DEFAULT CURRENT_DATE,
            last_reset_date DATE DEFAULT NULL,
            current_streak INT DEFAULT 0,
            longest_streak INT DEFAULT 0
        )
    )" );

}
