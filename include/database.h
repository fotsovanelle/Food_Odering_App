#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

class database
{
public:
    database();
    QSqlDatabase mydb;
    void add_order(QString str);
};

#endif // DATABASE_H
