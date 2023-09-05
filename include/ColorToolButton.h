#pragma once

#include <QToolButton>


class QAction;
class QMenu;
class QColorDialog;

class ColorToolButton : public QToolButton{
    Q_OBJECT

public:
    ColorToolButton(QWidget *parent = nullptr);
    ~ColorToolButton() = default;

public:
    QColor getColor() {return icon_color;}

private:
    void createGui();
    void connectSignals();
    void createActions();
    void buttonClick();
    void updateColor();
    void createIcon(QColor color);


private:
    QAction *m_color_act[18];
    QMenu       *m_menu   ;
    QColor      icon_color;

    QColorDialog *color_dialog;
};
