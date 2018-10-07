#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>
#include <QtWidgets>
#include <userservice.h>

class LoginForm : public QWidget
{
    Q_OBJECT
public:
    explicit LoginForm(QWidget *parent = nullptr);
    QLabel *lblUsername;
    QLineEdit *leUsername;
    QLabel *lblPassword;
    QLineEdit *lePassword;
    QPushButton *btnLogin;
    QLabel *lblNotSignedup;
    QPushButton *btnSignup;
    QPushButton *btnPlayAsGuest;
    QGridLayout *loGrid;
    QMessageBox *msgError;
    void setGridLayout();

private:
    UserService *userService;

signals:
    void successfullLogin();

public slots:
    void login();
};

#endif // LOGINFORM_H
