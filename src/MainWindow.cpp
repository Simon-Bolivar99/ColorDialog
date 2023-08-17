#include "include/MainWindow.h"
#include "include/UserMenu.h"

#include <QToolButton>
#include <QHBoxLayout>
#include <QAction>
#include <QDialog>
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
    m_tbutton = new QToolButton();
        m_tbutton->setIcon(QIcon(":/icons/cross.svg"));
        m_tbutton->setPopupMode(QToolButton::DelayedPopup);
    m_menu_button1 = new QPushButton("1");
    m_menu_button2 = new QPushButton("2");
    m_menu_button3 = new QPushButton("3");

    auto m_layout = new QHBoxLayout();
        m_layout->addWidget(m_tbutton);

    m_menu = new QMenu;
        m_menu->addAction(m_add_act);
        m_menu->addSeparator();
        m_menu->addAction(m_rm_act);
        m_tbutton->setMenu(m_menu);

    setLayout(m_layout);
}

void MainWindow::connectSignals()
{
    connect(m_tbutton, &QToolButton::clicked, this, &MainWindow::buttonClick);
}

void MainWindow::createActions()
{
    m_rm_act = new QAction(tr("&Удалить11111111111111111111111111111111111111111111111111111111111111111"),this);
    m_add_act = new QAction(tr("&Добавить"),this);
}

void MainWindow::buttonClick()
{

     qDebug() << QString("Click");
}

void MainWindow::buttonMenuClick()
{
    qDebug() << QString("Menu");
}


