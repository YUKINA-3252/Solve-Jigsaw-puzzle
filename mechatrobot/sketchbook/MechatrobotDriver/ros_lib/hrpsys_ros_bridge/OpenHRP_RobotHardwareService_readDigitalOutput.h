#ifndef _ROS_SERVICE_OpenHRP_RobotHardwareService_readDigitalOutput_h
#define _ROS_SERVICE_OpenHRP_RobotHardwareService_readDigitalOutput_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_ROBOTHARDWARESERVICE_READDIGITALOUTPUT[] = "hrpsys_ros_bridge/OpenHRP_RobotHardwareService_readDigitalOutput";

  class OpenHRP_RobotHardwareService_readDigitalOutputRequest : public ros::Msg
  {
    public:

    OpenHRP_RobotHardwareService_readDigitalOutputRequest()
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

    const char * getType(){ return OPENHRP_ROBOTHARDWARESERVICE_READDIGITALOUTPUT; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_RobotHardwareService_readDigitalOutputResponse : public ros::Msg
  {
    public:
      typedef bool _operation_return_type;
      _operation_return_type operation_return;
      uint32_t dOut_length;
      typedef uint8_t _dOut_type;
      _dOut_type st_dOut;
      _dOut_type * dOut;

    OpenHRP_RobotHardwareService_readDigitalOutputResponse():
      operation_return(0),
      dOut_length(0), dOut(NULL)
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
      *(outbuffer + offset + 0) = (this->dOut_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->dOut_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->dOut_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->dOut_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dOut_length);
      for( uint32_t i = 0; i < dOut_length; i++){
      *(outbuffer + offset + 0) = (this->dOut[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->dOut[i]);
      }
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
      uint32_t dOut_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      dOut_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      dOut_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      dOut_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->dOut_length);
      if(dOut_lengthT > dOut_length)
        this->dOut = (uint8_t*)realloc(this->dOut, dOut_lengthT * sizeof(uint8_t));
      dOut_length = dOut_lengthT;
      for( uint32_t i = 0; i < dOut_length; i++){
      this->st_dOut =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_dOut);
        memcpy( &(this->dOut[i]), &(this->st_dOut), sizeof(uint8_t));
      }
     return offset;
    }

    const char * getType(){ return OPENHRP_ROBOTHARDWARESERVICE_READDIGITALOUTPUT; };
    const char * getMD5(){ return "ffc623ba0f3a614b80c5c033ff5a0059"; };

  };

  class OpenHRP_RobotHardwareService_readDigitalOutput {
    public:
    typedef OpenHRP_RobotHardwareService_readDigitalOutputRequest Request;
    typedef OpenHRP_RobotHardwareService_readDigitalOutputResponse Response;
  };

}
#endif
