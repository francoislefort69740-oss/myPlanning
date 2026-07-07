#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QLabel;
class QPushButton;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void boutonClique();
    void boutonClose();

private:
    QString HELLO_WORLD;
    QLabel *m_titre;
    QLabel *m_label;
    QPushButton *m_bouton;
    QPushButton *m_close;
};
#endif // MAINWINDOW_H
