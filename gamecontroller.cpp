#include "gamecontroller.h"

GameController::GameController(QObject *parent) : QObject(parent)
{
    _loginForm = new LoginForm();
    _signupForm = new SignupForm();

    openLoginForm();

    QObject::connect(_loginForm->btnSignup,SIGNAL(clicked()),this,SLOT(openSignupForm()));
    QObject::connect(_signupForm->btnCancel,SIGNAL(clicked()),this,SLOT(openLoginForm()));
}

#include <QDebug>
void GameController::loadUser(QString username)
{
    QFile file;
    file.setFileName("./" + username + ".json");
    file.open(QIODevice::ReadOnly);

    QJsonDocument userDoc = QJsonDocument::fromJson(file.readAll());

    file.close();

    QJsonObject userObject(userDoc.object());

    _user = new User();
    _user->read(userObject);
    qDebug() << _user->_username;
}

void GameController::openSignupForm()
{
    _signupForm->show();
    _loginForm->hide();
}

void GameController::openLoginForm()
{
    _signupForm->hide();
    _loginForm->show();
}
