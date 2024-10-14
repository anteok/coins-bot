#ifndef USER_H
#define USER_H

#include <QSqlDatabase>


class UserTable
{
private:
    QSqlDatabase* db;
public:
    UserTable(QSqlDatabase *db);
    bool create(unsigned userId, QString nickname);
    bool grant_admin(unsigned userId);
};

#endif // USER_H
