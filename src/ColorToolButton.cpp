#include <include/ColorToolButton.h>
#include <QMenu>
#include <QToolButton>
#include <QColorDialog>
#include <QString>
#include <QList>

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
    setIcon(QIcon(button_icon));
    setPopupMode(QToolButton::DelayedPopup);
    createMenu(m_act.size());
}

void ColorToolButton::connectSignals()
{
    connect(this, &QToolButton::clicked, this, &ColorToolButton::buttonClick);

    for (int i = 0; i <m_act.size(); i++){
         connect(m_act[i], &QAction::triggered, this, [this, i](bool checked) {
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
        m_act.push_back(new QAction(QIcon(pixmap),tr(color_dialog->customColor(i).name().toUtf8()),this));
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
     createMenu(1);

}

void ColorToolButton::updateColor()
{
    QPixmap pixmap(QSize(56,36));
    for (int i =0;i<m_act.size();i++){
        pixmap.fill(color_dialog->customColor(i));
            m_act[i]->setIcon(QIcon(pixmap));
            m_act[i]->setText(tr(color_dialog->customColor(i).name().toUtf8()));
    }
}

void ColorToolButton::createMenu(int size)
{
    m_menu = new QMenu;
        for (int i =0;i<size;i++){
            m_menu->addAction(m_act[i]);
        }
    setMenu(m_menu);
}

void ColorToolButton::createIcon(QColor color)
{
    QPixmap button_icon(QSize(56,36));
    icon_color = color;
    button_icon.fill(color);
    setIcon(QIcon(button_icon));
}

