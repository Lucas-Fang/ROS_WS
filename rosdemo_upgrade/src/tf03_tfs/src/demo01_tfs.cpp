#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include "geometry_msgs/TransformStamped.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"tfs_sub");
    ros::NodeHandle nh;

    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener sub(buffer);
    //创建一个相对于son1的坐标点
    geometry_msgs::PointStamped psATson1;
    psATson1.header.stamp = ros::Time::now();
    psATson1.header.frame_id = "son1";
    psATson1.point.x = 1.0;
    psATson1.point.y = 2.0;
    psATson1.point.z = 3.0;

    //编写实现逻辑
    ros::Rate rate(10);

    while (ros::ok())
    {
        try
        {
           //1.计算son1与son2的相对关系
           geometry_msgs::TransformStamped son1Toson2 = buffer.lookupTransform("son2","son1",ros::Time(0));
           //(目标坐标系，相对的坐标系，时间（此处为时间间隔相聚最近的两个位置）)
           ROS_INFO("son1相对于son2的信息：父级%s，子级%s 偏移量（%.2f %.2f %.2f）",
                    son1Toson2.header.frame_id.c_str(),
                    son1Toson2.child_frame_id.c_str(),
                    son1Toson2.transform.translation.x ,
                    son1Toson2.transform.translation.y ,
                    son1Toson2.transform.translation.z );
           
           //2.计算son1中的某一个坐标点在son2中的坐标值
            geometry_msgs::PointStamped psATson2 = buffer.transform(psATson1,"son2");
            ROS_INFO("坐标点在son2中的值为:(%.2f,%.2f,%.2f)",
                    psATson2.point.x,
                    psATson2.point.y,
                    psATson2.point.z
                    );
        }
        catch(const std::exception& e)
        {
            ROS_INFO("ERROR:%s",e.what());
        }


        rate.sleep();
        ros::spinOnce();
    }
    
    return 0;
}
