#include "ros/ros.h"
/*实现服务器曾改数据功能
    1、使用句柄 nodehandel
    2、使用ros::param::set()

*/
int main(int argc, char *argv[])
{
    ros::init(argc,argv,"set_para");
    //1、
    ros::NodeHandle nh;
    nh.setParam("type","xaioche");//设置机器人参数（给参数取名，参数类型+参数本体）
    nh.setParam("radius",200);
    //2、
    ros::param::set("type_param","xiaocheche");
    ros::param::set("radius_param",200);
    //修改参数
    nh.setParam("radius",6);
    ros::param::set("radius_param",4);
    return 0;
}
