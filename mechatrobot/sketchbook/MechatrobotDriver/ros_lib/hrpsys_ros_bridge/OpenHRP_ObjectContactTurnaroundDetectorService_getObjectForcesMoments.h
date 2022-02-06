#ifndef _ROS_SERVICE_OpenHRP_ObjectContactTurnaroundDetectorService_getObjectForcesMoments_h
#define _ROS_SERVICE_OpenHRP_ObjectContactTurnaroundDetectorService_getObjectForcesMoments_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Float64MultiArray.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_OBJECTCONTACTTURNAROUNDDETECTORSERVICE_GETOBJECTFORCESMOMENTS[] = "hrpsys_ros_bridge/OpenHRP_ObjectContactTurnaroundDetectorService_getObjectForcesMoments";

  class OpenHRP_ObjectContactTurnaroundDetectorService_getObjectForcesMomentsRequest : public ros::Msg
  {
    public:

    OpenHRP_ObjectContactTurnaroundDetectorService_getObjectForcesMomentsRequest()
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

    const char * getType(){ return OPENHRP_OBJECTCONTACTTURNAROUNDDETECTORSERVICE_GETOBJECTFORCESMOMENTS; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_ObjectContactTurnaroundDetectorService_getObjectForcesMomentsResponse : public ros::Msg
  {
    public:
      typedef bool _operation_return_type;
      _operation_return_type operation_return;
      typedef std_msgs::Float64MultiArray _o_forces_type;
      _o_forces_type o_forces;
      typedef std_msgs::Float64MultiArray _o_moments_type;
      _o_moments_type o_moments;
      float o_3dofwrench[3];
      typedef float _o_fric_coeff_wrench_type;
      _o_fric_coeff_wrench_type o_fric_coeff_wrench;

    OpenHRP_ObjectContactTurnaroundDetectorService_getObjectForcesMomentsResponse():
      operation_return(0),
      o_forces(),
      o_moments(),
      o_3dofwrench(),
      o_fric_coeff_wrench(0)
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
      offset += this->o_forces.serialize(outbuffer + offset);
      offset += this->o_moments.serialize(outbuffer + offset);
      for( uint32_t i = 0; i < 3; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->o_3dofwrench[i]);
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->o_fric_coeff_wrench);
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
      offset += this->o_forces.deserialize(inbuffer + offset);
      offset += this->o_moments.deserialize(inbuffer + offset);
      for( uint32_t i = 0; i < 3; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->o_3dofwrench[i]));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->o_fric_coeff_wrench));
     return offset;
    }

    const char * getType(){ return OPENHRP_OBJECTCONTACTTURNAROUNDDETECTORSERVICE_GETOBJECTFORCESMOMENTS; };
    const char * getMD5(){ return "d0bce08e142f0891f190c6bf4aa33922"; };

  };

  class OpenHRP_ObjectContactTurnaroundDetectorService_getObjectForcesMoments {
    public:
    typedef OpenHRP_ObjectContactTurnaroundDetectorService_getObjectForcesMomentsRequest Request;
    typedef OpenHRP_ObjectContactTurnaroundDetectorService_getObjectForcesMomentsResponse Response;
  };

}
#endif
