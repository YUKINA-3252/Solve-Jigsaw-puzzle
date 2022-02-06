#ifndef _ROS_SERVICE_OpenHRP_GraspControllerService_startGrasp_h
#define _ROS_SERVICE_OpenHRP_GraspControllerService_startGrasp_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_GRASPCONTROLLERSERVICE_STARTGRASP[] = "hrpsys_ros_bridge/OpenHRP_GraspControllerService_startGrasp";

  class OpenHRP_GraspControllerService_startGraspRequest : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef float _target_error_type;
      _target_error_type target_error;

    OpenHRP_GraspControllerService_startGraspRequest():
      name(""),
      target_error(0)
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
      offset += serializeAvrFloat64(outbuffer + offset, this->target_error);
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
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->target_error));
     return offset;
    }

    const char * getType(){ return OPENHRP_GRASPCONTROLLERSERVICE_STARTGRASP; };
    const char * getMD5(){ return "4b4e4ccae8b8f257602cbe7f48c64b68"; };

  };

  class OpenHRP_GraspControllerService_startGraspResponse : public ros::Msg
  {
    public:
      typedef bool _operation_return_type;
      _operation_return_type operation_return;

    OpenHRP_GraspControllerService_startGraspResponse():
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

    const char * getType(){ return OPENHRP_GRASPCONTROLLERSERVICE_STARTGRASP; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_GraspControllerService_startGrasp {
    public:
    typedef OpenHRP_GraspControllerService_startGraspRequest Request;
    typedef OpenHRP_GraspControllerService_startGraspResponse Response;
  };

}
#endif
