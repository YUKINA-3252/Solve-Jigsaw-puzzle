#ifndef _ROS_SERVICE_OpenHRP_ObjectContactTurnaroundDetectorService_checkObjectContactTurnaroundDetection_h
#define _ROS_SERVICE_OpenHRP_ObjectContactTurnaroundDetectorService_checkObjectContactTurnaroundDetection_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_OBJECTCONTACTTURNAROUNDDETECTORSERVICE_CHECKOBJECTCONTACTTURNAROUNDDETECTION[] = "hrpsys_ros_bridge/OpenHRP_ObjectContactTurnaroundDetectorService_checkObjectContactTurnaroundDetection";

  class OpenHRP_ObjectContactTurnaroundDetectorService_checkObjectContactTurnaroundDetectionRequest : public ros::Msg
  {
    public:

    OpenHRP_ObjectContactTurnaroundDetectorService_checkObjectContactTurnaroundDetectionRequest()
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

    const char * getType(){ return OPENHRP_OBJECTCONTACTTURNAROUNDDETECTORSERVICE_CHECKOBJECTCONTACTTURNAROUNDDETECTION; };
    const char * getMD5(){ return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

  class OpenHRP_ObjectContactTurnaroundDetectorService_checkObjectContactTurnaroundDetectionResponse : public ros::Msg
  {
    public:
      typedef int64_t _operation_return_type;
      _operation_return_type operation_return;

    OpenHRP_ObjectContactTurnaroundDetectorService_checkObjectContactTurnaroundDetectionResponse():
      operation_return(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_operation_return;
      u_operation_return.real = this->operation_return;
      *(outbuffer + offset + 0) = (u_operation_return.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_operation_return.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_operation_return.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_operation_return.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_operation_return.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_operation_return.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_operation_return.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_operation_return.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->operation_return);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int64_t real;
        uint64_t base;
      } u_operation_return;
      u_operation_return.base = 0;
      u_operation_return.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_operation_return.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_operation_return.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_operation_return.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_operation_return.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_operation_return.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_operation_return.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_operation_return.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->operation_return = u_operation_return.real;
      offset += sizeof(this->operation_return);
     return offset;
    }

    const char * getType(){ return OPENHRP_OBJECTCONTACTTURNAROUNDDETECTORSERVICE_CHECKOBJECTCONTACTTURNAROUNDDETECTION; };
    const char * getMD5(){ return "82ded91c1a3e10db0e5768f3931d83ed"; };

  };

  class OpenHRP_ObjectContactTurnaroundDetectorService_checkObjectContactTurnaroundDetection {
    public:
    typedef OpenHRP_ObjectContactTurnaroundDetectorService_checkObjectContactTurnaroundDetectionRequest Request;
    typedef OpenHRP_ObjectContactTurnaroundDetectorService_checkObjectContactTurnaroundDetectionResponse Response;
  };

}
#endif
