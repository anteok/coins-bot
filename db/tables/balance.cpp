//
// Created by kanogwaith on 14.10.2024.
//

#include <QSqlQuery>
#include <QSqlError>
#include "balance.h"

BalanceTable::BalanceTable(QSqlDatabase *db) {
    this->db = db;
}

bool BalanceTable::create(unsigned int userId, int startBalance) {
    QSqlQuery query(*this->db);
    query.prepare("INSERT INTO balance (balance,user_id)"
                  "VALUES (:balance, :user_id)");
    query.bindValue(":balance", startBalance);
    query.bindValue(":user_id", userId);

    if (!query.exec()) {
        qDebug() << query.lastError();
        return false;
    }
    return true;
}

bool BalanceTable::changeBalance(unsigned int userId, int balanceDiff) {
    QSqlQuery query(*this->db);
    query.prepare("UPDATE balance SET balance = balance + :diff WHERE user_id = :user_id");
    query.bindValue(":diff", balanceDiff);
    query.bindValue(":user_id", userId);

    if (!query.exec()) {
        qDebug() << query.lastError();
        return false;
    }
    return true;
}