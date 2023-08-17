#include "include/UserMenu.h"

UserMenu::UserMenu(QWidget *parent)
    : QMenu(parent)
{
}

UserMenu::UserMenu(const QString &title, QWidget *parent): QMenu(title, parent)
{
}

UserMenu::~UserMenu()
{
}
