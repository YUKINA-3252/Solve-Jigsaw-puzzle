#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_StrideLimitationType_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_StrideLimitationType_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_AutoBalancerService_StrideLimitationType : public ros::Msg
  {
    public:
      enum { SQUARE = 0 };
      enum { CIRCLE = 1 };

    OpenHRP_AutoBalancerService_StrideLimitationType()
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

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_StrideLimitationType"; };
    const char * getMD5(){ return "aee5d0aad410c13c3528c10e82cc8c83"; };

  };

}
#endif
