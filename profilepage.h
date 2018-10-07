#ifndef PROFILEPAGE_H
#define PROFILEPAGE_H

#include <QWidget>
#include <QtWidgets>
#include <userservice.h>

class ProfilePage : public QWidget
{
    Q_OBJECT
public:
    explicit ProfilePage(QWidget *parent = nullptr);
    QLabel *lblPicture;
    QLabel *lblUsername;
    QLabel *lblFirstname;
    QLabel *lblLastname;
    QLabel *lblDOB;
    QGridLayout *loGrid;
    UserService *userService;
    void setGridLayout();

signals:

public slots:
};

#endif // PROFILEPAGE_H
