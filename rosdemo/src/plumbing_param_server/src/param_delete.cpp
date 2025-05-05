#include "ros/ros.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"param_delete");
    //1.
    ros::NodeHandle nh;
    bool flag1 = nh.deleteParam("radius");
    if (flag1)
    {
        ROS_INFO("DELETE SUCCESSED!");
    }
    else
    {
        ROS_INFO("Delete failure!");
    }

    //2.
    bool flag2 = ros::param::del("radius_param");
    
    if (flag2)
    {
        ROS_INFO("radius_param DELETE SUCCESSED!");
    }
    else
    {
        ROS_INFO("radius_param Delete failure!");
    }
    return 0;
}

