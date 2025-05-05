#include "ros/ros.h"
#include "std_msgs/String.h"

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"hello");//节点名称
    // ros::NodeHandle nh;

    // //设置不同类型的话题
    
    // //1.全局(根 / 后面直接带名称)话题名称以 / 开头，这种情况下和节点的命名空间或者名字都没有
    // ros::Publisher pub = nh.advertise<std_msgs::String>("/chatter",100);
    // //或者
    // ros::Publisher pub = nh.advertise<std_msgs::String>("/yyy/chatter",100);

    // //2.相对 不使用 / 开头 参考的节点命名空间
    // ros::Publisher pub = nh.advertise<std_msgs::String>("chatter",100);

    //3.私有  需要创造一个特殊的nodehandle,此时话题名称和节点的名字和命名空间有关
    //注意：如果在这个情况下，创造的话题名称以  / 开头，那么会生成全局话题
    ros::NodeHandle nh("~");
    ros::Publisher pub = nh.advertise<std_msgs::String>("chatter",100);

    while (ros::ok())
    {
        
    }
    
    return 0;
}

