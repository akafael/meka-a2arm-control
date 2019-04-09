cmake_minimum_required(VERSION 2.8.3)
project(m3ctrl_msgs)

find_package(catkin REQUIRED COMPONENTS  message_generation  std_msgs )

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_message_files(  FILES  M3JointCmd.msg )

generate_messages(  DEPENDENCIES  std_msgs )

catkin_package(
  LIBRARIES 
  CATKIN_DEPENDS 
)

