#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QLocale loc(QLocale::C);
    loc.setNumberOptions(QLocale::RejectGroupSeparator);

    QValidator *validator = new QDoubleValidator(this);

    validator->setLocale(loc);

    ui->lineEdit->setValidator(validator);
    ui->lineEdit_2->setValidator(validator);
    ui->lineEdit_3->setValidator(validator);

    ui->lineEdit_5->setValidator(validator);
    ui->lineEdit_6->setValidator(validator);
    ui->lineEdit_7->setValidator(validator);

//task 1
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onPushButton_Clicked);
//task 2
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::onPushButton_2_Clicked);
//task 3
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::onPushButton_3_Clicked);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::onPushButton_4_Clicked);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::onPushButton_5_Clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::onPushButton_Clicked()
{

     double a, b, c, d, x1, x2;
     a = ui->lineEdit->text().toDouble();
     b = ui->lineEdit_2->text().toDouble();
     c = ui->lineEdit_3->text().toDouble();

     d = b * b - 4 * a * c;

         if (qFuzzyIsNull(a))
         {
             x1 = (-1) * (c / b);
             ui->lineEdit_4->setText("x1 = " + QString::number(x1));
         }
         else if (d > 0)
         {
             x1 = ((-b) - qSqrt(d)) / (2 * a);
             x2 = ((-b) + qSqrt(d)) / (2 * a);

             ui->lineEdit_4->setText("x1 = " + QString::number(x1) +
                                     ", x2 = " + QString::number(x2));
         }
         else if (qFuzzyCompare(d, 0))
         {
             x1 = -(b / (2 * a));
             ui->lineEdit_4->setText("x1 = " + QString::number(x1));
         }
         else if (d < 0)
         {
             ui->lineEdit_4->setText("Not found");
         }
}


void MainWindow::onPushButton_2_Clicked()
{
    bool isRedian = ui->radioButton_2->isChecked();

    double a, b, angle, c, degrees;

    a = ui->lineEdit_5->text().toDouble();
    b = ui->lineEdit_6->text().toDouble();
    angle = ui->lineEdit_7->text().toDouble();

    degrees = (isRedian) ? qRadiansToDegrees(angle) : angle;

    c = a * a + b * b - 2 * a * b * qCos(degrees / 180 * M_PI);
    c = (qPow(c, 1.0 / 2));

    ui->lineEdit_8->setText(QString::number(c));
}


void MainWindow::onPushButton_3_Clicked()
{
   QString addValueText = ui->plainTextEdit->toPlainText();
   ui->plainTextEdit_2->appendPlainText(addValueText);
}

void MainWindow::onPushButton_4_Clicked()
{
    QString addValueText = ui->plainTextEdit->toPlainText();

    if(!addValueText.isEmpty()){ui->plainTextEdit_2->setPlainText(addValueText);}

}

void MainWindow::onPushButton_5_Clicked()
{
    QString addValueText = ui->plainTextEdit->toPlainText();
    if(!addValueText.isEmpty())
    {
    ui->plainTextEdit_2->appendHtml("<font color='red'>" + addValueText + "</font>");
    }
}

