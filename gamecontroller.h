#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include <loginform.h>
#include <signupform.h>

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

signals:

public slots:
    void openSignupForm();
    void openLoginForm();
};

#endif // GAMECONTROLLER_H
