#include "ros/ros.h"


int main(int argc, char *argv[])
{
    ros::init(argc,argv,"change_RGB_Color");
    //使用句柄 1-1
    ros::NodeHandle nh("turtle1");
    nh.setParam("background_r",255);
    nh.setParam("background_g",255);
    nh.setParam("background_b",0);
    //使用句柄1-2
    // ros::NodeHandle nh;
    // nh.setParam("/turtle1/background_r",20);
    // nh.setParam("/turtle1/background_g",40);
    // nh.setParam("/turtle1/background_b",10);

    //使用param
    // ros::param::set("/turtle1/background_r",0);
    // ros::param::set("/turtle1/background_g",0);
    // ros::param::set("/turtle1/background_b",0);
    return 0;
}
