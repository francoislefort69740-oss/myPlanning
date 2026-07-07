#ifndef LAYOUTMANAGER_H
#define LAYOUTMANAGER_H

#include <QVBoxLayout>

class LayoutManager : public QVBoxLayout
{
public:
    explicit LayoutManager(const QList<QWidget*> &widgets, QWidget *parent = nullptr);
    void addWidgets(const QList<QWidget*> myList);
};

#endif // LAYOUTMANAGER_H
