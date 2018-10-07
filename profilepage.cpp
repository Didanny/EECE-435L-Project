#include "profilepage.h"

ProfilePage::ProfilePage(QWidget *parent) : QWidget(parent)
{
    User user;
    userService = UserService::getInstance();
    userService->getCurrentUser(user);

    lblDOB = new QLabel(user.getDOB());
    lblFirstname = new QLabel(user.getFirstName());
    lblLastname = new QLabel(user.getLastName());
    lblUsername = new QLabel(user.getUsername());

    QImage picture;
    picture.load("./" + user.getUsername() + ".png");
    lblPicture->setPixmap(QPixmap::fromImage(picture));

    setGridLayout();

    this->setLayout(loGrid);
}

void ProfilePage::setGridLayout()
{
    loGrid = new QGridLayout();
    loGrid->addWidget(lblPicture,0,0,10,1);
    loGrid->addWidget(lblUsername,0,1,1,2);
    loGrid->addWidget(lblFirstname,1,1);
    loGrid->addWidget(lblLastname,1,2);
    loGrid->addWidget(lblDOB,2,1,1,2);
}