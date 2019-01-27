#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  // Initialize the pick_objects node
  ros::init(argc, argv, "pick_objects");

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  // Wait 5 sec for move_base action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;

  // set up the frame parameters
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();

// FIRST GOAL
  // Define a position and orientation for the robot to reach
  goal.target_pose.pose.position.x = -0.5;
  goal.target_pose.pose.position.y = -7.0;
  goal.target_pose.pose.orientation.z = 1.0;
  goal.target_pose.pose.orientation.w = 0.0;

   // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending Goal 1: PICKUP ZONE");
  ac.sendGoal(goal);

  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
  {
    ROS_INFO("Hooray, reached the pickup zone");
    ROS_INFO("Picking up object");
    // Wait 5 seconds to simulate picking up object
    ros::Duration(5).sleep();
    ROS_INFO("Object picked up");
    }
  else 
  {
    ROS_INFO("The base failed to reach the pickup zone");
   }
// SECOND GOAL
    // Define a position and orientation for the robot to reach
  goal.target_pose.pose.position.x = -7.0;
  goal.target_pose.pose.position.y = -5.5;
  goal.target_pose.pose.orientation.z = 0.8;
  goal.target_pose.pose.orientation.w = 0.5;

   // Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending Goal 2: DROPOFF ZONE");
  ac.sendGoal(goal);

  // Wait an infinite time for the results
  ac.waitForResult();
  
    // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Hooray, reached the dropoff zone");
  else
    ROS_INFO("The base failed to reach the dropoff zone");
    

  return 0;
}
