#!/usr/bin/env bash
# Call from .student_bashrc
# 		source /home/workspace/RoboND-Home-Service-Robot/udasetup.sh
# Manually source this file using:
#		sudo -s source /home/workspace/RoboND-Home-Service-Robot/udasetup.sh
alias srcb="source /home/workspace/RoboND-Home-Service-Robot/udasetup.sh"

# supposed to return directory containing scripts (bash/shell incompatibility?)
# DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
# or
# DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

#!/bin/sh
# CATKIN_DIR="$( cd $( dirname $BASH_SOURCE[0] )/../.. >/dev/null && pwd )"
# export ROBOT_INITIAL_POSE="-x -3 -y -3"
# xterm  -e  " roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=$CATKIN_DIR/src/World/custom_environment.world; " &

# $(find pkg)           # for launch files
# rospack find pkg      # for bash


alias rr="cdcbz; ./gazebo-arm.sh"
alias rro="cdcbz; ./gazebo-arm.sh | tee /home/workspace/RoboND-Home-Service-Robot/tests/output.txt"
alias rrd="cdcbz; ./gazebo-arm.sh | tee /home/workspace/RoboND-Home-Service-Robot/tests/$(date +%a%H:%M:%S).txt"
alias rrd="srcb; cdcbz; ./gazebo-arm.sh | tee /home/workspace/RoboND-Home-Service-Robot/tests/$(date +%a%H:%M:%S).txt"


#alias cdc="cd /home/workspace/RoboND-Home-Service-Robot" #custom cd command that goes to catkin_ws
alias cdh="cd /home/workspace/RoboND-Home-Service-Robot"
alias cdcb="cd /home/workspace/RoboND-Home-Service-Robot/build"
alias cdcmk="cdcb; make" #goes to catkin_ws, runs catkin_make, waits until it's made, then sources devel/setup.bash


alias gcm="cdc; git checkout master"
alias gcw="cdc; git checkout workspaces"
alias gpm="cdc; git pull rw master"
alias gpw="cdc; git pull rw workspaces"

alias kz="killall gazebo & killall gzserver & killall gzclient" #kills gazebo if frozen
alias gitcon="git config --global credential.helper 'cache --timeout=999999'; git config --global user.name 'rwbot'; git config --global user.email 'rwbotx@gmail.com'"
