#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QtWidgets>

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = nullptr);
    QTabWidget *twTab;

signals:

public slots:
};

#endif // MAINWIDGET_H
