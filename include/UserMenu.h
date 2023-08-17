#pragma once
#include <QMenu>

class UserMenu : public QMenu{
    Q_OBJECT

public:
    UserMenu(QWidget *parent);
    UserMenu(const QString &title, QWidget *parent);
    ~UserMenu();
};
