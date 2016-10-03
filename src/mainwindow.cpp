#include "funrobo_gpsview/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, QString image_path) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_graphicsScene(new QGraphicsScene(this))
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&m_graphicsScene);

    QPixmap bk(image_path);
    m_graphicsScene.addPixmap(bk);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateGPS(float lt, float lg){
    //ignore lt,lg
    m_graphicsScene.addEllipse(5,5,5,5);
}
