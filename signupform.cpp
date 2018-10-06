#include "signupform.h"

SignupForm::SignupForm(QWidget *parent) : QWidget(parent)
{
    lblConfirmPassword = new QLabel("Confirm Password:");
    lblDOB = new QLabel("Date of Birth:");
    lblFirstName = new QLabel("First Name:");
    lblLastName = new QLabel("Last Name:");
    lblPassword = new QLabel("Password:");
    lblUsername = new QLabel("Username:");
    lblGender = new QLabel("Gender:");

    leConfirmPassword = new QLineEdit();
    leConfirmPassword->setEchoMode(QLineEdit::Password);
    leFirstName = new QLineEdit();
    leLastName = new QLineEdit();
    lePassword = new QLineEdit();
    lePassword->setEchoMode(QLineEdit::Password);
    leUsername = new QLineEdit();

    grpGender = new QGroupBox();
    rbMale = new QRadioButton("Male");
    rbFemale = new QRadioButton("Female");
    loGender = new QHBoxLayout();
    loGender->addWidget(rbMale);
    loGender->addWidget(rbFemale);
    grpGender->setLayout(loGender);

    btnDOB = new QPushButton("Select DOB");

    setGridLayout();

    this->setLayout(loGrid);

    QObject::connect(btnDOB,SIGNAL(clicked()),this,SLOT(saveUser()));
}

void SignupForm::setGridLayout()
{
    loGrid = new QGridLayout();
    loGrid->addWidget(lblFirstName,0,0);
    loGrid->addWidget(lblLastName,0,1);
    loGrid->addWidget(leFirstName,1,0);
    loGrid->addWidget(leLastName,1,1);
    loGrid->addWidget(lblDOB,2,0);
    loGrid->addWidget(btnDOB,2,1);
    loGrid->addWidget(lblGender,3,0);
    loGrid->addWidget(grpGender,3,1);
    loGrid->addWidget(lblUsername,4,0);
    loGrid->addWidget(leUsername,4,1);
    loGrid->addWidget(lblPassword,5,0);
    loGrid->addWidget(lblConfirmPassword,5,1);
    loGrid->addWidget(lePassword,6,0);
    loGrid->addWidget(leConfirmPassword,6,1);
}

void SignupForm::saveUser()
{
    User user(leFirstName->text(),leLastName->text(),lePassword->text(),leUsername->text());
    user.saveUser();
}
