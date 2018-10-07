#include "main_page.h"

//profile_page::profile_page(QWidget *parent) : QWidget(parent)
//{
//    l_first_name = new QLabel("Fist Name: ");
//    l_last_name = new QLabel("Last Name: ");
//    l_gender = new QLabel("Gender: ");
//    l_email = new QLabel("Email: ");
//    l_username = new QLabel("Username: ");
//    l_DOB = new QLabel("Date of Birth: ");
//    l_profile_pic = new QLabel();
//    //gives an error cause no such file, should be input, maybe during construction of instance
//    //l_profile_pic->setPixmap("myFile.png");

//    //read from file -- your method

////    user_first_name = new QLabel("Fist Name:");
////    user_last_name = new QLabel("Last Name:");
////    user_gender = new QLabel("Gender:");
////    user_email = new QLabel("Email:");
////    user_username = new QLabel("Username:");


//    // did grid layout
//    gl_layout->addWidget(l_profile_pic, 0, 0, 1, 2);
//    gl_layout->addWidget(l_first_name, 1, 1);
//    gl_layout->addWidget(l_last_name, 2, 2);
//    gl_layout->addWidget(l_DOB, 3, 3);
//    gl_layout->addWidget(l_gender, 4, 4);
//    gl_layout->addWidget(l_email, 5, 5);
//    gl_layout->addWidget(l_username, 6, 6);

//    setLayout(gl_layout);




//}

//games_page::games_page(QWidget *parent) : QWidget(parent)
//{
//    pb_game1 = new QPushButton("Game 1");
//    pb_game2 = new QPushButton("Game 2");
//    pb_game3 = new QPushButton("Game 3");

//    vl_layout = new QVBoxLayout;

//    vl_layout->addWidget(pb_game1);
//    vl_layout->addWidget(pb_game2);
//    vl_layout->addWidget(pb_game3);

//    setLayout(vl_layout);





//}



main_page::main_page(QWidget *parent) : QWidget(parent)
{
    tabWidget = new QTabWidget(this);
    tabWidget->addTab(new QCalendarWidget(), "Profile");
    tabWidget->addTab(new QWidget(), "Games");
    tabWidget->show();
    int x = 700;
    tabWidget->setFixedSize(x,x);
//    this->setFixedSize(x,x);
}
