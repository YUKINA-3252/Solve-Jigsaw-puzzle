#ifndef _ROS_hrpsys_ros_bridge_RTC_Size3D_h
#define _ROS_hrpsys_ros_bridge_RTC_Size3D_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

  class RTC_Size3D : public ros::Msg
  {
    public:
      typedef float _l_type;
      _l_type l;
      typedef float _w_type;
      _w_type w;
      typedef float _h_type;
      _h_type h;

    RTC_Size3D():
      l(0),
      w(0),
      h(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->l);
      offset += serializeAvrFloat64(outbuffer + offset, this->w);
      offset += serializeAvrFloat64(outbuffer + offset, this->h);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->l));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->w));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->h));
     return offset;
    }

    const char * getType(){ return "hrpsys_ros_bridge/RTC_Size3D"; };
    const char * getMD5(){ return "09ee73e9959cb322594a7a11cdaf6fce"; };

  };

}
#endif
