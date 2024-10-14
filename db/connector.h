#ifndef CONNECTOR_H
#define CONNECTOR_H

#include<QtSql/QSqlDatabase>

class databaseConnector
{
private:
    QSqlDatabase db;

    void migrate();
public:
    databaseConnector();
    QSqlDatabase* get_db();
    ~databaseConnector();
};

#endif // CONNECTOR_H
