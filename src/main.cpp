#include "funrobo_gpsview/mainwindow.h"
#include <QApplication>

#include <ros/ros.h>
#include <ros/package.h>

#include <sensor_msgs/NavSatFix.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString image_path = (ros::package::getPath("funrobo_gpsview") + "/assets/olin.png").c_str();

    MainWindow w(nullptr,image_path);
    w.show();

    return a.exec();
}
