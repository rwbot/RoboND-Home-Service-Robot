#!/bin/sh
#source /opt/ros/kinetic/setup.bash
#source /home/nvidia/catkin_ws/devel/setup.bash
export TURTLEBOT_3D_SENSOR=kinect


xterm -e "  roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=/home/nvidia/catkin_ws/src/worlds/uda.world" &
sleep 10

xterm -e "  roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 5

xterm -e "  export TURTLEBOT_3D_SENSOR=kinect; roslaunch turtlebot_navigation gmapping_demo.launch" &
sleep 5

xterm -e "  roslaunch turtlebot_teleop  keyboard_teleop.launch" 




