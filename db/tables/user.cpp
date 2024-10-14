#include "user.h"

#include <QSqlQuery>
#include <QSqlError>


UserTable::UserTable(QSqlDatabase *db) {
    this->db = db;
}

bool UserTable::create(unsigned int userId, QString nickname) {
    QSqlQuery query(*this->db);

    query.prepare("INSERT INTO users (user_id, nickname)"
                  "VALUES (:user_id, :nickname)");
    query.bindValue(":user_id", userId);
    query.bindValue(":nickname", nickname);

    if (!query.exec()) {
        qDebug() << query.lastError();
        return false;
    }
    return true;
}

bool UserTable::grant_admin(unsigned int userId) {
    QSqlQuery query(*this->db);

    query.prepare("UPDATE users SET role_id = 1 WHERE user_id = :user_id");
    query.bindValue(":user_id", userId);

    if (!query.exec()) {
        qDebug() << query.lastError();
        return false;
    }
    return true;
}
