#include "ros/ros.h"
#include "plumbing_server_client/ADDInts.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    if (argc!=3)
    {
        ROS_INFO("INPUT_FAILURE!");
        return 1;
    }
    
    ros::init(argc,argv,"CLIENT");
    ros::NodeHandle myhd;
    ros::ServiceClient client = myhd.serviceClient<plumbing_server_client::ADDInts>("addints");
    plumbing_server_client::ADDInts ai;
    ai.request.num1=atoi(argv[1]);
    ai.request.num2=atoi(argv[2]);
    //调用此函数可以达到：如果服务端未启动，那么客户端刮起(以下两个函数都可以实现)
    // client.waitForExistence();
    ros::service::waitForService("addints");
    bool flag = client.call(ai);
    if(flag)
    {
        ROS_INFO("SUCESSED!");
        ROS_INFO("OUTPUT = %d",ai.response.sum);
    }
    else
    {
        ROS_INFO("FAILURE!");
    }
    ros::spinOnce();
    return 0;
}
