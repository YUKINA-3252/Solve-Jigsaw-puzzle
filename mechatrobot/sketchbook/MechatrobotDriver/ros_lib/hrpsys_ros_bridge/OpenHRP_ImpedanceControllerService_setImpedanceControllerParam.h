#ifndef _ROS_SERVICE_OpenHRP_ImpedanceControllerService_setImpedanceControllerParam_h
#define _ROS_SERVICE_OpenHRP_ImpedanceControllerService_setImpedanceControllerParam_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_ImpedanceControllerService_impedanceParam.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_IMPEDANCECONTROLLERSERVICE_SETIMPEDANCECONTROLLERPARAM[] = "hrpsys_ros_bridge/OpenHRP_ImpedanceControllerService_setImpedanceControllerParam";

  class OpenHRP_ImpedanceControllerService_setImpedanceControllerParamRequest : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef hrpsys_ros_bridge::OpenHRP_ImpedanceControllerService_impedanceParam _i_param_type;
      _i_param_type i_param;

    OpenHRP_ImpedanceControllerService_setImpedanceControllerParamRequest():
      name(""),
      i_param()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_name = strlen(this->name);
      varToArr(outbuffer + offset, length_name);
      offset += 4;
      memcpy(outbuffer + offset, this->name, length_name);
      offset += length_name;
      offset += this->i_param.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_name;
      arrToVar(length_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_name-1]=0;
      this->name = (char *)(inbuffer + offset-1);
      offset += length_name;
      offset += this->i_param.deserialize(inbuffer + offset);
     return offset;
    }

    const char * getType(){ return OPENHRP_IMPEDANCECONTROLLERSERVICE_SETIMPEDANCECONTROLLERPARAM; };
    const char * getMD5(){ return "10de3a474fe16e6a161496a2d382093b"; };

  };

  class OpenHRP_ImpedanceControllerService_setImpedanceControllerParamResponse : public ros::Msg
  {
    public:
      typedef bool _operation_return_type;
      _operation_return_type operation_return;

    OpenHRP_ImpedanceControllerService_setImpedanceControllerParamResponse():
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

    const char * getType(){ return OPENHRP_IMPEDANCECONTROLLERSERVICE_SETIMPEDANCECONTROLLERPARAM; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_ImpedanceControllerService_setImpedanceControllerParam {
    public:
    typedef OpenHRP_ImpedanceControllerService_setImpedanceControllerParamRequest Request;
    typedef OpenHRP_ImpedanceControllerService_setImpedanceControllerParamResponse Response;
  };

}
#endif
