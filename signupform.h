#ifndef SIGNUPFORM_H
#define SIGNUPFORM_H

#include <QWidget>
#include <QtWidgets>
#include <user.h>

class SignupForm : public QWidget
{
    Q_OBJECT
public:
    explicit SignupForm(QWidget *parent = nullptr);
    QLabel *lblFirstName;
    QLabel *lblLastName;
    QLineEdit *leFirstName;
    QLineEdit *leLastName;
    QLabel *lblDOB;
    QPushButton *btnDOB;
    QLabel *lblUsername;
    QLineEdit *leUsername;
    QLabel *lblPassword;
    QLabel *lblConfirmPassword;
    QLineEdit *lePassword;
    QLineEdit *leConfirmPassword;
    QGroupBox *grpGender;
    QHBoxLayout *loGender;
    QGridLayout *loGrid;
    QRadioButton *rbMale;
    QRadioButton *rbFemale;
    QLabel *lblGender;
    QCalendarWidget *wCalendar;
    QPushButton *btnSignup;
    QPushButton *btnCancel;
    void setGridLayout();

signals:

public slots:
    void saveUser();
};

#endif // SIGNUPFORM_H
