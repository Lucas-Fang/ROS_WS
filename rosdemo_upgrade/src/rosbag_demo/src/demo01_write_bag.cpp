#include "ros/ros.h"
#include "rosbag/bag.h"
#include "std_msgs/String.h"

int main(int argc, char *argv[])
{
    //初始化
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"bag_write");
    ros::NodeHandle nh;

    //创建rosbag对象
    rosbag::Bag bag;
    //打开文件流
    bag.open("hello.bag",rosbag::bagmode::Write);

    //写数据
    std_msgs::String msg;
    msg.data = "hello XXXX";
    msg.data = "hello XXXX";
    msg.data = "hello XXXX";
    bag.write("/chatter",ros::Time::now(),msg);
    //关闭文件流
    bag.close();
    return 0;
}
