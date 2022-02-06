#ifndef _ROS_SERVICE_OpenHRP_RobotHardwareService_readDigitalInput_h
#define _ROS_SERVICE_OpenHRP_RobotHardwareService_readDigitalInput_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_ROBOTHARDWARESERVICE_READDIGITALINPUT[] = "hrpsys_ros_bridge/OpenHRP_RobotHardwareService_readDigitalInput";

  class OpenHRP_RobotHardwareService_readDigitalInputRequest : public ros::Msg
  {
    public:

    OpenHRP_RobotHardwareService_readDigitalInputRequest()
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

    const char * getType(){ return OPENHRP_ROBOTHARDWARESERVICE_READDIGITALINPUT; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_RobotHardwareService_readDigitalInputResponse : public ros::Msg
  {
    public:
      typedef bool _operation_return_type;
      _operation_return_type operation_return;
      uint32_t din_length;
      typedef uint8_t _din_type;
      _din_type st_din;
      _din_type * din;

    OpenHRP_RobotHardwareService_readDigitalInputResponse():
      operation_return(0),
      din_length(0), din(NULL)
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
      *(outbuffer + offset + 0) = (this->din_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->din_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->din_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->din_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->din_length);
      for( uint32_t i = 0; i < din_length; i++){
      *(outbuffer + offset + 0) = (this->din[i] >> (8 * 0)) & 0xFF;
      offset += sizeof(this->din[i]);
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
      uint32_t din_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      din_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      din_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      din_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->din_length);
      if(din_lengthT > din_length)
        this->din = (uint8_t*)realloc(this->din, din_lengthT * sizeof(uint8_t));
      din_length = din_lengthT;
      for( uint32_t i = 0; i < din_length; i++){
      this->st_din =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->st_din);
        memcpy( &(this->din[i]), &(this->st_din), sizeof(uint8_t));
      }
     return offset;
    }

    const char * getType(){ return OPENHRP_ROBOTHARDWARESERVICE_READDIGITALINPUT; };
    const char * getMD5(){ return "e3afb3b596ca4ee32072d4200ab0872e"; };

  };

  class OpenHRP_RobotHardwareService_readDigitalInput {
    public:
    typedef OpenHRP_RobotHardwareService_readDigitalInputRequest Request;
    typedef OpenHRP_RobotHardwareService_readDigitalInputResponse Response;
  };

}
#endif
