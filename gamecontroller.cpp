#include "gamecontroller.h"

GameController::GameController(QObject *parent) : QObject(parent)
{
    _loginForm = new LoginForm();
    _signupForm = new SignupForm();

    openLoginForm();

    QObject::connect(_loginForm->btnSignup,SIGNAL(clicked()),this,SLOT(openSignupForm()));
    QObject::connect(_signupForm->btnCancel,SIGNAL(clicked()),this,SLOT(openLoginForm()));
    QObject::connect(_loginForm,SIGNAL(successfullLogin()),this,SLOT(openMainWidget()));
    QObject::connect(_signupForm,SIGNAL(signupComplete()),this,SLOT(openMainWidget()));
}

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

void GameController::openMainWidget()
{
    _main = new MainWidget();
    _signupForm->close();
    _loginForm->close();
    _main->show();
}
