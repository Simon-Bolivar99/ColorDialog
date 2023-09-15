#pragma once

#include <QMainWindow>

class QToolButton;
class QAction;
class QMenu;
class ColorToolButton;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void createGui();

private:

    ColorToolButton *ColorButton;

};

