#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>
#include <QtWidgets>

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
    void setGridLayout();

signals:

public slots:
};

#endif // LOGINFORM_H
