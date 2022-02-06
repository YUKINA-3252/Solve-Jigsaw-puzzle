#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_ThermoLimiterService_tlParam_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_ThermoLimiterService_tlParam_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_ThermoLimiterService_tlParam : public ros::Msg
  {
    public:
      typedef uint32_t _debug_print_freq_type;
      _debug_print_freq_type debug_print_freq;
      typedef float _alarmRatio_type;
      _alarmRatio_type alarmRatio;

    OpenHRP_ThermoLimiterService_tlParam():
      debug_print_freq(0),
      alarmRatio(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->debug_print_freq >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->debug_print_freq >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->debug_print_freq >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->debug_print_freq >> (8 * 3)) & 0xFF;
      offset += sizeof(this->debug_print_freq);
      offset += serializeAvrFloat64(outbuffer + offset, this->alarmRatio);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->debug_print_freq =  ((uint32_t) (*(inbuffer + offset)));
      this->debug_print_freq |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->debug_print_freq |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->debug_print_freq |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->debug_print_freq);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->alarmRatio));
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_ThermoLimiterService_tlParam"; };
    const char * getMD5(){ return "88c69a9bed27b10a90c2c0ab22b103a4"; };

  };

}
#endif
