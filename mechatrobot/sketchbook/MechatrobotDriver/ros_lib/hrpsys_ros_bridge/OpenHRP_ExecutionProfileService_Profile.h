#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_ExecutionProfileService_Profile_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_ExecutionProfileService_Profile_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_ExecutionProfileService_ComponentProfile.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_ExecutionProfileService_Profile : public ros::Msg
  {
    public:
      typedef float _max_period_type;
      _max_period_type max_period;
      typedef float _min_period_type;
      _min_period_type min_period;
      typedef float _avg_period_type;
      _avg_period_type avg_period;
      typedef float _max_process_type;
      _max_process_type max_process;
      uint32_t profiles_length;
      typedef hrpsys_ros_bridge::OpenHRP_ExecutionProfileService_ComponentProfile _profiles_type;
      _profiles_type st_profiles;
      _profiles_type * profiles;
      typedef int32_t _count_type;
      _count_type count;
      typedef int32_t _timeover_type;
      _timeover_type timeover;

    OpenHRP_ExecutionProfileService_Profile():
      max_period(0),
      min_period(0),
      avg_period(0),
      max_process(0),
      profiles_length(0), profiles(NULL),
      count(0),
      timeover(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->max_period);
      offset += serializeAvrFloat64(outbuffer + offset, this->min_period);
      offset += serializeAvrFloat64(outbuffer + offset, this->avg_period);
      offset += serializeAvrFloat64(outbuffer + offset, this->max_process);
      *(outbuffer + offset + 0) = (this->profiles_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->profiles_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->profiles_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->profiles_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->profiles_length);
      for( uint32_t i = 0; i < profiles_length; i++){
      offset += this->profiles[i].serialize(outbuffer + offset);
      }
      union {
        int32_t real;
        uint32_t base;
      } u_count;
      u_count.real = this->count;
      *(outbuffer + offset + 0) = (u_count.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_count.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_count.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_count.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->count);
      union {
        int32_t real;
        uint32_t base;
      } u_timeover;
      u_timeover.real = this->timeover;
      *(outbuffer + offset + 0) = (u_timeover.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_timeover.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_timeover.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_timeover.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->timeover);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->max_period));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->min_period));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->avg_period));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->max_process));
      uint32_t profiles_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      profiles_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      profiles_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      profiles_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->profiles_length);
      if(profiles_lengthT > profiles_length)
        this->profiles = (hrpsys_ros_bridge::OpenHRP_ExecutionProfileService_ComponentProfile*)realloc(this->profiles, profiles_lengthT * sizeof(hrpsys_ros_bridge::OpenHRP_ExecutionProfileService_ComponentProfile));
      profiles_length = profiles_lengthT;
      for( uint32_t i = 0; i < profiles_length; i++){
      offset += this->st_profiles.deserialize(inbuffer + offset);
        memcpy( &(this->profiles[i]), &(this->st_profiles), sizeof(hrpsys_ros_bridge::OpenHRP_ExecutionProfileService_ComponentProfile));
      }
      union {
        int32_t real;
        uint32_t base;
      } u_count;
      u_count.base = 0;
      u_count.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_count.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_count.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_count.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->count = u_count.real;
      offset += sizeof(this->count);
      union {
        int32_t real;
        uint32_t base;
      } u_timeover;
      u_timeover.base = 0;
      u_timeover.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_timeover.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_timeover.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_timeover.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->timeover = u_timeover.real;
      offset += sizeof(this->timeover);
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_ExecutionProfileService_Profile"; };
    const char * getMD5(){ return "81d6e451dd3c3c507eb655f4a7c6fba2"; };

  };

}
#endif
