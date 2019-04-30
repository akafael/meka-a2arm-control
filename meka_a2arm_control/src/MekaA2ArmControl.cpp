#include "meka_a2arm_control/MekaA2ArmControl.hpp"

// STD
#include <string>

namespace meka_a2arm_control {

MekaA2ArmControl::MekaA2ArmControl(ros::NodeHandle& nodeHandle)
    : nodeHandle_(nodeHandle)
{
  if (!readParameters()) {
    ROS_ERROR("Could not read parameters.");
    ros::requestShutdown();
  }
  subscriber_ = nodeHandle_.subscribe(subscriberTopic_, 1,
                                      &MekaA2ArmControl::topicCallback, this);
  serviceServer_ = nodeHandle_.advertiseService("get_average",
                                                &MekaA2ArmControl::serviceCallback, this);
  ROS_INFO("Successfully launched node.");
}

MekaA2ArmControl::~MekaA2ArmControl()
{
}

bool MekaA2ArmControl::readParameters()
{
  if (!nodeHandle_.getParam("subscriber_topic", subscriberTopic_)) return false;
  return true;
}

void MekaA2ArmControl::topicCallback(const m3ctrl_msgs::M3JointCmd::ConstPtr& msg)
{
  // do nothing
}

bool MekaA2ArmControl::serviceCallback(std_srvs::Trigger::Request& request,
                                         std_srvs::Trigger::Response& response)
{
  response.success = true;
  response.message = "The answer is 42";
  return true;
}

} /* namespace */
