#include "LayoutManager.h"

LayoutManager::LayoutManager(const QList<QWidget*> &widgets, QWidget *parent) :
    QVBoxLayout(parent) {
    addWidgets(widgets);
}

void LayoutManager::addWidgets(const QList<QWidget*> list){
    for (QWidget *element : list) {
        addWidget(element);
    }
}
