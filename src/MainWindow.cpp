#include "include/MainWindow.h"
#include "include/ColorToolButton.h"

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
    createGui();
}

MainWindow::~MainWindow()
{
    delete ColorButton;
}

void MainWindow::createGui()
{
    ColorButton = new ColorToolButton();
    //ColorButton->setFixedSize(QSize (150,150));
    auto m_layout = new QHBoxLayout();
        m_layout->addWidget(ColorButton);
        m_layout->setStretch(0, 1);
    setLayout(m_layout);
    ColorButton->setBaseSize(150, 150);
    ColorButton->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
}





