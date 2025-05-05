#include "ros/ros.h"
#include "plumbing_pub_sub/person.h"


int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    
    ros::init(argc,argv,"my_msgs");
    ros::NodeHandle my_nh;
    // //使用自定义信息发布
    ros::Publisher pub = my_nh.advertise<plumbing_pub_sub::person>("chat",10);
    plumbing_pub_sub::person person;
    person.name = "林沼君";
    person.age = 20 ;
    person.height = 106;
    ros::Rate rate(5);

    while(ros::ok())
     {
        pub.publish(person);
    //ROS_INFO("发送的数据为：%s,%d,%.2f",person.name.c_str(),person.age.c_str(),person.height.c_str());
        ROS_INFO("发送的数据为：%s,%d,%.0f",person.name.c_str(),person.age,person.height);
       
        rate.sleep();
        ros::spinOnce();

    }

    

    return 0;
}

