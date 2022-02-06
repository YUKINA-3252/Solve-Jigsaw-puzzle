#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_UseForceMode_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_UseForceMode_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_AutoBalancerService_UseForceMode : public ros::Msg
  {
    public:
      enum { MODE_NO_FORCE = 0 };
      enum { MODE_REF_FORCE = 1 };
      enum { MODE_REF_FORCE_WITH_FOOT = 2 };
      enum { MODE_REF_FORCE_RFU_EXT_MOMENT = 3 };

    OpenHRP_AutoBalancerService_UseForceMode()
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

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_UseForceMode"; };
    const char * getMD5(){ return "5be011a017c93d868ff77be53c745605"; };

  };

}
#endif
