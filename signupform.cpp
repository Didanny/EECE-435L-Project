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
    lblPicture = new QLabel("Profile");

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
    btnSignup = new QPushButton("Sign Up");
    btnCancel = new QPushButton("Cancel");
    btnPicture = new QPushButton("Select a Profile Picture");

    wCalendar = new QCalendarWidget();

    msgError = new QMessageBox();

    picture = new QImage();

    setGridLayout();

    this->setLayout(loGrid);

    QObject::connect(btnSignup,SIGNAL(clicked()),this,SLOT(checkForm()));
    QObject::connect(btnPicture,SIGNAL(clicked(bool)),this,SLOT(selectPicture()));
}

void SignupForm::setGridLayout()
{
    loGrid = new QGridLayout();
    loGrid->addWidget(lblFirstName,0,0);
    loGrid->addWidget(lblLastName,0,1);
    loGrid->addWidget(leFirstName,1,0);
    loGrid->addWidget(leLastName,1,1);
    loGrid->addWidget(lblDOB,2,0,1,2);
    loGrid->addWidget(wCalendar,3,0,2,5);
    loGrid->addWidget(lblGender,8,0);
    loGrid->addWidget(grpGender,8,1);
    loGrid->addWidget(lblUsername,9,0);
    loGrid->addWidget(leUsername,9,1);
    loGrid->addWidget(lblPassword,10,0);
    loGrid->addWidget(lblConfirmPassword,10,1);
    loGrid->addWidget(lePassword,11,0);
    loGrid->addWidget(leConfirmPassword,11,1);
    loGrid->addWidget(lblPicture,12,0,6,2);
    loGrid->addWidget(btnPicture,18,0,1,2);
    loGrid->addWidget(btnSignup,19,0,1,2);
    loGrid->addWidget(btnCancel,20,0,1,2);
}

void SignupForm::checkForm()
{
    msgError->hide();

    if (!checkCompletion())
    {
        msgError->setText("Please complete the form");
        msgError->show();
        return;
    }

    if (!checkGender())
    {
        msgError->setText("Please select a gender!");
        msgError->show();
        return;
    }

    if (!checkPassword())
    {
        msgError->setText("Please make sure your password is atleast 8 characters long, contains numbers, and is lower and upper case!");
        msgError->show();
        return;
    }

    if(!checkUsername())
    {
        msgError->setText("Please change your username, it is already taken!");
        msgError->show();
        return;
    }

    saveUser();
    signupComplete();
}

void SignupForm::selectPicture()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("Select Profile Picture"),"",tr("Images(*.png *.jpeg *.jpg *.bmp *.gif)"));

    if (filename.length() > 0)
    {
        bool success = picture->load(filename);
        *picture = picture->scaledToWidth(lblPicture->width());
        if (success)
        {
            lblPicture->setPixmap(QPixmap::fromImage(*picture));
        }
    }
}

bool SignupForm::checkPassword()
{
    bool isNumeric;
    bool isLongerThan7;
    bool isMixedCase;
    bool isMatching;

    QString password = lePassword->text();

    isMatching = password == leConfirmPassword->text();
    isLongerThan7 = password.length() > 7;
    isMixedCase = password != password.toLower();

    QRegularExpression regex("[0-9]+");
    QRegularExpressionMatch match = regex.match(password);
    isNumeric = match.hasMatch();

    return isNumeric && isLongerThan7 && isMixedCase && isMatching;
}

bool SignupForm::checkUsername()
{
    QString path = "./" + leUsername->text() + ".json";
    return !(QFileInfo::exists(path) && QFileInfo(path).isFile());
}

bool SignupForm::checkGender()
{
    return rbFemale->isChecked() || rbMale->isChecked();
}

bool SignupForm::checkCompletion()
{
    return leFirstName->text().length() > 0 &&
            leLastName->text().length() > 0 &&
            lePassword->text().length() > 0 &&
            leConfirmPassword->text().length() > 0 &&
            leUsername->text().length() > 0;
}

void SignupForm::saveUser()
{
    QString gender;
    if (rbFemale->isChecked())
    {
        gender = "female";
    }
    else
    {
        gender = "male";
    }
    User user(leFirstName->text(),leLastName->text(),lePassword->text(),leUsername->text(),wCalendar->selectedDate().toString(),gender);
    user.saveUser();
    picture->save("./" + leUsername->text() + ".png");
}
