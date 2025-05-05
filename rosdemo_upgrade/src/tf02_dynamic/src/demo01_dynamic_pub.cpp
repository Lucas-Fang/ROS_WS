#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include "tf2_ros/transform_broadcaster.h"
#include "geometry_msgs/TransformStamped.h"
#include "tf2/LinearMath/Quaternion.h"

void doPose(const turtlesim::Pose::ConstPtr& pose)
{
    //创建发布对象
    static tf2_ros::TransformBroadcaster pub;
    //组织被发布的数据
    geometry_msgs::TransformStamped ts;
    ts.header.frame_id = "world";
    ts.header.stamp = ros::Time::now();
    ts.child_frame_id = "turtle1";
    //坐标系偏移量确定
    ts.transform.translation.x = pose->x;//获取的乌龟的x位移
    ts.transform.translation.y = pose->y;
    ts.transform.translation.z = 0;
    /*乌龟的欧拉角 0 0 yaw（theta）*/
    tf2::Quaternion qtn;
    qtn.setRPY(0,0,pose->theta);
    ts.transform.rotation.x = qtn.getX();
    ts.transform.rotation.y = qtn.getY();
    ts.transform.rotation.z = qtn.getZ();
    ts.transform.rotation.w = qtn.getW();
    //发布
    pub.sendTransform(ts);
}

int main(int argc, char  *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"dynamic_pub");
    ros::NodeHandle nh;
    //创建订阅对象，订阅乌龟节点，以便于拿到乌龟的位姿 /turtle1/pose
    ros::Subscriber sub = nh.subscribe("/turtle1/pose",100 ,doPose);

    ros::spin();
    return 0;
}
