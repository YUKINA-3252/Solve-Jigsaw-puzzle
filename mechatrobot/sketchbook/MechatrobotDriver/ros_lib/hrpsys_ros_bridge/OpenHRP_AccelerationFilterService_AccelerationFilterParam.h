#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_AccelerationFilterService_AccelerationFilterParam_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_AccelerationFilterService_AccelerationFilterParam_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_AccelerationFilterService_AccelerationFilterParam : public ros::Msg
  {
    public:
      typedef float _gravity_type;
      _gravity_type gravity;
      typedef bool _use_filter_type;
      _use_filter_type use_filter;
      uint32_t filter_param_length;
      typedef float _filter_param_type;
      _filter_param_type st_filter_param;
      _filter_param_type * filter_param;

    OpenHRP_AccelerationFilterService_AccelerationFilterParam():
      gravity(0),
      use_filter(0),
      filter_param_length(0), filter_param(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->gravity);
      union {
        bool real;
        uint8_t base;
      } u_use_filter;
      u_use_filter.real = this->use_filter;
      *(outbuffer + offset + 0) = (u_use_filter.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->use_filter);
      *(outbuffer + offset + 0) = (this->filter_param_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->filter_param_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->filter_param_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->filter_param_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->filter_param_length);
      for( uint32_t i = 0; i < filter_param_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->filter_param[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->gravity));
      union {
        bool real;
        uint8_t base;
      } u_use_filter;
      u_use_filter.base = 0;
      u_use_filter.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->use_filter = u_use_filter.real;
      offset += sizeof(this->use_filter);
      uint32_t filter_param_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      filter_param_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      filter_param_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      filter_param_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->filter_param_length);
      if(filter_param_lengthT > filter_param_length)
        this->filter_param = (float*)realloc(this->filter_param, filter_param_lengthT * sizeof(float));
      filter_param_length = filter_param_lengthT;
      for( uint32_t i = 0; i < filter_param_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_filter_param));
        memcpy( &(this->filter_param[i]), &(this->st_filter_param), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_AccelerationFilterService_AccelerationFilterParam"; };
    const char * getMD5(){ return "f4998353c6d72b85e0f3171257a9dd83"; };

  };

}
#endif
