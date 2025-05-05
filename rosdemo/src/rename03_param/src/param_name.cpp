#include "ros/ros.h"

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"hello");
    ros::NodeHandle nh;

    /*使用 ros::param 来设置参数*/

    //1.全局 相对与整个系统
    ros::param::set("/radiusA",100);
    //2.相对 相对于命名空间和节同级
    ros::param::set("radiusA",100);
    //3.私有 相对于节点，是节点的下一级
    ros::param::set("~radiusA",100);
    
    /* 使用 nodehandle 设置参数*/

    //1.全局
    nh.setParam("/radiusA_nh",1000);
    //2.相对
    nh.setParam("radiusA_nh",1000);
    //3.私有
   ros::NodeHandle nh_private("~");
   nh_private.setParam("radius_nh",1000);
    
    return 0;
}
