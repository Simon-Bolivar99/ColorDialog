#include <include/ColorToolButton.h>
#include <QMenu>
#include <QToolButton>
#include <QColorDialog>
#include <QString>

ColorToolButton::ColorToolButton(QWidget *parent)
    : QToolButton(parent)
{
    createActions();
    createGui();
    connectSignals();
}


void ColorToolButton::createGui()
{
    QPixmap button_icon(QSize(56,36));
        button_icon.fill(color_dialog->customColor(0));
    setIcon(QIcon(button_icon));
    setPopupMode(QToolButton::DelayedPopup);

    m_menu = new QMenu;
        for (int i =0;i<17;i++){
            m_menu->addAction(m_color_act[i]);
        }
    setMenu(m_menu);
}

void ColorToolButton::connectSignals()
{
    connect(this, &QToolButton::clicked, this, &ColorToolButton::buttonClick);

    //ACTIONS
    for (int i =0;i<17;i++){
         connect(m_color_act[i], &QAction::triggered, this, [this](const int i){createIcon(color_dialog->customColor(i));});
    }
}

void ColorToolButton::createActions()
{

    color_dialog = new QColorDialog();
    QPixmap pixmap(QSize(56,36));
    for (int i=0;i<17;i++){
        pixmap.fill(color_dialog->customColor(i));
        m_color_act[i]  = new QAction(QIcon(pixmap),tr(color_dialog->customColor(i).name().toUtf8()),this);
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
}

void ColorToolButton::updateColor()
{
    QPixmap pixmap(QSize(56,36));
    for (int i =0;i<17;i++){
        pixmap.fill(color_dialog->customColor(i));
            m_color_act[i]->setIcon(QIcon(pixmap));
    }
}

void ColorToolButton::createIcon(QColor color)
{
    QPixmap button_icon(QSize(56,36));
    icon_color = color;
    button_icon.fill(color);
    setIcon(QIcon(button_icon));
}

