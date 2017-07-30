#include "mysql.h"
#include <QMessageBox>

MySql::MySql()
{
    isConnected = open();
}

bool MySql::open()
{
    QStringList drivers = QSqlDatabase::drivers();
    qDebug() << drivers;
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    //db.setHostName("192.168.0.150");
    //db.setPort(3306);//mysql远程登陆的默认端口是3306
    db.setDatabaseName("jtgl");
    db.setUserName("root");
    db.setPassword("840912");
    if(db.open())
    {
        qDebug() << "open jtgl database succeed";
        strTables = db.tables();
        return true;
    }
    else
    {
        qDebug() << db.lastError();
        QMessageBox::about(NULL,"error","数据库连接错误");
        return false;
    }
}
