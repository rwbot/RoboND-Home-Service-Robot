#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose.h>
#include <nav_msgs/Odometry.h>

geometry_msgs::Pose pickup;
geometry_msgs::Pose dropoff;
bool is_preparing = true;
visualization_msgs::Marker marker;
visualization_msgs::Marker dropoffMARKER;
ros::Publisher marker_pub;

void odomCallback(const nav_msgs::Odometry::ConstPtr& msg){
        const bool is_picking_up = (abs(pickup.position.x - msg->pose.pose.position.x) + abs(pickup.position.y - msg->pose.pose.position.y)) < 1;
        
        const bool is_dropping_off = (abs(dropoff.position.x - msg->pose.pose.position.x) + abs(dropoff.position.y - msg->pose.pose.position.y)) < 2;
       
        
        if(is_preparing){
            marker_pub.publish(marker);
            std::cout << "ODOM CALLBACK     PREPARING: " <<  is_preparing << std::endl;
         }
        
        if(is_picking_up){
            is_preparing = false;
            sleep(5);
            marker.action = visualization_msgs::Marker::DELETE;
            marker_pub.publish(marker);
            std::cout << "IS PICKING UP" << std::endl;
        } else if(is_dropping_off){
            sleep(5);
            dropoffMARKER.action = visualization_msgs::Marker::ADD;
            marker_pub.publish(dropoffMARKER);
            std::cout << "IS DROPPING OFF" << std::endl;
        }
    }
    
    
    
    
int main( int argc, char** argv )
{
  ros::init(argc, argv, "add_markers");
  ros::NodeHandle n;
  ros::Rate r(1);
    marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
    pickup.position.x = -0.5;
    pickup.position.y = -7.0;
    dropoff.position.x = -7.0;
    dropoff.position.y = -5.5;
    ros::Subscriber marker_sub = n.subscribe("/odom",1000,odomCallback);
    // Set our initial shape type to be a cube
    uint32_t shape = visualization_msgs::Marker::SPHERE;
 
 // while (ros::ok())
 // {
    marker.header.frame_id = "map";
    marker.header.stamp = ros::Time::now();


    marker.ns = "add_markers";
    marker.id = 0;
    marker.type = shape;

    marker.action = visualization_msgs::Marker::ADD;
    marker.scale.x = 1.0;
    marker.scale.y = 1.0;
    marker.scale.z = 1.0;
    marker.color.r = 0.0f;
    marker.color.g = 1.0f;
    marker.color.b = 0.0f;
    marker.color.a = 1.0;
    marker.lifetime = ros::Duration();
    
    marker.pose.position.x = pickup.position.x;
    marker.pose.position.y = pickup.position.y;

    dropoffMARKER = marker;
    dropoffMARKER.id = 1;
    dropoffMARKER.pose.position.x = dropoff.position.x;
    dropoffMARKER.pose.position.y = dropoff.position.y;
    
    //if(is_preparing){
        //marker.action = visualization_msgs::Marker::ADD;
        std::cout << "MAIN" << std::endl;
        marker_pub.publish(marker);
    //}
    
/*
    // Publish the marker
    while (marker_pub.getNumSubscribers() < 1)
    {
      if (!ros::ok())
      {
        return 0;
      }
      ROS_WARN_ONCE("Please create a subscriber to the marker");
      sleep(1);
    }
*/

    
    //ros::Duration(5).sleep();
    //dropoff.action = visualization_msgs::Marker::DELETE;
    //marker_pub.publish(dropoff);
/*    marker.action = visualization_msgs::Marker::ADD;
    marker.pose.position.x = -7.0;
    marker.pose.position.y = -5.5;
    marker_pub.publish(marker); 
*/

    while(ros::ok()){
        ros::spinOnce();
        r.sleep();
    }
  //}
}
