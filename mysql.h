#ifndef MYSQL_H
#define MYSQL_H

#include <QtSql/QSqlDatabase>
#include <QStringList>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

class MySql
{
public:
    MySql();
    QSqlDatabase db;
    bool isConnected;
    QStringList strTables;
    QString insertline;

    bool open();

};

#endif // MYSQL_H
