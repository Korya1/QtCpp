#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMath>
#include <QString>
#include <QValidator>
#include <QDoubleValidator>
#include <QLocale>
#include <QTextDocument>
#include <QTextEdit>


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
    void onPushButton_Clicked();
    void onPushButton_2_Clicked();
    void onPushButton_3_Clicked();
    void onPushButton_4_Clicked();
    void onPushButton_5_Clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
