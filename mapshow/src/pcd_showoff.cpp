#include <ros/ros.h>
#include <pcl/point_cloud.h>
#include <pcl_conversions/pcl_conversions.h>
#include <sensor_msgs/PointCloud2.h>
#include <string>
#include <pcl/point_types.h>

int main (int argc, char **argv)
{
    ros::init (argc, argv, "pcd_showoff");

    ros::NodeHandle nh;
    ros::Publisher pub1 = nh.advertise<sensor_msgs::PointCloud2> ("/main1_pcd",10);
    // ros::Publisher pub2 = nh.advertise<sensor_msgs::PointCloud2> ("main2_pcd", 1);
    // ros::Publisher pub3 = nh.advertise<sensor_msgs::PointCloud2> ("moon_hall_pcd", 1);
    // ros::Publisher pub4 = nh.advertise<sensor_msgs::PointCloud2> ("xiqianyuan_pcd", 1);
    // ros::Publisher pub5 = nh.advertise<sensor_msgs::PointCloud2> ("yunfeng_pcd", 1);
    // ros::Publisher pub6 = nh.advertise<sensor_msgs::PointCloud2> ("yunfeng_nei_pcd", 1);
    // ros::Publisher pub7 = nh.advertise<sensor_msgs::PointCloud2> ("qingxi_pcd", 1);
    // ros::Publisher pub8 = nh.advertise<sensor_msgs::PointCloud2> ("qingxi_nei_pcd", 1);
    // ros::Publisher pub9 = nh.advertise<sensor_msgs::PointCloud2> ("cuibai_pcd", 1);
    // ros::Publisher pub10 = nh.advertise<sensor_msgs::PointCloud2> ("cuibai_nei_pcd", 1);

    std::string pcd_address_1;
    std::string pcd_address_2;
    std::string pcd_address_3;
    std::string pcd_address_4;
    std::string pcd_address_5;
    std::string pcd_address_6;
    std::string pcd_address_7;
    std::string pcd_address_8;
    std::string pcd_address_9;
    std::string pcd_address_10;

    nh.getParam("pcd_address_1",pcd_address_1);
    // nh.getParam("pcd_address_2",pcd_address_2);
    // nh.getParam("pcd_address_3",pcd_address_3);
    // nh.getParam("pcd_address_4",pcd_address_4);
    // nh.getParam("pcd_address_5",pcd_address_5);
    // nh.getParam("pcd_address_6",pcd_address_6);
    // nh.getParam("pcd_address_7",pcd_address_7);
    // nh.getParam("pcd_address_8",pcd_address_8);
    // nh.getParam("pcd_address_9",pcd_address_9);
    // nh.getParam("pcd_address_10",pcd_address_10);

    std::cout<<"pcd_address:"<<pcd_address_1<<std::endl;
    pcl::PointCloud<pcl::PointXYZI>::Ptr cloud1(new pcl::PointCloud<pcl::PointXYZI>);

    if(pcl::io::loadPCDFile<pcl::PointXYZI> (pcd_address_1, *cloud1) == -1)
    {
        PCL_ERROR("couldn't read pcd file! \n");
        return 0;
    }

    std::cout<<"cloud1->size():"<<cloud1->width * cloud1->height<<std::endl;

    // pcl::PCLPointCloud2::Ptr cloud2(new pcl::PCLPointCloud2);
    // pcl::io::loadPCDFile (pcd_address_2, *cloud2);

    // pcl::PCLPointCloud2::Ptr cloud3(new pcl::PCLPointCloud2);
    // pcl::io::loadPCDFile (pcd_address_3, *cloud3);

    // pcl::PCLPointCloud2::Ptr cloud4(new pcl::PCLPointCloud2);
    // pcl::io::loadPCDFile (pcd_address_4, *cloud4);

    // pcl::PCLPointCloud2::Ptr cloud5(new pcl::PCLPointCloud2);
    // pcl::io::loadPCDFile (pcd_address_5, *cloud5);

    // pcl::PCLPointCloud2::Ptr cloud6(new pcl::PCLPointCloud2);
    // pcl::io::loadPCDFile (pcd_address_6, *cloud6);

    // pcl::PCLPointCloud2::Ptr cloud7(new pcl::PCLPointCloud2);
    // pcl::io::loadPCDFile (pcd_address_7, *cloud7);

    // pcl::PCLPointCloud2::Ptr cloud8(new pcl::PCLPointCloud2);
    // pcl::io::loadPCDFile (pcd_address_8, *cloud8);

    // pcl::PCLPointCloud2::Ptr cloud9(new pcl::PCLPointCloud2);
    // pcl::io::loadPCDFile (pcd_address_9, *cloud9);

    // pcl::PCLPointCloud2::Ptr cloud10(new pcl::PCLPointCloud2);
    // pcl::io::loadPCDFile (pcd_address_10, *cloud10);


    // Convert to ROS data type
    sensor_msgs::PointCloud2 output1;
    pcl::toROSMsg(*cloud1, output1);
    output1.header.frame_id = "map";
    output1.header.stamp = ros::Time::now();


    // Convert to ROS data type
    // sensor_msgs::PointCloud2 output2;
    // pcl_conversions::fromPCL(*cloud2, output2);
    // output2.header.frame_id = std::string("map");

    // // Convert to ROS data type
    // sensor_msgs::PointCloud2 output3;
    // pcl_conversions::fromPCL(*cloud3, output3);
    // output3.header.frame_id = std::string("map");

    // // Convert to ROS data type
    // sensor_msgs::PointCloud2 output4;
    // pcl_conversions::fromPCL(*cloud4, output4);
    // output4.header.frame_id = std::string("map");

    // // Convert to ROS data type
    // sensor_msgs::PointCloud2 output5;
    // pcl_conversions::fromPCL(*cloud5, output5);
    // output5.header.frame_id = std::string("map");

    // // Convert to ROS data type
    // sensor_msgs::PointCloud2 output6;
    // pcl_conversions::fromPCL(*cloud6, output6);
    // output6.header.frame_id = std::string("map");

    // // Convert to ROS data type
    // sensor_msgs::PointCloud2 output7;
    // pcl_conversions::fromPCL(*cloud7, output7);
    // output7.header.frame_id = std::string("map");

    // // Convert to ROS data type
    // sensor_msgs::PointCloud2 output8;
    // pcl_conversions::fromPCL(*cloud8, output8);
    // output8.header.frame_id = std::string("map");

    // // Convert to ROS data type
    // sensor_msgs::PointCloud2 output9;
    // pcl_conversions::fromPCL(*cloud9, output9);
    // output9.header.frame_id = std::string("map");

    // // Convert to ROS data type
    // sensor_msgs::PointCloud2 output10;
    // pcl_conversions::fromPCL(*cloud10, output10);
    // output10.header.frame_id = std::string("map");
    ros::Rate loop_rate(100);

    while (ros::ok())
    {
        // Publish the data
        pub1.publish (output1);
      
        // pub2.publish (output2);
        // ros::Duration(0.09).sleep();

        // pub3.publish (output3);
        // ros::Duration(0.09).sleep();

        // pub4.publish (output4);
        // ros::Duration(0.09).sleep();

        // pub5.publish (output5);
        // ros::Duration(0.09).sleep();

        // pub6.publish (output6);
        // ros::Duration(0.09).sleep();

        // pub7.publish (output7);
        // ros::Duration(0.09).sleep();

        // pub8.publish (output8);
        // ros::Duration(0.09).sleep();

        // pub9.publish (output9);
        // ros::Duration(0.09).sleep();

        // pub10.publish (output10);
        // ros::Duration(0.09).sleep();
        loop_rate.sleep();
    }

    return 0;
}
