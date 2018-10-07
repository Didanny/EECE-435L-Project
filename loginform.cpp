#include "loginform.h"

LoginForm::LoginForm(QWidget *parent) : QWidget(parent)
{
    lblNotSignedup = new QLabel("Not Signed Up?");
    lblPassword = new QLabel("Password:");
    lblUsername = new QLabel("Username");

    leUsername = new QLineEdit();
    lePassword = new QLineEdit();
    lePassword->setEchoMode(QLineEdit::Password);

    btnLogin = new QPushButton("Login");
    btnPlayAsGuest = new QPushButton("Play As Guest");
    btnSignup = new QPushButton("Sign Up");

    msgError = new QMessageBox();

    userService = UserService::getInstance();

    setGridLayout();

    QObject::connect(btnLogin,SIGNAL(clicked(bool)),this,SLOT(login()));
}

void LoginForm::setGridLayout()
{
    loGrid = new QGridLayout();

    loGrid->addWidget(lblUsername,0,0);
    loGrid->addWidget(lblPassword,0,1);
    loGrid->addWidget(leUsername,1,0);
    loGrid->addWidget(lePassword,1,1);
    loGrid->addWidget(btnLogin,2,0,1,2);
    loGrid->addWidget(lblNotSignedup,3,0,1,2);
    loGrid->addWidget(btnSignup,4,0);
    loGrid->addWidget(btnPlayAsGuest,4,1);

    this->setLayout(loGrid);
}

void LoginForm::login()
{
    msgError->hide();

    User user;
    if (userService->getUser(leUsername->text(),user) == false)
    {
        msgError->setText("Incorrect username");
        msgError->show();
        return;
    }

    if (user.authenticate(lePassword->text()))
    {
        userService->setCurrentUser(leUsername->text());
        successfullLogin();
    }
    else
    {
        msgError->setText("Incorrect password");
        msgError->show();
    }
}
