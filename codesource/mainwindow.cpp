#include "mainwindow.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QApplication>
#include <QDebug>
#include "LayoutManager.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    // Widget central obligatoire pour un QMainWindow
    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    // Widgets
    HELLO_WORLD = "HELLO WORLD!";
    m_label = new QLabel(HELLO_WORLD, this);
    m_bouton = new QPushButton("VALIDE", this);
    m_close = new QPushButton("CLOSE", this);
    QList<QWidget*> list = {m_label,m_bouton,m_close};

    // Layout
    new LayoutManager(list, central);

    // Connexion signal / slot
    connect(m_bouton, &QPushButton::clicked, this, &MainWindow::boutonClique);
    connect(m_close, &QPushButton::clicked, this, &MainWindow::boutonClose);
}

void MainWindow::boutonClose()
{
    this->close();
}

void MainWindow::boutonClique()
{
    if(HELLO_WORLD == "HELLO WORLD!"){
        HELLO_WORLD = "HELLO WORLD , after Click!";
    } else {
        HELLO_WORLD = "HELLO WORLD!";
    }

    m_label->setText(HELLO_WORLD);
}

