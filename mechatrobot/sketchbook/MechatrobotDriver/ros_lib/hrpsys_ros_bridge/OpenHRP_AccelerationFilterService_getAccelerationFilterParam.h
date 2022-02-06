#ifndef _ROS_SERVICE_OpenHRP_AccelerationFilterService_getAccelerationFilterParam_h
#define _ROS_SERVICE_OpenHRP_AccelerationFilterService_getAccelerationFilterParam_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_AccelerationFilterService_AccelerationFilterParam.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_ACCELERATIONFILTERSERVICE_GETACCELERATIONFILTERPARAM[] = "hrpsys_ros_bridge/OpenHRP_AccelerationFilterService_getAccelerationFilterParam";

  class OpenHRP_AccelerationFilterService_getAccelerationFilterParamRequest : public ros::Msg
  {
    public:

    OpenHRP_AccelerationFilterService_getAccelerationFilterParamRequest()
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

    const char * getType(){ return OPENHRP_ACCELERATIONFILTERSERVICE_GETACCELERATIONFILTERPARAM; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_AccelerationFilterService_getAccelerationFilterParamResponse : public ros::Msg
  {
    public:
      typedef bool _operation_return_type;
      _operation_return_type operation_return;
      typedef hrpsys_ros_bridge::OpenHRP_AccelerationFilterService_AccelerationFilterParam _i_param_type;
      _i_param_type i_param;

    OpenHRP_AccelerationFilterService_getAccelerationFilterParamResponse():
      operation_return(0),
      i_param()
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
      offset += this->i_param.serialize(outbuffer + offset);
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
      offset += this->i_param.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return OPENHRP_ACCELERATIONFILTERSERVICE_GETACCELERATIONFILTERPARAM; };
    const char * getMD5(){ return "e0b1252ed60cf838260991ca7a71a68c"; };

  };

  class OpenHRP_AccelerationFilterService_getAccelerationFilterParam {
    public:
    typedef OpenHRP_AccelerationFilterService_getAccelerationFilterParamRequest Request;
    typedef OpenHRP_AccelerationFilterService_getAccelerationFilterParamResponse Response;
  };

}
#endif
