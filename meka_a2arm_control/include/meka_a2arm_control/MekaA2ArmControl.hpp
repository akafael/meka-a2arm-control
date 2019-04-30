#pragma once

// ROS
#include <ros/ros.h>
#include <m3ctrl_msgs/M3JointCmd.h>
#include <sensor_msgs/JointState.h>
#include <std_srvs/Trigger.h>

namespace meka_a2arm_control {

/*!
 * Main class for the node to handle the ROS interfacing.
 */
class MekaA2ArmControl

{
 public:
  /*!
   * Constructor.
   * @param nodeHandle the ROS node handle.
   */
  MekaA2ArmControl(ros::NodeHandle& nodeHandle);

  /*!
   * Destructor.
   */
  virtual ~MekaA2ArmControl();

 private:
  /*!
   * Reads and verifies the ROS parameters.
   * @return true if successful.
   */
  bool readParameters();

  /*!
   * ROS topic callback method.
   * @param message the received message.
   */
  void topicCallback(const m3ctrl_msgs::M3JointCmd::ConstPtr& msg);

  /*!
   * ROS service server callback.
   * @param request the request of the service.
   * @param response the provided response.
   * @return true if successful, false otherwise.
   */
  bool serviceCallback(std_srvs::Trigger::Request& request,
                       std_srvs::Trigger::Response& response);

  //! ROS node handle.
  ros::NodeHandle& nodeHandle_;

  //! ROS topic subscriber.
  ros::Subscriber subscriber_;

  //! ROS topic name to subscribe to.
  std::string subscriberTopic_;

  //! ROS service server.
  ros::ServiceServer serviceServer_;
};

} /* namespace */
