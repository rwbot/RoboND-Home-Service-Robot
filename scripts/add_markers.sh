#!/bin/sh

# xterm -e "  roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=/home/nvidia/catkin_ws/src/worlds/uda.world" &
# sleep 10
# xterm -e "  export TURTLEBOT_3D_SENSOR=kinect; export TURTLEBOT_GAZEBO_MAP_FILE=/home/nvidia/catkin_ws/src/worlds/kinect-map.yaml; roslaunch turtlebot_gazebo amcl_demo.launch"&
# sleep 5
# xterm -e "  roslaunch add_markers view_home_service.launch" &
xterm -e "  roslaunch home_service home_service.launch" &
sleep 10
xterm -e " roslaunch add_markers view_home_service.launch" &
sleep 5
xterm -e "  rosrun add_markers add_markers" &
sleep 5
xterm -e "  rosrun add_markers add_markers"
