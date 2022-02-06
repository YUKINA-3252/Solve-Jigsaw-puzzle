#ifndef _ROS_pr2_gripper_sensor_msgs_PR2GripperForceServoActionFeedback_h
#define _ROS_pr2_gripper_sensor_msgs_PR2GripperForceServoActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "pr2_gripper_sensor_msgs/PR2GripperForceServoFeedback.h"

namespace pr2_gripper_sensor_msgs
{

  class PR2GripperForceServoActionFeedback : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef pr2_gripper_sensor_msgs::PR2GripperForceServoFeedback _feedback_type;
      _feedback_type feedback;

    PR2GripperForceServoActionFeedback():
      header(),
      status(),
      feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->feedback.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return "pr2_gripper_sensor_msgs/PR2GripperForceServoActionFeedback"; };
    const char * getMD5(){ return "d8ca0d3860c2a6ed1145d230fe6bd9db"; };

  };

}
#endif
