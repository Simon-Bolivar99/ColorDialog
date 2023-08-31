#include "include/MainWindow.h"

#include <QToolButton>
#include <QHBoxLayout>
#include <QAction>
#include <QDialog>
#include <QColorDialog>
#include <QMenu>
#include <QPushButton>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    createActions();
    createGui();
    connectSignals();

}

MainWindow::~MainWindow()
{
}

void MainWindow::createGui()
{
    m_color_button = new QToolButton();
        QPixmap button_icon(QSize(56,36));
        button_icon.fill(Qt::black);
        m_color_button->setIcon(QIcon(button_icon));
        m_color_button->setPopupMode(QToolButton::DelayedPopup);
    auto m_layout = new QHBoxLayout();
        m_layout->addWidget(m_color_button);

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

             m_color_button->setMenu(m_menu);

    setLayout(m_layout);
}

void MainWindow::connectSignals()
{
    connect(m_color_button, &QToolButton::clicked, this, &MainWindow::buttonClick);

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

}

void MainWindow::createActions()
{
    QPixmap pixmap(QSize(56,36));
    pixmap.fill(Qt::black);
        m_color_act1 = new QAction(QIcon(pixmap),tr("black"),this);
    pixmap.fill(Qt::white);
        m_color_act2 = new QAction(QIcon(pixmap),tr("white"),this);
    pixmap.fill(Qt::red);
        m_color_act3 = new QAction(QIcon(pixmap),tr("red"),this);
    pixmap.fill(Qt::darkRed);
        m_color_act4 = new QAction(QIcon(pixmap),tr("darkRed"),this);
    pixmap.fill(Qt::green);
        m_color_act5 = new QAction(QIcon(pixmap),tr("green"),this);
    pixmap.fill(Qt::darkGreen);
        m_color_act6 = new QAction(QIcon(pixmap),tr("darkGreen"),this);
    pixmap.fill(Qt::blue);
        m_color_act7 = new QAction(QIcon(pixmap),tr("blue"),this);
    pixmap.fill(Qt::darkBlue);
        m_color_act8 = new QAction(QIcon(pixmap),tr("darkBlue"),this);
    pixmap.fill(Qt::cyan);
        m_color_act9 = new QAction(QIcon(pixmap),tr("cyan"),this);
    pixmap.fill(Qt::darkCyan);
        m_color_act10 = new QAction(QIcon(pixmap),tr("darkCyan"),this);
    pixmap.fill(Qt::magenta);
        m_color_act11 = new QAction(QIcon(pixmap),tr("magenta"),this);
    pixmap.fill(Qt::darkMagenta);
        m_color_act12 = new QAction(QIcon(pixmap),tr("darkMagenta"),this);
    pixmap.fill(Qt::yellow);
        m_color_act13 = new QAction(QIcon(pixmap),tr("yellow"),this);
    pixmap.fill(Qt::darkYellow);
        m_color_act14 = new QAction(QIcon(pixmap),tr("darkYellow"),this);
    pixmap.fill(Qt::gray);
        m_color_act15 = new QAction(QIcon(pixmap),tr("gray"),this);
    pixmap.fill(Qt::darkGray);
        m_color_act16 = new QAction(QIcon(pixmap),tr("darkGray"),this);
    pixmap.fill(Qt::lightGray);
        m_color_act17 = new QAction(QIcon(pixmap),tr("lightGray"),this);


}

void MainWindow::buttonClick()
{
     icon_color = QColorDialog::getColor(Qt::black,this);
     createIcon(icon_color);
}

void MainWindow::createIcon(QColor color)
{
    QPixmap button_icon(QSize(56,36));
    button_icon.fill(color);
    m_color_button->setIcon(QIcon(button_icon));
}



