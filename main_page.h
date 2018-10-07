#ifndef MAIN_PAGE_H
#define MAIN_PAGE_H

#include <QWidget>
#include <QtWidgets>
#include <QPixmap>

//class profile_page : public QWidget
//{
//    Q_OBJECT
//public:
//    explicit profile_page(QWidget *parent = nullptr);
//    QLabel *l_first_name, *l_last_name, *l_DOB, *l_gender, *l_email, *l_username, *l_profile_pic;
//    QLabel *user_first_name, *user_last_name, *user_gender, *user_email, *user_username;
//    QGridLayout *gl_layout;


//signals:

//public slots:
//};

//class games_page : public QWidget
//{
//    Q_OBJECT
//public:
//    explicit games_page(QWidget *parent = nullptr);
//    QPushButton *pb_game2, *pb_game1, *pb_game3;
//    QVBoxLayout *vl_layout;


//signals:

//public slots:
//};



class main_page : public QWidget
{
    Q_OBJECT
public:
    explicit main_page(QWidget *parent = nullptr);
    QTabWidget *tabWidget;
signals:

public slots:
};

#endif // MAIN_PAGE_H
