#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void onPushBtn_openPushBtn();
    void onPushBtn_savePushBtn();
    void onPushBtn_infoPushBtn();
    void onPushBtn_openHTMLPushBtn();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
