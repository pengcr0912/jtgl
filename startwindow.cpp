#include "startwindow.h"
#include "mainwindow.h"

extern MySql* mySql;
extern QString userType("");

StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent)
{
    isConnected = false;

    QWidget* startWidget = new QWidget;
    lineEdit_name = new QLineEdit;
    lineEdit_password = new QLineEdit;
    QPushButton* pushButton_start = new QPushButton("登陆");
    QPushButton* pushButton_cancel = new QPushButton("取消");
    QLabel* label_name = new QLabel("用户名");
    QLabel* label_password = new QLabel("密码");

    QVBoxLayout* layoutV = new QVBoxLayout;
    QHBoxLayout* layoutH = new QHBoxLayout;
    QGridLayout* layoutG = new QGridLayout;
    layoutG->addWidget(label_name, 0, 0);
    layoutG->addWidget(label_password, 1, 0);
    layoutG->addWidget(lineEdit_name, 0, 1);
    layoutG->addWidget(lineEdit_password, 1, 1);
    layoutH->addWidget(pushButton_start);
    layoutH->addWidget(pushButton_cancel);
    layoutV->addLayout(layoutG);
    layoutV->addLayout(layoutH);
    startWidget->setLayout(layoutV);

    setCentralWidget(startWidget);
    setWindowTitle("登陆窗口");
    Qt::WindowFlags flags = 0;
    flags |= Qt::WindowMinimizeButtonHint;
    setWindowFlags(flags); //禁止最大化

    connect(pushButton_start,SIGNAL(clicked()),this,SLOT(on_buttonBox_accept()));
    connect(pushButton_cancel,SIGNAL(clicked()),this,SLOT(on_buttonBox_cancel()));
    resize(200, 100);
}

StartWindow::~StartWindow()
{
}

void StartWindow::on_buttonBox_accept()
{
    //userType = "";
    QString password;
    if(mySql->isConnected || mySql->open())
    {
        QSqlQuery query;
        QString insertline;
        if(mySql->strTables.contains("user"))
        {
            insertline=QString("select * from user where name = '%1'").arg(lineEdit_name->text());
            query.exec(insertline);

            while(query.next())
            {
                password = query.value(1).toString();
                userType = query.value(2).toString();
            }
            if(userType == "")
            {
                QMessageBox::about(NULL,"error","用户不存在");
                return;
            }
            else if(password != lineEdit_password->text())
            {
                QMessageBox::about(NULL,"error","密码错误");
                return;
            }
        }
        else
            qDebug() << "user表不存在";
    }

    isConnected = true;
    MainWindow* w = new MainWindow;
    w->setWindowFlags(w->windowFlags() & ~Qt::WindowMaximizeButtonHint &  ~Qt::WindowMinimizeButtonHint);
    w->showMaximized();
    w->show();
    QMainWindow::close();
}

void StartWindow::on_buttonBox_cancel()
{
    QMainWindow::close();
}
