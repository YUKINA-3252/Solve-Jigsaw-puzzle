#ifndef _ROS_hrpsys_ros_bridge_OpenHRP_ReferenceForceUpdaterService_ReferenceForceUpdaterParam_h
#define _ROS_hrpsys_ros_bridge_OpenHRP_ReferenceForceUpdaterService_ReferenceForceUpdaterParam_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class OpenHRP_ReferenceForceUpdaterService_ReferenceForceUpdaterParam : public ros::Msg
  {
    public:
      float motion_dir[3];
      typedef const char* _frame_type;
      _frame_type frame;
      typedef float _update_freq_type;
      _update_freq_type update_freq;
      typedef float _update_time_ratio_type;
      _update_time_ratio_type update_time_ratio;
      typedef float _p_gain_type;
      _p_gain_type p_gain;
      typedef float _d_gain_type;
      _d_gain_type d_gain;
      typedef float _i_gain_type;
      _i_gain_type i_gain;
      typedef bool _is_hold_value_type;
      _is_hold_value_type is_hold_value;
      typedef float _transition_time_type;
      _transition_time_type transition_time;

    OpenHRP_ReferenceForceUpdaterService_ReferenceForceUpdaterParam():
      motion_dir(),
      frame(""),
      update_freq(0),
      update_time_ratio(0),
      p_gain(0),
      d_gain(0),
      i_gain(0),
      is_hold_value(0),
      transition_time(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      for( uint32_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->motion_dir[i]);
      }
      uint32_t length_frame = strlen(this->frame);
      varToArr(outbuffer + offset, length_frame);
      offset += 4;
      memcpy(outbuffer + offset, this->frame, length_frame);
      offset += length_frame;
      offset += serializeAvrFloat64(outbuffer + offset, this->update_freq);
      offset += serializeAvrFloat64(outbuffer + offset, this->update_time_ratio);
      offset += serializeAvrFloat64(outbuffer + offset, this->p_gain);
      offset += serializeAvrFloat64(outbuffer + offset, this->d_gain);
      offset += serializeAvrFloat64(outbuffer + offset, this->i_gain);
      union {
        bool real;
        uint8_t base;
      } u_is_hold_value;
      u_is_hold_value.real = this->is_hold_value;
      *(outbuffer + offset + 0) = (u_is_hold_value.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->is_hold_value);
      offset += serializeAvrFloat64(outbuffer + offset, this->transition_time);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      for( uint32_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->motion_dir[i]));
      }
      uint32_t length_frame;
      arrToVar(length_frame, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_frame; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_frame-1]=0;
      this->frame = (char *)(inbuffer + offset-1);
      offset += length_frame;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->update_freq));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->update_time_ratio));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->p_gain));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->d_gain));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->i_gain));
      union {
        bool real;
        uint8_t base;
      } u_is_hold_value;
      u_is_hold_value.base = 0;
      u_is_hold_value.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->is_hold_value = u_is_hold_value.real;
      offset += sizeof(this->is_hold_value);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->transition_time));
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/OpenHRP_ReferenceForceUpdaterService_ReferenceForceUpdaterParam"; };
    const char * getMD5(){ return "45f77140e71c50446783880c2993a2ed"; };

  };

}
#endif
