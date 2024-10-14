//
// Created by kanogwaith on 14.10.2024.
//

#ifndef QT_CMAKE_COINS_BOT_BALANCE_H
#define QT_CMAKE_COINS_BOT_BALANCE_H


#include <QSqlDatabase>

class BalanceTable {
private:
    QSqlDatabase* db;
public:
    BalanceTable(QSqlDatabase *db);
    bool create(unsigned userId, int startBalance = 10);
    bool changeBalance(unsigned userId, int balanceDiff);
};


#endif //QT_CMAKE_COINS_BOT_BALANCE_H
