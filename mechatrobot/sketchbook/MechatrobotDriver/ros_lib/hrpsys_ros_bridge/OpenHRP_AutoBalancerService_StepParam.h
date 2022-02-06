#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_StepParam_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_AutoBalancerService_StepParam_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_AutoBalancerService_StepParam : public ros::Msg
  {
    public:
      typedef float _step_height_type;
      _step_height_type step_height;
      typedef float _step_time_type;
      _step_time_type step_time;
      typedef float _toe_angle_type;
      _toe_angle_type toe_angle;
      typedef float _heel_angle_type;
      _heel_angle_type heel_angle;

    OpenHRP_AutoBalancerService_StepParam():
      step_height(0),
      step_time(0),
      toe_angle(0),
      heel_angle(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->step_height);
      offset += serializeAvrFloat64(outbuffer + offset, this->step_time);
      offset += serializeAvrFloat64(outbuffer + offset, this->toe_angle);
      offset += serializeAvrFloat64(outbuffer + offset, this->heel_angle);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->step_height));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->step_time));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->toe_angle));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->heel_angle));
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_StepParam"; };
    const char * getMD5(){ return "e5cf9e499f1e01973e9491c2d02ea815"; };

  };

}
#endif
