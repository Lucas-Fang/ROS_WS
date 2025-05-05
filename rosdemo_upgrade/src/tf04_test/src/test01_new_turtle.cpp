#include "ros/ros.h"
#include "turtlesim/Spawn.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"service_spawn");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("/spawn");

    turtlesim::Spawn spawn;
    spawn.request.x = 1.0;
    spawn.request.y = 4.0;
    spawn.request.theta = 1.57;
    spawn.request.name = "turtle2";
    //判断服务器状态
    //ros::service::waitForService("/spawn");或者
    client.waitForExistence();
    bool flag = client.call(spawn);
    if(flag)
    {
        ROS_INFO("Service_sucess,turtle'name:%s ",spawn.response.name.c_str());
    }
    else
    {
        ROS_INFO("Service_fail!");
    }

    return 0;
}

