#include <QApplication>
#include <QWidget>
#include <QPushButton>

#include <loginform.h>

/**
 * \mainpage EECE-435L-Project
 * \author Danny Abraham
 * \author Simon Tchaghlassian
 * \version 1.0
 * */

int main(int argc, char** argv)
{
    QApplication app(argc,argv);

    LoginForm *loginForm = new LoginForm();
    loginForm->show();

    return app.exec();
}
