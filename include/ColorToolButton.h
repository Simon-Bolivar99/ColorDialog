#pragma once

#include <QToolButton>
#include <QList>

class QAction;
class QMenu;
class QColorDialog;

class ColorToolButton : public QToolButton{
    Q_OBJECT

public:
    ColorToolButton(QWidget *parent = nullptr);
    ~ColorToolButton();

public:
    QColor getColor() {return icon_color;}

private:
    void createGui();
    void connectSignals();
    void createActions();
    void buttonClick();
    void updateColor();//изменение цветов после работы с диалоговым окном
    void createMenu();//создание QMenu
    void updateMenu();
    void createIcon(QColor color);

    void deleteActions();

private:
    struct action_color_t{
        QAction  *action;
        QColor    color_act;
        bool      visible;

    };
    QList <action_color_t> action_list;

    QMenu       *m_menu   ;
    QColor      icon_color; //цвет  ColorToolButton
    QColorDialog *color_dialog;

    int numColors;

};
