#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMainWindow>
#include "database.h"
#include <QPixmap>
#include <QMessageBox>
#include <string>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_View_card_clicked();

    void on_Back_clicked();

    void on_pay_clicked();

    void on_Add_Achu_clicked();

    void on_Add_Eru_clicked();

    void on_Add_koki_clicked();

    void on_Add_pasta_clicked();

    void on_Add_frid_clicked();

    void on_Add_meat_clicked();

    void on_order_history_clicked();

private:
    Ui::MainWindow *ui;
    void add_message();
    void pay_message();
    QString card = "";
    int total = 0;
    database db;
};
#endif // MAINWINDOW_H
