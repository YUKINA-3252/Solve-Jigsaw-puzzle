#ifndef _ROS_SERVICE_OpenHRP_CollisionDetectorService_setTolerance_h
#define _ROS_SERVICE_OpenHRP_CollisionDetectorService_setTolerance_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_COLLISIONDETECTORSERVICE_SETTOLERANCE[] = "hrpsys_ros_bridge/OpenHRP_CollisionDetectorService_setTolerance";

  class OpenHRP_CollisionDetectorService_setToleranceRequest : public ros::Msg
  {
    public:
      typedef const char* _link_pair_name_type;
      _link_pair_name_type link_pair_name;
      typedef float _tolerance_type;
      _tolerance_type tolerance;

    OpenHRP_CollisionDetectorService_setToleranceRequest():
      link_pair_name(""),
      tolerance(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_link_pair_name = strlen(this->link_pair_name);
      varToArr(outbuffer + offset, length_link_pair_name);
      offset += 4;
      memcpy(outbuffer + offset, this->link_pair_name, length_link_pair_name);
      offset += length_link_pair_name;
      offset += serializeAvrFloat64(outbuffer + offset, this->tolerance);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_link_pair_name;
      arrToVar(length_link_pair_name, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_link_pair_name; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_link_pair_name-1]=0;
      this->link_pair_name = (char *)(inbuffer + offset-1);
      offset += length_link_pair_name;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->tolerance));
     return offset;
    }

    const char * getType(){ return OPENHRP_COLLISIONDETECTORSERVICE_SETTOLERANCE; };
    const char * getMD5(){ return "454672d6fa714d34c7d2963712d4bbe5"; };

  };

  class OpenHRP_CollisionDetectorService_setToleranceResponse : public ros::Msg
  {
    public:
      typedef bool _operation_return_type;
      _operation_return_type operation_return;

    OpenHRP_CollisionDetectorService_setToleranceResponse():
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

    const char * getType(){ return OPENHRP_COLLISIONDETECTORSERVICE_SETTOLERANCE; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_CollisionDetectorService_setTolerance {
    public:
    typedef OpenHRP_CollisionDetectorService_setToleranceRequest Request;
    typedef OpenHRP_CollisionDetectorService_setToleranceResponse Response;
  };

}
#endif
