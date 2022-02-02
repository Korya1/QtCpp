#pragma once
#include <QMainWindow>
#include <QString>
#include <QStandardItemModel>


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
    void on_lineEdit_textChanged(const QString &arg1);
    void onPushButton_PushButton();
    void onPushButton_PushButton2();
    void checkBox_PressedCheckBox();
    void on_upPushButton_Clicked();
    void on_downPushButton_Clicked();
    void on_pushButton_5_Clicked();
private:
    Ui::MainWindow *ui;
    QStandardItemModel *model;
    QStandardItemModel *model2;
};

