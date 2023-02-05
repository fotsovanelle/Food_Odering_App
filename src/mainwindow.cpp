#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    QPixmap picAchu("C:/Users/bungong/Documents/QT_tutorial/Food_App/images/Achu.jpg");
    QPixmap picERU("C:/Users/bungong/Documents/QT_tutorial/Food_App/images/Eru.jpg");
    QPixmap picKoki("C:/Users/bungong/Documents/QT_tutorial/Food_App/images/koki.jpg");
    QPixmap picPasta("C:/Users/bungong/Documents/QT_tutorial/Food_App/images/pasta.jpg");
    QPixmap picFrid("C:/Users/bungong/Documents/QT_tutorial/Food_App/images/frid.jpg");
    QPixmap picMeat("C:/Users/bungong/Documents/QT_tutorial/Food_App/images/meat.jpg");
    ui->label_ACHU->setPixmap(picAchu.scaled(ui->label_ACHU->width(),ui->label_ACHU->height(),Qt::KeepAspectRatio));
    ui->label_ERU->setPixmap(picERU.scaled(ui->label_ERU->width(),ui->label_ERU->height(),Qt::KeepAspectRatio));
    ui->label_Koki->setPixmap(picKoki.scaled(ui->label_Koki->width(),ui->label_Koki->height(),Qt::KeepAspectRatio));
    ui->label_Pasta->setPixmap(picPasta.scaled(ui->label_Pasta->width(),ui->label_Pasta->height(),Qt::KeepAspectRatio));
    ui->label_Frid->setPixmap(picFrid.scaled(ui->label_Frid->width(),ui->label_Frid->height(),Qt::KeepAspectRatio));
    ui->label_Meat->setPixmap(picMeat.scaled(ui->label_Meat->width(),ui->label_Meat->height(),Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_View_card_clicked()
{
    card += "Total = " + QString::number(total);
    card += " FCFA";
    ui->stackedWidget->setCurrentIndex(1);
    ui->ViewOder_text->setText(card);

}



void MainWindow::on_Back_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::add_message(){
    QMessageBox::information(this,tr("ADD TO CARD"),tr("Item added successfully."));
}
void MainWindow::on_pay_clicked()
{
    db.add_order(card);
    pay_message();
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_Add_Achu_clicked()
{
    add_message();
    card += ("1 plate of Achu \n");
    total += 2000;
}


void MainWindow::on_Add_Eru_clicked()
{
    add_message();
    card += ("1 plate of Eru \n");
    total += 1000;
}


void MainWindow::on_Add_koki_clicked()
{
    add_message();
    card += ("1 plate of Koki \n");
    total += 1500;
}


void MainWindow::on_Add_pasta_clicked()
{
    add_message();
    card += ("1 plate of Pasta \n");
    total += 2000;
}


void MainWindow::on_Add_frid_clicked()
{
    add_message();
    card += ("1 plate of Frid\n");
    total += 2500;
}


void MainWindow::on_Add_meat_clicked()
{
    add_message();
    card += ("1 plate of Meat \n");
    total += 8000;
}

void MainWindow::pay_message(){
     QMessageBox::information(this,tr("payment"),tr("Paid successfully."));
}

void MainWindow::on_order_history_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery *qry = new QSqlQuery(db.mydb);
    qry->prepare("select order_text from Orders");
    qry->exec();
    modal->setQuery(*qry);
    ui->listView->setModel(modal);
    qDebug()<< modal->rowCount();
}

