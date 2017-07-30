#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

#pragma execution_character_set("utf-8");

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    //explicit StartWindow(QWidget *parent = 0);
    StartWindow(QWidget *parent = 0);
    ~StartWindow();

    bool isConnected;
    QLineEdit* lineEdit_name;
    QLineEdit* lineEdit_password;

private slots:
    void on_buttonBox_accept();
    void on_buttonBox_cancel();
};

#endif // STARTWINDOW_H
