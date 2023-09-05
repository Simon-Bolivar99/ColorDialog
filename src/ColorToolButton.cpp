#include <include/ColorToolButton.h>
#include <QMenu>
#include <QToolButton>
#include <QColorDialog>

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
        button_icon.fill(Qt::black);
    setIcon(QIcon(button_icon));
    setPopupMode(QToolButton::DelayedPopup);

    m_menu = new QMenu;
        m_menu->addAction(m_color_act1);
        m_menu->addAction(m_color_act2);
        m_menu->addAction(m_color_act3);
        m_menu->addAction(m_color_act4);
        m_menu->addAction(m_color_act5);
        m_menu->addAction(m_color_act6);
        m_menu->addAction(m_color_act7);
        m_menu->addAction(m_color_act8);
        m_menu->addAction(m_color_act9);
        m_menu->addAction(m_color_act10);
        m_menu->addAction(m_color_act11);
        m_menu->addAction(m_color_act12);
        m_menu->addAction(m_color_act13);
        m_menu->addAction(m_color_act14);
        m_menu->addAction(m_color_act15);
        m_menu->addAction(m_color_act16);
        m_menu->addAction(m_color_act17);

    setMenu(m_menu);
}

void ColorToolButton::connectSignals()
{
    connect(this, &QToolButton::clicked, this, &ColorToolButton::buttonClick);

    //ACTIONS
    connect(m_color_act1, &QAction::triggered, this, [this](){createIcon(Qt::black);});
    connect(m_color_act2, &QAction::triggered, this, [this](){createIcon(Qt::white);});
    connect(m_color_act3, &QAction::triggered, this, [this](){createIcon(Qt::red);});
    connect(m_color_act4, &QAction::triggered, this, [this](){createIcon(Qt::darkRed);});
    connect(m_color_act5, &QAction::triggered, this, [this](){createIcon(Qt::green);});
    connect(m_color_act6, &QAction::triggered, this, [this](){createIcon(Qt::darkGreen);});
    connect(m_color_act7, &QAction::triggered, this, [this](){createIcon(Qt::blue);});
    connect(m_color_act8, &QAction::triggered, this, [this](){createIcon(Qt::darkBlue);});
    connect(m_color_act9, &QAction::triggered, this, [this](){createIcon(Qt::cyan);});
    connect(m_color_act10, &QAction::triggered, this, [this](){createIcon(Qt::darkCyan);});
    connect(m_color_act11, &QAction::triggered, this, [this](){createIcon(Qt::magenta);});
    connect(m_color_act12, &QAction::triggered, this, [this](){createIcon(Qt::darkMagenta);});
    connect(m_color_act13, &QAction::triggered, this, [this](){createIcon(Qt::yellow);});
    connect(m_color_act14, &QAction::triggered, this, [this](){createIcon(Qt::darkYellow);});
    connect(m_color_act15, &QAction::triggered, this, [this](){createIcon(Qt::gray);});
    connect(m_color_act16, &QAction::triggered, this, [this](){createIcon(Qt::darkGray);});
    connect(m_color_act17, &QAction::triggered, this, [this](){createIcon(Qt::lightGray);});
    connect(m_color_act18, &QAction::triggered, this, [this](){createIcon(Qt::lightGray);});

}

void ColorToolButton::createActions()
{

    color_dialog = new QColorDialog();
    QPixmap pixmap(QSize(56,36));
    pixmap.fill(color_dialog->customColor(0));
        m_color_act1 = new QAction(QIcon(pixmap),tr("custom"),this);
    pixmap.fill(color_dialog->customColor(1));
        m_color_act2 = new QAction(QIcon(pixmap),tr("custom"),this);
    pixmap.fill(color_dialog->customColor(2));
        m_color_act3 = new QAction(QIcon(pixmap),tr("custom"),this);
    pixmap.fill(color_dialog->customColor(3));
        m_color_act4 = new QAction(QIcon(pixmap),tr("custom"),this);
    pixmap.fill(color_dialog->customColor(4));
        m_color_act5 = new QAction(QIcon(pixmap),tr("custom"),this);
    pixmap.fill(color_dialog->customColor(5));
        m_color_act6 = new QAction(QIcon(pixmap),tr("custom"),this);
    pixmap.fill(color_dialog->customColor(6));
        m_color_act7 = new QAction(QIcon(pixmap),tr("custom"),this);
    pixmap.fill(color_dialog->customColor(7));
        m_color_act8 = new QAction(QIcon(pixmap),tr("custom"),this);
    pixmap.fill(color_dialog->customColor(8));
        m_color_act9 = new QAction(QIcon(pixmap),tr("custom"),this);
    pixmap.fill(color_dialog->customColor(9));
        m_color_act10 = new QAction(QIcon(pixmap),tr("custom"),this);
    pixmap.fill(color_dialog->customColor(10));
        m_color_act11 = new QAction(QIcon(pixmap),tr("custom"),this);
    pixmap.fill(color_dialog->customColor(11));
        m_color_act12 = new QAction(QIcon(pixmap),tr("custom"),this);
    pixmap.fill(color_dialog->customColor(12));
        m_color_act13 = new QAction(QIcon(pixmap),tr("custom"),this);
    pixmap.fill(color_dialog->customColor(13));
        m_color_act14 = new QAction(QIcon(pixmap),tr("custom"),this);
    pixmap.fill(color_dialog->customColor(14));
        m_color_act15 = new QAction(QIcon(pixmap),tr("custom"),this);
    pixmap.fill(color_dialog->customColor(15));
        m_color_act16 = new QAction(QIcon(pixmap),tr("custom"),this);
    pixmap.fill(color_dialog->customColor(16));
        m_color_act17 = new QAction(QIcon(pixmap),tr("custom"),this);
    pixmap.fill(color_dialog->customColor(17));
        m_color_act18 = new QAction(QIcon(pixmap),tr("custom"),this);


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

    pixmap.fill(color_dialog->customColor(0));
        m_color_act1->setIcon(QIcon(pixmap));
    pixmap.fill(color_dialog->customColor(1));
        m_color_act2->setIcon(QIcon(pixmap));
    pixmap.fill(color_dialog->customColor(2));
        m_color_act3->setIcon(QIcon(pixmap));
    pixmap.fill(color_dialog->customColor(3));
        m_color_act4->setIcon(QIcon(pixmap));
    pixmap.fill(color_dialog->customColor(4));
        m_color_act5->setIcon(QIcon(pixmap));
    pixmap.fill(color_dialog->customColor(5));
        m_color_act6->setIcon(QIcon(pixmap));
    pixmap.fill(color_dialog->customColor(6));
        m_color_act7->setIcon(QIcon(pixmap));
    pixmap.fill(color_dialog->customColor(7));
        m_color_act8->setIcon(QIcon(pixmap));
    pixmap.fill(color_dialog->customColor(8));
        m_color_act9->setIcon(QIcon(pixmap));
    pixmap.fill(color_dialog->customColor(9));
        m_color_act10->setIcon(QIcon(pixmap));
    pixmap.fill(color_dialog->customColor(10));
        m_color_act11->setIcon(QIcon(pixmap));
    pixmap.fill(color_dialog->customColor(11));
        m_color_act12->setIcon(QIcon(pixmap));
    pixmap.fill(color_dialog->customColor(12));
        m_color_act13->setIcon(QIcon(pixmap));
    pixmap.fill(color_dialog->customColor(13));
        m_color_act14->setIcon(QIcon(pixmap));
    pixmap.fill(color_dialog->customColor(14));
        m_color_act15->setIcon(QIcon(pixmap));
    pixmap.fill(color_dialog->customColor(15));
        m_color_act16->setIcon(QIcon(pixmap));
    pixmap.fill(color_dialog->customColor(16));
        m_color_act17->setIcon(QIcon(pixmap));
    pixmap.fill(color_dialog->customColor(17));
        m_color_act18->setIcon(QIcon(pixmap));

}

void ColorToolButton::createIcon(QColor color)
{
    QPixmap button_icon(QSize(56,36));
    icon_color = color;
    button_icon.fill(color);
    setIcon(QIcon(button_icon));
}

//QColor selectedColor() const
//void setCurrentColor(const QColor &color)


