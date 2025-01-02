#ifndef DATABASESETUP_H
#define DATABASESETUP_H

#include <QSqlDatabase>

class DatabaseSetup {

public:
    DatabaseSetup() = delete;

    static QSqlDatabase getDatabase();
    static void setup();

};

#endif // DATABASESETUP_H
