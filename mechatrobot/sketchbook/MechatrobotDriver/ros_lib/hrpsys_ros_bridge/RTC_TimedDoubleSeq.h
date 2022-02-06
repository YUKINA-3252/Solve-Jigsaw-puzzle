#ifndef _ROS_hrpsys_ros_bridge_RTC_TimedDoubleSeq_h
#define _ROS_hrpsys_ros_bridge_RTC_TimedDoubleSeq_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/RTC_Time.h"

namespace hrpsys_ros_bridge
{

  class RTC_TimedDoubleSeq : public ros::Msg
  {
    public:
      typedef hrpsys_ros_bridge::RTC_Time _tm_type;
      _tm_type tm;
      uint32_t data_length;
      typedef float _data_type;
      _data_type st_data;
      _data_type * data;

    RTC_TimedDoubleSeq():
      tm(),
      data_length(0), data(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->tm.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->data_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data_length);
      for( uint32_t i = 0; i < data_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->data[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->tm.deserialize(inbuffer + offset);
      uint32_t data_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      data_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->data_length);
      if(data_lengthT > data_length)
        this->data = (float*)realloc(this->data, data_lengthT * sizeof(float));
      data_length = data_lengthT;
      for( uint32_t i = 0; i < data_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_data));
        memcpy( &(this->data[i]), &(this->st_data), sizeof(float));
      }
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/RTC_TimedDoubleSeq"; };
    const char * getMD5(){ return "d9e01689e17707d99ff596edf800755c"; };

  };

}
#endif
