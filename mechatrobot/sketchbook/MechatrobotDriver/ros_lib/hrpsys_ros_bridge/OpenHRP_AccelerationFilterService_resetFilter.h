#ifndef _ROS_SERVICE_OpenHRP_AccelerationFilterService_resetFilter_h
#define _ROS_SERVICE_OpenHRP_AccelerationFilterService_resetFilter_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_ACCELERATIONFILTERSERVICE_RESETFILTER[] = "hrpsys_ros_bridge/OpenHRP_AccelerationFilterService_resetFilter";

  class OpenHRP_AccelerationFilterService_resetFilterRequest : public ros::Msg
  {
    public:
      typedef int64_t _mode_type;
      _mode_type mode;
      float vel[3];

    OpenHRP_AccelerationFilterService_resetFilterRequest():
      mode(0),
      vel()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_mode;
      u_mode.real = this->mode;
      *(outbuffer + offset + 0) = (u_mode.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_mode.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_mode.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_mode.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_mode.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_mode.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_mode.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_mode.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->mode);
      for( uint32_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->vel[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_mode;
      u_mode.base = 0;
      u_mode.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_mode.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_mode.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_mode.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_mode.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_mode.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_mode.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_mode.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->mode = u_mode.real;
      offset += sizeof(this->mode);
      for( uint32_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->vel[i]));
      }
     return offset;
    }

    const char * getType(){ return OPENHRP_ACCELERATIONFILTERSERVICE_RESETFILTER; };
    const char * getMD5(){ return "6aa446ed8230245127d4d463e427ccb3"; };

  };

  class OpenHRP_AccelerationFilterService_resetFilterResponse : public ros::Msg
  {
    public:
      typedef bool _operation_return_type;
      _operation_return_type operation_return;

    OpenHRP_AccelerationFilterService_resetFilterResponse():
      operation_return(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_operation_return;
      u_operation_return.real = this->operation_return;
      *(outbuffer + offset + 0) = (u_operation_return.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->operation_return);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_operation_return;
      u_operation_return.base = 0;
      u_operation_return.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->operation_return = u_operation_return.real;
      offset += sizeof(this->operation_return);
     return offset;
    }

    const char * getType(){ return OPENHRP_ACCELERATIONFILTERSERVICE_RESETFILTER; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_AccelerationFilterService_resetFilter {
    public:
    typedef OpenHRP_AccelerationFilterService_resetFilterRequest Request;
    typedef OpenHRP_AccelerationFilterService_resetFilterResponse Response;
  };

}
#endif
