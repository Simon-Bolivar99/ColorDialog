#include <include/ColorToolButton.h>

#include <QMenu>
#include <QToolButton>
#include <QColorDialog>
#include <QString>
#include <QList>
#include <QPainter>

ColorToolButton::ColorToolButton(QWidget *parent)
    :  color_dialog (new QColorDialog(this)), m_menu(new QMenu(this)), numColors (color_dialog->customCount())
{
    createActions();
    createGui();
    connectSignals();

}

ColorToolButton::~ColorToolButton()
{
    deleteActions();
}

void ColorToolButton::createGui()
{
    QPixmap button_icon(QSize(56,36));
        button_icon.fill(color_dialog->customColor(0));
        QPainter p(&button_icon);
        p.drawRect(0,0,55,35);
        setIcon(QIcon(button_icon));
        //iconSize(QSize(height()*0.4 , width()*0.4));
        QIcon(Normal);
    setPopupMode(QToolButton::DelayedPopup);
    createMenu();
}

void ColorToolButton::connectSignals()
{
    connect(this, &QToolButton::clicked, this, &ColorToolButton::buttonClick);

    for (int i = 0; i <action_list.size(); i++){
         connect(action_list[i].action, &QAction::triggered, this, [this, i](bool checked) {
             Q_UNUSED(checked)

             createIcon(color_dialog->customColor(i));
         });
    }
}

void ColorToolButton::createActions()
{

    QPixmap pixmap(QSize(56,36));
    for (int i=0;i<numColors;i++){
        pixmap.fill(color_dialog->customColor(i));
        QPainter p(&pixmap);
        p.drawRect(0,0,55,35);
        action_list.push_back({new QAction(QIcon(pixmap),tr(color_dialog->customColor(i).name().toUtf8()),this),
                         color_dialog->customColor(i),
                         false});
    }

}

void ColorToolButton::buttonClick()
{
     const QColorDialog::ColorDialogOptions options = QFlag(QColorDialog::DontUseNativeDialog);
     QColor color = color_dialog->getColor(icon_color,this, "Select Color",options);
     if (color.isValid()){
         icon_color = color;
         createIcon(icon_color);
     }
     updateColor();
     updateMenu();

}

void ColorToolButton::updateColor()
{
    QPixmap pixmap(QSize(56,36));
    for (int i =0;i<action_list.size();i++){
        action_list[i].color_act=color_dialog->customColor(i);
        pixmap.fill(action_list[i].color_act);
            QPainter p(&pixmap);
            p.drawRect(0,0,55,35);
            action_list[i].action->setIcon(QIcon(pixmap));
            action_list[i].action->setText(tr(action_list[i].color_act.name().toUtf8()));
    }
}

void ColorToolButton::createMenu()
{
        for (int i =0;i<action_list.size();i++){
            for (int j = 0; j<i;j++){
                if(action_list[i].color_act == action_list[j].color_act)
                {
                    action_list[i].visible = false;
                    break;
                }
                else
                    action_list[i].visible = true;
            }
            if(action_list[i].visible == true || i == 0)
                m_menu->addAction(action_list[i].action);
        }
    setMenu(m_menu);

}

void ColorToolButton::updateMenu()
{
    m_menu->clear();
    createMenu();
}


void ColorToolButton::createIcon(QColor color)
{
    QPixmap button_icon(QSize(56,36));

        icon_color = color;
        button_icon.fill(color);
        QPainter p(&button_icon);
        p.drawRect(0,0,55,35);

        setIcon(QIcon(button_icon));
}

void ColorToolButton::deleteActions()
{
    for (int i = 0;i<numColors;i++)
      delete[]  action_list[i].action;
}

