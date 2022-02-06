#ifndef _ROS_SERVICE_OpenHRP_ReferenceForceUpdaterService_startReferenceForceUpdaterNoWait_h
#define _ROS_SERVICE_OpenHRP_ReferenceForceUpdaterService_startReferenceForceUpdaterNoWait_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_REFERENCEFORCEUPDATERSERVICE_STARTREFERENCEFORCEUPDATERNOWAIT[] = "hrpsys_ros_bridge/OpenHRP_ReferenceForceUpdaterService_startReferenceForceUpdaterNoWait";

  class OpenHRP_ReferenceForceUpdaterService_startReferenceForceUpdaterNoWaitRequest : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;

    OpenHRP_ReferenceForceUpdaterService_startReferenceForceUpdaterNoWaitRequest():
      name("")
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
     return offset;
    }

    const char * getType(){ return OPENHRP_REFERENCEFORCEUPDATERSERVICE_STARTREFERENCEFORCEUPDATERNOWAIT; };
    const char * getMD5(){ return "c1f3d28f1b044c871e6eff2e9fc3c667"; };

  };

  class OpenHRP_ReferenceForceUpdaterService_startReferenceForceUpdaterNoWaitResponse : public ros::Msg
  {
    public:
      typedef bool _operation_return_type;
      _operation_return_type operation_return;

    OpenHRP_ReferenceForceUpdaterService_startReferenceForceUpdaterNoWaitResponse():
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

    const char * getType(){ return OPENHRP_REFERENCEFORCEUPDATERSERVICE_STARTREFERENCEFORCEUPDATERNOWAIT; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_ReferenceForceUpdaterService_startReferenceForceUpdaterNoWait {
    public:
    typedef OpenHRP_ReferenceForceUpdaterService_startReferenceForceUpdaterNoWaitRequest Request;
    typedef OpenHRP_ReferenceForceUpdaterService_startReferenceForceUpdaterNoWaitResponse Response;
  };

}
#endif
