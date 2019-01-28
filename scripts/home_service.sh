#!/bin/sh

xterm -e "  roslaunch home_service home_service.launch" &
sleep 10
xterm -e " roslaunch add_markers view_home_service.launch" &
sleep 5
xterm -e "  rosrun add_markers add_markers" &
sleep 2
xterm -e "  rosrun pick_objects pick_objects"
