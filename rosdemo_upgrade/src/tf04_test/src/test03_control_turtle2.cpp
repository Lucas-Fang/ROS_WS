#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include "geometry_msgs/TransformStamped.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"tfs_sub");
    ros::NodeHandle nh;

    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener sub(buffer);

    //创建发布对象，准备发布速度信息
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel",100);

    //编写实现逻辑
    ros::Rate rate(10);

    while (ros::ok())
    {
        try
        {
           //1.计算son1与son2的相对关系
           geometry_msgs::TransformStamped son1Toson2 = buffer.lookupTransform("turtle2","turtle1",ros::Time(0));
           //(目标坐标系，相对的坐标系，时间（此处为时间间隔相聚最近的两个位置）)
           ROS_INFO("turtle1相对于turtle2的信息：父级%s，子级%s 偏移量（%.2f %.2f %.2f）",
                    son1Toson2.header.frame_id.c_str(),
                    son1Toson2.child_frame_id.c_str(),
                    son1Toson2.transform.translation.x ,
                    son1Toson2.transform.translation.y ,
                    son1Toson2.transform.translation.z );
           //根据相对位置计算turtle2速度，并且发布
           geometry_msgs::Twist twist;
            /*
             组织速度发布 只需要设置线速度x发布，还有yaw轴角速度z

             x = 系数 * 开方（x^2 + y^2）
             z = 系数 * 反正切（对边，临边）
            */
           twist.linear.x = 0.5*sqrt(pow(son1Toson2.transform.translation.x,2)+pow(son1Toson2.transform.translation.y,2));
           twist.angular.z = 10*atan2f32(son1Toson2.transform.translation.y,son1Toson2.transform.translation.x);
           //发布
           pub.publish(twist);


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
