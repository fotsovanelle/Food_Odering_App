#include "database.h"
#include <iostream>

database::database()
{
    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("database.db");
    if (!mydb.open()){
        std::cout << "not open"<< std::endl;
    }else{
        std::cout << "opened"<< std::endl;
    }

    QString query = ("Create table Orders("
                      "id integer primary key autoincrement,"
                       "order_text varchar(255));");
    QSqlQuery qry;
    if(!qry.exec(query)){
        qDebug()<<"error creating table";
    }
    qDebug() << "end";
}



void database::add_order(QString str){
    QSqlQuery qry;
    qry.prepare("insert into Orders(order_text) values(?);");
    qry.addBindValue(str);

    if(!qry.exec()){
        qDebug()<<"error adding value";
    }
}
