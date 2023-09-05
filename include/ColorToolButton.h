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

private:
    void createGui();
    void connectSignals();
    void createActions();
    void buttonClick();
    void updateColor();
    void createIcon(QColor color);


private:
    QAction     *m_color_act1 ;
    QAction     *m_color_act2 ;
    QAction     *m_color_act3 ;
    QAction     *m_color_act4 ;
    QAction     *m_color_act5 ;
    QAction     *m_color_act6 ;
    QAction     *m_color_act7 ;
    QAction     *m_color_act8 ;
    QAction     *m_color_act9 ;
    QAction     *m_color_act10 ;
    QAction     *m_color_act11 ;
    QAction     *m_color_act12 ;
    QAction     *m_color_act13 ;
    QAction     *m_color_act14 ;
    QAction     *m_color_act15 ;
    QAction     *m_color_act16 ;
    QAction     *m_color_act17 ;
    QAction     *m_color_act18 ;
    QMenu       *m_menu   ;
    QColor      icon_color;

    QColorDialog *color_dialog;
};
