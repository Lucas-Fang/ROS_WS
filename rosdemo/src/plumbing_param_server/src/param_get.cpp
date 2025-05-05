#include "ros/ros.h"

/*查询服务器中的数据 */
int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"get_param");

    ros::NodeHandle nh;
    //1、param
    float radius = nh.param("radius",0.5);//正确的话返回服务器中键的值，错误的话返回后面设置的默认值
    ROS_INFO("半径为:%.2f",radius);
    //2.getparam
    float radius_f = 0.0;
    // bool result = nh.getParam("radius",radius_f);

    //3.getParamCached，从缓存里面获取数据 性能上比较getparam有提升
    double result = nh.getParamCached("radius",radius_f);//获取数据之后放到radius_f里面
    if(result)
    {
        ROS_INFO("半径为:%.2f",radius_f);
    }
    else
    {
        ROS_INFO("被查询的变量不存在！");
    }
    //4.getgetParamNames,获取所有键的名称；
    std::vector<std::string> names;
    nh.getParamNames(names);
    for(auto &&name : names)
    {
        ROS_INFO("遍历的元素：%s",name.c_str());
    }
    //5.hasParam
    bool flag1 = nh.hasParam("radius");//判断这个键在不在，在返回 1,不在返回 0；
    bool flag2 = nh.hasParam("radiusxxx");
    ROS_INFO("flag1在不在？%d",flag1);
    ROS_INFO("flag2在不在？%d",flag2);

    //6.searchParam 搜索这个键，并将这个键的信息保存在后面的字符串参数里面；
    std::string key;
    nh.searchParam("/radius",key);
    ROS_INFO("查询的结果为：%s",key.c_str());
    return 0;
}
