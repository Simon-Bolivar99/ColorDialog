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
}

void MainWindow::createGui()
{
    m_color_button = new ColorToolButton();
    auto m_layout = new QHBoxLayout();
        m_layout->addWidget(m_color_button);

    setLayout(m_layout);
}





