#ifndef _ROS_SERVICE_OpenHRP_RemoveForceSensorLinkOffsetService_removeForceSensorOffset_h
#define _ROS_SERVICE_OpenHRP_RemoveForceSensorLinkOffsetService_removeForceSensorOffset_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace hrpsys_ros_bridge
{

static const char OPENHRP_REMOVEFORCESENSORLINKOFFSETSERVICE_REMOVEFORCESENSOROFFSET[] = "hrpsys_ros_bridge/OpenHRP_RemoveForceSensorLinkOffsetService_removeForceSensorOffset";

  class OpenHRP_RemoveForceSensorLinkOffsetService_removeForceSensorOffsetRequest : public ros::Msg
  {
    public:
      uint32_t names_length;
      typedef char* _names_type;
      _names_type st_names;
      _names_type * names;
      typedef float _tm_type;
      _tm_type tm;

    OpenHRP_RemoveForceSensorLinkOffsetService_removeForceSensorOffsetRequest():
      names_length(0), names(NULL),
      tm(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->names_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->names_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->names_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->names_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->names_length);
      for( uint32_t i = 0; i < names_length; i++){
      uint32_t length_namesi = strlen(this->names[i]);
      varToArr(outbuffer + offset, length_namesi);
      offset += 4;
      memcpy(outbuffer + offset, this->names[i], length_namesi);
      offset += length_namesi;
      }
      offset += serializeAvrFloat64(outbuffer + offset, this->tm);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t names_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      names_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      names_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      names_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->names_length);
      if(names_lengthT > names_length)
        this->names = (char**)realloc(this->names, names_lengthT * sizeof(char*));
      names_length = names_lengthT;
      for( uint32_t i = 0; i < names_length; i++){
      uint32_t length_st_names;
      arrToVar(length_st_names, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_names; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_names-1]=0;
      this->st_names = (char *)(inbuffer + offset-1);
      offset += length_st_names;
        memcpy( &(this->names[i]), &(this->st_names), sizeof(char*));
      }
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->tm));
     return offset;
    }

    const char * getType(){ return OPENHRP_REMOVEFORCESENSORLINKOFFSETSERVICE_REMOVEFORCESENSOROFFSET; };
    const char * getMD5(){ return "c89cf9d69f0652e9bafee37766b5d68d"; };

  };

  class OpenHRP_RemoveForceSensorLinkOffsetService_removeForceSensorOffsetResponse : public ros::Msg
  {
    public:
      typedef bool _operation_return_type;
      _operation_return_type operation_return;

    OpenHRP_RemoveForceSensorLinkOffsetService_removeForceSensorOffsetResponse():
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

    const char * getType(){ return OPENHRP_REMOVEFORCESENSORLINKOFFSETSERVICE_REMOVEFORCESENSOROFFSET; };
    const char * getMD5(){ return "8dd59ee39c15084c92106411b8c3e8fc"; };

  };

  class OpenHRP_RemoveForceSensorLinkOffsetService_removeForceSensorOffset {
    public:
    typedef OpenHRP_RemoveForceSensorLinkOffsetService_removeForceSensorOffsetRequest Request;
    typedef OpenHRP_RemoveForceSensorLinkOffsetService_removeForceSensorOffsetResponse Response;
  };

}
#endif
