#include "ros/ros.h"
#include "rosbag/bag.h"
#include "rosbag/view.h"
#include "std_msgs/String.h"

int main(int argc, char *argv[])
{
   //初始化
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"bag_read");
    ros::NodeHandle nh;

    rosbag::Bag bag;

    //打开文件流
    bag.open("hello.bag",rosbag::bagmode::Read);

    //读数据 取出话题，时间戳，消息
    // rosbag::View(bag);

    for (auto &&m : rosbag::View(bag))
    {
        //解析
        std::string topic = m.getTopic();
        ros::Time time = m.getTime();
        std_msgs::StringPtr p = m.instantiate<std_msgs::String>();
        ROS_INFO("解析的内容，话题：%s，时间戳：%.2f，消息值：%s",
                topic.c_str(),
                time.toSec(),
                p->data.c_str());
    }
    //关闭文件流
    bag.close();
    return 0; 
}
