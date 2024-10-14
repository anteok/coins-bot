#include <QProcessEnvironment>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QDebug>

#include "connector.h"


databaseConnector::databaseConnector() {
    QString dbUrl = QProcessEnvironment::systemEnvironment().value("DB_URL", "local.db");
    this->db = QSqlDatabase::addDatabase("QSQLITE");
    this->db.setDatabaseName(dbUrl);
    this->db.open();

    this->migrate();
}


void databaseConnector::migrate() {
    QFile migration("./migration.sql");
    if (migration.open(QFile::ReadOnly | QFile::Text)) {

        QTextStream migrationStream (&migration);
        QStringList queries = migrationStream.readAll().split(';');


        for (QStringList::Iterator queries_iter = queries.begin(); queries_iter != queries.end(); ++queries_iter) {
            QSqlQuery query(this->db);
            if (((*queries_iter).trimmed().size() > 0) && (!query.exec(*queries_iter))) {
                qDebug() << query.lastError();
            }
        }

    } else {
        qDebug() << "Cannot open migration file!";
    }

}


databaseConnector::~databaseConnector() {
    this->db.close();
}
