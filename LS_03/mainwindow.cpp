#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextStream>
#include <QString>
#include <QFileDialog>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->OpenPushBtn, &QPushButton::clicked, this, &MainWindow::onPushBtn_openPushBtn);
    connect(ui->SavePushBtn, &QPushButton::clicked, this, &MainWindow::onPushBtn_savePushBtn);
    connect(ui->InfoPushBtn, &QPushButton::clicked, this, &MainWindow::onPushBtn_infoPushBtn);

    connect(ui->radioButton, &QRadioButton::pressed, this, [this](){
        connect(ui->OpenPushBtn, &QPushButton::clicked, this, &MainWindow::onPushBtn_openPushBtn);
        disconnect(ui->OpenPushBtn, &QPushButton::clicked, this, &MainWindow::onPushBtn_openHTMLPushBtn);
    });

    connect(ui->radioButton_2, &QRadioButton::pressed, this, [this](){
        disconnect(ui->OpenPushBtn, &QPushButton::clicked, this, &MainWindow::onPushBtn_openPushBtn);
        connect(ui->OpenPushBtn, &QPushButton::clicked, this, &MainWindow::onPushBtn_openHTMLPushBtn);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onPushBtn_openPushBtn()
{
    QString path{ QFileDialog::getOpenFileName(this, "Open File", QDir::currentPath(), "Text (*.txt)") };
    if(!path.isEmpty())
    {
        QFile file(path);
        if(file.open(QFile::ReadOnly | QFile::ExistingOnly)){
           QTextStream stream(&file);
           ui->plainTextEdit->setPlainText(stream.readAll());
           file.close();
        }
    }
}

void MainWindow::onPushBtn_savePushBtn()
{
    QString path{ QFileDialog::getSaveFileName(this, "Save File", QDir::currentPath(), "Text (*.txt)") };
    if(!path.isEmpty())
    {
        QFile file(path);
        if(file.open(QFile::WriteOnly)){
            QTextStream stream(&file);
            stream << ui->plainTextEdit->toPlainText();
            file.close();
        }
    }
}

void MainWindow::onPushBtn_infoPushBtn()
{
    QFile file(":/infoText.txt");
    if (file.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&file);
        ui->plainTextEdit->setPlainText(stream.readAll());
        file.close();
    }
}

void MainWindow::onPushBtn_openHTMLPushBtn()
{
    QString path{ QFileDialog::getOpenFileName(this, "Open html File", QDir::currentPath(), "html (*.html)") };
    QString parsText;
    if(!path.isEmpty())
    {
        QFile file(path);
        if(file.open(QFile::ReadOnly | QFile::ExistingOnly)){
            QTextStream stream(&file);
            parsText = stream.readAll();
            file.close();
        }
    }
    {
    QRegularExpression regExp { "\"temp\":\"(.+)\",\"tempFeelsLike\":\"(.+)\",\"description\":\"(.+)\"" };
    QRegularExpressionMatch match { regExp.match(parsText) };
    QString txt = match.captured(1);
    ui->plainTextEdit->appendPlainText("Temperature: " + txt);
    }

    {
    QRegularExpression regExp { "\"type\":\"USD\",\"rate\":(.+)" };
    QRegularExpressionMatch match { regExp.match(parsText) };
    QString txt = match.captured(1);
    txt.truncate(txt.indexOf(','));
    ui->plainTextEdit->appendPlainText("Dollar: " +  txt);
    }

}

