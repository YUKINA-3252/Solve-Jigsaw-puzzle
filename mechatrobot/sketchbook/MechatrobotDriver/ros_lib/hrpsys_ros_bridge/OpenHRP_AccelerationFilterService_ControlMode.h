#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_AccelerationFilterService_ControlMode_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_AccelerationFilterService_ControlMode_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_AccelerationFilterService_ControlMode : public ros::Msg
  {
    public:
      enum { MODE_IDLE = 0 };
      enum { MODE_ZERO_VELOCITY = 1 };
      enum { MODE_RELATIVE_LOCAL_VELOCITY = 2 };
      enum { MODE_ABSOLUTE_LOCAL_VELOCITY = 3 };
      enum { MODE_RELATIVE_GLOBAL_VELOCITY = 4 };
      enum { MODE_ABSOLUTE_GLOBAL_VELOCITY = 5 };

    OpenHRP_AccelerationFilterService_ControlMode()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_AccelerationFilterService_ControlMode"; };
    const char * getMD5(){ return "31c1a5ecea5bda1ce9e430cddfc8be17"; };

  };

}
#endif
