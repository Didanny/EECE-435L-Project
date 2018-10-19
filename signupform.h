#ifndef SIGNUPFORM_H
#define SIGNUPFORM_H

#include <QWidget>
#include <QtWidgets>
#include <QFileInfo>
#include <QFileDialog>
#include <user.h>
#include <userservice.h>

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
    QMessageBox *msgError;
    QLabel *lblPicture;
    QPushButton *btnPicture;
    QImage *picture;
    UserService *userService;
    void setGridLayout();

private:
    bool checkPassword();
    bool checkUsername();
    bool checkGender();
    bool checkCompletion();

signals:
    void signupComplete();

public slots:
    void saveUser();
    void checkForm();
    void selectPicture();
};

#endif // SIGNUPFORM_H
