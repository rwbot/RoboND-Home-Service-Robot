#!/bin/sh
#source /opt/ros/kinetic/setup.bash
#source /home/nvidia/catkin_ws/devel/setup.bash
export TURTLEBOT_3D_SENSOR=kinect
export TURTLEBOT_GAZEBO_MAP_FILE=/home/nvidia/catkin_ws/src/worlds/kinect-map.yaml

xterm -e "  roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=/home/nvidia/catkin_ws/src/worlds/uda.world" &
sleep 10
xterm -e " export TURTLEBOT_3D_SENSOR=kinect; export TURTLEBOT_GAZEBO_MAP_FILE=/home/nvidia/catkin_ws/src/worlds/kinect-map.yaml; roslaunch turtlebot_gazebo amcl_demo.launch"&

#xterm -e "  roslaunch turtlebot_navigation amcl_demo.launch map_file:=/home/nvidia/catkin_ws/src/worlds/kinect-map.yaml" &
#xterm -e "  roslaunch turtlebot_gazebo amcl_demo.launch " &
sleep 5

xterm -e "  roslaunch turtlebot_rviz_launchers view_navigation.launch" 







