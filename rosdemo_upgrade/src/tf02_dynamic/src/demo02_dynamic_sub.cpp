#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h"
#include "geometry_msgs/PointStamped.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
/*
    为了实现，在乌龟坐标系下的一个点，转换成世界坐标系下的
*/
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"tf_sub_d");
    ros::NodeHandle nh;
    //创建订阅对象 ----> 订阅坐标系相对关系
      //创建一个buffer缓存
    tf2_ros::Buffer buffer;
      //再创建监听对象（监听对象可以将订阅的数据放入缓存）
    tf2_ros::TransformListener listener(buffer);
    //组织一个坐标点数据
    geometry_msgs::PointStamped ps;
    //坐标点所参考的坐标系
    ps.header.frame_id = "turtle1";
    /*时间戳要修改
        原因：放入buffer里面的数据是有延迟的且自带一个时间戳，如果这里使用ros：：time：：now的话，
             那么这两个时间戳对比之后发现时间不同步就会报错；而设置0的话，就会任务认为这个坐标与
             时间没有关系，就不会报错了
    */
    ps.header.stamp = ros::Time(0.0);
    ps.point.x = 2.0;
    ps.point.y = 5.0;
    ps.point.z = 3.0;

    ros::Duration(2).sleep();//睡觉两秒，有足够时间订阅到数据
    //转换算法（需要tf内置实现）
    ros::Rate rate(10);
    while (ros::ok())
    {
        //核心代码 将ps转换成 相当于base_link的坐标点
        geometry_msgs::PointStamped ps_out;
        //最后输出

        /*
        注意：会出现base_link找不到的异常
            原因：订阅的话题中的数据还没有被放到buffer中
            解决：1.添加ros::Duration(2).sleep()；
                 2.使用try进行异常处理
        */
       try
       {
            ps_out = buffer.transform(ps,"world");//调用时必须包含 tf2_geometry_msgs/tf2_geometry_msgs.h
            ROS_INFO("转换后的坐标值：（%.2f,%.2f,%.2f),参考的坐标系：%s",
                ps_out.point.x,
                ps_out.point.y,
                ps_out.point.z,
                ps_out.header.frame_id.c_str()
                );
       }
       catch(const std::exception& e)
       {
        // std::cerr << e.what() << '\n';
        ROS_INFO("异常消息：%s",e.what());
       }

        rate.sleep();
        ros::spinOnce();
    }
    return 0;
}

