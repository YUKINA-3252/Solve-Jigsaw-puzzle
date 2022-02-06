#ifndef _ROS_SERVICE_OpenHRP_AccelerationFilterService_setAccelerationFilterParam_h
#define _ROS_SERVICE_OpenHRP_AccelerationFilterService_setAccelerationFilterParam_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_AccelerationFilterService_AccelerationFilterParam.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_ACCELERATIONFILTERSERVICE_SETACCELERATIONFILTERPARAM[] = "hrpsys_ros_bridge/OpenHRP_AccelerationFilterService_setAccelerationFilterParam";

  class OpenHRP_AccelerationFilterService_setAccelerationFilterParamRequest : public ros::Msg
  {
    public:
      typedef hrpsys_ros_bridge::OpenHRP_AccelerationFilterService_AccelerationFilterParam _i_param_type;
      _i_param_type i_param;

    OpenHRP_AccelerationFilterService_setAccelerationFilterParamRequest():
      i_param()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->i_param.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->i_param.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return OPENHRP_ACCELERATIONFILTERSERVICE_SETACCELERATIONFILTERPARAM; };
    const char * getMD5(){ return "b20cc49805488b859a9f0d966408a53b"; };

  };

  class OpenHRP_AccelerationFilterService_setAccelerationFilterParamResponse : public ros::Msg
  {
    public:
      typedef bool _operation_return_type;
      _operation_return_type operation_return;

    OpenHRP_AccelerationFilterService_setAccelerationFilterParamResponse():
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

    const char * getType(){ return OPENHRP_ACCELERATIONFILTERSERVICE_SETACCELERATIONFILTERPARAM; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_AccelerationFilterService_setAccelerationFilterParam {
    public:
    typedef OpenHRP_AccelerationFilterService_setAccelerationFilterParamRequest Request;
    typedef OpenHRP_AccelerationFilterService_setAccelerationFilterParamResponse Response;
  };

}
#endif
