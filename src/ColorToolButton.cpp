#include <include/ColorToolButton.h>

#include <QMenu>
#include <QToolButton>
#include <QColorDialog>
#include <QString>
#include <QList>
#include <QPainter>

ColorToolButton::ColorToolButton(QWidget *parent)
    : QToolButton(parent), color_dialog (new QColorDialog()), numColors (color_dialog->customCount())
{
    createActions();
    createGui();
    connectSignals();
}


void ColorToolButton::createGui()
{
    QPixmap button_icon(QSize(56,36));
        button_icon.fill(color_dialog->customColor(0));
        QPainter p(&button_icon);
        p.drawRect(0,0,55,35);
    setIcon(QIcon(button_icon));
    setPopupMode(QToolButton::DelayedPopup);
    createMenu();
}

void ColorToolButton::connectSignals()
{
    connect(this, &QToolButton::clicked, this, &ColorToolButton::buttonClick);

    for (int i = 0; i <m_act.size(); i++){
         connect(m_act[i].action, &QAction::triggered, this, [this, i](bool checked) {
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
        m_act.push_back({new QAction(QIcon(pixmap),tr(color_dialog->customColor(i).name().toUtf8()),this),
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
    for (int i =0;i<m_act.size();i++){
        m_act[i].color_act=color_dialog->customColor(i);
        pixmap.fill(m_act[i].color_act);
            QPainter p(&pixmap);
            p.drawRect(0,0,55,35);
            m_act[i].action->setIcon(QIcon(pixmap));
            m_act[i].action->setText(tr(m_act[i].color_act.name().toUtf8()));
    }
}

void ColorToolButton::createMenu()
{
    m_menu = new QMenu;
        for (int i =0;i<m_act.size();i++){
            for (int j = 0; j<i;j++){
                if(m_act[i].color_act == m_act[j].color_act)
                {
                    m_act[i].visible = false;
                    break;
                }
                else
                    m_act[i].visible = true;
            }
            if(m_act[i].visible == true || i == 0)
                m_menu->addAction(m_act[i].action);
        }
    setMenu(m_menu);

}

void ColorToolButton::updateMenu()
{
    delete m_menu;
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

