#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QGraphicsScene m_graphicsScene;
public:
    explicit MainWindow(QWidget *parent = 0, QString image_path="");
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:
    void updateGPS(float lt, float lg);
};

#endif // MAINWINDOW_H
