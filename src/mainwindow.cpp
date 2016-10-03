#include "funrobo_gpsview/mainwindow.h"
#include "ui_mainwindow.h"

#define LT_MIN (-71.264387)
#define LT_MAX (-71.263483)
#define LG_MIN (42.293132)
#define LG_MAX (42.293790)

#define WIDTH (496)
#define HEIGHT (487)

#define RADIUS (5.0)

MainWindow::MainWindow(QWidget *parent, QString image_path) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_graphicsScene(new QGraphicsScene(this))
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&m_graphicsScene);

    QPixmap bk(image_path);
    if(!bk.isNull()){
        m_graphicsScene.addPixmap(bk);
    }

    gpsPen = QPen(gpsBrush,1.0,Qt::SolidLine,Qt::SquareCap,Qt::BevelJoin);
    gpsBrush = QBrush(QColor(255,0,0),Qt::SolidPattern);


    gpsPointer = new QGraphicsEllipseItem(QRectF(0.0,0.0,RADIUS*2,RADIUS*2));
    gpsPointer->setPen(gpsPen);
    gpsPointer->setBrush(gpsBrush);
    m_graphicsScene.addItem(gpsPointer);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete gpsPointer;
}

void MainWindow::updateGPS(float lt, float lg){
    //img = (height x width) 487 x 496

    float x = (lg - LG_MIN)/(LG_MAX - LG_MIN); // normalize
    x *= WIDTH;
    float y = (lt - LT_MIN)/(LT_MAX - LT_MIN); // normalize
    y *= HEIGHT;
    if(0<=x && x<WIDTH && 0<=y && y<HEIGHT){
       gpsPointer->setRect(x - RADIUS,y - RADIUS,RADIUS*2,RADIUS*2);
        ui->lat_val->setText(QString::number(lt));
        ui->long_val->setText(QString::number(lg));
    }else{
        ui->lat_val->setText("OUT OF RANGE");
        ui->long_val->setText("OUT OF RANGE");
    }
}
