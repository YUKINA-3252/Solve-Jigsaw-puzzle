#ifndef _ROS_SERVICE_OpenHRP_ReferenceForceUpdaterService_setReferenceForceUpdaterParam_h
#define _ROS_SERVICE_OpenHRP_ReferenceForceUpdaterService_setReferenceForceUpdaterParam_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "hrpsys_ros_bridge/OpenHRP_ReferenceForceUpdaterService_ReferenceForceUpdaterParam.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_REFERENCEFORCEUPDATERSERVICE_SETREFERENCEFORCEUPDATERPARAM[] = "hrpsys_ros_bridge/OpenHRP_ReferenceForceUpdaterService_setReferenceForceUpdaterParam";

  class OpenHRP_ReferenceForceUpdaterService_setReferenceForceUpdaterParamRequest : public ros::Msg
  {
    public:
      typedef const char* _name_type;
      _name_type name;
      typedef hrpsys_ros_bridge::OpenHRP_ReferenceForceUpdaterService_ReferenceForceUpdaterParam _i_param_type;
      _i_param_type i_param;

    OpenHRP_ReferenceForceUpdaterService_setReferenceForceUpdaterParamRequest():
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

    const char * getType(){ return OPENHRP_REFERENCEFORCEUPDATERSERVICE_SETREFERENCEFORCEUPDATERPARAM; };
    const char * getMD5(){ return "6ce2b3451a4b25293885fe343c10d78a"; };

  };

  class OpenHRP_ReferenceForceUpdaterService_setReferenceForceUpdaterParamResponse : public ros::Msg
  {
    public:
      typedef bool _operation_return_type;
      _operation_return_type operation_return;

    OpenHRP_ReferenceForceUpdaterService_setReferenceForceUpdaterParamResponse():
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

    const char * getType(){ return OPENHRP_REFERENCEFORCEUPDATERSERVICE_SETREFERENCEFORCEUPDATERPARAM; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_ReferenceForceUpdaterService_setReferenceForceUpdaterParam {
    public:
    typedef OpenHRP_ReferenceForceUpdaterService_setReferenceForceUpdaterParamRequest Request;
    typedef OpenHRP_ReferenceForceUpdaterService_setReferenceForceUpdaterParamResponse Response;
  };

}
#endif