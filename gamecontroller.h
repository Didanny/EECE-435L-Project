#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include <loginform.h>
#include <signupform.h>
#include <mainwidget.h>

class GameController : public QObject
{
    Q_OBJECT
public:
    explicit GameController(QObject *parent = nullptr);
    void loadUser(QString username);

private:
    User *_user;
    LoginForm *_loginForm;
    SignupForm *_signupForm;
    MainWidget *_main;

signals:

public slots:
    void openSignupForm();
    void openLoginForm();
    void openMainWidget();
};

#endif // GAMECONTROLLER_H
