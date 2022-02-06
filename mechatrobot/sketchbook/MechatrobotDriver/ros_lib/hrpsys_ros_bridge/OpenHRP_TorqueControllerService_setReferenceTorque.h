#ifndef _ROS_SERVICE_OpenHRP_TorqueControllerService_setReferenceTorque_h
#define _ROS_SERVICE_OpenHRP_TorqueControllerService_setReferenceTorque_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_TORQUECONTROLLERSERVICE_SETREFERENCETORQUE[] = "hrpsys_ros_bridge/OpenHRP_TorqueControllerService_setReferenceTorque";

  class OpenHRP_TorqueControllerService_setReferenceTorqueRequest : public ros::Msg
  {
    public:
      typedef const char* _jname_type;
      _jname_type jname;
      typedef float _tauRef_type;
      _tauRef_type tauRef;

    OpenHRP_TorqueControllerService_setReferenceTorqueRequest():
      jname(""),
      tauRef(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_jname = strlen(this->jname);
      varToArr(outbuffer + offset, length_jname);
      offset += 4;
      memcpy(outbuffer + offset, this->jname, length_jname);
      offset += length_jname;
      offset += serializeAvrFloat64(outbuffer + offset, this->tauRef);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_jname;
      arrToVar(length_jname, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_jname; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_jname-1]=0;
      this->jname = (char *)(inbuffer + offset-1);
      offset += length_jname;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->tauRef));
     return offset;
    }

    const char * getType(){ return OPENHRP_TORQUECONTROLLERSERVICE_SETREFERENCETORQUE; };
    const char * getMD5(){ return "1153c46acb791af55d857dbb85eb7e0a"; };

  };

  class OpenHRP_TorqueControllerService_setReferenceTorqueResponse : public ros::Msg
  {
    public:
      typedef bool _operation_return_type;
      _operation_return_type operation_return;

    OpenHRP_TorqueControllerService_setReferenceTorqueResponse():
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

    const char * getType(){ return OPENHRP_TORQUECONTROLLERSERVICE_SETREFERENCETORQUE; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_TorqueControllerService_setReferenceTorque {
    public:
    typedef OpenHRP_TorqueControllerService_setReferenceTorqueRequest Request;
    typedef OpenHRP_TorqueControllerService_setReferenceTorqueResponse Response;
  };

}
#endif
