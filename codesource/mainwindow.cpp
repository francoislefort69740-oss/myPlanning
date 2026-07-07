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
    m_titre = new QLabel("PLANNING", this);
    m_label = new QLabel(HELLO_WORLD, this);
    m_bouton = new QPushButton("VALIDE", this);
    m_close = new QPushButton("CLOSE", this);
    QList<QWidget*> list = {m_titre,m_label,m_bouton,m_close};

    // customisation
    QString titleSteelSheet = "background-color: #AAAAAA;"
                              "border-radius: 5px;"
                              "color: black;"
                              "font-size: 20px;"
                              "font-weight: bold;"
                              "padding: 10px";


    QString mySteelSheet = "QLabel {"
                           "background-color: #BBBBBB;"
                           "border-radius: 30px;"
                           "padding: 5px;"
                           "color: black;"
                           "}"
                           "QLabel:hover {"
                           "background-color: #CCCCCC;"
                           "}";

    m_label->setStyleSheet(mySteelSheet);
    m_titre->setAlignment(Qt::AlignCenter);
    m_titre->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
    m_titre->setStyleSheet(titleSteelSheet);
    m_label->setAlignment(Qt::AlignCenter);

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

