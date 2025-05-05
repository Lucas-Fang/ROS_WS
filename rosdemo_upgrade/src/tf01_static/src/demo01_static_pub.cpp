#include "ros/ros.h"
#include "tf2_ros/static_transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h"

/*
    需求：发布两个坐标系的相对关系

    流程：
        1.包含头文件
        2.设置编码 节点初始化 NodeHandle；
        3.创建发布对象
        4.组织被发布的消息
        5.发布数据
        6.spin();
*/
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"static_pub");
    ros::NodeHandle nh;
    //创建发布对象
    tf2_ros::StaticTransformBroadcaster pub;
    //4.组织被发布的消息
    geometry_msgs::TransformStamped tfs;
    tfs.header.stamp = ros::Time::now();//时间戳
    tfs.header.frame_id = "base_link";//相对坐标系中被参考的那一个，车身
    tfs.child_frame_id = "laser" ;//雷达
    tfs.transform.translation.x=0.2;
    tfs.transform.translation.y=0.0;
    tfs.transform.translation.z=0.5;
    //四元数需要根据欧拉角转换
    tf2::Quaternion qtn; //创建四元数对象
    //向该对象设置欧拉角，自动转换成四元数
    qtn.setRPY(0,0,0);
    tfs.transform.rotation.x = qtn.getX();
    tfs.transform.rotation.y = qtn.getY();
    tfs.transform.rotation.z = qtn.getZ();
    tfs.transform.rotation.w = qtn.getW();
    //5.
    pub.sendTransform(tfs); 
    ros::spin();
    return 0;
}
/*
也可以直接用命令行的方式(ros官方封装好的静态坐标变换)
rosrun tf2_ros static_trasform_publisher 0.1 0.2 0.3 (偏移量x,y,z) 0 0 0（欧拉角yaw pitch roll）/base_link /laser
*/
