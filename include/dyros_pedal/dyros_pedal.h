#ifndef _DYROS_PEDAL_H
#define _DYROS_PEDAL_H
// ROS LIBRARY
#include <ros/ros.h>
// ROS MESSAGE
#include <std_msgs/Float32.h>
#include <sensor_msgs/Joy.h>

#include "tocabi_msgs/WalkingCommand.h"

class DyrosPedal
  {
  public:
    DyrosPedal();
    void pedalCallback(const sensor_msgs::Joy::ConstPtr& joy);
     
  private:
    ros::NodeHandle nh_;
    ros::Publisher walking_cmd_pub_;
    ros::Subscriber pedal_sub_;
    bool walk_cmd_;
    bool walk_cmd_pre_;
    tocabi_msgs::WalkingCommand walk_cmd_msg_;
  };
 

 int main(int argc, char** argv);

#endif
