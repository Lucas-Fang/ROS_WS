#include "ros/ros.h"

int main(int argc, char *argv[])
{
    //解决中文乱码问题
    setlocale(LC_ALL,"");

    ros::init(argc,argv,"hello_vscode");
    ROS_INFO("hello,哈哈哈");
    return 0;
}
