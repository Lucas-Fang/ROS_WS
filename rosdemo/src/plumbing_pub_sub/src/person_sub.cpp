#include "ros/ros.h"
#include "plumbing_pub_sub/person.h"

void rc_msgs(const plumbing_pub_sub::person::ConstPtr& person)
{
    ROS_INFO("订阅到的信息为：%s,%d,%.0f",person->name.c_str(),person->age,person->height);
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ROS_INFO("订阅方实现：");
    ros::init(argc,argv,"my_sub");
    
    ros::NodeHandle mynh;
    ros::Subscriber sub = mynh.subscribe("chat",10,rc_msgs);
    
    ros::spin();
    return 0;
}
