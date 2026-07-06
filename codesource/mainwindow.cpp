#include "mainwindow.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QApplication>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Widget central obligatoire pour un QMainWindow
    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    // Widgets
    HELLO_WORLD = "HELLO WORLD!";
    m_label = new QLabel(HELLO_WORLD, this);
    m_bouton = new QPushButton("VALIDE", this);
    m_close = new QPushButton("CLOSE", this);

    // Layout
    QVBoxLayout *layout = new QVBoxLayout(central);
    layout->addWidget(m_label);
    layout->addWidget(m_bouton);
    layout->addWidget(m_close);

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

