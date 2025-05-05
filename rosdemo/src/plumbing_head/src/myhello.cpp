#include "ros/ros.h"
#include "plumbing_head/head.h"




// void hello_ns::hello::run()
// {
//     ROS_INFO("run函数运行");
// }
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"myhello");
    hello_ns::hello myhello;
    myhello.run();

    return 0;
}

