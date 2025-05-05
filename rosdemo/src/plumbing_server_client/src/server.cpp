#include "ros/ros.h"
#include "plumbing_server_client/ADDInts.h"


bool doNums(plumbing_server_client::ADDInts::Request &request,
            plumbing_server_client::ADDInts::Response &response)
{
    int num1=request.num1;
    int num2=request.num2;
    ROS_INFO("收到的数据为:num1 %d,num2 %d",num1,num2);
    int sum = num1+num2;
    response.sum=sum;
    ROS_INFO("解析出的数据为:sum %d",sum);

    return true;
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"SERVER");
    ros::NodeHandle myhd;
    ros::ServiceServer server = myhd.advertiseService("addints",doNums);
    ROS_INFO("服务器端启动！");

    ros::spin();
    return 0;
}
