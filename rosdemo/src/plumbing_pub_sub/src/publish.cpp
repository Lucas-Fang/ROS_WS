#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sstream"

int main(int argc, char *argv[])
{
    /* code */
    setlocale(LC_CTYPE, "zh_CN.utf8");
    ros::init(argc,argv,"TX");

    //�������
    ros::NodeHandle My_node_handle;
    //���������߶���
    ros::Publisher My_publish = My_node_handle.advertise<std_msgs::String>("Msg",10);
    //��д�����߼�����������
    ros::Rate rate(10);
    int count = 0;
    std_msgs::String msg;

    ros::Duration(3).sleep(); 
    while (ros::ok())
    {
        count++;
        // msg.data="Hello ROS!!!";
        std::stringstream ss;
        ss << "Hello --->" << count;
        msg.data=ss.str();
        My_publish.publish(msg);

        ROS_INFO("发送的数据为：%s",ss.str().c_str());
        rate.sleep();
        ros::spinOnce();//返回在执行的回调函数
    }
    





    return 0;
}
