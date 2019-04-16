#include <ros/ros.h>
#include "meka_a2arm_control/MekaA2ArmControl.hpp"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "meka_a2arm_control");
  ros::NodeHandle nodeHandle("~");

  meka_a2arm_control::MekaA2ArmControl MekaA2ArmControl(nodeHandle);

  ros::spin();
  return 0;
}
