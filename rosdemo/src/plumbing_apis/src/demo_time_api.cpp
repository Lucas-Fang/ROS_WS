#include "ros/ros.h"

    uint8_t count=0;
void callback(const ros::TimerEvent& event)
{

    ROS_INFO("----------->%.d",count);
    ROS_INFO("函数现在运行的时间是：%.2f",event.current_real.toSec());//打印现在运行的时间
    count++;
}
int main(int argc, char *argv[])
{
    if(count >=20)
    {
        ros::shutdown();//关闭节点
    }
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"time");
    ros::NodeHandle nh;//必须要有这个句柄，否则无法初始化成功

    //这个时间是相对于1970年00：00：00而言的
    ros::Time right_time =ros::Time::now();
    ROS_INFO("输出的时间是:%.2f",right_time.toSec());
    //or
    ROS_INFO("现在的时间是:%d",right_time.sec);

    ROS_INFO("------------------------------------------------");

    ROS_INFO("开始休眠");
    // ros::Duration du(4.5);
    // du.sleep();
    ROS_INFO("休眠结束");

    ROS_INFO("------------------------定时器-------------------");
    /*createTimer(ros::Duration period,    定时器持续时间
    const ros::TimerCallback &callback,     回调函数
    bool oneshot = false,                   是否只执行一次
    bool autostart = true)
    */
    // ros::Timer timer = nh.createTimer(ros::Duration(1),callback);
    // ros::Timer timer = nh.createTimer(ros::Duration(1),callback,true);//只执行一次
    ros::Timer timer = nh.createTimer(ros::Duration(1),callback,false,false);//不自动执行
    timer.start();//手动执行定时器
    ros::spin();//回旋

    return 0;
}
