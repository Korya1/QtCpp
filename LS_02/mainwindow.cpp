#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCommonStyle>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model = new QStandardItemModel();
    ui->listView->setModel(model);

    QCommonStyle style;
    ui->pushButton_3->setIcon(style.standardIcon(QStyle::SP_ArrowUp));
    ui->pushButton_4->setIcon(style.standardIcon(QStyle::SP_ArrowDown));

    model->appendRow(new QStandardItem(QIcon("../QtLesson2/data/c++.png"),"C++"));
    model->appendRow(new QStandardItem(QIcon("../QtLesson2/data/python.png"),"Python"));
    model->appendRow(new QStandardItem(QIcon("../QtLesson2/data/java.png"),"Java"));
    model->appendRow(new QStandardItem(QIcon("../QtLesson2/data/csharp.png"),"C#"));
    model->appendRow(new QStandardItem(QIcon("../QtLesson2/data/php.png"),"PHP"));
    model->appendRow(new QStandardItem(QIcon("../QtLesson2/data/javascript.png"),"JavaScript"));

    model2 = new QStandardItemModel();
    ui->tableView->setModel(model2);
    ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);

    model2->setHorizontalHeaderItem(0,new QStandardItem(QString("№")));
    model2->setHorizontalHeaderItem(1,new QStandardItem(QString("Computer name")));
    model2->setHorizontalHeaderItem(2,new QStandardItem(QString("IP")));
    model2->setHorizontalHeaderItem(3,new QStandardItem(QString("MAC")));

    QList<QStandardItem*>list;
    list.append(new QStandardItem("1"));
    list.append(new QStandardItem("compukter_01"));
    list.append(new QStandardItem("127.0.0.1"));
    list.append(new QStandardItem("01-F8-61-F9-10-FF"));
    model2->appendRow(list);

    list.clear();
    list.append(new QStandardItem("2"));
    list.append(new QStandardItem("compukter_02"));
    list.append(new QStandardItem("127.0.0.2"));
    list.append(new QStandardItem("02-F8-61-F9-10-FF"));
    model2->appendRow(list);

    list.clear();
    list.append(new QStandardItem("3"));
    list.append(new QStandardItem("compukter_03"));
    list.append(new QStandardItem("127.0.0.3"));
    list.append(new QStandardItem("03-F8-61-F9-10-FF"));
    model2->appendRow(list);


    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onPushButton_PushButton);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::onPushButton_PushButton2);
    connect(ui->checkBox, &QCheckBox::pressed, this, &MainWindow::checkBox_PressedCheckBox);
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::on_upPushButton_Clicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::on_downPushButton_Clicked);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::on_pushButton_5_Clicked);

}

MainWindow::~MainWindow()
{
    delete ui;    
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    QString str = ui->lineEdit->text();

    str.replace("#@AUT@", "©");
    str.replace("#@PROM@", "‰");
    str.replace("#@EU@", "€");
    str.replace("#@RUB@", "₽");

    ui->lineEdit->setText(str);
}

void MainWindow::onPushButton_PushButton(){
    model->appendRow(new QStandardItem(QIcon("../QtLesson2/data/default.png"),"New Item..."));
}

void MainWindow::onPushButton_PushButton2(){
    QModelIndex index = ui->listView->selectionModel()->currentIndex();
    model->removeRow(index.row());
}

void MainWindow::checkBox_PressedCheckBox(){

    bool isOn = ui->checkBox->isChecked();
    (!isOn) ? ui->listView->setViewMode(QListView::IconMode) :
              ui->listView->setViewMode(QListView::ListMode);
}

void MainWindow::on_upPushButton_Clicked()
{
    int currRow = ui->listView->selectionModel()->currentIndex().row();
    if(currRow > 0 && ui->listView->selectionModel()->hasSelection()) {
        QStandardItem* item1 = model->takeItem(currRow - 1);
        QStandardItem* item2 = model->takeItem(currRow);
        model->removeRow(currRow);
        model->removeRow(currRow - 1);
        model->insertRow(currRow - 1, item2);
        model->insertRow(currRow, item1);
    }
}

void MainWindow::on_downPushButton_Clicked()
{
    int currRow = ui->listView->selectionModel()->currentIndex().row();
    if(currRow < model->rowCount() - 1 && ui->listView->selectionModel()->hasSelection()) {
        QStandardItem* item1 = model->takeItem(currRow + 1);
        QStandardItem* item2 = model->takeItem(currRow);
        model->removeRow(currRow + 1);
        model->removeRow(currRow);
        model->insertRow(currRow, item1);
        model->insertRow(currRow + 1, item2);
    }
}

void MainWindow::on_pushButton_5_Clicked()
{
    QModelIndexList list = ui->tableView->selectionModel()->selectedRows();

    for(auto i : list) {
        int cCount = i.model()->columnCount();
        for(int j = 0; j < cCount; j++) {
            model2->item(i.row(), j)->setBackground(Qt::red);
        }
    }
}

