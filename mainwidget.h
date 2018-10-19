#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QtWidgets>
#include <profilepage.h>
#include <gamespage.h>

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = nullptr);
    QTabWidget *twTab;
    ProfilePage *profile;
    GamesPage *games;

signals:

public slots:
};

#endif // MAINWIDGET_H
