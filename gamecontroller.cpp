#include "gamecontroller.h"

GameController::GameController(QObject *parent) : QObject(parent)
{
    _loginForm = new LoginForm();
    _signupForm = new SignupForm();

    openLoginForm();

    QObject::connect(_loginForm->btnSignup,SIGNAL(clicked()),this,SLOT(openSignupForm()));
    QObject::connect(_signupForm->btnCancel,SIGNAL(clicked()),this,SLOT(openLoginForm()));
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
