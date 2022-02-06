#ifndef _ROS_SERVICE_OpenHRP_AutoBalancerService_getGoPosFootstepsSequence_h
#define _ROS_SERVICE_OpenHRP_AutoBalancerService_getGoPosFootstepsSequence_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_Footsteps.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_AUTOBALANCERSERVICE_GETGOPOSFOOTSTEPSSEQUENCE[] = "hrpsys_ros_bridge/OpenHRP_AutoBalancerService_getGoPosFootstepsSequence";

  class OpenHRP_AutoBalancerService_getGoPosFootstepsSequenceRequest : public ros::Msg
  {
    public:
      typedef float _x_type;
      _x_type x;
      typedef float _y_type;
      _y_type y;
      typedef float _th_type;
      _th_type th;

    OpenHRP_AutoBalancerService_getGoPosFootstepsSequenceRequest():
      x(0),
      y(0),
      th(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += serializeAvrFloat64(outbuffer + offset, this->x);
      offset += serializeAvrFloat64(outbuffer + offset, this->y);
      offset += serializeAvrFloat64(outbuffer + offset, this->th);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->th));
     return offset;
    }

    const char * getType(){ return OPENHRP_AUTOBALANCERSERVICE_GETGOPOSFOOTSTEPSSEQUENCE; };
    const char * getMD5(){ return "000e435776f4fd6ba555d25d7a61ed8f"; };

  };

  class OpenHRP_AutoBalancerService_getGoPosFootstepsSequenceResponse : public ros::Msg
  {
    public:
      typedef bool _operation_return_type;
      _operation_return_type operation_return;
      uint32_t o_footstep_length;
      typedef hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footsteps _o_footstep_type;
      _o_footstep_type st_o_footstep;
      _o_footstep_type * o_footstep;

    OpenHRP_AutoBalancerService_getGoPosFootstepsSequenceResponse():
      operation_return(0),
      o_footstep_length(0), o_footstep(NULL)
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
      *(outbuffer + offset + 0) = (this->o_footstep_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->o_footstep_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->o_footstep_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->o_footstep_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->o_footstep_length);
      for( uint32_t i = 0; i < o_footstep_length; i++){
      offset += this->o_footstep[i].serialize(outbuffer + offset);
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
      uint32_t o_footstep_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      o_footstep_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      o_footstep_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      o_footstep_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->o_footstep_length);
      if(o_footstep_lengthT > o_footstep_length)
        this->o_footstep = (hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footsteps*)realloc(this->o_footstep, o_footstep_lengthT * sizeof(hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footsteps));
      o_footstep_length = o_footstep_lengthT;
      for( uint32_t i = 0; i < o_footstep_length; i++){
      offset += this->st_o_footstep.deserialize(inbuffer + offset);
        memcpy( &(this->o_footstep[i]), &(this->st_o_footstep), sizeof(hrpsys_ros_bridge::OpenHRP_AutoBalancerService_Footsteps));
      }
     return offset;
    }

    const char * getType(){ return OPENHRP_AUTOBALANCERSERVICE_GETGOPOSFOOTSTEPSSEQUENCE; };
    const char * getMD5(){ return "cc0ef1a114b5c814d73c3153a686b820"; };

  };

  class OpenHRP_AutoBalancerService_getGoPosFootstepsSequence {
    public:
    typedef OpenHRP_AutoBalancerService_getGoPosFootstepsSequenceRequest Request;
    typedef OpenHRP_AutoBalancerService_getGoPosFootstepsSequenceResponse Response;
  };

}
#endif
