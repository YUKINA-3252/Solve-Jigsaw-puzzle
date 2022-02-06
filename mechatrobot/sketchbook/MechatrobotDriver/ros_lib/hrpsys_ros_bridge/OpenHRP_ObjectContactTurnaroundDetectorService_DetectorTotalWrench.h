#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_ObjectContactTurnaroundDetectorService_DetectorTotalWrench_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_ObjectContactTurnaroundDetectorService_DetectorTotalWrench_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_ObjectContactTurnaroundDetectorService_DetectorTotalWrench : public ros::Msg
  {
    public:
      enum { TOTAL_FORCE = 0 };
      enum { TOTAL_MOMENT = 1 };
      enum { TOTAL_MOMENT2 = 2 };

    OpenHRP_ObjectContactTurnaroundDetectorService_DetectorTotalWrench()
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

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_ObjectContactTurnaroundDetectorService_DetectorTotalWrench"; };
    const char * getMD5(){ return "1325b8d4b6e387911fb849c381169ce8"; };

  };

}
#endif
