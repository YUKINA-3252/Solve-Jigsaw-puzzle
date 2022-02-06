#ifndef _ROS_SERVICE_OpenHRP_TorqueControllerService_disableMultipleTorqueControllers_h
#define _ROS_SERVICE_OpenHRP_TorqueControllerService_disableMultipleTorqueControllers_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_TORQUECONTROLLERSERVICE_DISABLEMULTIPLETORQUECONTROLLERS[] = "hrpsys_ros_bridge/OpenHRP_TorqueControllerService_disableMultipleTorqueControllers";

  class OpenHRP_TorqueControllerService_disableMultipleTorqueControllersRequest : public ros::Msg
  {
    public:
      uint32_t jnames_length;
      typedef char* _jnames_type;
      _jnames_type st_jnames;
      _jnames_type * jnames;

    OpenHRP_TorqueControllerService_disableMultipleTorqueControllersRequest():
      jnames_length(0), jnames(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->jnames_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->jnames_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->jnames_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->jnames_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->jnames_length);
      for( uint32_t i = 0; i < jnames_length; i++){
      uint32_t length_jnamesi = strlen(this->jnames[i]);
      varToArr(outbuffer + offset, length_jnamesi);
      offset += 4;
      memcpy(outbuffer + offset, this->jnames[i], length_jnamesi);
      offset += length_jnamesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t jnames_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      jnames_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      jnames_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      jnames_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->jnames_length);
      if(jnames_lengthT > jnames_length)
        this->jnames = (char**)realloc(this->jnames, jnames_lengthT * sizeof(char*));
      jnames_length = jnames_lengthT;
      for( uint32_t i = 0; i < jnames_length; i++){
      uint32_t length_st_jnames;
      arrToVar(length_st_jnames, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_jnames; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_jnames-1]=0;
      this->st_jnames = (char *)(inbuffer + offset-1);
      offset += length_st_jnames;
        memcpy( &(this->jnames[i]), &(this->st_jnames), sizeof(char*));
      }
     return offset;
    }

    const char * getType(){ return OPENHRP_TORQUECONTROLLERSERVICE_DISABLEMULTIPLETORQUECONTROLLERS; };
    const char * getMD5(){ return "2ced7fdc11680dafdfdf754b59114e73"; };

  };

  class OpenHRP_TorqueControllerService_disableMultipleTorqueControllersResponse : public ros::Msg
  {
    public:
      typedef bool _operation_return_type;
      _operation_return_type operation_return;

    OpenHRP_TorqueControllerService_disableMultipleTorqueControllersResponse():
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

    const char * getType(){ return OPENHRP_TORQUECONTROLLERSERVICE_DISABLEMULTIPLETORQUECONTROLLERS; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_TorqueControllerService_disableMultipleTorqueControllers {
    public:
    typedef OpenHRP_TorqueControllerService_disableMultipleTorqueControllersRequest Request;
    typedef OpenHRP_TorqueControllerService_disableMultipleTorqueControllersResponse Response;
  };

}
#endif
