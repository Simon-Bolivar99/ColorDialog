#pragma once

#include <QMainWindow>

class QToolButton;
class QAction;
class QMenu;
class QPushButton;
class QtColorPicker;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void createGui();
    void connectSignals();
    void createActions();
    void buttonClick();
    void buttonMenuClick();

private:
    QToolButton *m_tbutton;
    QPushButton *m_menu_button1;
    QPushButton *m_menu_button2;
    QPushButton *m_menu_button3;
    QAction     *m_rm_act ;
    QAction     *m_add_act;
    QMenu       *m_menu   ;

    QtColorPicker *m_color_button;
};

