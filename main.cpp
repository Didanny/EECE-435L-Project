#include <QApplication>
#include <QWidget>
#include <QPushButton>

#include <loginform.h>
#include <signupform.h>

/**
 * \mainpage EECE-435L-Project
 * \author Danny Abraham
 * \author Simon Tchaghlassian
 * \version 1.0
 * */

int main(int argc, char** argv)
{
    QApplication app(argc,argv);

//    LoginForm *loginForm = new LoginForm();
//    loginForm->show();

//    QCalendarWidget *claendar = new QCalendarWidget();
//    claendar->show();

    SignupForm *signupForm = new SignupForm();
    signupForm->show();

    return app.exec();
}
