#include "ros/ros.h"
#include "std_msgs/String.h"


//回调函数，处理订阅到的数据
void rxmsg(const std_msgs::String::ConstPtr &msg)
{

    
    ROS_INFO("接受到的数据为：%s",msg->data.c_str());
}
int main(int argc, char *argv[])
{
    /* code */
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"RX");


    ros::NodeHandle my_nh;

    ros::Subscriber sub =my_nh.subscribe("Msg",10,rxmsg);


    ros::spin();//返回回调函数


    return 0;
}
