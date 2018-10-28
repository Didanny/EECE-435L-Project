#include "levelscene.h"

LevelScene::LevelScene()
{
    this->setSceneRect(0,0,1028,675);

    code = new QTextEdit();
    code->resize(200,200);
    code->move(this->width() - code->width() - 10, 10);
    this->addWidget(code);

    run = new QPushButton("Run");
    run->resize(100,25);
    run->move(this->width() - run->width() - 110, code->height() + 10);
    this->addWidget(run);

    hint = new QPushButton("Hint");
    hint->resize(100,25);
    hint->move(this->width() - hint->width() - 10, code->height() + 10);
    this->addWidget(hint);

    QObject::connect(run,SIGNAL(clicked(bool)),this,SLOT(execute()));
}
