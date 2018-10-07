#include "profilepage.h"

ProfilePage::ProfilePage(QWidget *parent) : QWidget(parent)
{
    User user;
    userService = UserService::getInstance();
    userService->getCurrentUser(user);
//    userService->getUser("b2",user);

    lblDOB = new QLabel(user.getDOB());
    lblFirstname = new QLabel(user.getFirstName());
    lblLastname = new QLabel(user.getLastName());
    lblUsername = new QLabel(user.getUsername());
    lblPicture = new QLabel();

    QImage picture;
    picture.load("./" + user.getUsername() + ".png");
    picture = picture.scaledToWidth(300);
    lblPicture->setPixmap(QPixmap::fromImage(picture));

    message = new QMessageBox();
    if (user.isDOB())
    {
        message->setText("Happy Birthday");
        message->show();
    }

    setGridLayout();

    this->setLayout(loGrid);
}

void ProfilePage::setGridLayout()
{
    loGrid = new QGridLayout();
    loGrid->addWidget(lblPicture,0,0,1,1);
    loGrid->addWidget(lblUsername,0,1,1,2);
    loGrid->addWidget(lblFirstname,1,1);
    loGrid->addWidget(lblLastname,1,2);
    loGrid->addWidget(lblDOB,2,1,1,2);
}
